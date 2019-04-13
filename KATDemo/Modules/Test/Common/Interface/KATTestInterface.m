//
//  KATTestInterface.m
//  KATDemo
//
//  Created by kAt on 2019/2/21.
//  Copyright © 2019 Kantice. All rights reserved.
//

#import "KATTestInterface.h"
#import "TestMacros.h"
#import <KATCoreLibrary/KATHttpRequest.h>



@implementation KATTestInterface

//GET方式请求接口(同步)
+ (KATHashMap *)getData:(id)data withPath:(NSString *)path
{
    //请求接口
    NSString *returnText=[[KATHttpRequest request] getTextWithUrl:[self getURLWithPath:path andData:data]];
    
    if(returnText)
    {
        KATHashMap *result=[KATHashMap hashMapWithString:returnText];
        
        if([self resultDataKey])//有返回数据的key
        {
            return result[[self resultDataKey]];
        }
        else
        {
            return result;
        }
    }
    
    return nil;
}


//GET方式请求接口(异步)
+ (void)getData:(id)data withPath:(NSString *)path andCallback:(void (^)(KATHashMap *result))callback
{
    //请求接口
    [[KATHttpRequest request] getTextWithUrl:[self getURLWithPath:path andData:data] andCallback:^(NSString *returnText)
    {
        KATHashMap *result=[KATHashMap hashMapWithString:returnText];
        
        if([self resultDataKey])//有返回数据的key
        {
            result=result[[self resultDataKey]];
        }
        
        if(callback)
        {
            callback(result);
        }
    }];
}


//POST方式请求接口(同步)
+ (KATHashMap *)postData:(id)data withPath:(NSString *)path
{
    //请求接口
    NSString *returnText=[[KATHttpRequest request] postTextWithUrl:[self postURLWithPath:path] andSendText:[[KATHashMap hashMapWithObject:data] description]];
    
    if(returnText)
    {
        KATHashMap *result=[KATHashMap hashMapWithString:returnText];
        
        if([self resultDataKey])//有返回数据的key
        {
            return result[[self resultDataKey]];
        }
        else
        {
            return result;
        }
    }
    
    return nil;
}


//POST方式请求接口(异步)
+ (void)postData:(id)data withPath:(NSString *)path andCallback:(void (^)(KATHashMap *result))callback
{
    //请求接口
    [[KATHttpRequest request] postTextWithUrl:[self postURLWithPath:path] andSendText:[[KATHashMap hashMapWithObject:data] description] andCallback:^(NSString *returnText)
    {
        KATHashMap *result=[KATHashMap hashMapWithString:returnText];
        
        if([self resultDataKey])//有返回数据的key
        {
            result=result[[self resultDataKey]];
        }
        
        if(callback)
        {
            callback(result);
        }
    }];
}


//表单方式请求接口(同步)
+ (KATHashMap *)postFormData:(id)data withPath:(NSString *)path
{
    //请求接口
    NSString *returnText=[[KATHttpRequest request] postTextWithUrl:[self postURLWithPath:path] andForm:[KATHashMap hashMapWithObject:data]];
    
    if(returnText)
    {
        KATHashMap *result=[KATHashMap hashMapWithString:returnText];
        
        if([self resultDataKey])//有返回数据的key
        {
            return result[[self resultDataKey]];
        }
        else
        {
            return result;
        }
    }
    
    return nil;
}


//表单方式请求接口(异步)
+ (void)postFormData:(id)data withPath:(NSString *)path andCallback:(void (^)(KATHashMap *result))callback
{
    //请求接口
    [[KATHttpRequest request] postTextWithUrl:[self postURLWithPath:path] andForm:[KATHashMap hashMapWithObject:data] andCallback:^(NSString *returnText)
    {
        KATHashMap *result=[KATHashMap hashMapWithString:returnText];
        
        if([self resultDataKey])//有返回数据的key
        {
            result=result[[self resultDataKey]];
        }
        
        if(callback)
        {
            callback(result);
        }
    }];
}


//上传数据(同步)
+ (KATHashMap *)uploadFile:(NSString *)file withPath:(NSString *)path andName:(NSString *)name
{
    //请求接口
    NSData *returnData=[[KATHttpRequest request] uploadFile:file withUrl:[self postURLWithPath:path] andName:name];
    
    if(returnData)
    {
        NSString *returnText=[[NSString alloc] initWithData:returnData encoding:NSUTF8StringEncoding];
        
        KATHashMap *result=[KATHashMap hashMapWithString:returnText];
        
        if([self resultDataKey])//有返回数据的key
        {
            return result[[self resultDataKey]];
        }
        else
        {
            return result;
        }
    }
    
    return nil;
}


