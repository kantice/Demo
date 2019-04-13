//
//  KATBrowser.h
//  KATFramework
//
//  Created by Yi Yu on 2017/6/14.
//  Copyright © 2017年 KatApp. All rights reserved.
//  封装了WKWebView的浏览器


#import <WebKit/WebKit.h>

#import "KATRouter.h"
#import "KATSprite.h"
#import "KATAlertWindow.h"
#import "KATButtonWindow.h"
#import "KATInputWindow.h"
#import "KATProgressBar.h"
#import "KATBrowserConfig.h"



#define BROWSER_STATUS_UNKNOWN 0
#define BROWSER_STATUS_START 1
#define BROWSER_STATUS_COMMIT 2
#define BROWSER_STATUS_FINISH 3
#define BROWSER_STATUS_FAIL 4




@class KATBrowser;


@protocol KATBrowserDelegate <NSObject>

@optional

///开始加载
- (void)browserDidStartLoading:(KATBrowser *)browser;

///内容开始返回
- (void)browserDidCommitLoading:(KATBrowser *)browser;

///完成加载
- (void)browserDidFinishLoading:(KATBrowser *)browser;

///加载失败
- (void)browserDidFailLoading:(KATBrowser *)browser;

///在请求发送前决定是否加载
- (BOOL)browser:(KATBrowser *)browser shouldLoadWithRequest:(NSURLRequest *)request;

///在收到响应时决定是否加载
- (BOOL)browser:(KATBrowser *)browser shouldLoadWithResponse:(NSURLResponse *)response;

///浏览器向下滚动
- (void)browserDidScrollDown:(KATBrowser *)browser;

///浏览器向上滚动
- (void)browserDidScrollUp:(KATBrowser *)browser;

///浏览器改变页面标题
- (void)browserDidChangePageTitle:(KATBrowser *)browser;


@end



@interface KATBrowser : KATSprite <WKNavigationDelegate,WKUIDelegate>


#pragma -mark 属性

///WebView控件
@property(nonatomic,retain,readonly) WKWebView *web;

///警告窗口
@property(nonatomic,retain,readonly) KATAlertWindow *alertWindow;

///确认窗口
@property(nonatomic,retain,readonly) KATButtonWindow *confirmWindow;

///输入窗口
@property(nonatomic,retain,readonly) KATInputWindow *inputWindow;

///底部添加的视图(默认为空，可以设置一个包含多个子视图的视图，该视图的宽度会自动填充，高度不变)
@property(nonatomic,retain) UIView *bottomView;

///跳转的scheme数组，默认有sms、telprompt、mailto、itms-apps，可添加删除(若存在该数组，则默认可以跳转到App Store)
@property(nonatomic,retain) KATArray *schemes;

///host过滤器(默认为空，若不为空，则只加载数组内的host)
@property(nonatomic,retain) KATArray<NSString *> *hostsFilter;

///失败刷新区域(透明，需要设置contents属性或添加内容,默认尺寸为0.618宽度正方形，中心位置)
@property(nonatomic,retain,readonly) KATSprite *refreshArea;

///进度条
@property(nonatomic,retain,readonly) KATProgressBar *progressBar;

///顶部留白高度
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

///浏览器状态
@property(nonatomic,assign,readonly) int status;

///页面标题
@property(nonatomic,copy,readonly) NSString *pageTitle;

///当前的URL
@property(nonatomic,copy,readonly) NSString *currentURL;

///配置
@property(nonatomic,retain) KATBrowserConfig *config;

///事件代理
@property(nonatomic,assign) id<KATBrowserDelegate> eventDelegate;



#pragma -mark 类方法

///获取实例
+ (instancetype)browserWithFrame:(CGRect)frame andWKConfig:(WKWebViewConfiguration *)config;

///获取实例
+ (instancetype)browserWithFrame:(CGRect)frame;

///获取实例
+ (instancetype)browserWithFrame:(CGRect)frame andConfig:(KATBrowserConfig *)config;

///清空缓存
+ (void)clearCache;

///清空cookie
+ (void)clearCookies;


#pragma -mark 对象方法

///加载页面内容
- (void)loadURL:(NSString *)url;

///重新加载(加载当前显示的页面)
- (void)reload;

///刷新(加载最近加载的URL)
- (void)updateURL;

///重新加载(优先加载缓存)
- (void)reloadFromOrigin;

///加载空白页
- (void)loadBlank;

///加载文件
- (void)loadFile:(NSString *)path;

///加载HTML字符串，baseURL是针对不完整的路径
- (void)loadHTML:(NSString *)html withBaseURL:(NSString *)base;

///加载HTML字符串
- (void)loadHTML:(NSString *)html;

///后退
- (void)goBack;

///前进
- (void)goForward;

///是否能后退
- (BOOL)canGoBack;

///是否能前进
- (BOOL)canGoForward;

///停止加载
- (void)stopLoading;

///适应尺寸
- (void)sizeToFit;

///获取当前的url
- (NSString *)currentURL;

//退回到最初的历史记录
- (void)goBackToFirstPage;


#pragma -mark JS交互

///执行JS代码
- (void)evalJavaScript:(NSString *)js completion:(void (^)(id obj,NSError *error))completion;

///通过id获取页面元素的某个属性
- (void)getAtrribute:(NSString *)attr inDocumentWithID:(NSString *)ID completion:(void (^)(id obj,NSError *error))completion;

///通过id获取页面元素的文本内容
- (void)getTextInDocumentWithID:(NSString *)ID completion:(void (^)(NSString *text,NSError *error))completion;

///获取页面中所有的图片(map类型，包含src、id、name、alt)
- (void)getImagesInDocumentWithCompletion:(void (^)(KATArray<KATHashMap *> *images,NSError *error))completion;

///在底部插入空白(单位为px)
- (void)insertBottomWithHeight:(double)height;

///在顶部插入空白(单位为px)
- (void)insertTopWithHeight:(double)height;



///释放内存
- (void)dealloc;




@end
