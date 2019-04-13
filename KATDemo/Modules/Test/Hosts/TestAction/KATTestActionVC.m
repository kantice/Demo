//
//  KATTestActionVC.m
//  KATDemo
//
//  Created by kAt on 2019/3/26.
//  Copyright © 2019 Kantice. All rights reserved.
//

#import "KATTestActionVC.h"

@interface KATTestActionVC () <KATRouterDelegate>

@end

@implementation KATTestActionVC

- (void)viewDidLoad
{
    [super viewDidLoad];
}


//不允许路由跳转
- (BOOL)allowRoutingWithValues:(KATHashMap *)values
{
    return NO;
}


#pragma -makr 各种Action的实体方法

//展示Toast
- (void)showToastWithMessage:(NSString *)msg
{
    [KATRouter showToastWithText:[NSString stringWithFormat:@"TEST_MSG: %@",msg]];
}


@end
