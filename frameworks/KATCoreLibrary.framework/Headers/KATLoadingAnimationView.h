//
//  KATLoadingAnimationView.h
//  KATFramework
//
//  Created by Kantice on 16/6/22.
//  Copyright © 2016年 KatApp. All rights reserved.
//  加载动画

#import "KATSprite.h"
#import "KATShapeUtil.h"
#import "KATAnimationViewDelegate.h"


#define LOADING_ANIMATION_STATUS_INIT 0
#define LOADING_ANIMATION_STATUS_READY 1
#define LOADING_ANIMATION_STATUS_START 2
#define LOADING_ANIMATION_STATUS_STOP 3
#define LOADING_ANIMATION_STATUS_FINISH 4


@interface KATLoadingAnimationView : KATSprite <KATAnimationViewDelegate>


#pragma -mark 属性

///圆环
@property(nonatomic,retain) KATShape *ringShape;

///成功标志
@property(nonatomic,retain) KATShape *successShape;

///失败标志
@property(nonatomic,retain) KATShape *failShape;

///旋转一周时长
@property(nonatomic,assign) double cycleDuration;

///圆环缺口(0~1)
@property(nonatomic,assign) float ringCut;

///状态
@property(nonatomic,assign,readonly) int status;


#pragma -mark 类方法

///获取实例
+ (instancetype)animationWithFrame:(CGRect)frame;


#pragma -mark 对象方法

///复位
- (void)restore;

///成功
- (void)success;

///失败
- (void)fail;

///播放
- (void)play;

///停止
- (void)stop;

//重新播放
- (void)replay;

///完成
- (void)finishWithValue:(KATAnimationFinishValue)value;


///释放内存
- (void)dealloc;


@end
