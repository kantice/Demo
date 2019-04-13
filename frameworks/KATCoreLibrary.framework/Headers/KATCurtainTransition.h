//
//  KATCurtainTransition.h
//  KATDemo
//
//  Created by kAt on 2018/12/5.
//  Copyright © 2018年 Kantice. All rights reserved.
//  帷幕风格转场动画(路由器专用)

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface KATCurtainTransition : NSObject <UIViewControllerAnimatedTransitioning,UIViewControllerTransitioningDelegate>

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


