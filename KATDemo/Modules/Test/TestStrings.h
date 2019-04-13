//
//  TestStrings.h
//  KATDemo
//
//  Created by kAt on 2018/12/5.
//  Copyright © 2018年 Kantice. All rights reserved.
//  Test模块字符串常量及变量集中营

#import <Foundation/Foundation.h>


@interface TestStrings : NSObject


#pragma -mark host名称

extern NSString *kTestHostTestA;//测试A
extern NSString *kTestHostTestB;//测试B
extern NSString *kTestHostTestAction;//测试Action


#pragma -mark host组

extern NSString *kTestGroupTest;//测试组


#pragma -mark Action名称

extern NSString *kTestActionToast;//吐司


#pragma -mark 日志事件名

extern NSString *kTestEventTestX;//测试事件X
extern NSString *kTestEventTestY;//测试事件Y
extern NSString *kTestEventTestZ;//测试事件Z


#pragma -mark 通用key

extern NSString *kTestKeyUserID;//用户ID


#pragma -mark 服务器和URL

extern NSString *kTestServerScheme;//服务器:协议
extern NSString *kTestServerHost;//服务器:Host
extern NSString *kTestServerPort;//服务器:端口

extern NSString *kTestServerTestScheme;//测试服务器:协议
extern NSString *kTestServerTestHost;//测试服务器:Host
extern NSString *kTestServerTestPort;//测试服务器:端口



#pragma -mark 字符串变量名(与配置文件的名称相对应)

//模块名称
@property(nonatomic,copy) NSString *moduleName;

//模块信息
@property(nonatomic,copy) NSString *moduleInfo;

@end


