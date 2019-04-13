//
//  KATItemRing.h
//  KATFramework
//
//  Created by Kantice on 16/6/21.
//  Copyright © 2016年 KatApp. All rights reserved.
//  显示项目或数值的进度环

#import "KATProgressRing.h"
#import "KATArray.h"
#import "KATProgressItem.h"



@interface KATItemRing : KATProgressRing

#pragma -mark 属性

///数值标签
@property(nonatomic,retain) UILabel *valueLabel;

///当前值(百分比)
@property(nonatomic,assign,readonly) double value;

///小数点精度(0~3)
@property(nonatomic,assign) int accuracy;

///显示的文本行数
@property(nonatomic,assign) int lines;

///字体尺寸
@property(nonatomic,assign) float fontSize;

///最大值
@property(nonatomic,assign) double maxValue;

///当前值
@property(nonatomic,assign,readonly) double currentValue;

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


#pragma -mark 类方法

///获取实例
+ (instancetype)itemRingWithFrame:(CGRect)frame;


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

///刷新
- (void)updateRing;


///释放内存
- (void)dealloc;


@end
