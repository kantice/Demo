//
//  KATSpotlight.h
//  KATFramework
//
//  Created by Yi Yu on 2018/4/24.
//  Copyright © 2018年 KatApp. All rights reserved.
//  聚光灯，用于聚焦显示


#import "KATSprite.h"
#import "KATShapeUtil.h"



@class KATSpotlight;

@protocol KATSpotlightDelegate <NSObject>

@optional

///聚光灯显示完成
- (void)spotlightDidShow:(KATSpotlight *)spotlight;

///聚光灯隐藏完成
- (void)spotlightDidHide:(KATSpotlight *)spotlight;

///聚光灯背景阴影点击
- (void)spotlightShadowTaped:(KATSpotlight *)spotlight;


@end



@interface KATSpotlight : KATSprite


#pragma -mark 属性

///显示时长
@property(nonatomic,assign) double showDuration;

///隐藏时长
@property(nonatomic,assign) double hideDuration;

///是否点击阴影隐藏
@property(nonatomic,assign) BOOL isTapShadowToHide;

///是否已经显示
@property(nonatomic,assign,readonly) BOOL isShown;

///阴影
@property(nonatomic,retain,readonly) UIView *shadow;

///事件代理
@property(nonatomic,assign) id<KATSpotlightDelegate> eventDelegate;


#pragma -mark 类方法

///通用方法获取实例(Views为覆盖层)
+ (instancetype)spotlightWithShapes:(KATArray<KATShape *> *)shapes andViews:(KATArray<UIView *> *)views;

///通过目标视图数组获取实例(以目标Frame做圆角矩形,Views为覆盖层)
+ (instancetype)spotlightWithTargets:(KATArray<UIView *> *)targets padding:(double)padding cornerRadius:(double)cornerRadius andViews:(KATArray<UIView *> *)views;

///通过目标视图获取实例(以目标Frame做圆角矩形,View为覆盖层)
+ (instancetype)spotlightWithTarget:(UIView *)target padding:(double)padding cornerRadius:(double)cornerRadius andView:(UIView *)view;


#pragma -mark 对象方法

///显示聚光灯
- (void)show;

///隐藏聚光灯
- (void)hide;

@end
