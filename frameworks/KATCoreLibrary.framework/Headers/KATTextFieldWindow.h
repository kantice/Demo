//
//  KATTextFieldWindow.h
//  KATFramework
//
//  Created by Yi Yu on 2018/1/19.
//  Copyright © 2018年 KatApp. All rights reserved.
//  带输入框的弹窗，已实现弹窗代理(与输入框焦点有关)，带图文本按钮


#import "KATPopWindow.h"
#import "KATLabelButton.h"
#import "KATLabel.h"
#import "KATShape.h"


@interface KATTextFieldWindow : KATPopWindow <KATPopWindowDelegate,UITextFieldDelegate>

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

///线宽
@property(nonatomic,assign) float lineWidth;

///线色
@property(nonatomic,retain) UIColor *lineColor;

///左按钮
@property(nonatomic,retain,readonly) KATLabelButton *leftButton;

///右按钮
@property(nonatomic,retain,readonly) KATLabelButton *rightButton;

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

///左按钮点击事件代码块
@property(nonatomic,copy) void (^leftAction)(NSString *);

///右按钮点击事件代码块
@property(nonatomic,copy) void (^rightAction)(NSString *);



#pragma -mark 类方法

///获取实例（标题、样式和事件）
+ (instancetype)windowWithTitle:(NSString *)title style:(KATTextStyle *)style leftButtonLabel:(NSString *)leftLabel leftButtonAction:(void (^)(NSString *text))leftAction rightButtonLabel:(NSString *)rightLabel rightButtonAction:(void (^)(NSString *text))rightAction;

///调整窗口
- (void)resizeWindow;


#pragma -mark 对象方法

///更新窗口
- (void)updateWindow;


///释放内存
- (void)dealloc;


@end
