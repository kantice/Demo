//
//  KATCycleAnimationView.h
//  KATFramework
//
//  Created by Kantice on 2017/5/2.
//  Copyright © 2017年 KatApp. All rights reserved.
//  循环移动动画

#import "KATSprite.h"
#import "KATAnimationViewDelegate.h"
#import "KATImageUtil.h"



@interface KATCycleAnimationView : UIView <KATAnimationViewDelegate>


#pragma -mark 属性

///是否为垂直方向移动(初始化后不能修改)
@property(nonatomic,assign,readonly) BOOL isMovingVertical;

///是否为后退移动(右、上为后退方向，左、下为前进方向)
@property(nonatomic,assign) BOOL isMovingBackward;

///每帧的位移距离
@property(nonatomic,assign) double frameDistance;

///帧间隔
@property(nonatomic,assign) int frameInterval;


#pragma -mark 类方法

/**
 获取实例

 @param frame 动画控件的Frame
 @param content 位移动画的内容
 @param distance 每次的位移距离
 @param vertical 是否为垂直方向移动(初始化后不能修改)
 @return 实例
 */
+ (instancetype)animationWithFrame:(CGRect)frame content:(UIView *)content distance:(double)distance andVertical:(BOOL)vertical;


/**
 获取实例

 @param frame 动画控件的Frame
 @param content 位移动画的内容
 @param interval 每次动画的间隔
 @param distance 每次的位移距离
 @param vertical 是否为垂直方向移动(初始化后不能修改)
 @return 实例
 */
+ (instancetype)animationWithFrame:(CGRect)frame content:(UIView *)content interval:(int)interval distance:(double)distance andVertical:(BOOL)vertical;


/**
 获取实例
 
 @param frame 动画控件的Frame
 @param image 位移动画的图片
 @param size 图片尺寸
 @param bias 图片尺寸偏移量(解决衔接问题)
 @param interval 每次动画的间隔
 @param distance 每次的位移距离
 @param vertical 是否为垂直方向移动(初始化后不能修改)
 @return 实例
 */
+ (instancetype)animationWithFrame:(CGRect)frame image:(UIImage *)image size:(CGSize)size bias:(float)bias interval:(int)interval distance:(double)distance andVertical:(BOOL)vertical;


#pragma -mark 对象方法

///播放（恢复）
- (void)play;

//重新播放
- (void)replay;

///停止
- (void)stop;

///释放内存
- (void)dealloc;



@end
