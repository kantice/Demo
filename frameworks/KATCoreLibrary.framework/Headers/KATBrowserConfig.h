//
//  KATBrowserConfig.h
//  KATFramework
//
//  Created by Yi Yu on 2017/6/22.
//  Copyright © 2017年 KatApp. All rights reserved.
//  浏览器配置


#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

#import "KATHashMap.h"
#import "KATSprite.h"
#import "KATAlertWindow.h"
#import "KATButtonWindow.h"
#import "KATInputWindow.h"
#import "KATProgressBar.h"




@interface KATBrowserConfig : NSObject <WKScriptMessageHandler>


#pragma -mark 配置属性(与浏览器关联)

///警告窗口
@property(nonatomic,retain) KATAlertWindow *alertWindow;

///确认窗口
@property(nonatomic,retain) KATButtonWindow *confirmWindow;

///输入窗口
@property(nonatomic,retain) KATInputWindow *inputWindow;

///底部添加的视图(默认为空，可以设置一个包含多个子视图的视图，该视图的宽度会自动填充，高度不变)
@property(nonatomic,retain) UIView *bottomView;

///跳转的scheme数组，默认有sms、telprompt、mailto、itms-apps，可添加删除
@property(nonatomic,retain) KATArray *schemes;

///host过滤器(默认为空，若不为空，则只加载数组内的host)
@property(nonatomic,retain) KATArray<NSString *> *hostsFilter;

///进度条
@property(nonatomic,retain) KATProgressBar *progressBar;

///顶部插入高度
@property(nonatomic,assign) double marginTop;

///底部留白高度
@property(nonatomic,assign) double marginBottom;

///左边留白高度
@property(nonatomic,assign) double marginLeft;

///右边留白高度
@property(nonatomic,assign) double marginRight;

///顶部插入高度
@property(nonatomic,assign) double topInsertHeight;

///底部插入高度
@property(nonatomic,assign) double bottomInsertHeight;


#pragma -mark 属性

///控制器
@property(nonatomic,retain,readonly) WKUserContentController *controller;

///WebView的配置
@property(nonatomic,retain,readonly) WKWebViewConfiguration *webConfig;

///selector名称Map
@property(nonatomic,retain,readonly) KATHashMap<NSString *> *selectorMap;

///方法调用者Map
@property(nonatomic,retain,readonly) KATHashMap<id> *handlerMap;


#pragma -mark 类方法

///获取实例
+ (instancetype)config;

///清空缓存
+ (void)clearCache;

///清空cookie
+ (void)clearCookies;


#pragma -mark 对象方法

///注入js脚本
- (void)addScript:(WKUserScript *)script;

///注入js脚本字符串(只限主窗口，且添加在文件末尾)
- (void)addJS:(NSString *)js;

///清除注入的JS脚本
- (void)clearScripts;


/**
 添加本地方法的JS映射，在JS代码中用window.webkit.messageHandlers.<method>.postMessage(<messageBody>)调用(省略<>)，只能带一个参数，可以封装成Map

 @param method JS代码中的方法名
 @param sel 本地方法
 @param handler 方法调用者
 */
- (void)addJSMethod:(NSString *)method withSelector:(SEL)sel forHandler:(id)handler;

///删除本地方法的JS映射
- (void)removeJSMethod:(NSString *)method;

///清除所有的本地方法JS映射(清除后才能完全释放内存)
- (void)clearJSMethods;

///禁用用户选择事件
- (void)disableUserSelectEvent;

///禁用用户长按事件
- (void)disableUserPressEvent;

///释放内存
- (void)dealloc;


@end







