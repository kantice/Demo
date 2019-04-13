//
//  KATPieceAnimationView.h
//  KATFramework
//
//  Created by Yi Yu on 2017/5/16.
//  Copyright © 2017年 KatApp. All rights reserved.
//  大图切片contents动画



#import "KATSprite.h"
#import "KATAnimationViewDelegate.h"



@class KATPieceAnimationView;


//切片动画代理
@protocol KATPieceAnimationViewDelegate <NSObject>

@optional

//切片动画播放完成(自然播放完成，非手动停止)
- (void)pieceAnimationFinished:(KATPieceAnimationView *)anim;

@end




@interface KATPieceAnimationView : KATSprite <KATAnimationViewDelegate>


///帧数间隔(每几帧变化一次)
@property(nonatomic,assign) int pieceFrameInverval;

///播放次数(小于等于0则无限次)
@property(nonatomic,assign) int playTimes;

///事件代理
@property(nonatomic,assign) id<KATPieceAnimationViewDelegate> eventDelegate;




///获取实例(简化构造方法)
+ (instancetype)animationWithImage:(UIImage *)image rows:(int)rows columns:(int)columns;


/**
 获取实例

 @param image 显示的大图
 @param rows 切片行数
 @param columns 切片列数
 @param count 切片数
 @param interval 帧数间隔(每几帧变化一次)
 @param times 重复播放次数
 @return 实例
 */
+ (instancetype)animationWithImage:(UIImage *)image rows:(int)rows columns:(int)columns count:(int)count interval:(int)interval andPlayTimes:(int)times;


/**
 获取实例
 
 @param image 显示的大图
 @param rows 切片行数
 @param columns 切片列数
 @param pieces 切片数组
 @param interval 帧数间隔(每几帧变化一次)
 @param times 重复播放次数
 @return 实例
 */
+ (instancetype)animationWithImage:(UIImage *)image rows:(int)rows columns:(int)columns pieces:(NSArray <NSNumber *> *)pieces interval:(int)interval andPlayTimes:(int)times;

/**
 获取实例
 
 @param image 显示的大图
 @param size 显示的尺寸
 @param rows 切片行数
 @param columns 切片列数
 @param pieces 切片数组
 @param interval 帧数间隔(每几帧变化一次)
 @param times 重复播放次数
 @return 实例
 */
+ (instancetype)animationWithImage:(UIImage *)image size:(CGSize)size rows:(int)rows columns:(int)columns pieces:(NSArray <NSNumber *> *)pieces interval:(int)interval andPlayTimes:(int)times;


///重新播放
- (void)replay;

///播放（继续播放）
- (void)play;

///停止
- (void)stop;

///显示某一帧
- (void)displayPieceWithIndex:(int)index;


///释放内存
- (void)dealloc;


@end
