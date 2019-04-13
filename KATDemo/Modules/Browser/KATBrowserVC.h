//
//  KATBrowserVC.h
//  KATDemo
//
//  Created by Yi Yu on 2018/3/22.
//  Copyright © 2018年 Kantice. All rights reserved.
//  网页浏览器模块


#import <UIKit/UIKit.h>


///浏览器导航栏右侧按钮ID
extern NSString *kBrowserNavButtonID;

///浏览器导航栏右侧按钮属性名(属性内容为json字符串: type:按钮类型, action:路由器注册的host行为, message:消息)
extern NSString *kBrowserNavButtonAttribute;


@interface KATBrowserVC : UIViewController

@end
