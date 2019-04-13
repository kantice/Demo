//
//  KATAlertWindow.h
//  KATFramework
//
//  Created by Kantice on 14-7-17.
//  Copyright (c) 2014年 KatApp. All rights reserved.
//  提醒窗口，不带按钮

#import "KATPopWindow.h"
#import "KATLabel.h"



@interface KATAlertWindow : KATPopWindow


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

///获取实例(全参数)
+ (instancetype)windowWithTitle:(NSString *)title titleStyle:(KATTextStyle *)tStyle info:(NSString *)info infoStyle:(KATTextStyle *)iStyle;


#pragma -mark 对象方法

///调整窗口
- (void)resizeWindow;

///更新窗口
- (void)updateWindow;

///释放内存
- (void)dealloc;


@end


