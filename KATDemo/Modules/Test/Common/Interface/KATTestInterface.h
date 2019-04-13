//
//  KATTestInterface.h
//  KATDemo
//
//  Created by kAt on 2019/2/21.
//  Copyright © 2019 Kantice. All rights reserved.
//  网络接口访问

#import <Foundation/Foundation.h>
#import "TestMacros.h"


@interface KATTestInterface : NSObject

///GET方式请求接口(同步)
+ (KATHashMap *)getData:(id)data withPath:(NSString *)path;

///GET方式请求接口(异步)
+ (void)getData:(id)data withPath:(NSString *)path andCallback:(void (^)(KATHashMap *result))callback;

///POST方式请求接口(同步)
+ (KATHashMap *)postData:(id)data withPath:(NSString *)path;

///POST方式请求接口(异步)
+ (void)postData:(id)data withPath:(NSString *)path andCallback:(void (^)(KATHashMap *result))callback;

///表单方式请求接口(同步)
+ (KATHashMap *)postFormData:(id)data withPath:(NSString *)path;

///表单方式请求接口(异步)
+ (void)postFormData:(id)data withPath:(NSString *)path andCallback:(void (^)(KATHashMap *result))callback;

///上传数据(同步)
+ (KATHashMap *)uploadFile:(NSString *)file withPath:(NSString *)path andName:(NSString *)name;

///上传数据(异步)
+ (void)uploadFile:(NSString *)file withPath:(NSString *)path andName:(NSString *)name andCallback:(void (^)(KATHashMap *result))callback;

///下载数据(适合少量数据)(同步)
+ (BOOL)downloadFile:(NSString *)file withPath:(NSString *)path;

///下载数据(适合少量数据)(异步)
+ (void)downloadFile:(NSString *)file withPath:(NSString *)path andCallback:(void (^)(BOOL result))callback;

///断点下载数据(适合少量、大量数据)(异步)(回调方法返回YES则停止下载)
+ (void)downloadFile:(NSString *)file withPath:(NSString *)path blockSize:(long long)blockSize andCallback:(BOOL (^)(long long currentSize,long long totalSize,int status))callback;

@end

