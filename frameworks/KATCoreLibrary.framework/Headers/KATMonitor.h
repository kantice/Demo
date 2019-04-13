//
//  KATMonitor.h
//  KATFramework
//
//  Created by kAt on 2018/10/15.
//  Copyright © 2018年 KatApp. All rights reserved.
//  性能监控显示器
//  为了防止循环引用，从父视图中删除时，会自动停止定时器


#import "KATSprite.h"
#import "KATMacros.h"
#import "KATLabel.h"


@interface KATMonitor : KATSprite

///标签样式
@property(nonatomic,retain) KATTextStyle *style;

///展示cpu使用率(默认是)
@property(nonatomic,assign) BOOL showCPU;

///展示内存使用量(默认是)
@property(nonatomic,assign) BOOL showMemory;

///展示FPS(默认是)
@property(nonatomic,assign) BOOL showFPS;


#pragma -mark 类方法

///获取实例
+ (instancetype)monitorWithFrame:(CGRect)frame;


#pragma -mark 对象方法

///开始计算
- (void)start;

///停止计算
- (void)stop;


///释放内存
- (void)dealloc;

@end


