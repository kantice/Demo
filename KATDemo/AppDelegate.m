//
//  AppDelegate.m
//  KATDemo
//
//  Created by Yi Yu on 2018/3/22.
//  Copyright © 2018年 Kantice. All rights reserved.
//

#import "AppDelegate.h"
#import <KATCoreLibrary/KATMonitor.h>



@interface AppDelegate ()

///性能监视器
@property(nonatomic,strong) KATMonitor *monitor;

@end



@implementation AppDelegate


//app加载时间
CFAbsoluteTime appStartTime;


//加载类
+ (void)load
{
    appStartTime=CFAbsoluteTimeGetCurrent();
    
    [super load];
}


//app加载完成
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    NSLog(@"============ launched duration: %fs", CFAbsoluteTimeGetCurrent()-appStartTime);
    
    //初始化开始时间
    CFAbsoluteTime initStartTime=CFAbsoluteTimeGetCurrent();
    
    [self initData];
    [self initView];
    
    NSLog(@"============ init duration: %fs",CFAbsoluteTimeGetCurrent()-initStartTime);
    
    return YES;
}


//app将要失活
- (void)applicationWillResignActive:(UIApplication *)application
{
    
}


//app进入后台
- (void)applicationDidEnterBackground:(UIApplication *)application
{
    
}


//app将要进入前台
- (void)applicationWillEnterForeground:(UIApplication *)application
{
    
}


//app激活
- (void)applicationDidBecomeActive:(UIApplication *)application
{
    
}


//app将要被终止
- (void)applicationWillTerminate:(UIApplication *)application
{
    
}


//app通过URL打开
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options
{    
    return YES;
}


//app通过其他app打开(iOS9之前版本，之后版本不会回调该方法)
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    return YES;
}


//后台会话任务完成后触发
//- (void)application:(UIApplication *)application handleEventsForBackgroundURLSession:(NSString *)identifier completionHandler:(nonnull void (^)(void))completionHandler
//{
//    //应添加一个backgroundSessionCompletionHandler属性，在session的代理函数中执行
//    self.backgroundSessionCompletionHandler=completionHandler;
//}


//app接收到本地通知
-(void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
{
    
}


//app接收到远程通知
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{
    
}


//app接收到远程通知
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler
{
    completionHandler(UIBackgroundFetchResultNewData);
}


//苹果推送服务回调，注册deviceToken
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    
}


//app注册用户消息
-(void)application:(UIApplication *)application didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings
{
    
}


//app支持的屏幕方向
- (UIInterfaceOrientationMask )application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window
{
//    return UIInterfaceOrientationMaskPortrait;
    return UIInterfaceOrientationMaskAll;
}



//初始化数据
- (void)initData
{
    NSLog(@"%@",SYSTEM_INFO);
    
    //初始化公有数据
    [AppData sharedData];
    
}




//初始化界面
- (void)initView
{
    //配置tabbar等
    
    //加入性能监视器
    self.monitor=[KATMonitor monitorWithFrame:CGRectMake(SCREEN_WIDTH-240.0, SCREEN_HEIGHT-SCREEN_MARGIN_BOTTOM-40.0, 240.0, 40.0)];
    [[KATRouter keyWindow] addSubview:_monitor];
    [_monitor start];
    
}




@end
