//
//  KATRouter.h
//  KATFramework
//
//  Created by Kantice on 2017/4/25.
//  Copyright © 2017年 KatApp. All rights reserved.
//  视图控制器切换路由器
//  AppDelegate需要实现生命周期代理方法
//
//  Action分为:
//  1.一般Action: 由id类型作为observer，添加后主动调用执行；
//  2.HostAction: 由host作为observer，执行action时会跳转到该host；
//  3.Mission: 由日志状态触发的action，分为日期、时长、事件次数三类触发模式；
//  三种action独立储存，由action的名称作为标识，添加相同的标识会覆盖当前的action。



#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <objc/runtime.h>

#import "KATHashMap.h"
#import "KATStack.h"
#import "KATTreeMap.h"
#import "KATDateUtil.h"
#import "KATURIParser.h"
#import "KATAppUtil.h"
#import "KATTabBar.h"
#import "KATNavBar.h"
#import "KATHttpRequest.h"
#import "KATImageUtil.h"

#import "KATAlertWindow.h"
#import "KATButtonWindow.h"
#import "KATChoiceWindow.h"
#import "KATInputWindow.h"
#import "KATTextFieldWindow.h"
#import "KATWaitWindow.h"
#import "KATToast.h"

#import "KATRouterLoader.h"



#define ROUTER_VERSION @"1.0"


@class KATTabBar;
@class KATNavBar;
@class KATNavTransition;


///根视图控制器的host
extern NSString * const kRouterRootHost;

///全局数据容器的host
extern NSString * const kRouterGlobalHost;

///执行者host
extern NSString * const kRouterExecutorHost;

///远程消息
extern NSString * const kRouterNotificationTypeRemote;

///本地消息
extern NSString * const kRouterNotificationTypeLocal;

///消息类型的key
extern NSString * const kRouterKeyMessageType;

///通知类型的key
extern NSString * const kRouterKeyNotificationType;

///scheme的key
extern NSString * const kRouterKeyScheme;

///user的key
extern NSString * const kRouterKeyUser;

///host的key
extern NSString * const kRouterKeyHost;

///fromHost的key
extern NSString * const kRouterKeyFromHost;

///toHost的key
extern NSString * const kRouterKeyToHost;

///是否回退的key
extern NSString * const kRouterKeyBackward;

///是否因为依赖关系而跳转的key
extern NSString * const kRouterKeyDependence;

///是否为外部链接而跳转的key
extern NSString * const kRouterKeyFromOutside;

///port的key
extern NSString * const kRouterKeyPort;

///path的key
extern NSString * const kRouterKeyPath;

///附加对象的key
extern NSString * const kRouterKeyAddition;

///fragment的key
extern NSString * const kRouterKeyFragment;

///默认的转场动画风格的key
extern NSString * const kRouterKeyTransitionStyle;

///默认的转场动画时长的key
extern NSString * const kRouterKeyTransitionDuration;

///默认的是否路由时新建实例的key
extern NSString * const kRouterKeyRoutingWithNewInstance;

///默认的是否路由时创建多例的key
extern NSString * const kRouterKeyRoutingWithMultipleInstance;

///fromHost的截图
extern NSString * const kRouterKeyFromHostSnapshot;




/*  日志
 
    app和host的进入离开记录会自动记录，event需要手动添加代码到需要记录的位置
    日志文件按日保存，文件名格式:yyyymmdd.log 如20140528.log
    在app退到后台时保存并上传至服务器(如果需要上传的话)

    内容结构:
    {
        "app":"demo", //app名称
 
        "date":"20140528", //日期
 
        "os_version":"12.0", //系统版本,上传服务器时携带,本地不保存
 
        "device_model":"iPhone", //设备型号,上传服务器时携带,本地不保存
 
        "device_type":"iPhone8,1", //设备类别,上传服务器时携带,本地不保存
 
        "device":"iPhone 6s", //具体设备,上传服务器时携带,本地不保存
 
        "app_version":"1.0.0", //app版本,上传服务器时携带,本地不保存
 
        "language":"en", //语言
 
        "locale":"US", //地区
 
        "signature":"1538987677", //服务器签名,如时间戳(1970年到现在的秒数),上传日志时会通过服务器获取,若获取不到,则不使用(本地保存的日志文件无该字段)
 
        "verification":"568FC169F139FBB787A366C147F9CC83", //校验码,生成规则为MD5("kat_router_logs-"+signature+"-"+app_version)(32位大写),上传服务器时会自动生成,本地日志无该字段
        
        "logs": //日志数组
        [
            //日志根节点
            {
                "id":"u12345678", //日志的id(用户ID)
 
                "date":"20140528", //记录的日期
 
                "num":"10000001", //记录编号(自增序号)
 
                "enter":"20140528220101", //app进入时间，精确到秒
         
                "hosts": //host跳转记录数组(根据数据顺序排列)
                [
                    //跳转的host单次记录(每次跳转都分别记录)
                    {
                        "index":"0", //序号(表示第N个跳转的页面，从0开始计)
 
                        "host":"mine", //host名称
 
                        "from":"home", //上一个host
 
                        "back":"0", //是否是回退回来(1是,0不是)
 
                        "uri":"app://mine/login?name=kat", //跳转时传入的URI
 
                        "level":"4", //host当前位于栈上的层次(从0开始计，4表示在第4层)(因为加载的时间关系，可能存在1层的误差)
 
                        "stack":"home,test2,test1", //host返回栈(以","分隔，最多存最近的5个)
         
                        "enter":"20140528220101", //host进入时间
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
                        "events": //action触发记录数组
                        [
                            //触发的单次事件
                            {
                                "index":"0", //序号(表示该host下的第N次事件，从0开始计)
 
                                "event":"mine.login", //事件名称(最好能以host为前缀保持唯一性)
                                
                                "time":"20140528220101000", //事件触发时间，精确到毫秒
         
                                "tag":"1", //事件的标签(整数，默认为0)
         
                                "msg":"test message", //事件携带的消息(整数，默认为空)
         
                                ... //其他属性(待定)
                            },
         
                            ... //其他事件
                        ],
         
                        "leave":"20140528220231", //host离开时间
         
                        "duration":"30", //host停留时间(单位为秒)
         
                        ... //其他属性(待定)
                    },
         
                    ... //其他host记录
                ],
         
                "leave":"20140528220201", //app离开时间
         
                "duration":"60", //app持续使用时间(单位为秒)
         
                "status":"0", //状态(0表示未知,1表示已上传,其他状态待定)
                
                ... //其他属性(待定)
            },
        
            ... //其他日志
        ]
    }

*/


///日志:默认的上传内容属性名
extern NSString * const kRouterLogsUploadContentDefaultKey;

///日志:app名称的key
extern NSString * const kRouterLogsKeyApp;

///日志:id的key
extern NSString * const kRouterLogsKeyID;

///日志:日期的key
extern NSString * const kRouterLogsKeyDate;

///日志:系统版本的key
extern NSString * const kRouterLogsKeyOSVersion;

///日志:设备型号的key
extern NSString * const kRouterLogsKeyDeviceModel;

///日志:设备类型的key
extern NSString * const kRouterLogsKeyDeviceType;

///日志:具体设备的key
extern NSString * const kRouterLogsKeyDevice;

///日志:app版本的key
extern NSString * const kRouterLogsKeyAppVersion;

///日志:语言的key
extern NSString * const kRouterLogsKeyLanguage;

///日志:地区的key
extern NSString * const kRouterLogsKeyLocale;

///日志:时间戳的key
extern NSString * const kRouterLogsKeySignature;

///日志:校验码的key
extern NSString * const kRouterLogsKeyVerification;

///日志:该日的日志数组
extern NSString * const kRouterLogsKeyLogs;

///日志:编号的key
extern NSString * const kRouterLogsKeyLogNum;

///日志:日期的key
extern NSString * const kRouterLogsKeyLogDate;

///日志:日期的key
extern NSString * const kRouterLogsKeyLogStatus;

///日志:app进入时间key
extern NSString * const kRouterLogsKeyAppEnterTime;

///日志:app离开时间key
extern NSString * const kRouterLogsKeyAppLeaveTime;

///日志:app持续使用时间key
extern NSString * const kRouterLogsKeyAppDuration;

///日志:host跳转记录数组key
extern NSString * const kRouterLogsKeyHosts;

///日志:每次展现的host的根节点key
extern NSString * const kRouterLogsKeyHost;

///日志:host序号key
extern NSString * const kRouterLogsKeyHostIndex;

///日志:host层次key
extern NSString * const kRouterLogsKeyHostLevel;

///日志:host进入时间key
extern NSString * const kRouterLogsKeyHostEnterTime;

///日志:host离开时间key
extern NSString * const kRouterLogsKeyHostLeaveTime;

///日志:host停留时间key
extern NSString * const kRouterLogsKeyHostDuration;

///日志:跳转到该host的URI的key
extern NSString * const kRouterLogsKeyHostURI;

///日志:跳转到该host的Host的key
extern NSString * const kRouterLogsKeyHostFrom;

///日志:是否回退回来的key
extern NSString * const kRouterLogsKeyHostBack;

///日志:host返回栈的key
extern NSString * const kRouterLogsKeyHostStack;

///日志:事件记录数组key
extern NSString * const kRouterLogsKeyEvents;

///日志:事件名称key
extern NSString * const kRouterLogsKeyEvent;

///日志:事件序号key
extern NSString * const kRouterLogsKeyEventIndex;

///日志:事件所带的消息key
extern NSString * const kRouterLogsKeyEventMessage;

///日志:事件触发时间key
extern NSString * const kRouterLogsKeyEventTime;

///日志:事件tag的key
extern NSString * const kRouterLogsKeyEventTag;



