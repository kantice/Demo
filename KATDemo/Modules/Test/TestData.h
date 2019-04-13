//
//  TestData.h
//  KATDemo
//
//  Created by kAt on 2018/12/5.
//  Copyright © 2018年 Kantice. All rights reserved.
//  Test模块数据中心

#import <Foundation/Foundation.h>
#import "TestStrings.h"


@interface TestData : NSObject


#pragma -mark 路径



#pragma -mark 数据

///字符串
@property(nonatomic,strong,readonly) TestStrings *strings;

///是否为测试服务器环境
//@property(nonatomic,assign,readonly) BOOL isTestServer;

///服务器协议
@property(nonatomic,copy,readonly) NSString *serverScheme;

///服务器host
@property(nonatomic,copy,readonly) NSString *serverHost;

///服务器端口
@property(nonatomic,copy,readonly) NSString *serverPort;


#pragma -mark 颜色



#pragma -mark 字体



#pragma -mark 样式



#pragma -mark 视图



#pragma -mark 类方法

///获取单例
+ (instancetype)sharedData;



#pragma -mark 对象方法

///保存配置
- (void)saveConfig;

@end


