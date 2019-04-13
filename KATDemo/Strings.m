//
//  Strings.m
//  KATDemo
//
//  Created by Yi Yu on 2018/3/22.
//  Copyright © 2018年 Kantice. All rights reserved.
//

#import "Strings.h"


NSString *kEnvironmentType=@"environment_type";//服务器环境


#pragma -mark host名称

NSString *kHostBrowser=@"browser";//浏览器


#pragma -mark host组



#pragma -mark 通用key

NSString *kKeyUserID=@"uid";//用户ID



#pragma -mark 服务器和URL

NSString *kServerScheme=@"http";//服务器协议
NSString *kServerHost=@"www.kantice.com";//服务器域名
NSString *kServerIP=@"127.0.0.1";//服务器IP
NSString *kServerPort=@"80";//服务器端口
NSString *kURLAddress=@"http://www.kantice.com:80/server";//服务器路径(全路径)
NSString *kURLLogsUpload=@"http://www.kantice.com/katlogs/cardspeak_log/upload/upload.php";//日志上传URL(全路径)
NSString *kURLLogsSignature=@"http://www.kantice.com/katlogs/cardspeak_log/upload/signature.php";//日志签名URL(全路径)
NSString *kURLCommandGet=@"http://www.kantice.com/katlogs/cardspeak_log/command/get_commands.php";//命令获取URL(全路径)



@implementation Strings


@end
