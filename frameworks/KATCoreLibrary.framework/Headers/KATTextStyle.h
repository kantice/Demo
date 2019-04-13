//
//  KATTextStyle.h
//  KATFramework
//
//  Created by Kantice on 16/1/26.
//  Copyright © 2016年 KatApp. All rights reserved.
//  文本样式

#import <UIKit/UIKit.h>

#import "KATArray.h"
#import "KATColor.h"



@interface KATTextStyle : NSObject <NSCopying>


#pragma -mark 属性

///排除区域数组（针对textView）
@property(nonatomic,retain) KATArray<UIBezierPath *> *exclusions;




#pragma -mark 边距

///上边距
@property(nonatomic,assign) float marginTop;

///下边距
@property(nonatomic,assign) float marginBottom;

///左边距
@property(nonatomic,assign) float marginLeft;

///右边距
@property(nonatomic,assign) float marginRight;


#pragma -mark 普通文本样式

///控件背景色
@property(nonatomic,retain) UIColor *bgColor;

///文本字体
@property(nonatomic,retain) UIFont *textFont;

///文本颜色
@property(nonatomic,retain) UIColor *textColor;

///文本对齐方式
@property(nonatomic,assign) NSTextAlignment textAlignment;

///换行模式（针对label）
@property(nonatomic,assign) NSLineBreakMode textLineBreak;

///文本背景色
@property(nonatomic,retain) UIColor *textBgColor;

///是否可编辑（针对textView）
@property(nonatomic,assign) BOOL editable;

///是否可选择（针对textView）
@property(nonatomic,assign) BOOL selectable;

///是否可滚动（针对textView）
@property(nonatomic,assign) BOOL scrollable;

///行数（针对label）
@property(nonatomic,assign) int lines;

///段落样式(默认为空(系统默认样式))
@property(nonatomic,retain) NSParagraphStyle *paragraph;


#pragma -mark 特殊文本样式

#pragma -mark url(Label点击url无效)

///是否有URL样式
@property(nonatomic,assign) BOOL hasUrlStyle;

///URL字体
@property(nonatomic,retain) UIFont *urlFont;

///URL文本颜色(TextView无法改变)
@property(nonatomic,retain) UIColor *urlTextColor;

///URL背景颜色
@property(nonatomic,retain) UIColor *urlBgColor;

///URL下划线、删除线颜色
@property(nonatomic,retain) UIColor *urlLineColor;

///URL下划线
@property(nonatomic,assign) NSUnderlineStyle urlUnderLine;

///URL删除线
@property(nonatomic,assign) NSUnderlineStyle urlDeleteLine;


#pragma -mark 电话号码

///是否有电话号码样式
@property(nonatomic,assign) BOOL hasPhoneStyle;

///电话号码字体
@property(nonatomic,retain) UIFont *phoneFont;

///电话号码文本颜色
@property(nonatomic,retain) UIColor *phoneTextColor;

///电话号码背景颜色
@property(nonatomic,retain) UIColor *phoneBgColor;

///电话号码下划线、删除线颜色
@property(nonatomic,retain) UIColor *phoneLineColor;

///电话号码下划线
@property(nonatomic,assign) NSUnderlineStyle phoneUnderLine;

///电话号码删除线
@property(nonatomic,assign) NSUnderlineStyle phoneDeleteLine;


#pragma -mark 日期

///是否有日期样式
@property(nonatomic,assign) BOOL hasDateStyle;

///日期字体
@property(nonatomic,retain) UIFont *dateFont;

///日期文本颜色
@property(nonatomic,retain) UIColor *dateTextColor;

///日期背景颜色
@property(nonatomic,retain) UIColor *dateBgColor;

///日期下划线、删除线颜色
@property(nonatomic,retain) UIColor *dateLineColor;

///日期下划线
@property(nonatomic,assign) NSUnderlineStyle dateUnderLine;

///日期删除线
@property(nonatomic,assign) NSUnderlineStyle dateDeleteLine;


#pragma -mark 时间

///是否有时间样式
@property(nonatomic,assign) BOOL hasTimeStyle;

///时间字体
@property(nonatomic,retain) UIFont *timeFont;

///时间文本颜色
@property(nonatomic,retain) UIColor *timeTextColor;

