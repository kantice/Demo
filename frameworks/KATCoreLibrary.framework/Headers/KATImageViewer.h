//
//  KATImageViewer.h
//  KATFramework
//
//  Created by Kantice on 16/4/15.
//  Copyright © 2016年 KatApp. All rights reserved.
//  图片显示控件，用于KATImage的全屏显示


#import <UIKit/UIKit.h>
#import "KATImage.h"
#import "KATMacros.h"




@interface KATImageViewer : UIView <KATButtonDelegate>

#pragma -mark 属性

///阴影
@property(nonatomic,retain,readonly) UIView *shadow;

///图片视图
@property(nonatomic,copy,readonly) KATImage *content;

///原始Frame
@property(nonatomic,assign,readonly) CGRect originalFrame;

///图片尺寸
@property(nonatomic,assign,readonly) CGSize imageSize;

///图片与屏幕的缩放比
@property(nonatomic,assign,readonly) float scaleRate;

///当前尺寸
@property(nonatomic,assign,readonly) CGSize currentSize;

///当前位置
@property(nonatomic,assign,readonly) CGPoint currentCenter;

///显示时间
@property(nonatomic,assign) double showDuration;

///是否已经显示
@property(nonatomic,assign,readonly) BOOL isShown;

///是否为实际尺寸
@property(nonatomic,assign,readonly) BOOL isActualSize;

///是否动画中
@property(nonatomic,assign,readonly) BOOL animating;

///是否可以保存
@property(nonatomic,assign) BOOL canSave;

///是否自动播放
@property(nonatomic,assign) BOOL autoPlay;




#pragma -mark 类方法

///获取实例
+ (instancetype)viewer;


#pragma -mark 对象方法

///显示图片
- (void)showWithImage:(KATImage *)image;

///隐藏
- (void)hide;


///释放内存
- (void)dealloc;

@end
