//
//  KATShapeButton.h
//  KATFramework
//
//  Created by Kantice on 16/3/20.
//  Copyright © 2016年 KatApp. All rights reserved.
//  形状按钮

#import <UIKit/UIKit.h>
#import "KATButton.h"
#import "KATShapeUtil.h"
#import "KATSprite.h"
#import "KATColor.h"
#import "KATStringUtil.h"


#define SBUTTON_CUSTOM 0
#define SBUTTON_ROUND 1
#define SBUTTON_RECT 2
#define SBUTTON_RECT_R 3
#define SBUTTON_OVAL 4
#define SBUTTON_DIAMOND 5


#define SBUTTON_STATE_UNCHECKED 0
#define SBUTTON_STATE_CHECKED 1
#define SBUTTON_STATE_BLINK 2

#define SBUTTON_TAP_ACTION_NONE 0
#define SBUTTON_TAP_ACTION_BLINK 1
#define SBUTTON_TAP_ACTION_CHECK 2
#define SBUTTON_TAP_ACTION_SCALE 3



@class KATShapeButton;

@protocol KATShapeButtonDelegate <NSObject>

@optional

///按钮点击
- (void)shapeButtonTaped:(KATShapeButton *)button;

///按钮长按
- (void)shapeButtonPressed:(KATShapeButton *)button;

@end



@interface KATShapeButton : KATSprite <KATSpriteDelegate>


#pragma -mark 属性

///携带的int值
@property(nonatomic,assign) long index;

///携带的消息
@property(nonatomic,retain) NSString *message;

///是否选中(只读)
@property(nonatomic,assign,readonly) BOOL checked;

///是否被禁用(只读)
@property(nonatomic,assign,readonly) BOOL disabled;

///禁用透明度
@property(nonatomic,assign) float disabledAlpha;

///颜色(线色)
@property(nonatomic,retain) UIColor *color;

///高亮色(为空时则使用线色)(默认为白色)
@property(nonatomic,retain) UIColor *lightColor;

///填充色(默认为线色)
@property(nonatomic,retain) UIColor *fillColor;

///背景色(未选中的填充色)(默认为透明)
@property(nonatomic,retain) UIColor *bgColor;

///标签
@property(nonatomic,retain) UILabel *label;

///按钮
@property(nonatomic,retain) KATButton *button;

///形状
@property(nonatomic,retain) KATShape *shape;

///状态
@property(nonatomic,assign) int state;

///点击动作类型（闪烁、选中或无动作）
@property(nonatomic,assign) int tapAction;

///闪烁时长
@property(nonatomic,assign) double blinkDuration;

///选中取消时长(隐式动画，无法设置)
@property(nonatomic,assign) double checkDuration;

///缩放时长
@property(nonatomic,assign) double scaleDuration;

///缩放尺寸(1.0为原始尺寸)
@property(nonatomic,assign) double scaleSize;

///点击事件代理
@property(nonatomic,assign) id<KATShapeButtonDelegate> eventDelegate;



#pragma -mark 类方法

///通过类型获取实例(带标签(nil则无)或按钮(KATButtonNone则无))
+ (instancetype)buttonWithFrame:(CGRect)frame andType:(int)type andColor:(UIColor *)color andLabel:(NSString *)label andButton:(KATButtonType)button;


///通过形状获取实例(带标签(nil则无)或按钮(KATButtonNone则无))
+ (instancetype)buttonWithFrame:(CGRect)frame andShape:(KATShape *)shape andColor:(UIColor *)color andLabel:(NSString *)label andButton:(KATButtonType)button;


#pragma -mark 对象方法

///添加按钮（添加过之后，则修改）
- (void)addButton:(KATButtonType)button;

///添加标签（添加过之后，则修改）
- (void)addLabel:(NSString *)label;

///选中
- (void)check;

///立刻选中(无动画效果)
- (void)checkImmediately;

///取消选中
- (void)cancel;

///立刻取消(无动画效果)
- (void)cancelImmediately;

///闪烁
- (void)blink;

///变换颜色
- (void)changeColor:(UIColor *)color;

///立即变换颜色(无动画效果)
- (void)changeColorImmediately:(UIColor *)color;

///禁用
- (void)disable;

///立即禁用(无动画效果)
- (void)disableImmediately;

///启用
- (void)enable;

///立即启用(无动画效果)
- (void)enableImmediately;

///刷新
- (void)updateView;


///释放内存
- (void)dealloc;



@end