///时间背景颜色
@property(nonatomic,retain) UIColor *timeBgColor;

///时间下划线、删除线颜色
@property(nonatomic,retain) UIColor *timeLineColor;

///时间下划线
@property(nonatomic,assign) NSUnderlineStyle timeUnderLine;

///时间删除线
@property(nonatomic,assign) NSUnderlineStyle timeDeleteLine;


#pragma -mark 范围

///是否有范围样式
@property(nonatomic,assign) BOOL hasRangeStyle;

///范围开始标记
@property(nonatomic,copy) NSString *rangeStartSymbol;

///范围结束标记
@property(nonatomic,copy) NSString *rangeEndSymbol;

///范围字体
@property(nonatomic,retain) UIFont *rangeFont;

///范围文本颜色
@property(nonatomic,retain) UIColor *rangeTextColor;

///范围背景颜色
@property(nonatomic,retain) UIColor *rangeBgColor;

///范围下划线、删除线颜色
@property(nonatomic,retain) UIColor *rangeLineColor;

///范围下划线
@property(nonatomic,assign) NSUnderlineStyle rangeUnderLine;

///范围删除线
@property(nonatomic,assign) NSUnderlineStyle rangeDeleteLine;


#pragma -mark 范围2

///是否有范围2样式
@property(nonatomic,assign) BOOL hasRange2Style;

///范围2开始标记
@property(nonatomic,copy) NSString *range2StartSymbol;

///范围2结束标记
@property(nonatomic,copy) NSString *range2EndSymbol;

///范围2字体
@property(nonatomic,retain) UIFont *range2Font;

///范围2文本颜色
@property(nonatomic,retain) UIColor *range2TextColor;

///范围2背景颜色
@property(nonatomic,retain) UIColor *range2BgColor;

///范围2下划线、删除线颜色
@property(nonatomic,retain) UIColor *range2LineColor;

///范围2下划线
@property(nonatomic,assign) NSUnderlineStyle range2UnderLine;

///范围2删除线
@property(nonatomic,assign) NSUnderlineStyle range2DeleteLine;


#pragma -mark 范围3

///是否有范围3样式
@property(nonatomic,assign) BOOL hasRange3Style;

///范围3开始标记
@property(nonatomic,copy) NSString *range3StartSymbol;

///范围3结束标记
@property(nonatomic,copy) NSString *range3EndSymbol;

///范围3字体
@property(nonatomic,retain) UIFont *range3Font;

///范围3文本颜色
@property(nonatomic,retain) UIColor *range3TextColor;

///范围3背景颜色
@property(nonatomic,retain) UIColor *range3BgColor;

///范围3下划线、删除线颜色
@property(nonatomic,retain) UIColor *range3LineColor;

///范围3下划线
@property(nonatomic,assign) NSUnderlineStyle range3UnderLine;

///范围3删除线
@property(nonatomic,assign) NSUnderlineStyle range3DeleteLine;


#pragma -mark 表达式

///是否有表达式样式
@property(nonatomic,assign) BOOL hasExpStyle;

///表达式
@property(nonatomic,copy) NSString *expression;

///表达式字体
@property(nonatomic,retain) UIFont *expFont;

///表达式文本颜色
@property(nonatomic,retain) UIColor *expTextColor;

///表达式背景颜色
@property(nonatomic,retain) UIColor *expBgColor;

///表达式下划线、删除线颜色
@property(nonatomic,retain) UIColor *expLineColor;

///表达式下划线
@property(nonatomic,assign) NSUnderlineStyle expUnderLine;

///表达式删除线
@property(nonatomic,assign) NSUnderlineStyle expDeleteLine;


#pragma -mark 表达式2

///是否有表达式2样式
@property(nonatomic,assign) BOOL hasExp2Style;

///表达式2
@property(nonatomic,copy) NSString *expression2;

///表达式2字体
@property(nonatomic,retain) UIFont *exp2Font;

///表达式2文本颜色
@property(nonatomic,retain) UIColor *exp2TextColor;

///表达式2背景颜色
@property(nonatomic,retain) UIColor *exp2BgColor;

///表达式2下划线、删除线颜色
@property(nonatomic,retain) UIColor *exp2LineColor;

///表达式2下划线
@property(nonatomic,assign) NSUnderlineStyle exp2UnderLine;