/*  命令
 
    用于执行远程服务器的命令
    在app加载完成时从服务器中更新(如果需要的话)，也可以在任意时刻主动调用方法更新或执行命令
 
    请求数据格式:
    {
        "id":"u12345678", //用户ID
 
        "app":"demo", //app名称
 
        "os_version":"12.0", //系统版本
 
        "device_model":"iPhone", //设备型号
 
        "device_type":"iPhone8,1", //设备类别
 
        "device":"iPhone 6s", //具体设备
 
        "app_version":"1.0.0", //app版本
 
        "router_version":"1.0.0", //路由器版本
 
        "language":"en", //语言
 
        "locale":"US", //地区
 
        "time":"201405282201010000", //获取任务的时间
 
        "check_code":"123456", //随机生成的路由器校验码(在更新命令时更新校验码)
 
        ... //其他字段
    }
 
 
    //命令集合数据格式
    {
        "code":"10001", //该命令集合代号
 
        "once":"1", //该命令集合是否只执行一次(非零则只执行一次，若为0或无该值，则执行多次)
 
        "time":"201405282201010000", //获取任务的时间
 
        "verification":"568FC169F139FBB787A366C147F9CC83", //命令的校验码，生成规则为MD5(code+"-"+userID+"-"+check_code+"-"+time)(32位大写)(check_code为路由器随机生成的校验码)
 
        "commands": //命令列表(按顺序执行)
        [
            {
                "type":"window", //类型:窗口
 
                "subtype":"toast", //子类型
 
                "info":"this is a test.", //信息
            },
 
            {
                "type":"window", //类型:窗口
 
                "subtype":"alert", //子类型
 
                "title":"test title", //默认标题
 
                "title.en":"英文标题", //英文标题
                "title.cn":"测试标题", //中文标题
                "title.cnt":"测试标题", //繁体中文标题
                "title.ja":"测试标题", //日文标题
 
                "info":"this is a test.", //默认信息
 
                "info.en":"this is a test.", //英文信息
                "info.cn":"this is a test.", //中文信息
                "info.cnt":"this is a test.", //繁体中文信息
                "info.ja":"this is a test.", //日文信息
 
            },
 
            {
                "type":"window", //类型:窗口
 
                "subtype":"button", //子类型
 
                "title":"test title", //标题
 
                "info":"this is a test.", //信息
 
                "uri":"test1", //跳转的URI
            },
 
            {
                "type":"window", //类型:窗口
 
                "subtype":"choice", //子类型
 
                "title":"test title", //标题
 
                "info":"this is a test.", //信息
 
                "cancel":"Cancel", //默认取消按钮
 
                "cancel.en":"取消",  //英文取消按钮
 
                "confirm":"OK",    //默认确定按钮
 
                "uri":"test2", //跳转的URI
             },
 
            {
                "type":"configuration", //类型:配置属性
 
                "key":"logs_keep_days", //属性名，如日志保存时长
 
                "value_type":"int", //值类型:string,int,float(分别对应NSString,long long int和double类型)
 
                "operator":"=", //操作符:=(直接替换),+(数字与原值相加，字符串追加),-(数值减),*(数值乘),/(数值除)
 
                "value":"3", //值
 
                "verification":"568FC169F139FBB787A366C147F9CC83", //修改属性需要验证码，生成规则为MD5(key+"-"+value+"-"+operator+"-"+check_code)(32位大写)
            },
 
            {
                "type":"values", //类型:存储值属性
 
                "key":"aa", //属性名
 
                "value_type":"int", //值类型:string,int,float(分别对应NSString,long long int和double类型)
 
                "operator":"+", //操作符:=(直接替换),+(数字与原值相加，字符串追加),-(数值减),*(数值乘),/(数值除)
 
                "value":"3", //值
 
                "verification":"568FC169F139FBB787A366C147F9CC83", //修改属性需要验证码，生成规则为MD5(key+"-"+value+"-"+operator+"-"+check_code)(32位大写)
            },

            {
                "type":"data", //类型:加密值属性
 
                "key":"aa", //属性名
 
                "value_type":"int", //值类型:string,int,float(分别对应NSString,long long int和double类型)
 
                "operator":"+", //操作符:=(直接替换),+(数字与原值相加，字符串追加),-(数值减),*(数值乘),/(数值除)
 
                "value":"3", //值
 
                "verification":"568FC169F139FBB787A366C147F9CC83" //修改属性需要验证码，生成规则为MD5(key+"-"+value+"-"+operator+"-"+check_code)(32位大写)
            },
 
            {
                "type":"action", //类型:动作
 
                "action":"main/do", //执行的动作(跳转到该host并执行动作)
 
                "value":"xx" //携带的参数
            },
 
            {
                "type":"route", //类型:路由跳转
 
                "uri":"http://www.kantice.com" //跳转的URI
            },
 
            {
                "type":"resource", //类型:资源
 
                "directory":"documents", //目录:app,documents,tmp,library
 
                "path":"/Resource/String/cn.txt", //保存的子路径(包括文件名)
 
                "url":"http://www.kantice.com/file/cn.txt" //服务器文件URL
            },
 
            {
                "type":"forbid", //类型:屏蔽host
 
                "hosts":"test3,test2", //屏蔽的host数组,逗号分隔
 
                "operator":"+", //操作符,删除操作为!,没有该字段或其他则为添加
 
                "redirect":"http://www.kantice.com" //重定向的URI
            },
 
            {
                "type":"route", //类型:路由跳转
 
                "uri":"test2", //跳转的URI
 
                "delay":"2", //延迟执行秒数
 
                "or_conditions_relationship":"1", //or条件关系,若无该字段或该字段为时，条件列表关系为and
 
                "conditions": //执行条件列表(若无条件，则直接执行)(数据格式错误都为失败结果，最终结果根据条件and或or的关系而定)
                [
                    {
                        "field":"configuration", //条件域:配置属性
 
                        "key":"logs_keep_days", //属性名，如日志保存时长
 
                        "value_type":"int", //值比较类型:string,int,float(分别对应NSString,long long int和double类型)
 
                        "compare_type":">=", //比较类型:<,>,<=,>=,==,!=
 
                        "compare_value":"60", //比较值，会转换为值类型进行比较
 
                        ... //其他字段
                    },
 
                    {
                        "field":"environment", //条件域:环境属性
 
                        "key":"os_version", //属性名，如系统版本
 
                        "value_type":"string", //值比较类型:string,int,float(分别对应NSString,long long int和double类型)
 
                        "compare_type":"==", //比较类型:<,>,<=,>=,==,!=
 
                        "compare_value":"1.1.0", //比较值，会转换为值类型进行比较
 
                        ... //其他字段
                    },
 
                    {
                        "field":"values", //条件域:存储变量属性
 
                        "host":"main", //所属host，若无该字段则用全局变量
 
                        "key":"aa", //属性名，储存变量的key
 
                        "value_type":"float", //值比较类型:string,int,float(分别对应NSString,long long int和double类型)
 
                        "compare_type":"<", //比较类型:<,>,<=,>=,==,!=
 
                        "compare_value":"300.0", //比较值，会转换为值类型进行比较
 
                        ... //其他字段
                    },
 
                    {
                        "field":"data", //条件域:加密变量属性
 
                        "key":"xx", //属性名，加密变量的key
 
                        "value_type":"int", //值比较类型:string,int,float(分别对应NSString,long long int和double类型)
 
                        "compare_type":"==", //比较类型:<,>,<=,>=,==,!=
 
                        "compare_value":"3", //比较值，会转换为值类型进行比较
 
                        ... //其他字段
                    },
 
                    {
                        "field":"logs", //条件域:日志
 
                        "key":"event_history_count", //日志统计方法名
 
                        "parameter":"event_name", //部分方法需要传入的参数:如host,group,event等
 
                        "compare_type":">", //比较类型:<,>,<=,>=,==,!=
 
                        "compare_value":"3", //比较值，会转换为值类型进行比较
 
                        ... //其他字段
                    },
 
                    ... //其他条件
                ],
 
                ... //其他字段
            },
 
            ... //其他命令
        ],
 
        ... //其他字段
    }
 
 */


///命令请求:用户ID的key
extern NSString * const kRouterCMDKeyRequestID;

///命令请求:OS版本的key
extern NSString * const kRouterCMDKeyRequestOSVersion;

///命令请求:App版本的key
extern NSString * const kRouterCMDKeyRequestAppVersion;

///命令请求:设备型号的key
extern NSString * const kRouterCMDKeyRequestDeviceModel;

///命令请求:设备类型的key
extern NSString * const kRouterCMDKeyRequestDeviceType;

///命令请求:具体设备的key
extern NSString * const kRouterCMDKeyRequestDevice;

///命令请求:路由器版本的key
extern NSString * const kRouterCMDKeyRequestRouterVersion;

///命令请求:语言的key
extern NSString * const kRouterCMDKeyRequestLanguage;

///命令请求:地区的key
extern NSString * const kRouterCMDKeyRequestLocale;

///命令请求:时间的key
extern NSString * const kRouterCMDKeyRequestTime;

///命令请求:校验码的key
extern NSString * const kRouterCMDKeyRequestCheckCode;


///命令:代号的key
extern NSString * const kRouterCMDKeyCode;

///命令:是否执行一次的key
extern NSString * const kRouterCMDKeyOnce;

///命令:请求时间的key
extern NSString * const kRouterCMDKeyTime;

///命令:校验码的key
extern NSString * const kRouterCMDKeyVerification;

///命令:命令列表的key
extern NSString * const kRouterCMDKeyCommands;


///命令:类型的key
extern NSString * const kRouterCMDKeyCommandType;

///命令:子类型的key
extern NSString * const kRouterCMDKeyCommandSubtype;

///命令:动作的key
extern NSString * const kRouterCMDKeyCommandAction;

///命令:标题的key
extern NSString * const kRouterCMDKeyCommandTitle;

///命令:信息的key
extern NSString * const kRouterCMDKeyCommandInfo;

///命令:"取消"文案的key
extern NSString * const kRouterCMDKeyCommandCancel;

///命令:"确定"文案的key
extern NSString * const kRouterCMDKeyCommandConfirm;

///命令:属性名的key
extern NSString * const kRouterCMDKeyCommandKey;

///命令:值的key
extern NSString * const kRouterCMDKeyCommandValue;

///命令:值类型的key
extern NSString * const kRouterCMDKeyCommandValueType;

///命令:操作符的key
extern NSString * const kRouterCMDKeyCommandOperator;

///命令:URI的key
extern NSString * const kRouterCMDKeyCommandURI;

///命令:Host的key
extern NSString * const kRouterCMDKeyCommandHost;

///命令:Host数组的key
extern NSString * const kRouterCMDKeyCommandHosts;

///命令:重定向URI的key
extern NSString * const kRouterCMDKeyCommandRedirect;

///命令:校验码的key
extern NSString * const kRouterCMDKeyCommandVerification;

///命令:延迟时间的key
extern NSString * const kRouterCMDKeyCommandDelay;

///命令:或条件关系的key
extern NSString * const kRouterCMDKeyCommandOrRelationship;

///命令:条件列表的key
extern NSString * const kRouterCMDKeyCommandConditions;

///命令:文件目录的key
extern NSString * const kRouterCMDKeyCommandDirectory;

///命令:文件路径的key
extern NSString * const kRouterCMDKeyCommandPath;

///命令:目标URL的key
extern NSString * const kRouterCMDKeyCommandURL;


///命令:条件域的key
extern NSString * const kRouterCMDKeyConditionField;

///命令:条件属性的key
extern NSString * const kRouterCMDKeyConditionKey;

///命令:条件值类型的key
extern NSString * const kRouterCMDKeyConditionValueType;

///命令:条件比较类型的key
extern NSString * const kRouterCMDKeyConditionCompareType;

///命令:条件比较值的key
extern NSString * const kRouterCMDKeyConditionCompareValue;

///命令:条件所属host的key
extern NSString * const kRouterCMDKeyConditionHost;

///命令:条件参数的key
extern NSString * const kRouterCMDKeyConditionParameter;


///命令类型:窗口
extern NSString * const kRouterCMDValueCommandTypeWindow;

///命令类型:存储变量属性
extern NSString * const kRouterCMDValueCommandTypeValues;

///命令类型:加密变量属性
extern NSString * const kRouterCMDValueCommandTypeData;

///命令类型:配置属性
extern NSString * const kRouterCMDValueCommandTypeConfiguration;

///命令类型:动作
extern NSString * const kRouterCMDValueCommandTypeAction;

///命令类型:路由跳转
extern NSString * const kRouterCMDValueCommandTypeRoute;

///命令类型:资源下载
extern NSString * const kRouterCMDValueCommandTypeResource;

///命令类型:屏蔽
extern NSString * const kRouterCMDValueCommandTypeForbid;


