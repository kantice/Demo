//
//  KATLabel.h
//  KATFramework
//
//  Created by Kantice on 16/1/26.
//  Copyright © 2016年 KatApp. All rights reserved.
//  富文本标签



#import <UIKit/UIKit.h>

#import "KATExpressionUtil.h"
#import "KATTextStyle.h"
#import "KATSprite.h"
#import "KATLabelButton.h"



@interface KATLabel : KATSprite


#pragma -mark 属性

///标签控件
@property(nonatomic,retain,readonly) UILabel *label;

///显示的文本
@property(nonatomic,copy) NSString *text;

///样式
@property(nonatomic,retain) KATTextStyle *style;

///内容尺寸
@property(nonatomic,assign,readonly) CGSize contentSize;

///文本尺寸
@property(nonatomic,assign,readonly) CGSize textSize;


#pragma -mark 类方法

///获取实例
+ (instancetype)labelWithFrame:(CGRect)frame andStyle:(KATTextStyle *)style;


#pragma -mark 对象方法

///调整显示大小(宽度不变)
- (void)adjustFrame;

///调整显示大小
- (void)resizeFrame;

///更新样式和内容尺寸
- (void)updateStyle;

///获取label按钮
- (KATLabelButton *)buttonWithAction:(void (^)(void))action;


///释放内存
- (void)dealloc;



@end



