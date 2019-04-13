//
//  TestMacros.h
//  KATDemo
//
//  Created by kAt on 2018/12/5.
//  Copyright © 2018年 Kantice. All rights reserved.
//  Test模块宏集合

#ifndef TestMacros_h
#define TestMacros_h

#import "TestData.h"

#import <KATCoreLibrary/KATRouter.h>
#import <KATCoreLibrary/KATMacros.h>

#define TEST_DATA [TestData sharedData]
#define TEST_STR [TestData sharedData].strings

#define TEST_RES_PATH [NSString stringWithFormat:@"%@/TestResource",[[NSBundle mainBundle] bundlePath]]

#endif /* TestMacros_h */
