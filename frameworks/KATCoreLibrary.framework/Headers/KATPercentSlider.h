//
//  KATPercentSlider.h
//  KATFramework
//
//  Created by Kantice on 16/6/23.
//  Copyright © 2016年 KatApp. All rights reserved.
//  带滑块的百分比进度条


#import "KATSprite.h"
#import "KATProgressBar.h"



@class KATPercentSlider;

@protocol KATPercentSliderDelegate <NSObject>

@optional

///值改变
- (void)percentSilderValueChanged:(KATPercentSlider *)slider;

///滑动结束
- (void)percentSilderEnded:(KATPercentSlider *)slider;

@end




@interface KATPercentSlider : KATSprite


#pragma -mark 属性

///数值标签
@property(nonatomic,retain) UILabel *valueLabel;

///符号标签
@property(nonatomic,retain) UILabel *symbolLabel;

///小数点精度(0~3)
@property(nonatomic,assign) int accuracy;

///当前值
@property(nonatomic,assign,readonly) double value;

//最大值
@property(nonatomic,assign) double maxValue;

///进度条
@property(nonatomic,retain) KATProgressBar *bar;

///滑块
@property(nonatomic,retain) KATSprite *slider;

///事件代理
@property(nonatomic,assign) id<KATPercentSliderDelegate> eventDelegate;


#pragma -mark 类方法

///获取实例
+ (instancetype)percentSliderWithFrame:(CGRect)frame;


#pragma -mark 对象方法

///设置数值
- (void)progressWithValue:(double)value animated:(BOOL)animated;

///释放内存
- (void)dealloc;


@end




