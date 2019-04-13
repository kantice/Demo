//
//  KATReplicatorSprite.h
//  KATFramework
//
//  Created by Yi Yu on 2017/5/15.
//  Copyright © 2017年 KatApp. All rights reserved.
//  复制变换效果的Sprite，作为容器


#import "KATSprite.h"



@interface KATReplicatorSprite : KATSprite

///复制的次数
@property(nonatomic,assign) int replicatorCount;

///复制的变化
@property(nonatomic,assign) CATransform3D replicatorTransform;

///复制的红色通道偏移
@property(nonatomic,assign) float replicatorRedOffset;

///复制的绿色通道偏移
@property(nonatomic,assign) float replicatorGreenOffset;

///复制的蓝色通道偏移
@property(nonatomic,assign) float replicatorBlueOffset;

///复制的透明通道偏移
@property(nonatomic,assign) float replicatorAlphaOffset;


/**
 获取实例(全参数)
 
 @param count 数量
 @param transform 变形
 @param red 红色偏移量
 @param green 绿色偏移量
 @param blue 蓝色偏移量
 @param alpha 透明度偏移量
 @return 实例
 */
+ (instancetype)replicatorSpriteWithCount:(int)count transform:(CATransform3D)transform andColorOffsetRed:(float)red green:(float)green blue:(float)blue alpha:(float)alpha;


///初始化复制子
- (void)initReplicator;



@end
