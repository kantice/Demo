//
//  KATRangeSlider.h
//  KATFramework
//
//  Created by Kantice on 16/6/24.
//  Copyright © 2016年 KatApp. All rights reserved.
//  范围选择滑块

#import "KATSprite.h"
#import "KATProgressBar.h"
#import "KATProgressItem.h"
#import "KATShapeUtil.h"
#import "KATStringUtil.h"



@class KATRangeSlider;

@protocol KATRangeSliderDelegate <NSObject>

@optional

///值改变
- (void)rangeSliderValueChanged:(KATRangeSlider *)slider;

///滑动结束
- (void)rangeSliderEnded:(KATRangeSlider *)slider;

///点击事件
- (void)rangeSliderTaped:(KATRangeSlider *)slider;


@end



@interface KATRangeSlider : KATSprite


#pragma -mark 属性

///是否自适应字体
@property(nonatomic,assign) BOOL autoAdjustFont;

///左标签
@property(nonatomic,retain) UILabel *topLabel;

///右标签
@property(nonatomic,retain) UILabel *bottomLabel;

///小数点精度(0~3)
@property(nonatomic,assign) int accuracy;

///当前左值(百分比)
@property(nonatomic,assign,readonly) double leftValue;

///当前右值(百分比)
@property(nonatomic,assign,readonly) double rightValue;

///当前上值(百分比)
@property(nonatomic,assign,readonly) double topValue;

///当前下值(百分比)
@property(nonatomic,assign,readonly) double bottomValue;

///进度条
@property(nonatomic,retain) KATProgressBar *bar;

///左滑块
@property(nonatomic,retain) KATSprite *topSlider;

///右滑块
@property(nonatomic,retain) KATSprite *bottomSlider;

///左滑块气泡
@property(nonatomic,retain) KATShape *topBubble;

///右滑块气泡
@property(nonatomic,retain) KATShape *bottomBubble;

///最大值
@property(nonatomic,assign) double maxValue;

///当前左值
@property(nonatomic,assign,readonly) double currentLeftValue;

///当前右值
@property(nonatomic,assign,readonly) double currentRightValue;

///当前上值
@property(nonatomic,assign,readonly) double currentTopValue;

///当前下值
@property(nonatomic,assign,readonly) double currentBottomValue;

///前缀
@property(nonatomic,copy) NSString *prefix;

///后缀
@property(nonatomic,copy) NSString *suffix;

///item数组
@property(nonatomic,retain) KATArray<__kindof KATProgressItem *> *items;

///上项目索引
@property(nonatomic,assign,readonly) int topIndex;

///下项目索引
@property(nonatomic,assign,readonly) int bottomIndex;

///上项目
@property(nonatomic,retain) KATProgressItem *topItem;

///下项目
@property(nonatomic,retain) KATProgressItem *bottomItem;

///左项目
@property(nonatomic,retain) KATProgressItem *leftItem;

///右项目
@property(nonatomic,retain) KATProgressItem *rightItem;

///事件代理
@property(nonatomic,assign) id<KATRangeSliderDelegate> eventDelegate;


#pragma -mark 类方法

///获取实例(默认值)
+ (instancetype)rangeSliderWithFrame:(CGRect)frame;

///获取实例(配置进度条高度、滑块宽度、圆角)
+ (instancetype)rangeSliderWithFrame:(CGRect)frame andBarHeight:(float)barHeight andSliderWidth:(float)sliderWidth cornerRadius:(float)sliderRadius padding:(float)padding;


#pragma -mark 对象方法

///加载项目
- (void)loadItems:(KATArray<__kindof KATProgressItem *> *)items;

///设置数值(百分比)
- (void)progressWithTopValue:(double)topValue bottomValue:(double)bottomValue animated:(BOOL)animated;

///设置当前值
- (void)progressWithCurrentTopValue:(double)topValue bottomValue:(double)bottomValue animated:(BOOL)animated;

///通过item的tag设置值
- (void)progressWithTopItemTag:(long long)topTag bottomItemTag:(long long)bottomTag animated:(BOOL)animated;

///通过item的index设置值
- (void)progressWithTopItemIndex:(int)topIndex bottomItemIndex:(int)bottomIndex animated:(BOOL)animated;

///释放内存
- (void)dealloc;



@end



