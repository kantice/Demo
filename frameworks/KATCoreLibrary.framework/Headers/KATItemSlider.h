//
//  KATItemSlider.h
//  KATFramework
//
//  Created by Kantice on 16/6/23.
//  Copyright © 2016年 KatApp. All rights reserved.
//  带滑块的项目进度条


#import "KATSprite.h"
#import "KATProgressBar.h"
#import "KATProgressItem.h"
#import "KATStringUtil.h"



@class KATItemSlider;

@protocol KATItemSliderDelegate <NSObject>

@optional

///值改变
- (void)itemSliderValueChanged:(KATItemSlider *)slider;

///滑动结束
- (void)itemSliderEnded:(KATItemSlider *)slider;

///点击事件
- (void)itemSliderTaped:(KATItemSlider *)slider;


@end



@interface KATItemSlider : KATSprite


#pragma -mark 属性

///是否自适应字体
@property(nonatomic,assign) BOOL autoAdjustFont;

///数值标签
@property(nonatomic,retain) UILabel *valueLabel;

///小数点精度(0~3)
@property(nonatomic,assign) int accuracy;

///当前值(百分比)
@property(nonatomic,assign,readonly) double value;

///进度条
@property(nonatomic,retain) KATProgressBar *bar;

///滑块
@property(nonatomic,retain) KATSprite *slider;

///最大值
@property(nonatomic,assign) double maxValue;

///当前值
@property(nonatomic,assign) double currentValue;

///前缀
@property(nonatomic,copy) NSString *prefix;

///后缀
@property(nonatomic,copy) NSString *suffix;

///item数组
@property(nonatomic,retain) KATArray<__kindof KATProgressItem *> *items;

///项目索引
@property(nonatomic,assign,readonly) int itemIndex;

///当前项目
@property(nonatomic,retain) KATProgressItem *currentItem;

///事件代理
@property(nonatomic,assign) id<KATItemSliderDelegate> eventDelegate;


#pragma -mark 类方法

///获取实例(默认值)
+ (instancetype)itemSliderWithFrame:(CGRect)frame;

///获取实例(配置进度条高度、滑块宽度、圆角)
+ (instancetype)itemSliderWithFrame:(CGRect)frame andBarHeight:(float)barHeight andSliderWidth:(float)sliderWidth cornerRadius:(float)sliderRadius;


#pragma -mark 对象方法

///加载项目
- (void)loadItems:(KATArray<__kindof KATProgressItem *> *)items;

///设置数值(百分比)
- (void)progressWithValue:(double)value animated:(BOOL)animated;

///设置当前值
- (void)progressWithCurrentValue:(double)value animated:(BOOL)animated;

///通过item的tag设置值
- (void)progressWithItemTag:(long long)tag animated:(BOOL)animated;

///通过item的index设置值
- (void)progressWithItemIndex:(int)index animated:(BOOL)animated;


///释放内存
- (void)dealloc;



@end


