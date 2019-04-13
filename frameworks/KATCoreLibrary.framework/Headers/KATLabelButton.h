//
//  KATLabelButton.h
//  KATFramework
//
//  Created by Kantice on 16/7/28.
//  Copyright © 2016年 KatApp. All rights reserved.
//  标签按钮


#import "KATSprite.h"



@class KATLabelButton;

@protocol KATLabelButtonDelegate <NSObject>

@optional

///标签点击事件
- (void)labelButtonTaped:(KATLabelButton *)button;

@end



@interface KATLabelButton : KATSprite


#pragma -mark 属性

///是否禁用
@property(nonatomic,assign) BOOL disabled;

///标签
@property(nonatomic,retain) UILabel *label;

///点击动画(置空则无动画)
@property(nonatomic,retain) CAAnimation *onClickAnimation;

///禁用时透明度
@property(nonatomic,assign) float disabledAlpha;

///点击动作
@property(nonatomic,copy) void (^onClickAction)(void);

///事件代理
@property(nonatomic,assign) id<KATLabelButtonDelegate> eventDelegate;


#pragma -mark 携带值

///类型
@property(nonatomic,assign) int type;

///编号
@property(nonatomic,assign) int num;

///int值2
@property(nonatomic,assign) long long index;

///double值
@property(nonatomic,assign) double value;

///字符串值
@property(nonatomic,copy) NSString *message;

///URL
@property(nonatomic,copy) NSString *url;

///id值
@property(nonatomic,retain) id object;



#pragma -mark 类方法


///获取实例
+ (instancetype)buttonWithFrame:(CGRect)frame text:(NSString *)text font:(UIFont *)font color:(UIColor *)color andAction:(void (^)(void))action;

///通过Label获取实例
+ (instancetype)buttonWithLabel:(UILabel *)label andAction:(void (^)(void))action;


#pragma -mark 对象方法


///释放内存
- (void)dealloc;

@end