//上传数据(异步)
+ (void)uploadFile:(NSString *)file withPath:(NSString *)path andName:(NSString *)name andCallback:(void (^)(KATHashMap *result))callback
{
    [[KATHttpRequest request] uploadFile:file withUrl:[self postURLWithPath:path] andName:name andCallback:^(NSData *returnData)
    {
        NSString *returnText=nil;
        
        if(returnData)
        {
            returnText=[[NSString alloc] initWithData:returnData encoding:NSUTF8StringEncoding];
        }
        
        KATHashMap *result=[KATHashMap hashMapWithString:returnText];
        
        if([self resultDataKey])//有返回数据的key
        {
            result=result[[self resultDataKey]];
        }
        
        if(callback)
        {
            callback(result);
        }
    }];
}


//下载数据(适合少量数据)(同步)
+ (BOOL)downloadFile:(NSString *)file withPath:(NSString *)path
{
    return [[KATHttpRequest request] downloadFile:file withUrl:[self postURLWithPath:path] replaceable:YES append:NO];
}


//下载数据(适合少量数据)(异步)
+ (void)downloadFile:(NSString *)file withPath:(NSString *)path andCallback:(void (^)(BOOL result))callback
{
    [[KATHttpRequest request] downloadFile:file withUrl:[self postURLWithPath:path] replaceable:YES append:NO andCallback:^(BOOL success)
    {
        if(callback)
        {
            callback(success);
        }
    }];
}


//断点下载数据(适合少量、大量数据)(异步)(回调方法返回YES则停止下载)
+ (void)downloadFile:(NSString *)file withPath:(NSString *)path blockSize:(long long)blockSize andCallback:(BOOL (^)(long long currentSize,long long totalSize,int status))callback
{
    KATHttpRequest *request=[KATHttpRequest request];
    
    WEAK_OBJ(request)
    
    [request downloadFile:file withUrl:[self postURLWithPath:path] blockSize:blockSize andCallback:^(long long currentSize, long long totalSize, int status)
    {
        BOOL stop=NO;
        
        if(callback)
        {
            stop=callback(currentSize, totalSize, status);
        }
        
        if(stop)
        {
            [requestWeak cancelDownload];
        }
    }];
}


#pragma mark - 内部方法

//构造GET请求的URL
+ (NSString *)getURLWithPath:(NSString *)path andData:(id)data
{
    //请求参数
    KATHashMap *query=[KATHashMap hashMap];
    [query putWithMap:[KATHashMap hashMapWithObject:data]];
    [query putWithMap:[self baseInfo]];
    
    //uri
    KATHashMap *uri=[KATHashMap hashMap];
    uri[kURIKeyScheme]=TEST_DATA.serverScheme;
    uri[kURIKeyHost]=TEST_DATA.serverHost;
    uri[kURIKeyPort]=TEST_DATA.serverPort;
    uri[kURIKeyPath]=path;
    uri[kURIKeyQuery]=query;
    
    return [KATURIParser URIWithMap:uri];
}


//构造POST请求的URL
+ (NSString *)postURLWithPath:(NSString *)path
{
    //uri
    KATHashMap *uri=[KATHashMap hashMap];
    uri[kURIKeyScheme]=TEST_DATA.serverScheme;
    uri[kURIKeyHost]=TEST_DATA.serverHost;
    uri[kURIKeyPort]=TEST_DATA.serverPort;
    uri[kURIKeyPath]=path;
    
    return [KATURIParser URIWithMap:uri];
}


//获取基础信息
+ (KATHashMap *)baseInfo
{
    KATHashMap *info=[KATHashMap hashMap];
    
    info[@"app_version"]=[KATSystemInfo systemInfo].appVersion;
    info[@"app_name"]=[KATSystemInfo systemInfo].appName;
    info[@"os_version"]=[KATSystemInfo systemInfo].osVersion;
    info[@"device"]=[KATSystemInfo systemInfo].device;
    info[@"locale"]=[KATSystemInfo systemInfo].locale;
    info[@"language"]=[KATSystemInfo systemInfo].language;
    
    return info;
}


//返回的数据key(若为nil则为self)
+ (NSString *)resultDataKey
{
    return @"data";
}


@end
