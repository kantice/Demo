//
//  KATButtonWindow.h
//  KATFramework
//
//  Created by Kantice on 17/5/19.
//  Copyright (c) 2015年 KatApp. All rights reserved.
//  带按钮的提示窗口

#import "KATPopWindow.h"

#import "KATButton.h"
#import "KATLabelButton.h"
#import "KATLabel.h"
#import "KATShape.h"



@interface KATButtonWindow : KATPopWindow <KATButtonDelegate>


#pragma -mark 属性

///标题
@property(nonatomic,copy) NSString *title;

///提示内容
@property(nonatomic,copy) NSString *info;

///标题样式
@property(nonatomic,retain) KATTextStyle *titleStyle;

///提示内容样式
@property(nonatomic,retain) KATTextStyle *infoStyle;

///窗口内容宽度
@property(nonatomic,assign) float contentWidth;

///窗口内容间距
@property(nonatomic,assign) float contentPadding;

///按钮高度
@property(nonatomic,assign) float buttonHeight;

///按钮线宽
@property(nonatomic,assign) float buttonLineWidth;

///线宽
@property(nonatomic,assign) float lineWidth;

///线色
@property(nonatomic,retain) UIColor *lineColor;

///按钮数组
@property(nonatomic,retain) KATArray<KATButton *> *buttons;



#pragma -mark 类方法

///获取实例（默认样式，只有标题）
+ (instancetype)windowWithTitle:(NSString *)title;

///获取实例（只有标题和样式）
+ (instancetype)windowWithTitle:(NSString *)title andStyle:(KATTextStyle *)style;

///获取实例（默认样式，只有提示）
+ (instancetype)windowWithInfo:(NSString *)info;

///获取实例（只有提示和样式）
+ (instancetype)windowWithInfo:(NSString *)info andStyle:(KATTextStyle *)style;

///获取实例（默认样式，带标题和提示）
+ (instancetype)windowWithTitle:(NSString *)title andInfo:(NSString *)info;

///获取实例（默认样式，带标题和提示和按钮）
+ (instancetype)windowWithTitle:(NSString *)title info:(NSString *)info andButtons:(KATArray<KATButton *> *)buttons;

///获取实例(全参数)
+ (instancetype)windowWithTitle:(NSString *)title titleStyle:(KATTextStyle *)tStyle info:(NSString *)info infoStyle:(KATTextStyle *)iStyle andButtons:(KATArray<KATButton *> *)buttons;

///调整窗口
- (void)resizeWindow;


#pragma -mark 对象方法

///更新窗口
- (void)updateWindow;


///释放内存
- (void)dealloc;


@end