///命令子类型:提醒弹窗
extern NSString * const kRouterCMDValueCommandSubtypeAlert;

///命令子类型:toast
extern NSString * const kRouterCMDValueCommandSubtypeToast;

///命令子类型:按钮弹窗
extern NSString * const kRouterCMDValueCommandSubtypeButton;

///命令子类型:选择弹窗(文本按钮弹窗)
extern NSString * const kRouterCMDValueCommandSubtypeChoice;


///命令目录类型:App
extern NSString * const kRouterCMDValueCommandDirectoryApp;

///命令目录类型:Documents
extern NSString * const kRouterCMDValueCommandDirectoryDocuments;

///命令目录类型:Library
extern NSString * const kRouterCMDValueCommandDirectoryLibrary;

///命令目录类型:Tmp
extern NSString * const kRouterCMDValueCommandDirectoryTmp;


///命令操作符类型:赋值
extern NSString * const kRouterCMDValueCommandOperatorAssign;

///命令操作符类型:加
extern NSString * const kRouterCMDValueCommandOperatorAdd;

///命令操作符类型:减
extern NSString * const kRouterCMDValueCommandOperatorMinus;

///命令操作符类型:乘
extern NSString * const kRouterCMDValueCommandOperatorMultiply;

///命令操作符类型:除
extern NSString * const kRouterCMDValueCommandOperatorDivide;

///命令操作符类型:删除
extern NSString * const kRouterCMDValueCommandOperatorDelete;


///命令条件域:配置属性
extern NSString * const kRouterCMDValueConditionFieldConfiguration;

///命令条件域:环境属性
extern NSString * const kRouterCMDValueConditionFieldEnvironment;

///命令条件域:存储值属性
extern NSString * const kRouterCMDValueConditionFieldValues;

///命令条件域:加密值属性
extern NSString * const kRouterCMDValueConditionFieldData;

///命令条件域:日志属性
extern NSString * const kRouterCMDValueConditionFieldLogs;


///命令域值类型:字符串
extern NSString * const kRouterCMDValueValueTypeString;

///命令域值类型:整数
extern NSString * const kRouterCMDValueValueTypeInteger;

///命令域值类型:浮点数
extern NSString * const kRouterCMDValueValueTypeFloat;


///命令域比较类型:等于
extern NSString * const kRouterCMDValueCompareTypeEqual;

///命令域比较类型:大于等于
extern NSString * const kRouterCMDValueCompareTypeGreaterOrEqual;

///命令域比较类型:大于
extern NSString * const kRouterCMDValueCompareTypeGreater;

///命令域比较类型:小于等于
extern NSString * const kRouterCMDValueCompareTypeLessOrEqual;

///命令域比较类型:小于
extern NSString * const kRouterCMDValueCompareTypeLess;

///命令域比较类型:不等于
extern NSString * const kRouterCMDValueCompareTypeNotEqual;


///命令域配置属性:转场动画风格
extern NSString * const kRouterCMDValueFieldConfigurationTransitionStyle;

///命令域配置属性:转场动画风格key
extern NSString * const kRouterCMDValueFieldConfigurationTransitionStyleKey;

///命令域配置属性:转场动画时长
extern NSString * const kRouterCMDValueFieldConfigurationTransitionDuration;

///命令域配置属性:转场动画时长key
extern NSString * const kRouterCMDValueFieldConfigurationTransitionDurationKey;

///命令域配置属性:路由时创建新实例的key
extern NSString * const kRouterCMDValueFieldConfigurationRoutingWithNewInstanceKey;

///命令域配置属性:路由时创建多例的key
extern NSString * const kRouterCMDValueFieldConfigurationRoutingWithMultipleInstanceKey;

///命令域配置属性:日志目录
extern NSString * const kRouterCMDValueFieldConfigurationLogsDir;

///命令域配置属性:是否保存日志
extern NSString * const kRouterCMDValueFieldConfigurationKeepLogs;

///命令域配置属性:是否上传日志
extern NSString * const kRouterCMDValueFieldConfigurationUploadLogs;

///命令域配置属性:日志上传的URL
extern NSString * const kRouterCMDValueFieldConfigurationLogsUploadURL;

///命令域配置属性:获取日志签名的URL
extern NSString * const kRouterCMDValueFieldConfigurationLogsSignatureURL;

///命令域配置属性:日志的app名称
extern NSString * const kRouterCMDValueFieldConfigurationLogsApp;

///命令域配置属性:日志的用户ID
extern NSString * const kRouterCMDValueFieldConfigurationLogsID;

///命令域配置属性:日志保存时长
extern NSString * const kRouterCMDValueFieldConfigurationLogsKeepDays;

///命令域配置属性:日志上传内容的key
extern NSString * const kRouterCMDValueFieldConfigurationLogsUploadContentKey;

///命令域配置属性:首次跳转的URI
extern NSString * const kRouterCMDValueFieldConfigurationFirstRouteURI;

///命令域配置属性:是否自动获取命令
extern NSString * const kRouterCMDValueFieldConfigurationGetCMD;

///命令域配置属性:获取命令的URL
extern NSString * const kRouterCMDValueFieldConfigurationCMDGetURL;


///命令域环境属性:系统版本
extern NSString * const kRouterCMDValueFieldEnvironmentOSVersion;

///命令域环境属性:设备型号
extern NSString * const kRouterCMDValueFieldEnvironmentDeviceModel;

///命令域环境属性:设备类别
extern NSString * const kRouterCMDValueFieldEnvironmentDeviceType;

///命令域环境属性:具体设备
extern NSString * const kRouterCMDValueFieldEnvironmentDevice;

///命令域环境属性:App版本
extern NSString * const kRouterCMDValueFieldEnvironmentAppVersion;

///命令域环境属性:语言
extern NSString * const kRouterCMDValueFieldEnvironmentLanguage;

///命令域环境属性:地区
extern NSString * const kRouterCMDValueFieldEnvironmentLocale;


///命令域日志属性:当日使用秒数(参数:无)
extern NSString * const kRouterCMDValueFieldLogsDayUsingSeconds;

///命令域日志属性:用户的当日使用秒数(参数:用户ID)
extern NSString * const kRouterCMDValueFieldLogsUserDayUsingSeconds;

///命令域日志属性:本次App的使用秒数(参数:无)
extern NSString * const kRouterCMDValueFieldLogsAppUsingSeconds;

///命令域日志属性:第一次日志距现在的天数(参数:无)
extern NSString * const kRouterCMDValueFieldLogsFirstLogDays;

///命令域日志属性:最后一次日志距现在的天数(参数:无)
extern NSString * const kRouterCMDValueFieldLogsLastLogDays;

///命令域日志属性:第一次日志距现在的秒数(参数:无)
extern NSString * const kRouterCMDValueFieldLogsFirstLogSeconds;

///命令域日志属性:最后一次日志距现在的秒数(参数:无)
extern NSString * const kRouterCMDValueFieldLogsLastLogSeconds;

///命令域日志属性:最后一次host记录距现在的天数(参数:host)
extern NSString * const kRouterCMDValueFieldLogsLastHostDays;

///命令域日志属性:最后一次event记录距现在的天数(参数:event)
extern NSString * const kRouterCMDValueFieldLogsLastEventDays;

///命令域日志属性:host的当日使用秒数(参数:host)
extern NSString * const kRouterCMDValueFieldLogsHostDayUsingSeconds;

///命令域日志属性:host的本次app使用秒数(参数:host)
extern NSString * const kRouterCMDValueFieldLogsHostAppUsingSeconds;

///命令域日志属性:group的当日使用秒数(参数:group)
extern NSString * const kRouterCMDValueFieldLogsGroupDayUsingSeconds;

///命令域日志属性:group的本次app使用秒数(参数:group)
extern NSString * const kRouterCMDValueFieldLogsGroupAppUsingSeconds;

///命令域日志属性:最后一次event距当日使用的秒数(参数:event)
extern NSString * const kRouterCMDValueFieldLogsLastEventDayUsingSeconds;

///命令域日志属性:最后一次event距本次App使用的秒数(参数:event)
extern NSString * const kRouterCMDValueFieldLogsLastEventAppUsingSeconds;

///命令域日志属性:event的历史出现次数(参数:event)
extern NSString * const kRouterCMDValueFieldLogsEventHistoryCount;

///命令域日志属性:event的当日出现次数(参数:event)
extern NSString * const kRouterCMDValueFieldLogsEventDayUsingCount;

///命令域日志属性:event的本次app使用出现次数(参数:event)
extern NSString * const kRouterCMDValueFieldLogsEventAppUsingCount;

///命令域日志属性:event的3日出现次数(参数:event)
extern NSString * const kRouterCMDValueFieldLogsEvent3DaysCount;

///命令域日志属性:event的7日出现次数(参数:event)
extern NSString * const kRouterCMDValueFieldLogsEvent7DaysCount;

///命令域日志属性:event的30日出现次数(参数:event)
extern NSString * const kRouterCMDValueFieldLogsEvent30DaysCount;


///获取命令事件
extern NSString * const kRouterEventCommandGet;

///执行命令事件前缀
extern NSString * const kRouterEventCommandExecute;


///获取命令任务
extern NSString * const kRouterMissionCommandGet;



//转场动画风格枚举
typedef NS_ENUM(NSUInteger, KATRouterTransitionStyle)
{
    KATRouterTransitionStyleNone=1,
    KATRouterTransitionStyleFade=2,
    KATRouterTransitionStyleMoveHorizontal=3,
    KATRouterTransitionStyleMoveVertical=4,
    KATRouterTransitionStylePushHorizontal=5,
    KATRouterTransitionStylePushVertical=6,
    KATRouterTransitionStyleRevealHorizontal=7,
    KATRouterTransitionStyleRevealVertical=8,
    KATRouterTransitionStyleCubeHorizontal=9,
    KATRouterTransitionStyleCubeVertical=10,
    KATRouterTransitionStyleFlipHorizontal=11,
    KATRouterTransitionStyleFlipVertical=12,
    KATRouterTransitionStyleSuck=13,
    KATRouterTransitionStyleRipple=14,
    KATRouterTransitionStyleCurlLeft=15,
    KATRouterTransitionStyleCurlRight=16,
    KATRouterTransitionStyleCurlBottom=17,
    KATRouterTransitionStyleNavHorizontal=18,
    KATRouterTransitionStyleNavVertical=19,
    KATRouterTransitionStyleCurtainHorizontal=20,
    KATRouterTransitionStyleCurtainVertical=21,
    KATRouterTransitionStyleCount
};


//app状态枚举
typedef NS_ENUM(NSUInteger, KATRouterAppStatus)
{
    KATRouterAppStatusUnknown=0,
    KATRouterAppStatusBecomeActive,
    KATRouterAppStatusResignActive,
    KATRouterAppStatusEnterForeground,
    KATRouterAppStatusEnterBackground,
    KATRouterAppStatusTerminate,
    KATRouterAppStatusOpenedWithURL
};


//网络状态枚举
typedef NS_ENUM(NSUInteger, KATRouterNetworkStatus)
{
    KATRouterNetworkStatusUnknown=0,
    KATRouterNetworkStatusNone,//无网络
    KATRouterNetworkStatusWWAN,//信号网络
    KATRouterNetworkStatusWiFi//Wi-Fi
};



