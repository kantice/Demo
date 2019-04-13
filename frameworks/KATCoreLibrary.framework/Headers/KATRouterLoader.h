//
//  KATRouterLoader.h
//  KATDemo
//
//  Created by kAt on 2018/12/3.
//  Copyright © 2018年 Kantice. All rights reserved.
//  路由器加载器

#import <Foundation/Foundation.h>
#import "KATHashMap.h"


#pragma -mark 路由器加载器host类

@interface KATRouterLoaderHost : NSObject

///host名称
@property(nonatomic,copy) NSString *hostName;

///类名
@property(nonatomic,copy) NSString *className;

///数据表
@property(nonatomic,retain) KATHashMap<NSString *> *values;

///动作表
@property(nonatomic,retain) KATHashMap<NSString *> *actions;

///依赖host
@property(nonatomic,copy) NSString *dependence;

///是否为地板
@property(nonatomic,assign) int isFloor;

///地板host
@property(nonatomic,copy) NSString *floor;

///所属分组数组
@property(nonatomic,retain) KATArray<NSString *> *groups;

///屏幕方向(1:竖屏、2:横屏、3:自由)(默认0根据全局设置)
@property(nonatomic,assign) int orientation;

///是否能侧滑回退(1:可以、2:不可以)(默认0根据全局设置)
@property(nonatomic,assign) int slideEnable;

///监听指定类型的消息
@property(nonatomic,copy) NSString *observedMessageType;

///转场动画类型(默认0根据全局设置)
@property(nonatomic,assign) int transitionStyle;

///是否一直持有
@property(nonatomic,assign) BOOL isAlwaysRetained;

///是否路由时新建实例
@property(nonatomic,assign) BOOL isRoutingWithNewInstance;

///是否路由时创建多例
@property(nonatomic,assign) BOOL isRoutingWithMultipleInstance;

///是否需要路由截图
@property(nonatomic,assign) BOOL isRequeredSnapshot;

@end


#pragma -mark 路由器加载器group类

@interface KATRouterLoaderGroup : NSObject

///组名称
@property(nonatomic,copy) NSString *groupName;

///host数组
@property(nonatomic,retain) KATArray<NSString *> *hosts;

///依赖host
@property(nonatomic,copy) NSString *dependence;

///地板host
@property(nonatomic,copy) NSString *floor;

///屏幕方向(1:竖屏、2:横屏、3:自由)(默认0根据全局设置)
@property(nonatomic,assign) int orientation;

///是否能侧滑回退(1:可以、2:不可以)(默认0根据全局设置)
@property(nonatomic,assign) int slideEnable;

///转场动画类型(默认0根据全局设置)
@property(nonatomic,assign) int transitionStyle;

///是否一直持有
@property(nonatomic,assign) BOOL isAlwaysRetained;

///是否路由时新建实例
@property(nonatomic,assign) BOOL isRoutingWithNewInstance;

///是否路由时创建多例
@property(nonatomic,assign) BOOL isRoutingWithMultipleInstance;

///是否需要路由截图
@property(nonatomic,assign) BOOL isRequeredSnapshot;

@end


#pragma -mark 路由器加载器类

@interface KATRouterLoader : NSObject

#pragma -mark 注册

///host数组
@property(nonatomic,retain) KATArray<KATRouterLoaderHost *> *hosts;

///组数组
@property(nonatomic,retain) KATArray<KATRouterLoaderGroup *> *groups;


#pragma -mark 参数配置

///首次路由URI
@property(nonatomic,copy) NSString *firstRouteURI;

///转场动画风格的key(方便传参数)
@property(nonatomic,copy) NSString *transitionStyleKey;

///转场动画风格
@property(nonatomic,assign) int transitionStyle;

///转场动画时长的key(方便传参数)
@property(nonatomic,copy) NSString *transitionDurationKey;

///转场动画时长
@property(nonatomic,assign) double transitionDuration;

///路由时是否新建实例的key(方便传参数)
@property(nonatomic,copy) NSString *routingWithNewInstanceKey;

///路由时是否创建多例的key(方便传参数)
@property(nonatomic,copy) NSString *routingWithMultipleInstanceKey;

///定时器间隔
@property(nonatomic,assign) double timerInterval;

///路由最大等待时间
@property(nonatomic,assign) double routingWaitDuration;

///地板host数组
@property(nonatomic,retain) KATArray<NSString *> *floorHosts;

///实例一直持有的host数组
@property(nonatomic,retain) KATArray<NSString *> *alwaysRetainedHosts;

///实例一直持有的组
@property(nonatomic,retain) KATArray<NSString *> *alwaysRetainedGroups;

///路由时新建实例的host数组
@property(nonatomic,retain) KATArray<NSString *> *routingWithNewInstanceHosts;

///路由时新建实例的组
@property(nonatomic,retain) KATArray<NSString *> *routingWithNewInstanceGroups;

///路由时创建多例的host数组
@property(nonatomic,retain) KATArray<NSString *> *routingWithMultipleInstanceHosts;

