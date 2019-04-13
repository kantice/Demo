//
//  KATNavBar.h
//  KATFramework
//
//  Created by Yi Yu on 2017/5/27.
//  Copyright © 2017年 KatApp. All rights reserved.
//  导航栏，与路由器结合



#import "KATSprite.h"
#import "KATMacros.h"
#import "KATButton.h"
#import "KATLabel.h"



@interface KATNavBar : KATSprite


///高度
@property(nonatomic,assign) CGFloat height;

///间距
@property(nonatomic,assign) CGFloat padding;

///颜色
@property(nonatomic,retain) UIColor *color;

///返回按钮
@property(nonatomic,retain,readonly) KATButton *backButton;

///模糊背景视图
@property(nonatomic,retain) UIVisualEffectView *blurView;

///图标图片
@property(nonatomic,retain) UIImage *icon;

///标题
@property(nonatomic,copy) NSString *title;

///副标题
@property(nonatomic,copy) NSString *subtitle;

///左按钮数组
@property(nonatomic,retain) KATArray<KATButton *> *leftButtons;

///右边按钮数组
@property(nonatomic,retain) KATArray<KATButton *> *rightButtons;

///是否显示返回按钮
@property(nonatomic,assign) BOOL hasBackButton;

///不透明度(用于渐变)
@property(nonatomic,assign) float opacity;

///是否有动画
@property(nonatomic,assign) BOOL hasAnimation;

///动画时长
@property(nonatomic,assign) double animationDuration;



///获取实例
+ (instancetype)navBar;


///更新内容
- (void)update;


///显示
- (void)show;


///隐藏
- (void)hide;



@end





