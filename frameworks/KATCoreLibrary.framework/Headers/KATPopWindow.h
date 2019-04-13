//
//  KATPopWindow.h
//  KATFramework
//
//  Created by Kantice on 14-8-28.
//  Copyright (c) 2014年 KatApp. All rights reserved.
//  基础弹出窗口，只充当载体，继承该类最好实现resizeWindow方法，用于横竖屏旋转时适配

#import <UIKit/UIKit.h>

#import "KATSprite.h"
#import "KATColor.h"
#import "KATAppUtil.h"


//弹窗动画类型
typedef NS_ENUM(NSUInteger, KATPopWindowAnimationType)
{
    //无动画
    KATPopWindowAnimationTypeNone=0,
    
    //平移
    KATPopWindowAnimationTypeMovingRight,
    KATPopWindowAnimationTypeMovingLeft,
    KATPopWindowAnimationTypeMovingUp,
    KATPopWindowAnimationTypeMovingDown,
    
    //快速移动(带缓冲)
    KATPopWindowAnimationTypeRunningRight,
    KATPopWindowAnimationTypeRunningLeft,
    KATPopWindowAnimationTypeRunningUp,
    KATPopWindowAnimationTypeRunningDown,
    
    //透明渐变
    KATPopWindowAnimationTypeAlpha,
    
    //缩放
    KATPopWindowAnimationTypeScale,
    
    //对焦(缩放+透明渐变)
    KATPopWindowAnimationTypeZoom,
    
    //旋转
    KATPopWindowAnimationTypeRotate,
    
    //掉落
    KATPopWindowAnimationTypeDrop,
    
    //飘落
    KATPopWindowAnimationTypeFloat,
    
    //模糊
    KATPopWindowAnimationTypeBlur,
    
    //模糊缩放
    KATPopWindowAnimationTypeBlurScale
};



@class KATPopWindow;

@protocol KATPopWindowDelegate <NSObject>

@optional

///窗口开始显示
- (void)windowWillShow:(KATPopWindow *)popWindow;

///窗口结束显示
- (void)windowDidShow:(KATPopWindow *)popWindow;

///窗口开始隐藏
- (void)windowWillHide:(KATPopWindow *)popWindow;

///窗口结束隐藏
- (void)windowDidHide:(KATPopWindow *)popWindow;

///窗口调整
- (void)windowDidResize:(KATPopWindow *)popWindow;

///窗体内容点击
- (void)windowContentTaped:(KATPopWindow *)popWindow;

///背景阴影点击
- (void)windowShadowTaped:(KATPopWindow *)popWindow;


@end



@interface KATPopWindow : UIView


#pragma -mark 属性

///屏幕尺寸
@property(nonatomic,assign) CGSize screenSize;

///阴影
@property(nonatomic,retain) UIView *shadow;

///内容
@property(nonatomic,retain,readonly) KATSprite *content;

///内容尺寸
@property(nonatomic,assign) CGSize contentSize;

///落点中心
@property(nonatomic,assign) CGPoint placement;

///圆角半径
@property(nonatomic,assign) float cornerRadius;

///背景色
@property(nonatomic,retain) UIColor *bgColor;

///阴影颜色
@property(nonatomic,retain) UIColor *shadowColor;

///显示模式
@property(nonatomic,assign) KATPopWindowAnimationType showMode;

///隐藏模式
@property(nonatomic,assign) KATPopWindowAnimationType hideMode;

///显示时间
@property(nonatomic,assign) double showDuration;

///隐藏时间
@property(nonatomic,assign) double hideDuration;

///是否已经显示
@property(nonatomic,assign,readonly) BOOL isShown;

///是否点击内容隐藏窗口
@property(nonatomic,assign) BOOL isTapContentToHide;

///是否点击阴影隐藏窗口
@property(nonatomic,assign) BOOL isTapShadowToHide;

///是否有模糊效果(初始化之前设置)
@property(nonatomic,assign) BOOL isBlurStyle;

///模糊背景视图
@property(nonatomic,retain,readonly) UIVisualEffectView *blurView;

///模糊动画视图（用于模糊进出动画）
@property(nonatomic,retain,readonly) UIVisualEffectView *blurAnimationView;

///模糊动画效果（用于模糊进出动画）
@property(nonatomic,retain,readonly) UIVisualEffect *blurEffect;

///事件代理
@property(nonatomic,assign) id<KATPopWindowDelegate> windowDelegate;


#pragma -mark 类方法

///获取实例
+ (instancetype)popWindow;


#pragma -mark 对象方法

///初始化数据
- (void)initData;

///初始化窗口
- (void)initWindow;

///调整窗口
- (void)resizeWindow;

///显示
- (void)show;

///隐藏
- (void)hide;

///抖动
- (void)shake;


///释放内存
- (void)dealloc;


@end



