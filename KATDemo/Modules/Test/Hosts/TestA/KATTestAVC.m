//
//  DMTestAVC.m
//  KATDemo
//
//  Created by Yi Yu on 2018/3/22.
//  Copyright © 2018年 Kantice. All rights reserved.
//

#import "KATTestAVC.h"
#import "KATTestData.h"
#import "TestMacros.h"
#import "KATTestInterface.h"


@interface KATTestAVC () <KATRouterDelegate>

@end


@implementation KATTestAVC


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
    self.view.backgroundColor=KCOLOR_GOLD;
    
    //测试按钮
    KATButton *button=[KATButton buttonWithFrame:RECT(40, 80, 40, 40) type:KATButtonTypeUpload color:KCOLOR_DARK lineWidth:2.0 scale:1.0 andOnClickAction:^
    {
        NSLog(@"TEST_INFO:%@",TEST_STR.moduleInfo);
        
        //新建一个测试数据
        KATTestData *data=[KATTestData data];
        data.index=9;
        data.name=@"XXX";
        
        //跳转到TestB，并传入参数和测试数据
        [KATRouter routeWithURI:[NSString stringWithFormat:@"%@?message=This is a test message!",kTestHostTestB] addition:data];
        
        //标记事件(日志埋点)
        [KATRouter markEvent:kTestEventTestY];
    }];
        
    [self.view addSubview:button];
    
    //按钮
    KATButton *messageButton=[KATButton buttonWithFrame:RECT(40, 180, 40, 40) type:KATButtonTypeChat color:KCOLOR_DARK lineWidth:2.0 scale:1.0 andOnClickAction:^
    {
        [KATRouter doHostAction:@"b.test/toast" withObject:@"TTTT" andForward:NO];
        
        //标记事件(日志埋点)
        [KATRouter markEvent:kTestEventTestX];
        
        KATTestData *data=[[KATTestData alloc] init];
        data.name=@"AYU";
        data.index=23;
        data.isMarked=YES;
        
        [KATTestInterface getData:data withPath:@"/test.php" andCallback:^(KATHashMap *result)
        {
            NSLog(@"result=%@",result);
        }];
    }];
    
    [self.view addSubview:messageButton];
}



#pragma -mark 路由器回调

//路由完成时回调
- (void)routingFinishWithValues:(KATHashMap *)values backward:(BOOL)backward
{
    //跳转过来收到的参数(包括URI)
    NSLog(@"values:%@",values);
}


@end
