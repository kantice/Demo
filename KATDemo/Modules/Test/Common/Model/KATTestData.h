//
//  KATTestData.h
//  KATDemo
//
//  Created by kAt on 2018/8/27.
//  Copyright © 2018年 Kantice. All rights reserved.
//  测试数据


#import <Foundation/Foundation.h>


@interface KATTestData : NSObject


///编号
@property(nonatomic,assign) int index;

///名称
@property(nonatomic,copy) NSString *name;

///描述
@property(nonatomic,copy) NSString *summary;

///是否标记
@property(nonatomic,assign) BOOL isMarked;


///便利构造方法，获取默认数据
+ (instancetype)data;


@end
