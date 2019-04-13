//
//  Strings.h
//  KATDemo
//
//  Created by Yi Yu on 2018/3/22.
//  Copyright © 2018年 Kantice. All rights reserved.
//  App字符串常量及变量集中营

#import <Foundation/Foundation.h>




extern NSString *kEnvironmentType;//服务器环境


#pragma -mark host名称

extern NSString *kHostBrowser;//浏览器


#pragma -mark host组



#pragma -mark 通用key

extern NSString *kKeyUserID;//用户ID



#pragma -mark 服务器和URL

extern NSString *kServerScheme;//服务器协议
extern NSString *kServerHost;//服务器域名
extern NSString *kServerIP;//服务器IP
extern NSString *kServerPort;//服务器端口
extern NSString *kURLAddress;//服务地址URL(全路径)
extern NSString *kURLLogsUpload;//日志上传URL(全路径)
extern NSString *kURLLogsSignature;//日志签名URL(全路径)
extern NSString *kURLCommandGet;//命令获取URL(全路径)


@interface Strings : NSObject

#pragma -mark 字符串变量名(与配置文件的名称相对应)

//app名称
@property(nonatomic,copy) NSString *appName;

//app信息
@property(nonatomic,copy) NSString *appInfo;


@end
