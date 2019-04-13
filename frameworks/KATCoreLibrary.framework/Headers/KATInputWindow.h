//
//  KATInputWindow.h
//  KATFramework
//
//  Created by Yi Yu on 2017/5/25.
//  Copyright © 2017年 KatApp. All rights reserved.
//  带输入框的弹窗，已实现弹窗代理(与输入框焦点有关)，带图形按钮


#import "KATPopWindow.h"
#import "KATLabel.h"
#import "KATShape.h"
#import "KATButton.h"



@interface KATInputWindow : KATPopWindow <KATButtonDelegate,KATPopWindowDelegate,UITextFieldDelegate>


#pragma -mark 属性

///标题
@property(nonatomic,copy) NSString *title;

///标题样式
@property(nonatomic,retain) KATTextStyle *titleStyle;

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

///确定按钮
@property(nonatomic,retain,readonly) KATButton *confirmButton;

///取消按钮
@property(nonatomic,retain,readonly) KATButton *cancelButton;

///输入框
@property(nonatomic,retain,readonly) UITextField *textField;

///输入字符过滤正则表达式
@property(nonatomic,retain) KATArray<NSString *> *filter;

///内容限定(正则表达式)
@property(nonatomic,retain) KATArray<__kindof NSString *> *requirement;

///最大字数(默认128)
@property(nonatomic,assign) int countMax;

///中心点坐标
@property(nonatomic,assign) CGPoint location;

///点击确定按钮事件代码块
@property(nonatomic,copy) void (^onConfirmAction)(NSString *);



#pragma -mark 类方法

///获取实例（无标题）
+ (instancetype)windowWithOnConfirmAction:(void (^)(NSString *text))action;

///获取实例（默认样式，事件可以之后设置）
+ (instancetype)windowWithTitle:(NSString *)title;

///获取实例（默认样式）
+ (instancetype)windowWithTitle:(NSString *)title andOnConfirmAction:(void (^)(NSString *text))action;

///获取实例（标题、样式和事件）
+ (instancetype)windowWithTitle:(NSString *)title style:(KATTextStyle *)style andOnConfirmAction:(void (^)(NSString *text))action;

///调整窗口
- (void)resizeWindow;


#pragma -mark 对象方法

///更新窗口
- (void)updateWindow;


///释放内存
- (void)dealloc;


@end



