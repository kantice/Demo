//
//  BrowserVC.m
//  KATDemo
//
//  Created by Yi Yu on 2018/3/22.
//  Copyright © 2018年 Kantice. All rights reserved.
//

#import "KATBrowserVC.h"
#import <KATCoreLibrary/KATBrowser.h>


NSString *kBrowserNavButtonID=@"kat_browser_nav_button";
NSString *kBrowserNavButtonAttribute=@"button_attr";


@interface KATBrowserVC () <KATRouterDelegate,KATBrowserDelegate>

///配置
@property(nonatomic,strong) KATBrowserConfig *config;

///浏览器
@property(nonatomic,strong) KATBrowser *browser;

///标题
@property(nonatomic,copy) NSString *pageTitle;

///左侧按钮数组
@property(nonatomic,strong) KATArray<KATButton *> *leftButtons;

///导航栏右侧按钮属性
@property(nonatomic,strong) KATHashMap *rightButtonMap;

@end



@implementation KATBrowserVC

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [self initData];
    [self initView];
    
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}


//初始化数据
- (void)initData
{
    self.pageTitle=@"";
    
//    [KATBrowser clearCache];//清除缓存
}


//初始化界面
- (void)initView
{
    WEAK_SELF;
    
    //背景色
    self.view.backgroundColor=KCOLOR_BACKGROUND;
    
    //配置
    self.config=[KATBrowserConfig config];
    _config.marginTop=[KATRouter getNavBar].height;
    _config.marginBottom=[KATRouter getTabBar].height;
//    [_config disableUserSelectEvent];
//    [_config disableUserPressEvent];
    
    //浏览器
    self.browser=[KATBrowser browserWithFrame:RECT(0, STATUS_BAR_HEIGHT, self.view.bounds.size.width, self.view.bounds.size.height-STATUS_BAR_HEIGHT) andConfig:_config];
    _browser.web.allowsBackForwardNavigationGestures=YES;
    _browser.eventDelegate=self;
    
    [self.view addSubview:_browser];
    
    //左侧按钮
    self.leftButtons=ARRAY([KATButton buttonWithFrame:CGRectZero type:KATButtonTypeLeft color:nil lineWidth:0 scale:0 andOnClickAction:^
    {
        if(weakSelf.browser.canGoBack)
        {
            [weakSelf.browser goBack];
        }
        else
        {
            [KATRouter backward];
        }
    }]);
}


#pragma -mark 回调方法

//路由回调
- (void)routingFinishWithValues:(KATHashMap *)values backward:(BOOL)backward
{
    if(!backward)
    {
        if(values[kRouterKeyAddition])
        {
            if([values[kRouterKeyAddition] isKindOfClass:[NSString class]])
            {
                [_browser loadURL:values[kRouterKeyAddition]];
            }
        }
    }
}


//将要被销毁
- (void)instanceWillBeReleased
{
    if(_browser)
    {
        _browser.eventDelegate=nil;
    }
}


//改变标题回调
- (void)browserDidChangePageTitle:(KATBrowser *)browser
{
    self.pageTitle=browser.pageTitle;
    
    if(!_pageTitle)
    {
        self.pageTitle=@"";
    }
    
    //重新加载
    [KATRouter reloadNavBar];
}


//是否跳转
- (BOOL)browser:(KATBrowser *)browser shouldLoadWithRequest:(NSURLRequest *)request
{
    KATHashMap *uri=[KATURIParser parseURI:[request.URL absoluteString]];
    
    if(uri[kURIKeyScheme] && [[KATAppUtil schemes] hasMember:uri[kURIKeyScheme]])
    {
        [KATRouter routeWithURI:[KATURIParser URIWithMap:uri]];
        
        return NO;
    }
    
    return YES;
}


//开始加载
- (void)browserDidStartLoading:(KATBrowser *)browser
{
    
}


//加载失败
- (void)browserDidFailLoading:(KATBrowser *)browser
{
    
}


//加载完成
- (void)browserDidFinishLoading:(KATBrowser *)browser
{
    //获取元素
    [_browser getAtrribute:kBrowserNavButtonAttribute inDocumentWithID:kBrowserNavButtonID completion:^(id obj, NSError *error)
    {
        //重置
        self.rightButtonMap=nil;
        
        //获取成功
        if(obj && [obj isKindOfClass:[NSString class]])
        {
            self.rightButtonMap=[KATHashMap hashMapWithString:obj];
        }
        
        //重新加载
        [KATRouter reloadNavBar];
    }];
}


//导航栏
- (BOOL)isShownNavBar:(KATNavBar *)navBar
{
    return YES;
}


//隐藏返回按钮(自定义左侧按钮)
- (BOOL)hideBackButtonInNavBar:(KATNavBar *)navBar
{
    return YES;
}


//导航栏左侧按钮
- (KATArray<KATButton *> *)leftButtonsInNavBar:(KATNavBar *)navBar
{
    return _leftButtons;
}


//导航栏标题
- (NSString *)titleInNavBar:(KATNavBar *)navBar
{
    return _pageTitle;
}


//导航栏右侧按钮
- (KATArray<KATButton *> *)rightButtonsInNavBar:(KATNavBar *)navBar
{
    if(_rightButtonMap)
    {
        WEAK_SELF;
        
        KATButton *button=[KATButton buttonWithFrame:CGRectZero type:[weakSelf.rightButtonMap[@"type"] intValue] color:nil lineWidth:0 scale:0 andOnClickAction:^
        {
            //事件
            if(weakSelf.rightButtonMap[@"action"])
            {
                [KATRouter doHostAction:weakSelf.rightButtonMap[@"action"] withObject:weakSelf.rightButtonMap[@"message"] andForward:weakSelf.rightButtonMap[@"action"]?[weakSelf.rightButtonMap[@"action"] boolValue]:NO];
            }
        }];
        
        return ARRAY(button);
    }

    return nil;
}


@end



