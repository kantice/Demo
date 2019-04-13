//
//  KATProgressRing.h
//  KATFramework
//
//  Created by Kantice on 16/6/20.
//  Copyright © 2016年 KatApp. All rights reserved.
//  进度环

#import <UIKit/UIKit.h>
#import "KATSprite.h"
#import "KATColor.h"
#import "KATShapeUtil.h"



@interface KATProgressRing : KATSprite

#pragma -mark 属性

///起点数值(百分比)
@property(nonatomic,assign,readonly) double startValue;

///终点数值(百分比)
@property(nonatomic,assign,readonly) double endValue;

///开始角度
@property(nonatomic,assign) double startAngle;

///结束角度
@property(nonatomic,assign) double endAngle;

///总角度
@property(nonatomic,assign,readonly) double totalAngle;

///中点角度(圆弧分割点)
//@property(nonatomic,assign,readonly) double middleAngle;

///蒙板起始角度
//@property(nonatomic,assign,readonly) double maskStartAngle;

///是否为顺时针旋转
@property(nonatomic,assign) BOOL clockwise;

///最长动画时长
@property(nonatomic,assign) double animationDuration;

///背景环
@property(nonatomic,retain) KATShape *bgRing;

///前景环
@property(nonatomic,retain) KATShape *frontRing;

/////前景环1
//@property(nonatomic,retain) KATShape *frontRing1;
//
/////前景蒙版1(用于裁剪前景环1)
//@property(nonatomic,retain) UIView *frontMask1;
//
/////前景环2
//@property(nonatomic,retain) KATShape *frontRing2;
//
/////前景蒙版2(用于裁剪前景环2)
//@property(nonatomic,retain) UIView *frontMask2;

///颜色(KATColor)
@property(nonatomic,assign) int color;

///环宽度与控件半径的比例比例(1.0为圆)
@property(nonatomic,assign) double ringWidth;

///环半径
@property(nonatomic,assign) double ringRadius;

///背景色透明度
@property(nonatomic,assign) double bgColorAlpha;

///前景环缩进
@property(nonatomic,assign) double frontIndent;



#pragma -mark 类方法

///获取实例
+ (instancetype)progressRingWithFrame:(CGRect)frame;

///通过设置参数获取实例
+ (instancetype)progressRingWithFrame:(CGRect)frame startAngle:(double)startAngle endAngle:(double)endAngle clockwise:(BOOL)clockwise;


#pragma -mark 对象方法

///设置数值
- (void)progressWithStartValue:(double)startValue endValue:(double)endValue animated:(BOOL)animated;

///设置结束数值
- (void)progressWithValue:(double)value animated:(BOOL)animated;

///刷新
- (void)updateRing;


///释放内存
- (void)dealloc;




@end
