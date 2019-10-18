//
//  KATBox.h
//  KATFramework
//
//  Created by Yi Yu on 2018/3/15.
//  Copyright © 2018年 KatApp. All rights reserved.
//  布局容器，各效果叠加时可能会有冲突

#import "KATSprite.h"



//对齐方式枚举
typedef NS_ENUM(NSUInteger, KATBoxAlignment)
{
    KATBoxAlignmentNone=0,//无对齐
    KATBoxAlignmentTopLeft=1,//上(横向排列模式)左(纵向排列模式)对齐
    KATBoxAlignmentBottomRight=2,//下(横向排列模式)右(纵向排列模式)对齐
    KATBoxAlignmentCenter=3//中心对齐
};


@interface KATBox : KATSprite

#pragma -mark 属性

///是否横向排列(默认纵向排列)
@property(nonatomic,assign) BOOL horizontalSort;

///是否自动布局子视图(具有填充、边缘吸附效果，可滚动模式填充一边，非滚动模式下填充两边，子类frame超出box边界时根据原子类的frame比例调整)
@property(nonatomic,assign) BOOL autoLayout;

///是否包裹内容(随子控件变化尺寸)
@property(nonatomic,assign) BOOL wrapContent;

///是否以最大宽度(高度)填充,(需要对齐,与包裹内容有冲突)
@property(nonatomic,assign) BOOL fillToFit;

///是否反序排列(从下往上/从右往左)排列(默认是从上往下/从左往右排列)
@property(nonatomic,assign) BOOL revserseSorted;

///边距
@property(nonatomic,assign) UIEdgeInsets paddingEdge;

///内边距
@property(nonatomic,assign) double paddingInner;

///是否可滚动
@property(nonatomic,assign) BOOL scrollable;

///对齐方式
@property(nonatomic,assign) KATBoxAlignment alignment;

///是否显示滚动条
@property(nonatomic,assign) BOOL showsScrollIndicator;

///是否可以一直滚动
@property(nonatomic,assign) BOOL alwaysBounce;

///内容视图
@property(nonatomic,retain,readonly) UIScrollView *contentView;

///动画时长(默认0.3s)
@property(nonatomic,assign) double animationDuration;

///是否更新时带动画效果(添加删除视图除外)(默认为是)
@property(nonatomic,assign) BOOL updatingWithAnimation;


#pragma -mark 类方法

///获取实例
+ (instancetype)boxWithFrame:(CGRect)frame;

///获取实例
+ (instancetype)boxWithFrame:(CGRect)frame horizontalSort:(BOOL)horizontalSort scrollable:(BOOL)scrollable autoLayout:(BOOL)autoLayout wrapContent:(BOOL)wrapContent;

///获取实例(全参数)
+ (instancetype)boxWithFrame:(CGRect)frame horizontalSort:(BOOL)horizontalSort paddingEdge:(UIEdgeInsets)paddingEdge paddingInner:(double)paddingInner scrollable:(BOOL)scrollable alignment:(KATBoxAlignment)alignment autoLayout:(BOOL)autoLayout wrapContent:(BOOL)wrapContent fillToFit:(BOOL)fill;

///通过子视图构造实例(横向、非滚动，包裹内容)
+ (instancetype)boxWithSubview:(__kindof UIView *)view;

///通过子视图数组构造横向非滚动实例(自动布局)
+ (instancetype)horizontalBoxWithSubviews:(KATArray<__kindof UIView *> *)views frame:(CGRect)frame paddingEdge:(UIEdgeInsets)paddingEdge paddingInner:(double)paddingInner;

///通过子视图数组构造纵向滚动实例
+ (instancetype)verticalBoxWithSubviews:(KATArray<__kindof UIView *> *)views frame:(CGRect)frame paddingEdge:(UIEdgeInsets)paddingEdge paddingInner:(double)paddingInner;

///构造横向非滚动实例(自动布局)
+ (instancetype)horizontalBoxWithFrame:(CGRect)frame paddingEdge:(UIEdgeInsets)paddingEdge paddingInner:(double)paddingInner;

///构造纵向滚动实例
+ (instancetype)verticalBoxWithFrame:(CGRect)frame paddingEdge:(UIEdgeInsets)paddingEdge paddingInner:(double)paddingInner;


#pragma -mark 对象方法

///更新视图
- (void)updateBox;

///带动画效果更新视图
- (void)updateBoxAnimated:(BOOL)animated;

///添加视图(默认比例权重1.0)(非滚动模式下自动布局将计算布局权重)
- (void)appendSubview:(__kindof UIView *)view;

///添加视图并设置比例权重(非滚动模式下自动布局将计算布局权重)
- (void)appendSubview:(__kindof UIView *)view withWeight:(double)weight;

//添加视图并设置比例权重和插入位置(非滚动模式下自动布局将计算布局权重)
- (void)appendSubview:(__kindof UIView *)view withWeight:(double)weight andIndex:(int)index;

///添加视图数组(默认比例权重1.0)
- (void)appendSubviews:(KATArray<__kindof UIView *> *)views;

///删除视图
- (void)removeSubview:(__kindof UIView *)view;

///清除所有子视图
- (void)clearSubviews;

///添加视图到指定的视图后
- (void)appendSubview:(__kindof UIView *)view withFrontView:(__kindof UIView *)frontView;

///插入视图到指定的视图前
- (void)insertSubview:(__kindof UIView *)view withRearView:(__kindof UIView *)rearView;

///添加视图到指定的视图后，并设置比例权重
- (void)appendSubview:(__kindof UIView *)view withFrontView:(__kindof UIView *)frontView andWeight:(double)weight;

///插入视图到指定的视图前，并设置比例权重
- (void)insertSubview:(__kindof UIView *)view withRearView:(__kindof UIView *)rearView andWeight:(double)weight;

///移动子视图到指定位置
- (void)moveSubview:(__kindof UIView *)view withIndex:(int)index;

///上(左)移子视图
- (void)moveUpWithSubview:(__kindof UIView *)view;

///下(右)移子视图
- (void)moveDownWithSubview:(__kindof UIView *)view;

///子视图至于最上(左)
- (void)moveToTopWithSubview:(__kindof UIView *)view;

///子视图至于最下(右)
- (void)moveToBottomWithSubview:(__kindof UIView *)view;

///交换两个子视图的位置
- (void)changePositionWithSubviewA:(__kindof UIView *)va andSubviewB:(__kindof UIView *)vb;

///子视图整体上(左)移
- (void)moveSubviewsUp;

///子视图整体下(右)移
- (void)moveSubviewsDown;

///反向排列子视图
- (void)reverseSubviews;

///获取子视图的位置
- (int)indexWithSubview:(__kindof UIView *)view;

///获取子视图的布局权重(没有该子视图则返回负数)
- (double)weightWithSubview:(__kindof UIView *)view;

///通过下标获取子视图
- (__kindof UIView *)subviewWithIndex:(int)index;

///获取首个子视图
- (__kindof UIView *)firstSubview;

///获取最后一个子视图
- (__kindof UIView *)lastSubview;

///获取子视图个数
- (int)countOfSubviews;


@end