//路由器协议
@protocol KATRouterDelegate <NSObject>

@optional

#pragma -mark 消息

///路由跳转完成后
- (void)routingFinishWithValues:(KATHashMap *)values backward:(BOOL)backward;

///路由跳转将要开始
- (void)routingBeginWithValues:(KATHashMap *)values backward:(BOOL)backward;

///路由跳转到其他VC
- (void)routingDismissWithValues:(KATHashMap *)values backward:(BOOL)backward;

///路由跳转到自己
- (void)routingToSelfWithValues:(KATHashMap *)values;

///是否允许路由跳转(VC上将要执行路由跳转行为时触发，返回YES表示允许，若没有实现该回调方法，则都允许路由)(对侧滑回退无效)
- (BOOL)allowRoutingWithValues:(KATHashMap *)values;

///接收到消息
- (void)receivedRouterMessage:(KATHashMap *)message;

///VC实例将要被释放
- (void)instanceWillBeReleased;

///定时器执行
- (void)routerTimerExecution;


#pragma -mark 标签、导航栏

///返回导航栏标题
- (NSString *)titleInNavBar:(KATNavBar *)navBar;

///返回导航栏副标题
- (NSString *)subtitleInNavBar:(KATNavBar *)navBar;

///返回导航栏图标
- (UIImage *)iconInNavBar:(KATNavBar *)navBar;

///是否隐藏导航栏返回按钮
- (BOOL)hideBackButtonInNavBar:(KATNavBar *)navBar;

///是否显示导航栏(返回NO，或者未实现该方法，则会自动隐藏)
- (BOOL)isShownNavBar:(KATNavBar *)navBar;

///返回导航栏左按钮数组(不用配置Frame、颜色、缩放和粗细，只用配置类型和回调)(若显示返回按钮，则跟在返回按钮之后)
- (KATArray<KATButton *> *)leftButtonsInNavBar:(KATNavBar *)navBar;

///返回导航栏右按钮数组(不用配置Frame、颜色、缩放和粗细，只用配置类型和回调)
- (KATArray<KATButton *> *)rightButtonsInNavBar:(KATNavBar *)navBar;

///选中了标签
- (void)tabBar:(KATTabBar *)tabBar didSelectHost:(NSString *)host;


#pragma -mark app状态

///App激活
- (void)appDidBecomeActive;

///App将要退出活跃
- (void)appWillResignActive;

///App将要进入前台
- (void)appWillEnterForeground;

///App进入后台
- (void)appDidEnterBackground;

///App将要终止
- (void)appWillTerminate;

///App通过URL中打开(此回调方法只在页面没有发生跳转的情况下正确执行，若有跳转，则会执行跳转前的VC的该回调方法，默认会发生跳转，推荐在routingFinishWithValues:回调方法中处理事件)
- (BOOL)appOpenedWithURL:(NSURL *)url andInfo:(KATHashMap *)info;

///App接收到通知(本地或远程)
- (void)appReceivedNotification:(KATHashMap *)info;

///App注册远程通知
- (void)appRegisteredRemoteNotificationWithDeviceToken:(NSData *)deviceToken;

///状态栏高度发生改变
- (void)appChangedStatusBarHeight:(CGFloat)height;


#pragma -mark host状态

///旋转事件(只适用于自由方向的host)
- (void)hostDidRotate;


#pragma -mark 网络状态

///网络状态改变
- (void)networkStatusDidChange:(KATRouterNetworkStatus)status;


@end




@interface KATRouter : NSObject


#pragma -mark App代理回调及动作(先执行该动作,再执行VC代理的回调方法)

///设置App激活动作
+ (void)setAppDidBecomeActiveAction:(BOOL (^)(void))action;

///设置App将要退出活跃动作
+ (void)setAppWillResignActiveAction:(BOOL (^)(void))action;

///设置App将要进入前台动作(此动作有默认值，即徽标清零)
+ (void)setAppWillEnterForegroundAction:(BOOL (^)(void))action;

///设置App进入后台动作
+ (void)setAppDidEnterBackgroundAction:(BOOL (^)(void))action;

///设置App将要终止动作
+ (void)setAppWillTerminateAction:(BOOL (^)(void))action;

///设置App通过URL中打开动作(此动作有默认值，即跳转到URL)(因为没有对应的系统通知，需要在AppDlelgate中实现application:openURL:options:方法，空实现亦可)
+ (void)setAppOpenedWithURLAction:(BOOL (^)(NSURL *url,KATHashMap *info))action;

///设置App收到通知(本地或远程)动作
+ (void)setAppReceivedNotificationAction:(BOOL (^)(KATHashMap *info))action;

///设置App注册远程通知动作
+ (void)setAppRegisterNotificationAction:(BOOL (^)(NSData *deviceToken))action;

///设置App改变状态栏高度的动作
+ (void)setAppChangeStatusBarHeightAction:(void (^)(CGFloat height))action;

///设置路由跳转时的动作
+ (void)setRouteWithURIAction:(KATHashMap *(^)(KATHashMap *uri,id addition))action;

///设置路由跳转时的动作(所有跳转方法)
+ (void)setRouteAction:(void (^)(KATHashMap *values))action;

///设置定时器动作(与时长任务共用一个定时器，优先执行改动作，再执行任务)
+ (void)setTimerAction:(void (^)(void))action;


#pragma -mark 注册

///通过类注册视图控制器,host为标识
+ (BOOL)registerHost:(NSString *)host withClass:(Class)cls;

///通过类名注册视图控制器,host为标识
+ (BOOL)registerHost:(NSString *)host withClassName:(NSString *)className;

///通过实例注册视图控制器,host为标识
+ (BOOL)registerHost:(NSString *)host withInstance:(UIViewController *)vc;

///删除注册的视图控制器
+ (BOOL)removeRegisteredHost:(NSString *)host;

///判断是否有注册过该host
+ (BOOL)hasRegisteredHost:(NSString *)host;

///获取host的类名
+ (NSString *)classNameWithHost:(NSString *)host;

///获取所有注册的host
+ (KATArray<NSString *> *)getRegisteredHosts;

///获取所有注册的类
+ (KATArray<NSString *> *)getRegisteredClasses;

///通过加载器配置路由器
+ (void)setUpWithLoader:(KATRouterLoader *)loader;

///通过文件配置路由器
+ (void)setUpWithFile:(NSString *)file;

///通过文件注册host和group
+ (void)registWithFile:(NSString *)file;


#pragma -mark 依赖关系(先看地板后看依赖)

///添加host的依赖关系(依赖host)
+ (void)addDependence:(NSString *)dependence withHost:(NSString *)host;

///添加host数组的依赖关系(依赖host)
+ (void)addDependence:(NSString *)dependence withHosts:(KATArray<NSString *> *)hosts;

///添加组的依赖关系(依赖host)
+ (void)addDependence:(NSString *)dependence withGroup:(NSString *)group;

///删除host的依赖关系(依赖host)
+ (void)removeDependenceWithHost:(NSString *)host;

///删除host数组的依赖关系(依赖host)
+ (void)removeDependenceWithHosts:(KATArray<NSString *> *)hosts;

///删除组的依赖关系(依赖host)
+ (void)removeDependenceWithGroup:(NSString *)group;

///获取host的依赖关系(依赖host)
+ (NSString *)dependenceWithHost:(NSString *)host;

///清除所有的依赖关系(依赖host)
+ (void)clearDependency;

///获取所有的依赖关系
+ (KATHashMap<NSString *> *)getDependency;

///关闭依赖关系路由的动画(包括地板路由)
+ (void)setDependencyTransitionClosed:(BOOL)closed;

///添加地板host
+ (void)addFloorHost:(NSString *)host;

///添加地板host数组
+ (void)addFloorHosts:(KATArray<NSString *> *)hosts;

///通过组添加地板host
+ (void)addFloorGroup:(NSString *)group;

///删除地板host
+ (void)removeFloorHost:(NSString *)host;

///删除地板host数组
+ (void)removeFloorHosts:(KATArray<NSString *> *)hosts;

///通过组删除地板host
+ (void)removeFloorGroup:(NSString *)group;

///清除所有的地板host
+ (void)clearFloorHosts;

///判断host是否为地板host
+ (BOOL)isFoorHost:(NSString *)host;

///获取地板host数组
+ (KATArray<NSString *> *)getFloorHosts;

///添加host的地板(host)
+ (void)addFloor:(NSString *)floor withHost:(NSString *)host;

///添加host数组的地板(host)
+ (void)addFloor:(NSString *)floor withHosts:(KATArray<NSString *> *)hosts;

///添加组的地板(host)
+ (void)addFloor:(NSString *)floor withGroup:(NSString *)group;

///删除host的地板(host)
+ (void)removeFloorWithHost:(NSString *)host;

///删除host数组的地板(host)
+ (void)removeFloorWithHosts:(KATArray<NSString *> *)hosts;

///删除组的地板(host)
+ (void)removeFloorWithGroup:(NSString *)group;

///清除所有host的地板(host)
+ (void)clearAllFloors;

///获取host的地板(host)
+ (NSString *)floorWithHost:(NSString *)host;

///获取所有的host的地板(host)关系
+ (KATHashMap<NSString *> *)getAllFloors;


#pragma -mark 分组

///将host加入到指定组(必须是注册过的host,组名不能为空)
+ (BOOL)addHost:(NSString *)host toGroup:(NSString *)group;

///将host数组加入到指定组(必须是注册过的host,组名不能为空)
+ (void)addHosts:(KATArray<NSString *> *)hosts toGroup:(NSString *)group;

///将host加入到多个组
+ (void)addHost:(NSString *)host toGroups:(KATArray<NSString *> *)groups;

///将host数组加入到多个组
+ (void)addHosts:(KATArray<NSString *> *)hosts toGroups:(KATArray<NSString *> *)groups;

///将host从指定组中删除
+ (void)removeHost:(NSString *)host fromGroup:(NSString *)group;

///清除host的所有组
+ (void)clearGroupsByHost:(NSString *)host;

///清除指定组中的所有host
+ (void)clearHostsInGroup:(NSString *)group;

///获取host所在的所有组
+ (KATArray<NSString *> *)groupsByHost:(NSString *)host;

///获取指定组的所有host
+ (KATArray<NSString *> *)hostsInGroup:(NSString *)group;

///判断指定组中是否包含该host
+ (BOOL)hasHost:(NSString *)host inGroup:(NSString *)group;

///判断是否存在该组
+ (BOOL)hasGroup:(NSString *)group;

///获取组
+ (KATHashMap<NSString *> *)getGroup:(NSString *)group;

///获取所有的组名称
+ (KATArray<NSString *> *)allGroups;


#pragma -mark 标签栏

///设置标签栏(默认为空)
+ (void)setTabBar:(KATTabBar *)tabBar;

///设置是否自动隐藏标签栏(非关联标签栏的host)(默认为是)
+ (void)setIsAutoHidingTabBar:(BOOL)hidding;

///隐藏标签栏
+ (void)hideTabBar;

///显示标签栏
+ (void)showTabBar;

///刷新标签栏
+ (void)updateTabBar;

///选中标签
+ (void)selectTabWithIndex:(unsigned)index;

