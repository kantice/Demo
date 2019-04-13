//
//  KATTextView.h
//  KATFramework
//
//  Created by Kantice on 16/1/25.
//  Copyright © 2016年 KatApp. All rights reserved.
//  文本显示（编辑）视图


#import <UIKit/UIKit.h>

#import "KATExpressionUtil.h"
#import "KATTextStyle.h"
#import "KATStringUtil.h"
#import "KATSprite.h"



@class KATTextView;

@protocol KATTextViewDelegate <NSObject>

@optional

///是否打开链接
- (BOOL)textView:(KATTextView *)textView shouldOpenURL:(NSURL *)URL;

///是否可以开始编辑
- (BOOL)textViewShouldStartEditing:(KATTextView *)textView;

///开始编辑
- (void)textViewDidStartEditing:(KATTextView *)textView;

///完成编辑
- (void)textViewDidFinishEditing:(KATTextView *)textView;

///是否改变内容
- (BOOL)textView:(KATTextView *)textView shouldChangeText:(NSString *)text;

///改变内容
- (void)textViewDidChangeText:(KATTextView *)textView;

///自动调整尺寸
- (void)textViewDidAutoResize:(KATTextView *)textView;

///键盘将要显示
- (void)textView:(KATTextView *)textView willShowKeyboard:(CGSize)size;

///键盘完成显示
- (void)textView:(KATTextView *)textView didShowKeyboard:(CGSize)size;

///键盘将要隐藏
- (void)textViewWillHideKeyboard:(KATTextView *)textView;


@end



@interface KATTextView : KATSprite <UITextViewDelegate>
{
    BOOL _needUpdate;//是否需要更新
}


#pragma -mark 属性

///事件代理
@property(nonatomic,assign) id<KATTextViewDelegate> eventDelegate;

///显示的视图
@property(nonatomic,retain,readonly) UITextView *textView;

///显示的文本
@property(nonatomic,copy) NSString *text;

///样式
@property(nonatomic,retain) KATTextStyle *style;

///内容尺寸
@property(nonatomic,assign) CGSize contentSize;

///文本尺寸
@property(nonatomic,assign) CGSize textSize;

///过滤内容(正则表达式)
@property(nonatomic,retain) KATArray<__kindof NSString *> *filter;

///内容限定(正则表达式)
@property(nonatomic,retain) KATArray<__kindof NSString *> *requirement;

///最大长度
@property(nonatomic,assign) int maxLength;

///随内容自动调整尺寸
@property(nonatomic,assign) BOOL autoResize;

///自动调整最大尺寸
@property(nonatomic,assign) double maxHeight;

//@property(nonatomic,retain) KATArray *spChars;//特殊字符(用于更新样式)




#pragma -mark 类方法

///获取实例
+ (instancetype)textViewWithFrame:(CGRect)frame andStyle:(KATTextStyle *)style;


#pragma -mark 对象方法

///调整显示大小(宽度不变)
- (void)adjustFrame;

///调整显示大小
- (void)resizeFrame;

///结束编辑
- (void)endEidting;

///更新样式和内容尺寸
- (void)updateStyle;

///显示最上面部分内容
- (void)displayTopAnimated:(BOOL)animated;

///显示最下面部分内容
- (void)displayBottomAnimated:(BOOL)animated;

///添加文本到末尾
- (void)appendText:(NSString *)text;

///从指定的位置添加文本
- (void)appendText:(NSString *)text atPosition:(int)position;

///从末尾删除文本
- (void)deleteTextWithLength:(int)length;

///从指定的位置删除文本
- (void)deleteTextWithLength:(int)length atPosition:(int)position;

///清除文本
- (void)clearText;


///释放内存
- (void)dealloc;



@end


