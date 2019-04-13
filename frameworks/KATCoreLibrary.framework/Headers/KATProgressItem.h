//
//  KATProgressItem.h
//  KATFramework
//
//  Created by Kantice on 16/6/21.
//  Copyright © 2016年 KatApp. All rights reserved.
//  进度项目

#import <Foundation/Foundation.h>

@interface KATProgressItem : NSObject

#pragma -mark 属性

///显示的标签内容(nil则显示数值)
@property(nonatomic,copy) NSString *text;

///显示的颜色(无颜色则显示默认颜色)
@property(nonatomic,assign) int color;

///索引
@property(nonatomic,assign) int index;

///携带的int值
@property(nonatomic,assign) long long tag;

///携带的double值
@property(nonatomic,assign) double value;

///携带的字符串值
@property(nonatomic,copy) NSString *message;

///携带的id值
@property(nonatomic,retain) id object;


#pragma -mark 类方法

///获取实例
+ (instancetype)itemWithText:(NSString *)text andColor:(int)color;


#pragma -mark 对象方法

///释放内存
- (void)dealloc;

@end
