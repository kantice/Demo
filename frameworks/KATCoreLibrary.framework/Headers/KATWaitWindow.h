//
//  KATWaitWindow.h
//  KATFramework
//
//  Created by Kantice on 15/9/18.
//  Copyright (c) 2015年 KatApp. All rights reserved.
//  等待窗口，该类的方法都在主线程中执行


#import "KATPopWindow.h"
#import "KATAnimationViewDelegate.h"
#import "KATStringUtil.h"
#import "KATLabel.h"
#import "KATLoadingAnimationView.h"
#import "KATWaitingAnimationView.h"
#import "KATPieceAnimationView.h"





//等待窗口风格枚举
typedef NS_ENUM(NSUInteger, KATWaitWindowStyle)
{
    KATWaitWindowStyleLight=0,
    KATWaitWindowStyleDark,
    KATWaitWindowStyleAlpha
};




@class KATWaitWindow;


@protocol KATWaitWindowDelegate <NSObject>

@optional

///完成
- (void)waitWindow:(KATWaitWindow *)waitWindow didFinishWithValue:(int)value;


@end





@interface KATWaitWindow : KATPopWindow


#pragma -mark 属性

///提示内容
@property(nonatomic,copy) NSString *info;

///提示内容样式
@property(nonatomic,retain) KATTextStyle *infoStyle;

///窗口内容宽度
@property(nonatomic,assign) float contentWidth;

///窗口内容间距
@property(nonatomic,assign) float contentPadding;

///样式
@property(nonatomic,assign) KATWaitWindowStyle style;

///加载动画
@property(nonatomic,retain) UIView<KATAnimationViewDelegate> *animationView;

///隐藏等待时长
@property(nonatomic,assign) float hideWaitDuration;

///是否自动隐藏
@property(nonatomic,assign) BOOL isAutoHide;

///事件代理
@property(nonatomic,assign) id<KATWaitWindowDelegate> eventDelegate;




#pragma -mark 类方法

///获取实例(切片动画)
+ (instancetype)windowWithPieceAnimation:(KATPieceAnimationView *)pieceAnimation;

///获取实例(等待样式)
+ (instancetype)waitingWithStyle:(KATWaitWindowStyle)style;

///获取实例(加载样式)
+ (instancetype)loadingWithStyle:(KATWaitWindowStyle)style;

///获取实例(带文本的加载样式)
+ (instancetype)loadingWithInfo:(NSString *)info andStyle:(KATWaitWindowStyle)style;

///获取实例(全参数)
+ (instancetype)windowWithStyle:(KATWaitWindowStyle)style animationView:(UIView<KATAnimationViewDelegate> *)animationView info:(NSString *)info infoStyle:(KATTextStyle *)iStyle;


#pragma -mark 对象方法

///更新窗口
- (void)updateWindow;

///完成
- (void)finishWithValue:(int)value andMessage:(NSString *)message;

///完成
- (void)finish;

///完成
- (void)finishWithValue:(int)value;

///完成
- (void)finishWithMessage:(NSString *)message;

///调整窗口
- (void)resizeWindow;


///释放内存
- (void)dealloc;


@end