///表达式2删除线
@property(nonatomic,assign) NSUnderlineStyle exp2DeleteLine;


#pragma -mark 表达式3

///是否有表达式3样式
@property(nonatomic,assign) BOOL hasExp3Style;

///表达式3
@property(nonatomic,copy) NSString *expression3;

///表达式3字体
@property(nonatomic,retain) UIFont *exp3Font;

///表达式3文本颜色
@property(nonatomic,retain) UIColor *exp3TextColor;

///表达式3背景颜色
@property(nonatomic,retain) UIColor *exp3BgColor;

///表达式3下划线、删除线颜色
@property(nonatomic,retain) UIColor *exp3LineColor;

///表达式3下划线
@property(nonatomic,assign) NSUnderlineStyle exp3UnderLine;

///表达式3删除线
@property(nonatomic,assign) NSUnderlineStyle exp3DeleteLine;


#pragma -mark 关键字

///是否有关键字样式
@property(nonatomic,assign) BOOL hasKeywordsStyle;

///关键字
@property(nonatomic,retain) KATArray<__kindof NSString *> *keywords;

///关键字字体
@property(nonatomic,retain) UIFont *keywordsFont;

///关键字文本颜色
@property(nonatomic,retain) UIColor *keywordsTextColor;

///关键字背景颜色
@property(nonatomic,retain) UIColor *keywordsBgColor;

///关键字下划线、删除线颜色
@property(nonatomic,retain) UIColor *keywordsLineColor;

///关键字下划线
@property(nonatomic,assign) NSUnderlineStyle keywordsUnderLine;

///关键字删除线
@property(nonatomic,assign) NSUnderlineStyle keywordsDeleteLine;


#pragma -mark 关键字2

///是否有关键字2样式
@property(nonatomic,assign) BOOL hasKeywords2Style;

///关键字2
@property(nonatomic,retain) KATArray<__kindof NSString *> *keywords2;

///关键字2字体
@property(nonatomic,retain) UIFont *keywords2Font;

///关键字2文本颜色
@property(nonatomic,retain) UIColor *keywords2TextColor;

///关键字2背景颜色
@property(nonatomic,retain) UIColor *keywords2BgColor;

///关键字2下划线、删除线颜色
@property(nonatomic,retain) UIColor *keywords2LineColor;

///关键字2下划线
@property(nonatomic,assign) NSUnderlineStyle keywords2UnderLine;

///关键字2删除线
@property(nonatomic,assign) NSUnderlineStyle keywords2DeleteLine;


#pragma -mark 关键字3

///是否有关键字3样式
@property(nonatomic,assign) BOOL hasKeywords3Style;

///关键字3
@property(nonatomic,retain) KATArray<__kindof NSString *> *keywords3;

///关键字3字体
@property(nonatomic,retain) UIFont *keywords3Font;

///关键字3文本颜色
@property(nonatomic,retain) UIColor *keywords3TextColor;

///关键字3背景颜色
@property(nonatomic,retain) UIColor *keywords3BgColor;

///关键字3下划线、删除线颜色
@property(nonatomic,retain) UIColor *keywords3LineColor;

///关键字3下划线
@property(nonatomic,assign) NSUnderlineStyle keywords3UnderLine;

///关键字3删除线
@property(nonatomic,assign) NSUnderlineStyle keywords3DeleteLine;


#pragma -mark 关键字4

///是否有关键字4样式
@property(nonatomic,assign) BOOL hasKeywords4Style;

///关键字4
@property(nonatomic,retain) KATArray<__kindof NSString *> *keywords4;

///关键字4字体
@property(nonatomic,retain) UIFont *keywords4Font;

///关键字4文本颜色
@property(nonatomic,retain) UIColor *keywords4TextColor;

///关键字4背景颜色
@property(nonatomic,retain) UIColor *keywords4BgColor;

///关键字4下划线、删除线颜色
@property(nonatomic,retain) UIColor *keywords4LineColor;

///关键字4下划线
@property(nonatomic,assign) NSUnderlineStyle keywords4UnderLine;

///关键字4删除线
@property(nonatomic,assign) NSUnderlineStyle keywords4DeleteLine;


#pragma -mark 关键字5

