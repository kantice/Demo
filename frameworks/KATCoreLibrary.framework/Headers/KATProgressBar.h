//
//  KATProgressBar.h
//  KATFramework
//
//  Created by Kantice on 16/6/17.
//  Copyright © 2016年 KatApp. All rights reserved.
//  进度条

#import <UIKit/UIKit.h>
#import "KATSprite.h"
#import "KATColor.h"
#import "KATShapeUtil.h"


@interface KATProgressBar : KATSprite

#pragma -mark 属性

///左数值
@property(nonatomic,assign,readonly) double leftValue;

///右数值
@property(nonatomic,assign,readonly) double rightValue;

///最长动画时长
@property(nonatomic,assign) double animationDuration;

///背景条
@property(nonatomic,retain) KATShape *bgBar;

///前景条
@property(nonatomic,retain) KATShape *frontBar;

///前景容器(用于裁剪前景条)
//@property(nonatomic,retain) UIView *frontContanier;

///颜色(KATColor)
@property(nonatomic,assign) int color;

///是否有圆角
@property(nonatomic,assign) BOOL hasRoundCorner;

///背景色透明度
@property(nonatomic,assign) double bgColorAlpha;

///前景条缩进
@property(nonatomic,assign) double frontIndent;

///开始点x
@property(nonatomic,assign,readonly) double startPointX;

///宽度
@property(nonatomic,assign,readonly) double width;


#pragma -mark 类方法

///获取实例
+ (instancetype)progressBarWithFrame:(CGRect)frame;


#pragma -mark 对象方法

///设置左右值
- (void)progressWithLeftValue:(double)leftValue rightValue:(double)rightValue animated:(BOOL)animated;

///设置右数值，左数值为0
- (void)progressWithValue:(double)value animated:(BOOL)animated;

///刷新
- (void)updateBar;


///释放内存
- (void)dealloc;




@end