///选中标签
+ (void)selectTabWithHost:(NSString *)host;

///通过index判断标签栏项目是否有圆点徽标
+ (BOOL)hasTabBadgeWithIndex:(unsigned)index;

///通过host判断标签栏项目是否有圆点徽标
+ (BOOL)hasTabBadgeWithHost:(NSString *)host;

///通过index添加圆点徽标
+ (void)addBadgeToTabWithIndex:(unsigned)index;

///通过host添加圆点徽标
+ (void)addBadgeToTabWithHost:(NSString *)host;

///通过index删除圆点徽标
+ (void)removeBadgeFromTabWithIndex:(unsigned)index;

///通过host删除圆点徽标
+ (void)removeBadgeFromTabWithHost:(NSString *)host;

///通过index获取标签栏项目的徽标数字
+ (int)badgeNumberWithIndex:(unsigned)index;

///通过host获取标签栏项目的徽标数字
+ (int)badgeNumberWithHost:(NSString *)host;

///通过index设置标签栏项目的数字徽标
+ (void)setBadgeNumber:(int)number withIndex:(unsigned)index;

///通过host设置标签栏项目的数字徽标
+ (void)setBadgeNumber:(int)number withHost:(NSString *)host;

///通过index获取标签栏项目的徽标文本
+ (NSString *)badgeTextWithIndex:(unsigned)index;

///通过host获取标签栏项目的徽标文本
+ (NSString *)badgeTextWithHost:(NSString *)host;

///通过index设置标签栏项目的文本徽标
+ (void)setBadgeText:(NSString *)text withIndex:(unsigned)index;

///通过host设置标签栏项目的文本徽标
+ (void)setBadgeText:(NSString *)text withHost:(NSString *)host;

///清除所有的徽标
+ (void)clearBadgesFromTabBar;

///获取标签栏
+ (KATTabBar *)getTabBar;

///获取tab栏选中的host
+ (NSString *)hostInSelectedTab;

///获取tab栏选中的URI
+ (NSString *)URIInSelectedTab;


#pragma -mark 导航栏

///设置导航栏(默认有)
+ (void)setNavBar:(KATNavBar *)navBar;

///隐藏导航栏
+ (void)hideNavBar;

///显示导航栏
+ (void)showNavBar;

///刷新导航栏
+ (void)updateNavBar;

///获取导航栏
+ (KATNavBar *)getNavBar;

///重新加载导航栏
+ (void)reloadNavBar;

//更新状态栏样式
+ (void)updateStatusBarStyle;

///设置是否自动更新状态栏样式(默认为否)
+ (void)setIsAutoStatusBarStyle:(BOOL)autoStyle;


#pragma -mark 横竖屏

///设置是否单一屏幕方向(只有单一方向的竖屏或横屏)
+ (void)setSingleOrientationOnly:(BOOL)singleOrientationOnly;

///设置默认屏幕方向是否为横屏
+ (void)setDefaultOrientationLandscape:(BOOL)isLandscapeDefault;

///添加竖屏方向的host数组
+ (void)addPortraitOrientationHosts:(KATArray<NSString *> *)hosts;

///通过指定组添加竖屏方向的host
+ (void)addPortraitOrientationHostsWithGroup:(NSString *)group;

///添加竖屏方向的host
+ (void)addPortraitOrientationHost:(NSString *)host;

///删除竖屏方向的host
+ (void)removePortraitOrientationHost:(NSString *)host;

///清除竖屏方向的host
+ (void)clearPortraitOrientationHosts;

///添加横屏方向的host数组
+ (void)addLandscapeOrientationHosts:(KATArray<NSString *> *)hosts;

///通过指定组添加横屏方向的host
+ (void)addLandscapeOrientationHostsWithGroup:(NSString *)group;

///添加横屏方向的host
+ (void)addLandscapeOrientationHost:(NSString *)host;

///删除横屏方向的host
+ (void)removeLandscapeOrientationHost:(NSString *)host;

///清除横屏方向的host
+ (void)clearLandscapeOrientationHosts;

///添加自由方向的host数组
+ (void)addFreeOrientationHosts:(KATArray<NSString *> *)hosts;

///通过指定组添加自由方向的host
+ (void)addFreeOrientationHostsWithGroup:(NSString *)group;

///添加自由方向的host
+ (void)addFreeOrientationHost:(NSString *)host;

///删除自由方向的host
+ (void)removeFreeOrientationHost:(NSString *)host;

///清除自由方向的host
+ (void)clearFreeOrientationHosts;


#pragma -mark 日志记录 (当日日志根据当日app首次进入时间算)

///设置日志保存目录(只设置一次)(Documents下)
+ (void)setLogsDirectory:(NSString *)dir;

///更改日志保存目录(Documents下)
+ (void)changeLogsDirectory:(NSString *)dir;

///获取历史日志
+ (KATTreeMap<KATHashMap *> *)getHistoryLogs;

///获取当日日志
+ (KATHashMap *)getDayLogs;

///获取本次app使用的日志
+ (KATHashMap *)getAppLog;

///获取当前host的日志
+ (KATHashMap *)getHostLog;

///清空日志
+ (void)clearLogs;

///设置是否保存日志(默认保存日志)(只设置一次)
+ (void)setShouldKeepLogs:(BOOL)keep;

///更改是否保存日志(默认保存日志)
+ (void)changeShouldKeepLogs:(BOOL)keep;

///设置日志保留时间(单位日,默认60日，最多保存1000日)(只设置一次)
+ (void)setLogsKeepingDays:(int)days;

///更改日志保留时间(单位日,默认60日，最多保存1000日)
+ (void)changeLogsKeepingDays:(int)days;

///获取日志上传地址
+ (NSString *)getLogsUploadURL;

///设置日志上传地址(只设置一次)
+ (void)setLogsUploadURL:(NSString *)URL;

///更改日志上传地址
+ (void)changeLogsUploadURL:(NSString *)URL;

///获取日志服务器签名地址
+ (NSString *)getLogsSignatureURL;

///设置日志服务器签名地址(只设置一次)
+ (void)setLogsSignatureURL:(NSString *)URL;

///修改日志服务器签名地址
+ (void)changeLogsSignatureURL:(NSString *)URL;

///获取日志的app名称
+ (NSString *)getLogsApp;

///设置日志的app名称(只设置一次)
+ (void)setLogsApp:(NSString *)app;

///更改日志的app名称
+ (void)changeLogsApp:(NSString *)app;

///获取日志用户ID
+ (NSString *)getLogsID;

///设置日志的用户ID(只设置一次)
+ (void)setLogsID:(NSString *)ID;

///更改日志的用户ID
+ (void)changeLogsID:(NSString *)ID;

///获取日志上传的内容属性名(只设置一次)
+ (NSString *)getLogsUploadContentKey;

///设置日志上传的内容属性名(只设置一次)
+ (void)setLogsUploadContentKey:(NSString *)key;

///更改日志上传的内容属性名
+ (void)changeLogsUploadContentKey:(NSString *)key;

///获取日志上传的附加信息
+ (KATHashMap *)getLogsUploadExtra;

///设置日志上传的附加信息(只设置一次)
+ (void)setLogsUploadExtra:(KATHashMap *)extra;

///更改日志上传的附加信息
+ (void)changeLogsUploadExtra:(KATHashMap *)extra;

///获取是否需要上传日志
+ (BOOL)getShouldUploadLogs;

///设置是否上传日志(只设置一次)
+ (void)setShouldUploadLogs:(BOOL)upload;

///更改是否上传日志
+ (void)changeShouldUploadLogs:(BOOL)upload;

///设置日志上传后回调动作，返回是否成功(默认为空，为空时，若有非0数据返回，则认为上传成功)
+ (void)setLogsDidUploadAction:(BOOL (^)(NSString *feeback))action;

///标记事件(全参数)
+ (void)markEvent:(NSString *)event withTag:(long long)tag andMessage:(NSString *)msg;

///标记事件
+ (void)markEvent:(NSString *)event withTag:(long long)tag;

///标记事件
+ (void)markEvent:(NSString *)event withMessage:(NSString *)msg;

///标记事件
+ (void)markEvent:(NSString *)event;


#pragma -mark 日志分析

///当日的app的使用时长(单位:秒)
+ (long long)durationByDayUsing;

///当日指定用户的app的使用时长(单位:秒)(IDs为空时返回所有的)
+ (long long)durationByDayUsingWithIDs:(KATArray<NSString *> *)IDs;

///本次app的使用时长(单位:秒)
+ (long long)durationByAppUsing;

///在当前host停留的时长(单位:秒)
+ (long long)durationByHostUsing;

///获取最早一次日志到现在的天数(没有则返回负数)
+ (int)daysFromFirstLog;

///获取最近一次日志到现在的天数(没有则返回负数)
+ (int)daysFromLastLog;

///获取最早一次日志到现在的秒数(从日志的开始时间计算，没有则返回负数)
+ (long long)secondsFromFirstLog;

///获取最近一次日志到现在的秒数(从日志的结束时间计算，没有则返回负数)
+ (long long)secondsFromLastLog;

///获取最近一次host日志到现在的天数(没有则返回负数)
+ (int)daysFromLastUsingWithHost:(NSString *)host;

///获取最近一次事件到现在的天数(没有则返回负数)
+ (int)daysFromLastEvent:(NSString *)event;

///获取该host当日的使用秒数
+ (long long)secondsByDayUsingWithHost:(NSString *)host;

///获取该host数组当日的使用秒数
+ (long long)secondsByDayUsingWithHosts:(KATArray<NSString *> *)hosts;

///获取该组当日的使用秒数
+ (long long)secondsByDayUsingWithGroup:(NSString *)group;

///获取该host在本次app使用中的使用秒数
+ (long long)secondsByAppUsingWithHost:(NSString *)host;

///获取该host数组在本次app使用中的使用秒数
+ (long long)secondsByAppUsingWithHosts:(KATArray<NSString *> *)hosts;

///获取该组在本次app使用中的使用秒数
+ (long long)secondsByAppUsingWithGroup:(NSString *)group;

///获取最近一次事件到现在的秒数(没有则返回负数)
+ (long long)secondsFromLastEvent:(NSString *)event;

///获取当日最近一次事件到现在的秒数(没有则返回负数)
+ (long long)secondsByDayUsingFromLastEvent:(NSString *)event;

///获取本次app使用中最近一次事件到现在的秒数(没有则返回负数)
+ (long long)secondsByAppUsingFromLastEvent:(NSString *)event;

///获取当前host中最近一次事件到现在的秒数(没有则返回负数)
+ (long long)secondsByHostUsingFromLastEvent:(NSString *)event;

///历史上触发该事件的总次数
+ (int)countInHistoryWithEvent:(NSString *)event;

///历史上触发该事件数组的总次数
+ (int)countInHistoryWithEvents:(KATArray<NSString *> *)events;

///当日触发该事件的次数
+ (int)countInDayUsingWithEvent:(NSString *)event;

///当日触发该事件数组的总次数
+ (int)countInDayUsingWithEvents:(KATArray<NSString *> *)events;

///多少日内触发该事件的次数(0代表当天，1代表当天和昨天)
+ (int)countInDays:(int)days withEvent:(NSString *)event;

