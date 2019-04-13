//
//  KATReflection.h
//  KATFramework
//
//  Created by Yi Yu on 2017/5/15.
//  Copyright © 2017年 KatApp. All rights reserved.
//  倒影容器，初始化frame之后不能改变，地平线为中点水平线，地平线之上为真实内容，地平线之下为倒影，子视图在地平线之下则不显示



#import "KATReplicatorSprite.h"




@interface KATReflection : KATReplicatorSprite


///获取实例
+ (instancetype)reflectionWithFrame:(CGRect)frame;


/**
 获取实例(全参数)

 @param frame Frame
 @param alpha 倒影的透明度
 @param angle 倒影的角度(cos(angle),M_PI为完全倒影)
 @param gradient 倒影的渐变值，小于等于0则无渐变效果，渐变从bound.size.height／2开始到bound.size.height结束，1.0为纯透明控制点的位置在bound.size.height的位置上，0.0则在bound.size.height/2的位置
 @return 实例
 */
+ (instancetype)reflectionWithFrame:(CGRect)frame alpha:(float)alpha angle:(float)angle gradient:(float)gradient;


@end
