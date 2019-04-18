//
//  DMTestBVC.m
//  KATDemo
//
//  Created by Yi Yu on 2018/3/22.
//  Copyright © 2018年 Kantice. All rights reserved.
//

#import "KATTestBVC.h"
#import <KATCoreLibrary/KATImage.h>


@interface KATTestBVC () <KATRouterDelegate>

@end


@implementation KATTestBVC


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
    
}


//初始化视图
- (void)initView
{
    self.view.backgroundColor=COLOR(190884099);
    
    //按钮
    KATButton *button=[KATButton buttonWithFrame:RECT(40, 80, 40, 40) type:KATButtonTypeUpload color:KCOLOR_GOLD lineWidth:2.0 scale:1.0 andOnClickAction:^
    {
        NSLog(@"APP_INFO:%@",STR.appInfo);
        
        [KATRouter routeWithURI:@"http://www.kantice.com"];        
    }];
        
    [self.view addSubview:button];
    
    //返回按钮
    KATButton *backButton=[KATButton buttonWithFrame:RECT(240, 80, 40, 40) type:KATButtonTypeClose color:KCOLOR_GOLD lineWidth:2.0 scale:1.0 andOnClickAction:^
    {
        [KATRouter backward];
    }];
    
    [self.view addSubview:backButton];
    
    //图片
    [KATImage setPercentRingHeight:32.0];
    [KATImage clearCacheBeforeDays:0];
    
    KATImage *image=[KATImage image];
    image.frame=CGRectMake(40, 140, 160, 160);
    image.isTapToShow=YES;
    [image loadWithURL:@"http://www.kantice.com/common/res/test/mai_07.jpg"];
    [self.view addSubview:image];
}


#pragma -mark 路由器回调

//路由完成时回调
- (void)routingFinishWithValues:(KATHashMap *)values backward:(BOOL)backward
{
    //跳转过来收到的参数(包括URI)
    NSLog(@"values:%@",values);
}


@end