///是否有关键字5样式
@property(nonatomic,assign) BOOL hasKeywords5Style;

///关键字5关键字
@property(nonatomic,retain) KATArray<__kindof NSString *> *keywords5;

///关键字5字体
@property(nonatomic,retain) UIFont *keywords5Font;

///关键字5文本颜色
@property(nonatomic,retain) UIColor *keywords5TextColor;

///关键字5背景颜色
@property(nonatomic,retain) UIColor *keywords5BgColor;

///关键字5下划线、删除线颜色
@property(nonatomic,retain) UIColor *keywords5LineColor;

///关键字5下划线
@property(nonatomic,assign) NSUnderlineStyle keywords5UnderLine;

///关键字5删除线
@property(nonatomic,assign) NSUnderlineStyle keywords5DeleteLine;


#pragma -mark 关键字6

///是否有关键字6样式
@property(nonatomic,assign) BOOL hasKeywords6Style;

///关键字6
@property(nonatomic,retain) KATArray<__kindof NSString *> *keywords6;

///关键字6字体
@property(nonatomic,retain) UIFont *keywords6Font;

///关键字6文本颜色
@property(nonatomic,retain) UIColor *keywords6TextColor;

///关键字6背景颜色
@property(nonatomic,retain) UIColor *keywords6BgColor;

///关键字6下划线、删除线颜色
@property(nonatomic,retain) UIColor *keywords6LineColor;

///关键字6下划线
@property(nonatomic,assign) NSUnderlineStyle keywords6UnderLine;

///关键字6删除线
@property(nonatomic,assign) NSUnderlineStyle keywords6DeleteLine;


#pragma -mark 关键字7

///是否有关键字7样式
@property(nonatomic,assign) BOOL hasKeywords7Style;

///关键字7
@property(nonatomic,retain) KATArray<__kindof NSString *> *keywords7;

///关键字7字体
@property(nonatomic,retain) UIFont *keywords7Font;

///关键字7文本颜色
@property(nonatomic,retain) UIColor *keywords7TextColor;

///关键字7背景颜色
@property(nonatomic,retain) UIColor *keywords7BgColor;

///关键字7下划线、删除线颜色
@property(nonatomic,retain) UIColor *keywords7LineColor;

///关键字7下划线
@property(nonatomic,assign) NSUnderlineStyle keywords7UnderLine;

///关键字7删除线
@property(nonatomic,assign) NSUnderlineStyle keywords7DeleteLine;


#pragma -mark 关键字8

///是否有关键字8样式
@property(nonatomic,assign) BOOL hasKeywords8Style;

///关键字8
@property(nonatomic,retain) KATArray<__kindof NSString *> *keywords8;

///关键字8字体
@property(nonatomic,retain) UIFont *keywords8Font;

///关键字8文本颜色
@property(nonatomic,retain) UIColor *keywords8TextColor;

///关键字8背景颜色
@property(nonatomic,retain) UIColor *keywords8BgColor;

///关键字8下划线、删除线颜色
@property(nonatomic,retain) UIColor *keywords8LineColor;

///关键字8下划线
@property(nonatomic,assign) NSUnderlineStyle keywords8UnderLine;

///关键字8删除线
@property(nonatomic,assign) NSUnderlineStyle keywords8DeleteLine;


#pragma -mark 关键字9

///是否有关键字9样式
@property(nonatomic,assign) BOOL hasKeywords9Style;

///关键字9
@property(nonatomic,retain) KATArray<__kindof NSString *> *keywords9;

///关键字9字体
@property(nonatomic,retain) UIFont *keywords9Font;

///关键字9文本颜色
@property(nonatomic,retain) UIColor *keywords9TextColor;

///关键字9背景颜色
@property(nonatomic,retain) UIColor *keywords9BgColor;

///关键字9下划线、删除线颜色
@property(nonatomic,retain) UIColor *keywords9LineColor;

///关键字9下划线
@property(nonatomic,assign) NSUnderlineStyle keywords9UnderLine;

///关键字9删除线
@property(nonatomic,assign) NSUnderlineStyle keywords9DeleteLine;



#pragma -mark 类方法

///获取实例
+ (instancetype)textStyle;


#pragma -mark 对象方法

///释放内存
- (void)dealloc;




@end






