//
//  KATBottomButtons.h
//  KATFramework
//
//  Created by Kantice on 16/4/15.
//  Copyright © 2016年 KatApp. All rights reserved.
//  底部按钮组

#import "KATPopWindow.h"
#import "KATArray.h"
#import "KATLabelButton.h"


#define BOTTOM_BUTTONS_COUNT_MAX 11


@class KATBottomButtons;

@protocol KATBottomButtonsDelegate <NSObject>

@optional

///按钮点击事件
- (void)buttonTapedWithIndex:(int)index andBottomButtons:(KATBottomButtons *)buttons;

@end



@interface KATBottomButtons : KATPopWindow

///标签按钮数组
@property(nonatomic,retain,readonly) KATArray<__kindof KATLabelButton *> *labels;

///按钮点击事件代理
@property(nonatomic,assign) id<KATBottomButtonsDelegate> buttonDelegate;


#pragma -mark 类方法

///获取实例
+ (instancetype)buttonsWithLabels:(KATArray<__kindof NSString *> *)labels;


#pragma -mark 对象方法

///调整窗口
- (void)resizeWindow;

///释放内存
- (void)dealloc;


@end
