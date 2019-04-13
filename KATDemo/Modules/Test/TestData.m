//
//  TestData.m
//  KATDemo
//
//  Created by kAt on 2018/12/5.
//  Copyright © 2018年 Kantice. All rights reserved.
//

#import "TestData.h"
#import "TestMacros.h"


@interface TestData ()

///字符串
@property(nonatomic,strong) TestStrings *strings;

///是否为测试服务器环境
@property(nonatomic,assign) BOOL isTestServer;

@end


@implementation TestData

//单例
static TestData *_data=nil;


//获取单例
+ (instancetype)sharedData
{
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^
    {
        //初始化
        _data=[[self alloc] init];
        
        //加载字符串
        if(LANGUAGE_CH)//简体中文
        {
            //先从doc目录中加载(便于远程更新文本)
            if([KATFileUtil existsFile:[NSString stringWithFormat:@"%@/strings_test_cn.txt",DOCUMENTS_PATH]])
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/strings_test_cn.txt",DOCUMENTS_PATH]] objectFromMapWithClass:[Strings class]];
            }
            else
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/String/cn.txt",TEST_RES_PATH]] objectFromMapWithClass:[TestStrings class]];
            }
        }
        else if(LANGUAGE_CHT)//繁体中文
        {
            //先从doc目录中加载(便于远程更新文本)
            if([KATFileUtil existsFile:[NSString stringWithFormat:@"%@/strings_test_cnt.txt",DOCUMENTS_PATH]])
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/strings_test_cnt.txt",DOCUMENTS_PATH]] objectFromMapWithClass:[Strings class]];
            }
            else
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/String/cnt.txt",TEST_RES_PATH]] objectFromMapWithClass:[TestStrings class]];
            }
        }
        else if(LANGUAGE_JA)//日文
        {
            //先从doc目录中加载(便于远程更新文本)
            if([KATFileUtil existsFile:[NSString stringWithFormat:@"%@/strings_test_ja.txt",DOCUMENTS_PATH]])
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/strings_test_ja.txt",DOCUMENTS_PATH]] objectFromMapWithClass:[Strings class]];
            }
            else
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/String/ja.txt",TEST_RES_PATH]] objectFromMapWithClass:[TestStrings class]];
            }
        }
        else if(LANGUAGE_EN)//英文
        {
            //先从doc目录中加载(便于远程更新文本)
            if([KATFileUtil existsFile:[NSString stringWithFormat:@"%@/strings_test_en.txt",DOCUMENTS_PATH]])
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/strings_test_en.txt",DOCUMENTS_PATH]] objectFromMapWithClass:[Strings class]];
            }
            else
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/String/en.txt",TEST_RES_PATH]] objectFromMapWithClass:[TestStrings class]];
            }
        }
        else//默认
        {
            //先从doc目录中加载(便于远程更新文本)
            if([KATFileUtil existsFile:[NSString stringWithFormat:@"%@/strings_test_default.txt",DOCUMENTS_PATH]])
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/strings_test_default.txt",DOCUMENTS_PATH]] objectFromMapWithClass:[Strings class]];
            }
            else
            {
                _data.strings=[[KATHashMap hashMapWithFile:[NSString stringWithFormat:@"%@/String/default.txt",TEST_RES_PATH]] objectFromMapWithClass:[TestStrings class]];
            }
        }
        
        //注册Host和group
        if([KATFileUtil existsFile:[NSString stringWithFormat:@"%@/router_register_test.txt",DOCUMENTS_PATH]])//先从doc目录中加载(便于远程更新配置)
        {
            [KATRouter registWithFile:[NSString stringWithFormat:@"%@/router_register_test.txt",DOCUMENTS_PATH]];
        }
        else
        {
            [KATRouter registWithFile:[NSString stringWithFormat:@"%@/Data/router_register.txt",TEST_RES_PATH]];
        }
        
        //服务器环境
//        _data.isTestServer=NO;
        
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

//获取服务器协议
- (NSString *)serverScheme
{
    //获取服务器环境
    int env=[[[NSUserDefaults standardUserDefaults] objectForKey:kEnvironmentType] intValue];
    
    if(env==1)//发布环境
    {
        return kTestServerTestScheme;
    }
    else//非测试环境
    {
        return kTestServerScheme;
    }
}


//获取服务器host
- (NSString *)serverHost
{
    //获取服务器环境
    int env=[[[NSUserDefaults standardUserDefaults] objectForKey:kEnvironmentType] intValue];
    
    if(env==1)//测试环境
    {
        return kTestServerTestHost;
    }
    else//发布环境
    {
        return kTestServerHost;
    }
}


//获取服务器端口
- (NSString *)serverPort
{
    //获取服务器环境
    int env=[[[NSUserDefaults standardUserDefaults] objectForKey:kEnvironmentType] intValue];
    
    if(env==1)//测试环境
    {
        return kTestServerTestPort;
    }
    else//发布环境
    {
        return kTestServerPort;
    }
}



//保存配置
- (void)saveConfig
{
    
}

@end
