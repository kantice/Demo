//
//  AppData.h
//  KATDemo
//
//  Created by Yi Yu on 2018/3/22.
//  Copyright © 2018年 Kantice. All rights reserved.
//  App共享数据中心

#import <Foundation/Foundation.h>
#import "Strings.h"
#import "Styles.h"


@interface AppData : NSObject

#pragma -mark 数据

///字符串
@property(nonatomic,strong,readonly) Strings *strings;

///样式
@property(nonatomic,strong,readonly) Styles *styles;

///用户数据
@property(nonatomic,strong,readonly) NSObject *userData;


#pragma -mark 路径

///数据文件路径
@property(nonatomic,copy) NSString *dataPath;


#pragma -mark 类方法

///获取单例
+ (instancetype)sharedData;



#pragma -mark 对象方法

///保存数据
- (void)saveData;



@end