///路由时创建多例的组
@property(nonatomic,retain) KATArray<NSString *> *routingWithMultipleInstanceGroups;

///路由时需要接收截图的host数组
@property(nonatomic,retain) KATArray<NSString *> *requeredSnapshotHosts;

///路由时需要接收截图的组
@property(nonatomic,retain) KATArray<NSString *> *requeredSnapshotGroups;

///禁止跳转的host数组
@property(nonatomic,retain) KATArray<NSString *> *forbiddenHosts;

///禁止跳转的组
@property(nonatomic,retain) KATArray<NSString *> *forbiddenGroups;

///重定向的URI(跳转被禁止的host时重定向的URI,若为nil有则不跳转)
@property(nonatomic,copy) NSString *redirectedURI;

///host的重定向表
@property(nonatomic,retain) KATHashMap<NSString *> *hostRedirections;

///scheme的处理表(processor为nil则为删除)(设置了处理者之后路由跳转时，scheme会被删除，host改为processor，路径和其他参数不变，原来的URI将作为addition字段传入)(先处理跳转过滤动作，再处理scheme)
@property(nonatomic,retain) KATHashMap<NSString *> *schemeProcessors;

///是否关闭依赖关系路由的动画
@property(nonatomic,assign) BOOL shouldCloseDependencyTransition;

///是否不自动隐藏标签栏(非关联标签栏的host)(默认为否)
@property(nonatomic,assign) BOOL isNotAutoHidingTabBar;

///是否自动更新状态栏样式
@property(nonatomic,assign) BOOL isAutoStatusBarStyle;


#pragma -mark 横竖屏

///是否单一屏幕方向(只有单一方向的竖屏或横屏)
@property(nonatomic,assign) BOOL isSingleOrientationOnly;

///是否默认屏幕方向是否为横屏
@property(nonatomic,assign) BOOL isLandscapeOrientationDefault;

///竖屏方向的host数组
@property(nonatomic,retain) KATArray<NSString *> *portraitOrientationHosts;

///竖屏方向的组
@property(nonatomic,retain) KATArray<NSString *> *portraitOrientationGroups;

///横屏方向的host数组
@property(nonatomic,retain) KATArray<NSString *> *landscapeOrientationHosts;

///横屏方向的组
@property(nonatomic,retain) KATArray<NSString *> *landscapeOrientationGroups;

///自由屏方向的host数组
@property(nonatomic,retain) KATArray<NSString *> *freeOrientationHosts;

///自由屏方向的组
@property(nonatomic,retain) KATArray<NSString *> *freeOrientationGroups;


#pragma -mark 日志

///是否保存日志
@property(nonatomic,assign) BOOL shouldKeepLogs;

///是否上传日志
@property(nonatomic,assign) BOOL shouldUploadLogs;

///日志存放目录(Documents下)
@property(nonatomic,copy) NSString *logsDirectory;

///日志保存天数
@property(nonatomic,assign) int logsKeepingDays;

///日志上传地址
@property(nonatomic,copy) NSString *logsUploadURL;

///日志签名地址
@property(nonatomic,copy) NSString *logsSignatureURL;

///日志的app名称
@property(nonatomic,copy) NSString *logsApp;

///日志的上传内容属性名称
@property(nonatomic,copy) NSString *logsUploadContentKey;

///日志上传时的附加信息
@property(nonatomic,retain) KATHashMap *logsUploadExtra;


#pragma -mark 远程命令

///是否获取远程命令
@property(nonatomic,assign) BOOL shouldGetCommands;

///远程命令获取地址
@property(nonatomic,copy) NSString *commandsGetURL;

///获取远程命令时的附加信息
@property(nonatomic,retain) KATHashMap *commandGetExtra;


#pragma -mark 侧滑回退

///可以侧滑回退的host数组
@property(nonatomic,retain) KATArray<NSString *> *slideEnabledHosts;

///可以侧滑回退的组
@property(nonatomic,retain) KATArray<NSString *> *slideEnabledGroups;

///不能侧滑回退的host数组
@property(nonatomic,retain) KATArray<NSString *> *slideDisabledHosts;

///不能侧滑回退的组
@property(nonatomic,retain) KATArray<NSString *> *slideDisabledGroups;

///侧滑完成进度点(0~1之间 默认0.4,即超过宽度的40%)
@property(nonatomic,assign) float slideFinishProgress;

///侧滑手势完成条件的滑动尾速(默认为每帧16点)
@property(nonatomic,assign) float slideFinishSpeed;

///侧滑手势起始点X坐标位置(0~1之间,默认0.5,即左半屏)
@property(nonatomic,assign) float slideStartXPoint;

///水平滑动动画效果的host是否自动带侧滑交互(默认否)
@property(nonatomic,assign) BOOL slideNotAutoSetting;


#pragma -mark 数据存取

///全局数据字典
@property(nonatomic,retain) KATHashMap *globalValues;

///全局加密数据
@property(nonatomic,retain) KATHashMap *globalData;




@end

