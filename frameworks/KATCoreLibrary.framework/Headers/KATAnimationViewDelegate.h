//
//  KATAnimationViewDelegate.h
//  KATFramework
//
//  Created by Yi Yu on 2017/5/23.
//  Copyright © 2017年 KatApp. All rights reserved.
//  动画视图协议


//动画完成值枚举
typedef NS_ENUM(NSUInteger, KATAnimationFinishValue)
{
    KATAnimationFinishValueSuccess=0,
    KATAnimationFinishValueFail,
    KATAnimationFinishValueOther
};


@protocol KATAnimationViewDelegate <NSObject>

@required

///播放（恢复）
- (void)play;

///停止
- (void)stop;


@optional

///重新播放
- (void)replay;

///结束
- (void)finishWithValue:(KATAnimationFinishValue)value;


@end



