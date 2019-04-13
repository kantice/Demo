//
//  KATPercentRing.h
//  KATFramework
//
//  Created by Kantice on 16/6/21.
//  Copyright © 2016年 KatApp. All rights reserved.
//  显示百分比的进度圆环

#import "KATProgressRing.h"




@interface KATPercentRing : KATProgressRing

#pragma -mark 属性

///数值标签
@property(nonatomic,retain) UILabel *valueLabel;

///符号标签
@property(nonatomic,retain) UILabel *symbolLabel;

///小数点精度(0~3)
@property(nonatomic,assign) int accuracy;

///当前值
@property(nonatomic,assign,readonly) double value;


#pragma -mark 类方法

///获取实例
+ (instancetype)percentRingWithFrame:(CGRect)frame;


#pragma -mark 对象方法

///设置数值
- (void)progressWithValue:(double)value animated:(BOOL)animated;

///刷新
- (void)updateRing;


///释放内存
- (void)dealloc;


@end
