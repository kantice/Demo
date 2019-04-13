//
//  KATNavTransition.h
//  KATFramework
//
//  Created by Kantice on 2017/8/2.
//  Copyright © 2017年 KatApp. All rights reserved.
//  导航栏风格的转场动画(路由器专用)


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface KATNavTransition : NSObject <UIViewControllerAnimatedTransitioning,UIViewControllerTransitioningDelegate>

///动画时长
@property(nonatomic,assign) double duration;

///是否为消失动画
@property(nonatomic,assign) BOOL isDismissAnimation;

///是否为纵向动画
@property(nonatomic,assign) BOOL isVerticalAnimation;


///获取动画实例(默认为出现动画)
+ (instancetype)transition;

///释放内存
- (void)dealloc;

@end