///多少日内触发该事件数组的总次数(0代表当天，1代表当天和昨天)
+ (int)countInDays:(int)days withEvents:(KATArray<NSString *> *)events;

///本次app使用中触发该事件的次数
+ (int)countInAppUsingWithEvent:(NSString *)event;

///获取最近一次事件
+ (KATHashMap *)getLastEvent:(NSString *)event;

///获取指定ID的事件(从最近到最初的时间排序)(IDs为空时返回所有的)
+ (KATArray<KATHashMap *> *)eventsWithIDs:(KATArray<NSString *> *)IDs;

///本次app使用中触发该事件数组的总次数
+ (int)countInAppUsingWithEvents:(KATArray<NSString *> *)events;

///在当前host中触发该事件的次数
+ (int)countInHostUsingWithEvent:(NSString *)event;

///在当前host中触发该事件数组的总次数
+ (int)countInHostUsingWithEvents:(KATArray<NSString *> *)events;


#pragma -mark 任务(在主线程中执行,方法中不能带参数)(可以删除后再添加,但不能覆盖)

///添加未使用app的天数触发的任务(超过天数则触发)(app打开时判断执行)
+ (void)addMission:(NSString *)mission forUnusedDays:(unsigned int)days withObserver:(NSString *)observerHost selector:(NSString *)selector andTimes:(unsigned int)times;

///添加未使用host的天数触发的任务(超过天数则触发)(app打开时判断执行)
+ (void)addMission:(NSString *)mission withHost:(NSString *)host forUnusedDays:(unsigned int)days observer:(NSString *)observerHost selector:(NSString *)selector andTimes:(unsigned int)times;

///添加未触发事件的天数触发的任务(超过天数则触发)(app打开时判断执行)
+ (void)addMission:(NSString *)mission withEvent:(NSString *)event forUntriggeredDays:(unsigned int)days observer:(NSString *)observerHost selector:(NSString *)selector andTimes:(unsigned int)times;

///添加当日使用时长任务(超过时长则触发，只触发一次)
+ (void)addMission:(NSString *)mission byDayUsingForDuration:(unsigned int)seconds withObserver:(NSString *)observerHost andSelector:(NSString *)selector;

///添加app使用时长任务(超过时长则触发，只触发一次)
+ (void)addMission:(NSString *)mission byAppUsingForDuration:(unsigned int)seconds withObserver:(NSString *)observerHost andSelector:(NSString *)selector;

///添加host停留时长任务(超过时长则触发，只触发一次)
+ (void)addMission:(NSString *)mission byUsingHost:(NSString *)host forDuration:(unsigned int)seconds observer:(NSString *)observerHost andSelector:(NSString *)selector;

///添加app使用中host停留时长任务(超过时长则触发，只触发一次)
+ (void)addMission:(NSString *)mission byAppUsingWithHost:(NSString *)host forDuration:(unsigned int)seconds observer:(NSString *)observerHost andSelector:(NSString *)selector;

///添加app使用中host数组总停留时长任务(超过时长则触发，只触发一次)
+ (void)addMission:(NSString *)mission byAppUsingWithHosts:(KATArray<NSString *> *)hosts forDuration:(unsigned int)seconds observer:(NSString *)observerHost andSelector:(NSString *)selector;

///添加app使用中指定组总停留时长任务(超过时长则触发，只触发一次)
+ (void)addMission:(NSString *)mission byAppUsingWithGroup:(NSString *)group forDuration:(unsigned int)seconds observer:(NSString *)observerHost andSelector:(NSString *)selector;

///添加当日host停留时长任务(超过时长则触发，只触发一次)
+ (void)addMission:(NSString *)mission byDayUsingWithHost:(NSString *)host forDuration:(unsigned int)seconds observer:(NSString *)observerHost andSelector:(NSString *)selector;

///添加当日host数组总停留时长任务(超过时长则触发，只触发一次)
+ (void)addMission:(NSString *)mission byDayUsingWithHosts:(KATArray<NSString *> *)hosts forDuration:(unsigned int)seconds observer:(NSString *)observerHost andSelector:(NSString *)selector;

///添加当日指定组总停留时长任务(超过时长则触发，只触发一次)
+ (void)addMission:(NSString *)mission byDayUsingWithGroup:(NSString *)group forDuration:(unsigned int)seconds observer:(NSString *)observerHost andSelector:(NSString *)selector;

///添加当日未触发事件时长的任务(超过时长则触发，只触发一次)
+ (void)addMission:(NSString *)mission withEvent:(NSString *)event forUntriggeredDuration:(unsigned int)seconds observer:(NSString *)observerHost andSelector:(NSString *)selector;

///添加定时任务(超过时长则触发，只触发一次)
+ (void)addMission:(NSString *)mission forDuration:(unsigned int)seconds withObserver:(NSString *)observerHost andSelector:(NSString *)selector;

///添加历史事件发生次数任务(到达该次数则触发，可设置触发次数)
+ (void)addMission:(NSString *)mission withEvent:(NSString *)event forCount:(unsigned int)count observer:(NSString *)observerHost selector:(NSString *)selector andTimes:(unsigned int)times;

///添加历史事件数组发生总数任务(到达该次数则触发，可设置触发次数)
+ (void)addMission:(NSString *)mission withEvents:(KATArray<NSString *> *)events forCount:(unsigned int)count observer:(NSString *)observerHost selector:(NSString *)selector andTimes:(unsigned int)times;

///添加当日事件发生次数任务(到达该次数则触发，可设置触发次数)
+ (void)addMission:(NSString *)mission byDayUsingWithEvent:(NSString *)event forCount:(unsigned int)count observer:(NSString *)observerHost selector:(NSString *)selector andTimes:(unsigned int)times;

///添加当日事件数组发生总数任务(到达该次数则触发，可设置触发次数)
+ (void)addMission:(NSString *)mission byDayUsingWithEvents:(KATArray<NSString *> *)events forCount:(unsigned int)count observer:(NSString *)observerHost selector:(NSString *)selector andTimes:(unsigned int)times;

///添加app使用时事件发生次数任务(到达该次数则触发，可设置触发次数)
+ (void)addMission:(NSString *)mission byAppUsingWithEvent:(NSString *)event forCount:(unsigned int)count observer:(NSString *)observerHost selector:(NSString *)selector andTimes:(unsigned int)times;

///添加app使用时事件数组发生总数任务(到达该次数则触发，可设置触发次数)
+ (void)addMission:(NSString *)mission byAppUsingWithEvents:(KATArray<NSString *> *)events forCount:(unsigned int)count observer:(NSString *)observerHost selector:(NSString *)selector andTimes:(unsigned int)times;

///判断是否已经添加了该任务
+ (BOOL)hasMission:(NSString *)mission;

///删除任务
+ (void)removeMission:(NSString *)mission;

///清除所有任务
+ (void)clearMissions;


#pragma -mark 命令(主要用于处理远程服务器返回的命令)

///获取是否获取远程命令
+ (BOOL)getShouldGetCommands;

///设置是否获取远程命令(只设置一次)
+ (void)setShouldGetCommands:(BOOL)get;

///更改是否获取远程命令(若需要自动获取,则每日最多自动获取一次远程命令)
+ (void)changeShouldGetCommands:(BOOL)get;

///获取命令获取地址
+ (NSString *)getCommandsGetURL;

///设置命令获取地址(只设置一次)
+ (void)setCommandsGetURL:(NSString *)URL;

///更改命令获取地址
+ (void)changeCommandsGetURL:(NSString *)URL;

///获取命令时的附加信息
+ (KATHashMap *)getCommandGetExtra;

///设置命令获取时的附加信息(只设置一次)
+ (void)setCommandGetExtra:(KATHashMap *)extra;

///更改命令获取时的附加信息
+ (void)changeCommandGetExtra:(KATHashMap *)extra;

///执行命令
+ (void)executeCommands:(KATHashMap *)commands;

///获取远程命令并执行
+ (void)getRemoteCommands;

///获取校验码
+ (NSString *)getCommandCheckCode;


#pragma -mark 路由(跳转)(在主线程中进行)

///禁用路由(调用该方法后，路由将无法进行，直到启用路由)(在禁用期间的所有路由行为都将被取消)
+ (void)disableRouting;

///启用路由(默认为启用)
+ (void)enableRouting;

///暂停路由(调用该方法后，路由将无法进行，直到恢复路由，恢复后，原先的路由行为将继续执行)
+ (void)pauseRouting;

///恢复路由
+ (void)resumeRouting;

///路由
+ (void)routeWithURI:(NSString *)URI;

///路由
+ (void)routeWithURI:(NSString *)URI addition:(id)addition;

///路由
+ (void)routeWithURI:(NSString *)URI andHandle:(void (^)(void))handle;

///路由
+ (void)routeWithURI:(NSString *)URI addition:(id)addition andHandle:(void (^)(void))handle;

///路由(全参数)
+ (void)routeWithURI:(NSString *)URI selector:(SEL)sel object:(id)obj addition:(id)addition andHandle:(void (^)(void))handle;

///回退
+ (void)backward;

///回退(query不带问号)
+ (void)backwardWithQuery:(NSString *)query;

///回退
+ (void)backwardWithAddition:(id)addition;

///回退
+ (void)backwardWithHandle:(void (^)(void))handle;

///回退(全参数)(query不带问号)
+ (void)backwardWithQuery:(NSString *)query addition:(id)addition andHandle:(void (^)(void))handle;

///回退到指定的URI(该host必须在回退栈上才会执行，若栈上有多个该host，则回退到最顶端的host，执行时会清除栈顶到host之间的所有回退节点)
+ (void)backwardWithURI:(NSString *)URI addition:(id)addition andHandle:(void (^)(void))handle;

///路由到当前host(不带参数刷新当前host的方法，会触发回调，用于恢复导航栏、标签栏等操作)
+ (void)routeCurrent;

///路由到当前tab栏选中的host
+ (void)routeToTabBarSelectdHost;

///路由到当前tab栏选中的URI
+ (void)routeToTabBarSelectdURI;

///退回到当前tab栏选中的host
+ (void)backToTabBarSelectdHost;

///退回到当前tab栏选中的URI
+ (void)backToTabBarSelectdURI;

///回到根节点
+ (void)backToRoot;


#pragma -mark 侧滑回退

///获取侧滑回退的host数组
+ (KATArray<NSString *> *)getSlideHosts;

///添加侧滑回退的host数组
+ (void)addSlideHosts:(KATArray<NSString *> *)hosts;

///通过组添加侧滑回退的host
+ (void)addSlideHostsWithGroup:(NSString *)group;

///添加侧滑回退的host
+ (void)addSlideHost:(NSString *)host;

///删除侧滑回退的host
+ (void)removeSlideHost:(NSString *)host;

///清除侧滑回退的host
+ (void)clearSlideHosts;

///获取禁止侧滑回退的host数组
+ (KATArray<NSString *> *)getSlideDisabledHosts;

///添加禁止侧滑回退的host数组
+ (void)addSlideDisabledHosts:(KATArray<NSString *> *)hosts;

///通过组添加禁止侧滑回退的host
+ (void)addSlideDisabledHostsWithGroup:(NSString *)group;

///添加禁止侧滑回退的host
+ (void)addSlideDisabledHost:(NSString *)host;

///删除禁止侧滑回退的host
+ (void)removeSlideDisabledHost:(NSString *)host;

