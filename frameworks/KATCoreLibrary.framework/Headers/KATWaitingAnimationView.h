//
//  KATWaitingAnimationView.h
//  KATFramework
//
//  Created by Yi Yu on 2017/5/24.
//  Copyright © 2017年 KatApp. All rights reserved.
//  旋转等待动画视图


#import "KATSprite.h"
#import "KATShapeUtil.h"
#import "KATAnimationViewDelegate.h"




@interface KATWaitingAnimationView : KATSprite <KATAnimationViewDelegate>


#pragma -mark 属性

///圆环
@property(nonatomic,retain) KATShape *ringShape;

///旋转一周时长
@property(nonatomic,assign) double cycleDuration;

///圆环缺口(0~1)
@property(nonatomic,assign) float ringCut;


#pragma -mark 类方法

///获取实例
+ (instancetype)animationWithFrame:(CGRect)frame;


#pragma -mark 对象方法

///复位
- (void)restore;

///播放
- (void)play;

//重新播放
- (void)replay;

///停止
- (void)stop;


///释放内存
- (void)dealloc;


@end
