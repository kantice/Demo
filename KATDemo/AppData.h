//
//  AppData.h
//  KATDemo
//
//  Created by Yi Yu on 2018/3/22.
//  Copyright © 2018年 Kantice. All rights reserved.
//  App共享数据中心

#import <Foundation/Foundation.h>
#import "Strings.h"



@interface AppData : NSObject


#pragma -mark 路径



#pragma -mark 数据

///字符串
@property(nonatomic,strong,readonly) Strings *strings;


#pragma -mark 颜色



#pragma -mark 字体



#pragma -mark 样式



#pragma -mark 视图



#pragma -mark 类方法

///获取单例
+ (instancetype)sharedData;



#pragma -mark 对象方法

///保存配置
- (void)saveConfig;



@end