///清除禁止侧滑回退的host
+ (void)clearSlideDisabledHosts;

///设置侧滑完成进度点(0~1之间 默认0.4,即超过宽度的40%)
+ (void)setSlideFinishProgress:(float)progress;

///设置侧滑手势完成条件的滑动尾速(默认为每帧16点)
+ (void)setSlideFinishSpeed:(float)speed;

///设置侧滑手势起始点X坐标位置(0~1之间,默认0.5,即左半屏)
+ (void)setSlideStartXPoint:(float)xPoint;

///设置水平滑动动画效果的host是否自动带侧滑交互(默认是)
+ (void)setSlideAutoSetting:(BOOL)autoSetting;

///判断是否正在滑动中
+ (BOOL)isRouterSliding;


#pragma -mark 发送消息(不跳转,在receivedRouterMessage:回调方法中处理)

///发送消息到指定的host
+ (void)sendMessage:(KATHashMap *)message toHost:(NSString *)host;

///发送消息到当前的host
+ (void)sendMessage:(KATHashMap *)message;

///广播消息(发送消息给所有的已经实例化的Host)
+ (void)broadcastMessage:(KATHashMap *)message;

///广播指定类型的消息(发送消息给监听该类型消息的Host)
+ (void)broadcastMessage:(KATHashMap *)message withType:(NSString *)type;

///监听指定类型的消息(通过host指定)
+ (void)addObserverWithHost:(NSString *)host forMessageType:(NSString *)type;

///监听指定类型的消息(通过类指定)
+ (void)addObserverWithClass:(Class)cls forMessageType:(NSString *)type;

///监听指定类型的消息(通过类名指定)
+ (void)addObserverWithClassName:(NSString *)name forMessageType:(NSString *)type;

///监听指定类型的消息(通过实例指定)
+ (void)addObserverWithInstance:(UIViewController *)instance forMessageType:(NSString *)type;

///移除监听指定类型的消息(通过host移除)
+ (void)removeObserverWithHost:(NSString *)host forMessageType:(NSString *)type;

///移除监听指定类型的消息(通过类移除)
+ (void)removeObserverWithClass:(Class)cls forMessageType:(NSString *)type;

///移除监听指定类型的消息(通过类名移除)
+ (void)removeObserverWithClassName:(NSString *)name forMessageType:(NSString *)type;

///移除监听指定类型的消息(通过实例移除)
+ (void)removeObserverWithInstance:(UIViewController *)instance forMessageType:(NSString *)type;

///移除所有的监听消息
+ (void)removeObserverForAllMessageTypesWithHost:(NSString *)host;

///清除所有的消息及监听器
+ (void)clearMessageObservers;

///通过URI的方式发送消息
+ (void)noticeWithURI:(NSString *)URI;


#pragma -mark 执行动作

///添加执行动作(重复添加会覆盖)(方法最多带一个参数)
+ (void)addAction:(NSString *)action withObserver:(id)observer andSelector:(SEL)selector;

///移除执行动作
+ (void)removeAction:(NSString *)action;

///执行动作
+ (void)doAction:(NSString *)action;

///执行带参数的动作
+ (void)doAction:(NSString *)action withObject:(id)obj;

///清除所有动作
+ (void)clearActions;

///添加host执行动作(重复添加会覆盖)(方法最多带一个参数)
+ (void)addHostAction:(NSString *)action withHost:(NSString *)host andSelector:(NSString *)selector;

///移除host执行动作
+ (void)removeHostAction:(NSString *)action;

///执行host动作(执行时会跳转到该host)(主线程中执行)
+ (void)doHostAction:(NSString *)action;

///执行带参数的host动作(执行时会跳转到该host)(主线程中执行)
+ (void)doHostAction:(NSString *)action withObject:(id)obj;

///执行host动作(若forward为NO，且该host没有实例(非总是持有模式)，则不执行)(主线程中执行)
+ (void)doHostAction:(NSString *)action withObject:(id)obj andForward:(BOOL)forward;

///清除所有的host动作
+ (void)clearHostActions;


#pragma -mark 数据存取(能对数据进行持久化存储,不适合大量数据)

///判断全局数据是否可用(防止数据结构重组时冲突)
+ (BOOL)isValueAvailable;

///判断host数据是否可用(防止数据结构重组时冲突)
+ (BOOL)isValueAvailableForHost:(NSString *)host;

///获取数据(全局)
+ (id)getValueWithKey:(NSString *)key;

///通过host获取数据(未注册的host用全局容器)
+ (id)getValueWithKey:(NSString *)key andHost:(NSString *)host;

///通过VC实例获取数据(未注册的VC用全局容器)
+ (id)getValueWithKey:(NSString *)key andInstance:(UIViewController *)vc;

///获取所有的全局数据
+ (KATHashMap *)getAllValues;

///获取所有的host数据
+ (KATHashMap *)getAllValuesForHost:(NSString *)host;

///获取所有的host数据(通过VC)
+ (KATHashMap *)getAllValuesForInstance:(UIViewController *)vc;

///设置数据(全局)(置空则删除数据)
+ (void)setValue:(id)value withKey:(NSString *)key;

///通过host设置数据(未注册的host用全局容器)(置空则删除数据)
+ (void)setValue:(id)value withKey:(NSString *)key andHost:(NSString *)host;

///通过VC实例设置数据(未注册的VC用全局容器)(置空则删除数据)
+ (void)setValue:(id)value withKey:(NSString *)key andInstance:(UIViewController *)vc;

///清除host下的所有数据
+ (void)clearValuesWithHost:(NSString *)host;

///通过VC清除host下的所有数据
+ (void)clearValuesWithInstance:(UIViewController *)vc;

///清除所有的数据
+ (void)clearAllValues;


#pragma -mark 加密数据存取(持久化存储时会对数据加密,密钥自动生成,且保存在钥匙串中),部分敏感的环境变量也存在于此,所以不要轻易清除数据

///判断加密数据是否可用(防止数据结构重组时冲突)
+ (BOOL)isDataAvailable;

///获取加密数据
+ (id)getDataWithKey:(NSString *)key;

///获取所有的加密数据
+ (id)getAllData;

///设置加密数据
+ (void)setData:(id)data withKey:(NSString *)key;

///清除加密数据
+ (void)clearAllData;

///获取加密数据密码
+ (NSString *)passwordForData;

///更新加密数据密码(原有的密码会失效)
+ (void)updatePasswordForData;

///清除加密数据密码
+ (void)clearPasswordForData;

///获取用户识别码(第一次获取的时候生成,并保存到Keychain)
+ (NSString *)UUID;


#pragma -mark 参数配置

///设置首次路由URI(只设置一次)
+ (void)setFirstRouteURI:(NSString *)URI;

///更改首次路由URI
+ (void)changeFirstRouteURI:(NSString *)URI;

///获取首次路由URI
+ (NSString *)firstRouteURI;

///设置转场动画风格的key(方便传参数)(只设置一次)
+ (void)setTransitionStyleKey:(NSString *)key;

///更改转场动画风格的key(方便传参数)
+ (void)changeTransitionStyleKey:(NSString *)key;

///获取转场动画风格的key
+ (NSString *)transitionStyleKey;

///设置转场动画风格(只设置一次)
+ (void)setTransitionStyle:(KATRouterTransitionStyle)style;

///更改转场动画风格
+ (void)changeTransitionStyle:(KATRouterTransitionStyle)style;

///设置host的默认转场动画
+ (void)setTransitionStyle:(KATRouterTransitionStyle)style forHost:(NSString *)host;

///设置host数组的默认转场动画
+ (void)setTransitionStyle:(KATRouterTransitionStyle)style forHosts:(KATArray<NSString *> *)hosts;

///设置指定组的默认转场动画
+ (void)setTransitionStyle:(KATRouterTransitionStyle)style forGroup:(NSString *)group;

///删除host的默认转场动画
+ (void)removeTransitionStyleFromHost:(NSString *)host;

///清除所有的host默认转场动画
+ (void)clearTransitionStyleFromAllHosts;

///设置转场动画时长的key(方便传参数)(只设置一次)
+ (void)setTransitionDurationKey:(NSString *)key;

///更改转场动画时长的key(方便传参数)
+ (void)changeTransitionDurationKey:(NSString *)key;

///获取转场动画时长的key
+ (NSString *)transitionDurationKey;

///设置转场动画时长(只设置一次)
+ (void)setTransitionDuration:(double)duration;

///更改转场动画时长
+ (void)changeTransitionDuration:(double)duration;

///设置路由时是否新建实例的key(方便传参数)(只设置一次)
+ (void)setRoutingWithNewInstanceKey:(NSString *)key;

///更改路由时是否新建实例的key(方便传参数)
+ (void)changeRoutingWithNewInstanceKey:(NSString *)key;

///获取路由时是否新建实例的key
+ (NSString *)routingWithNewInstanceKey;

///设置路由时是否创建多例的key(方便传参数)(只设置一次)
+ (void)setRoutingWithMultipleInstanceKey:(NSString *)key;

///更改路由时是否创建多例的key(方便传参数)
+ (void)changeRoutingWithMultipleInstanceKey:(NSString *)key;

///获取路由时是否创建多例的key
+ (NSString *)routingWithMultipleInstanceKey;

///设置根视图内容图片(默认为启动图片)
+ (void)setRootContents:(UIImage *)contents;

///设置定时器间隔
+ (void)setTimerInterval:(double)interval;

///设置路由最大等待时间(默认为转场动画最大时长)
+ (void)setRoutingWaitDuration:(double)duration;

///获取根视图控制器
+ (UIViewController *)rootViewController;

///获取栈顶host
+ (NSString *)topHost;

///获取栈顶VC(路由器中的栈顶，不一定是app中的栈顶)
+ (UIViewController *)topViewController;

///获取主窗口
+ (UIWindow *)keyWindow;


#pragma -mark 弹窗

///获取提示窗口(用于设置样式等)
+ (KATAlertWindow *)getAlertWindow;

///显示提示窗口(直接显示之前设置过的窗口)
+ (void)showAlertWindow;

///隐藏提示窗口
+ (void)hideAlertWindow;

///显示提示窗口(设置标题和信息)
+ (void)showAlertWindowWithTitle:(NSString *)title andInfo:(NSString *)info;

///获取按钮窗口(用于设置样式等)
+ (KATButtonWindow *)getButtonWindow;

///显示按钮窗口(直接显示之前设置过的窗口)
+ (void)showButtonWindow;

///隐藏按钮窗口
+ (void)hideButtonWindow;

///显示按钮窗口(设置标题、信息和确认按钮动作，默认带一个取消按钮和一个确认按钮)
+ (void)showButtonWindowWithTitle:(NSString *)title info:(NSString *)info andOnConfirmAction:(void (^)(void))action;

///显示按钮窗口(设置标题、信息和按钮)
+ (void)showButtonWindowWithTitle:(NSString *)title info:(NSString *)info andButtons:(KATArray<KATButton *> *)buttons;

///获取选择窗口(用于设置样式等)
+ (KATChoiceWindow *)getChoiceWindow;

///显示选择窗口(直接显示之前设置过的窗口)
+ (void)showChoiceWindow;

///隐藏选择窗口
+ (void)hideChoiceWindow;

