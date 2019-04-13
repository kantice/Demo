//
//  KATIntArray.h
//  KATFramework
//
//  Created by Kantice on 13-11-18.
//  Copyright (c) 2013年 Kantice. All rights reserved.
//  存储int类型的数组


#import <Foundation/Foundation.h>


///数组最大容量
#define INT_ARRAY_CAPACITY_DEFAULT (128)

///空值
#define INT_ARRAY_VALUE_EMPTY INT_MIN


@interface KATIntArray : NSObject<NSCopying>



#pragma mark - 属性

///所存储的数组长度
@property(nonatomic,assign,readonly) int length;

///数组的最大容量
@property(nonatomic,assign,readonly) int capacity;

///数组中的最小值
@property(nonatomic,assign,readonly) int min;

///数组中的最大值
@property(nonatomic,assign,readonly) int max;

///数组中的和
@property(nonatomic,assign,readonly) long long sum;

///是否自动扩容
@property(nonatomic,assign) BOOL autoExpand;


#pragma mark - 类方法

///构造方法
+ (instancetype)intArray;

///设置数组容量的构造方法
+ (instancetype)intArrayWithCapacity:(int)capacity;


#pragma mark - 对象方法

///添加数组成员，成功则返回YES
- (BOOL)put:(int)value;

///根据索引获取数组成员，失败则返回空值
- (int)get:(int)index;

///设置成员数据
- (BOOL)set:(int)value withIndex:(int)index;

///从指定的位置插入数据，成功则返回YES
- (BOOL)put:(int)value withIndex:(int)index;

///从指定的位置添加数组，成功则返回YES
- (BOOL)putArray:(KATIntArray *)array withIndex:(int)index;

///根据range获取成员数组，失败则返回nil
- (KATIntArray *)getFormRange:(NSRange)range;

///删除数组成员，成功则返回YES
- (BOOL)deleteWithIndex:(int)index;

///替换数组成员值，成功则返回YES
- (BOOL)replaceValue:(int)value withIndex:(int)index;

///所有成员向前移动
- (void)forwardByStep:(int)step;

///所有成员向后移动
- (void)backwardByStep:(int)step;

///交换成员位置
- (BOOL)changePositionWithIndexA:(int)a andIndexB:(int)b;

///获取第一个成员
- (int)firstMember;

///获取最后一个成员
- (int)lastMember;

///获取随机的成员
- (int)randomMember;

///根据range删除数组成员，成功则返回YES
- (BOOL)deleteFromRange:(NSRange)range;

///数组排序
- (void)sort;

///数组反序
- (void)reverse;

///数组乱序洗牌
- (void)shuffle;

///清空数组
- (void)clear;

///是否已经存满
- (BOOL)isFull;

///描述
- (NSString *)description;

///数组复制
- (id)copyWithZone:(NSZone *)zone;

///内存释放
- (void)dealloc;



@end
