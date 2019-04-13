//
//  AppData.m
//  KATDemo
//
//  Created by Yi Yu on 2018/3/22.
//  Copyright © 2018年 Kantice. All rights reserved.
//

#import "AppData.h"

#import "TestData.h"



@interface AppData ()


//字符串
@property(nonatomic,strong) Strings *strings;


@end




@implementation AppData


//单例
static AppData *_data=nil;


//获取单例
+ (instancetype)sharedData
{
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^
    {
        //初始化
        _data=[[self alloc] init];
        
        //加载文本
        if(LANGUAGE_CH)//简体中文
        {
            //先从doc目录中加载(便于远程更新文本)
            if([KATFileUtil existsFile:[NSString stringWithFormat:@"%@/strings_cn.txt",DOCUMENTS_PATH]])
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/strings_cn.txt",DOCUMENTS_PATH]] objectFromMapWithClass:[Strings class]];
            }
            else
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/Resource/String/cn.txt",APP_PATH]] objectFromMapWithClass:[Strings class]];
            }
        }
        else if(LANGUAGE_CHT)//繁体中文
        {
            //先从doc目录中加载(便于远程更新文本)
            if([KATFileUtil existsFile:[NSString stringWithFormat:@"%@/strings_cnt.txt",DOCUMENTS_PATH]])
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/strings_cnt.txt",DOCUMENTS_PATH]] objectFromMapWithClass:[Strings class]];
            }
            else
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/Resource/String/cnt.txt",APP_PATH]] objectFromMapWithClass:[Strings class]];
            }
        }
        else if(LANGUAGE_JA)//日文
        {
            //先从doc目录中加载(便于远程更新文本)
            if([KATFileUtil existsFile:[NSString stringWithFormat:@"%@/strings_ja.txt",DOCUMENTS_PATH]])
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/strings_ja.txt",DOCUMENTS_PATH]] objectFromMapWithClass:[Strings class]];
            }
            else
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/Resource/String/ja.txt",APP_PATH]] objectFromMapWithClass:[Strings class]];
            }
        }
        else if(LANGUAGE_EN)//英文
        {
            //先从doc目录中加载(便于远程更新文本)
            if([KATFileUtil existsFile:[NSString stringWithFormat:@"%@/strings_en.txt",DOCUMENTS_PATH]])
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/strings_en.txt",DOCUMENTS_PATH]] objectFromMapWithClass:[Strings class]];
            }
            else
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/Resource/String/en.txt",APP_PATH]] objectFromMapWithClass:[Strings class]];
            }
        }
        else//默认
        {
            //先从doc目录中加载(便于远程更新文本)
            if([KATFileUtil existsFile:[NSString stringWithFormat:@"%@/strings_default.txt",DOCUMENTS_PATH]])
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/strings_default.txt",DOCUMENTS_PATH]] objectFromMapWithClass:[Strings class]];
            }
            else
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/Resource/String/default.txt",APP_PATH]] objectFromMapWithClass:[Strings class]];
            }
        }
        
        //注册Host和group
        if([KATFileUtil existsFile:[NSString stringWithFormat:@"%@/router_register.txt",DOCUMENTS_PATH]])//先从doc目录中加载(便于远程更新配置)
        {
            [KATRouter registWithFile:[NSString stringWithFormat:@"%@/router_register.txt",DOCUMENTS_PATH]];
        }
        else
        {
            [KATRouter registWithFile:[NSString stringWithFormat:@"%@/Resource/Data/router_register.txt",APP_PATH]];
        }
        
        //启用其他模块
        [TestData sharedData];
        
        //加载路由器配置文件
        if([KATFileUtil existsFile:[NSString stringWithFormat:@"%@/router_loader.txt",DOCUMENTS_PATH]])//先从doc目录中加载(便于远程更新配置)
        {
            [KATRouter setUpWithFile:[NSString stringWithFormat:@"%@/router_loader.txt",DOCUMENTS_PATH]];
        }
        else
        {
            [KATRouter setUpWithFile:[NSString stringWithFormat:@"%@/Resource/Data/router_loader.txt",APP_PATH]];
        }
        
        //设置用户日志ID(首次用UUID，如果有帐号系统，则在帐号登录后改变用户日志ID)
        [KATRouter setLogsID:[KATRouter UUID]];
        
        //设置日志上传成功判断
        [KATRouter setLogsDidUploadAction:^BOOL(NSString *feeback)
        {
            if(feeback && [feeback intValue]/100==2)//返回200
            {
                return YES;
            }
            
            return NO;
        }];
    });
    
    return _data;
}


//重写alloc
+ (instancetype)alloc
{
    if(_data)
    {
        return nil;
    }
    else
    {
        return [super alloc];
    }
    
}



#pragma -mark 对象方法

//保存配置
- (void)saveConfig
{
    
}


@end