///显示选择窗口(设置标题、信息和左右按钮标签及动作)
+ (void)showChoiceWindowWithTitle:(NSString *)title info:(NSString *)info leftButtonLabel:(NSString *)leftLabel leftButtonAction:(void (^)(void))leftAction rightButtonLabel:(NSString *)rightLabel rightButtonAction:(void (^)(void))rightAction;

///显示选择窗口(设置标题、信息和按钮)
+ (void)showChoiceWindowWithTitle:(NSString *)title info:(NSString *)info andButtons:(KATArray<KATLabelButton *> *)buttons;

///获取输入窗口(用于设置样式等)
+ (KATInputWindow *)getInputWindow;

///显示输入窗口(直接显示之前设置过的窗口)
+ (void)showInputWindow;

///隐藏输入窗口
+ (void)hideInputWindow;

///显示输入窗口(设置标题和确认动作)
+ (void)showInputWindowWithTitle:(NSString *)title andOnConfirmAction:(void (^)(NSString *text))action;

///获取输入框窗口(用于设置样式等)
+ (KATTextFieldWindow *)getTextFieldWindow;

///显示输入框窗口(直接显示之前设置过的窗口)
+ (void)showTextFieldWindow;

///隐藏输入框窗口
+ (void)hideTextFieldWindow;

///显示输入框窗口(设置标题、信息和左右按钮标签及动作)
+ (void)showTextFieldWindowWithTitle:(NSString *)title leftButtonLabel:(NSString *)leftLabel leftButtonAction:(void (^)(NSString *text))leftAction rightButtonLabel:(NSString *)rightLabel rightButtonAction:(void (^)(NSString *text))rightAction;

///获取等待窗口(用于设置样式等)
+ (KATWaitWindow *)getWaitWindow;

///显示等待窗口(直接显示之前设置过的窗口)
+ (void)showWaitWindow;

///隐藏等待窗口
+ (void)hideWaitWindow;

///获取加载窗口(用于设置样式等)
+ (KATWaitWindow *)getLoadingWindow;

///显示加载窗口(直接显示之前设置过的窗口)
+ (void)showLoadingWindow;

///隐藏加载窗口
+ (void)hideLoadingWindow;

///加载完成
+ (void)loadingWindowSuccessWithMessage:(NSString *)message;

///加载失败
+ (void)loadingWindowFailWithMessage:(NSString *)message;

///获取吐司(用于设置样式等)
+ (KATToast *)getToast;

///显示吐司(直接显示之前设置过的窗口)
+ (void)showToast;

///显示吐司(设置文本)
+ (void)showToastWithText:(NSString *)text;

///显示吐司(设置按钮)
+ (void)showToastWithButton:(KATButtonType)button;

///显示吐司(设置文本、按钮、时长和位置)
+ (void)showToastWithText:(NSString *)text button:(KATButtonType)button duration:(float)duration andPosition:(int)position;


#pragma -mark 内容管理

///是否正在跳转
+ (BOOL)isRouting;

///通过类获取host
+ (NSString *)hostWithClass:(Class)cls;

///通过类名获取host
+ (NSString *)hostWithClassName:(NSString *)name;

///通过实例获取host
+ (NSString *)hostWithInstance:(UIViewController *)instance;

///获取当前的host
+ (NSString *)currentHost;

///正在路由的host
+ (NSString *)routingHost;

///获取当前的host的实例
+ (UIViewController *)currentHostInstance;

///判断是否为当前的host
+ (BOOL)isCurrentHost:(NSString *)host;

///判断是否为当前的host实例
+ (BOOL)isCurrentHostInstance:(UIViewController *)instance;

///获取类
+ (Class)classWithHost:(NSString *)host;

///获取实例
+ (UIViewController *)instanceWithHost:(NSString *)host;

///释放实例
+ (void)releaseInstance:(UIViewController *)instance;

///释放实例
+ (void)releaseInstanceWithHost:(NSString *)host;

///释放所有实例
+ (void)releaseAllInstances;

///获取一直持有的host数组
+ (KATArray<NSString *> *)getAlwaysRetainedHosts;

///添加一直持有的host
+ (void)addAlwaysRetainedHost:(NSString *)host;

///添加一直持有的host数组
+ (void)addAlwaysRetainedHosts:(KATArray<NSString *> *)hosts;

///通过指定组添加一直持有的host
+ (void)addAlwaysRetainedHostsWithGroup:(NSString *)group;

///删除一直持有的host
+ (void)removeAlwaysRetainedHost:(NSString *)host;

///清除一直持有的host
+ (void)clearAlwaysRetainedHosts;

///获取路由时新建实例的host数组
+ (KATArray<NSString *> *)getRoutingWithNewInstanceHosts;

///添加路由时新建实例的host
+ (void)addRoutingWithNewInstanceHost:(NSString *)host;

///添加路由时新建实例的host数组
+ (void)addRoutingWithNewInstanceHosts:(KATArray<NSString *> *)hosts;

///通过指定组添加路由时新建实例的host
+ (void)addRoutingWithNewInstanceHostsWithGroup:(NSString *)group;

///删除路由时新建实例的host
+ (void)removeRoutingWithNewInstanceHost:(NSString *)host;

///清除路由时新建实例的host
+ (void)clearRoutingWithNewInstanceHosts;

///获取路由时创建多例的host数组
+ (KATArray<NSString *> *)getRoutingWithMultipleInstanceHosts;

///添加路由时创建多例的host
+ (void)addRoutingWithMultipleInstanceHost:(NSString *)host;

///添加路由时创建多例的host数组
+ (void)addRoutingWithMultipleInstanceHosts:(KATArray<NSString *> *)hosts;

///通过指定组添加路由时创建多例的host
+ (void)addRoutingWithMultipleInstanceHostsWithGroup:(NSString *)group;

///删除路由时创建多例的host
+ (void)removeRoutingWithMultipleInstanceHost:(NSString *)host;

///清除路由时创建多例的host
+ (void)clearRoutingWithMultipleInstanceHosts;

///获取需要接收截图的host数组
+ (KATArray<NSString *> *)getRequeredSnapshotHosts;

///添加需要接收截图的host
+ (void)addRequeredSnapshotHost:(NSString *)host;

///添加需要接收截图的host数组
+ (void)addRequeredSnapshotHosts:(KATArray<NSString *> *)hosts;

///通过指定组添加需要接收截图的host
+ (void)addRequeredSnapshotHostsWithGroup:(NSString *)group;

///删除需要接收截图的host
+ (void)removeRequeredSnapshotHost:(NSString *)host;

///清除需要接收截图的host
+ (void)clearRequeredSnapshotHosts;

///获取禁止跳转的host数组
+ (KATArray<NSString *> *)getForbiddenHosts;

///添加禁止跳转的host
+ (void)addForbiddenHost:(NSString *)host;

///添加禁止跳转的host数组
+ (void)addForbiddenHosts:(KATArray<NSString *> *)hosts;

///通过指定组添加禁止跳转的host
+ (void)addForbiddenHostsWithGroup:(NSString *)group;

///删除禁止跳转的host
+ (void)removeForbiddenHost:(NSString *)host;

///清除禁止跳转的host
+ (void)clearForbiddenHosts;

///获取重定向的URI(跳转被禁止的host时重定向的URI,若为nil有则不跳转)(默认为nil)
+ (NSString *)redirectedURI;

///设置被禁止路由的host的重定向的URI(跳转被禁止的host时重定向的URI,若为nil有则不跳转)(默认为nil)
+ (void)setRedirectedURI:(NSString *)URI;

///获取host重定向表(非禁止路由的host)(copy)
+ (KATHashMap<NSString *> *)getHostRedirections;

///设置host的重定向URI(非禁止路由的host)
+ (void)setRedirection:(NSString *)URI forHost:(NSString *)host;

///删除host的重定向URI
+ (void)removeRedirectionForHost:(NSString *)host;

///清除所有的host的重定向URI
+ (void)clearRedirections;

///获取Scheme的处理表(copy)
+ (KATHashMap<NSString *> *)getSchemeProcessors;

///设置Scheme的处理者Processor(processor为nil则为删除)(设置了处理者之后路由跳转时，scheme会被删除，host改为processor，路径和其他参数不变，原来的URI将作为addition字段传入)(先处理跳转过滤动作，再处理scheme)
+ (void)setProcessor:(NSString *)processor forScheme:(NSString *)scheme;

///删除Scheme的处理者
+ (void)removeProcessorForScheme:(NSString *)scheme;

///清除所有的scheme的处理者
+ (void)clearSchemeProcessors;

///获取返回栈
+ (KATStack<NSString *> *)backwardStack;

///将host插入到返回栈上的目标host之下
+ (BOOL)insertHost:(NSString *)host toBackwardStack:(NSString *)targetHost;

///将host插入到返回栈上的目标host之上
+ (BOOL)appendHost:(NSString *)host toBackwardStack:(NSString *)targetHost;

///将host插入到返回栈上的栈顶
+ (BOOL)appendToBackwardStackWithHost:(NSString *)host;

///将返回栈上的host删除
+ (void)removeHostFromBackwardStack:(NSString *)host;

///获取app加载时间
+ (CFAbsoluteTime)appLoadingTime;


#pragma -mark 网络访问

///获取http请求(用于参数配置)
+ (KATHttpRequest *)getHttpRequest;

///发起Http的GET请求(回调处理在主线程中)
+ (void)httpGetWithURL:(NSString *)URL andCallback:(void (^)(NSString *receivedData))callback;

///发起Http的POST请求(回调处理在主线程中)
+ (void)httpPostWithURL:(NSString *)URL sendData:(NSString *)sendData andCallback:(void (^)(NSString *receivedData))callback;

///发起Http的表单提交(回调处理在主线程中)
+ (void)httpSubmitForm:(KATHashMap *)form withURL:(NSString *)URL andCallback:(void (^)(NSString *receivedData))callback;

///发起Http文件上传，设置表单属性名称(回调处理在主线程中)
+ (void)httpUploadFile:(NSString *)file withURL:(NSString *)URL name:(NSString *)name andCallback:(void (^)(NSString *receivedData))callback;

///发起Http文件下载(会替换原文件)(回调处理在主线程中)
+ (void)httpDownloadFile:(NSString *)file withURL:(NSString *)URL andCallback:(void (^)(BOOL success))callback;

///获取网络状态
+ (KATRouterNetworkStatus)networkStatus;

///开始监听网络状态
+ (void)startNetworkStatusDetectionWithTestingHost:(NSString *)host;


#pragma -mark 全局队列和定时器

///获取自定义全局请求队列(串行)
+ (dispatch_queue_t)customQueueForRequest;

///获取自定义全局处理队列(串行)
+ (dispatch_queue_t)customQueueForProcess;

///获取自定义全局数据队列(串行)
+ (dispatch_queue_t)customQueueForData;

///获取自定义全局其他队列(串行)
+ (dispatch_queue_t)customQueueForOther;

///获取自定义全局并行队列
+ (dispatch_queue_t)customQueueForConcurrent;

///启动全局定时器
+ (void)startRouterTimerWithInterval:(double)interval;

///关闭全局定时器
+ (void)stopRouterTimer;

#pragma -mark 其他

///释放路由器
+ (void)releaseRouter;


@end

