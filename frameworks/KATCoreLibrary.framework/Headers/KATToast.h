//
//  KATToast.h
//  KATFramework
//
//  Created by Kantice on 16/2/20.
//  Copyright © 2016年 KatApp. All rights reserved.
//  吐司


#import <UIKit/UIKit.h>
#import "KATLabel.h"
#import "KATSprite.h"
#import "KATButton.h"


#define TOAST_POSITION_BOTTOM 0
#define TOAST_POSITION_CENTER 1
#define TOAST_POSITION_TOP 2

#define TOAST_BUTTON_POSITION_TOP 0
#define TOAST_BUTTON_POSITION_LEFT 1
#define TOAST_BUTTON_POSITION_RIGHT


#define TOAST_DURATION_EXTREME_SHORT 2.0f
#define TOAST_DURATION_SHORT 3.5f
#define TOAST_DURATION_NORMAL 5.0f
#define TOAST_DURATION_LONG 8.0f
#define TOAST_DURATION_EXTREME_LONG 14.0f



@interface KATToast : KATSprite
{
    BOOL _showing;//动画进行状态（防止重复）
    BOOL _hiding;//动画进行状态（防止重复）
}


#pragma -mark 属性

///按钮类型(默认为None，不带按钮)(按钮大小和线宽自适应)
@property(nonatomic,assign) KATButtonType buttonType;

///按钮颜色(默认为白色)
@property(nonatomic,retain) UIColor *buttonColor;

///文本内容
@property(nonatomic,copy) NSString *text;

///内容样式
@property(nonatomic,retain) KATTextStyle *style;

///位置
@property(nonatomic,assign) int position;

///持续时长
@property(nonatomic,assign) float duration;

///是否可点击
@property(nonatomic,assign) BOOL canTap;

///内容最大宽度
@property(nonatomic,assign) float contentWidth;

///内容间距
@property(nonatomic,assign) float contentPadding;





#pragma -mark 类方法

///获取实例
+ (instancetype)toast;

///获取实例
+ (instancetype)toastWithButton:(KATButtonType)type;

///获取实例
+ (instancetype)toastWithButton:(KATButtonType)type andText:(NSString *)text;

///获取实例
+ (instancetype)toastWithText:(NSString *)text;

///获取实例
+ (instancetype)toastWithText:(NSString *)text andDuration:(float)duration;

///获取实例
+ (instancetype)toastWithText:(NSString *)text andStyle:(KATTextStyle *)style;

///获取实例（全参数）
+ (instancetype)toastWithButton:(KATButtonType)type text:(NSString *)text style:(KATTextStyle *)style duration:(float)duration andPosition:(int)position;


#pragma -mark 对象方法

///更新
- (void)update;

///显示
- (void)show;

///隐藏
- (void)hide;


///释放内存
- (void)dealloc;


@end

