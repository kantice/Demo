//
//  KATTestData.m
//  KATDemo
//
//  Created by kAt on 2018/8/27.
//  Copyright © 2018年 Kantice. All rights reserved.
//

#import "KATTestData.h"

@implementation KATTestData


//便利构造方法，获取默认数据
+ (instancetype)data
{
    return [[self alloc] init];
}


//初始化
- (instancetype)init
{
    if(self=[super init])
    {
        self.index=0;
        self.name=@"";
        self.summary=nil;
        self.isMarked=NO;
    }
    
    return self;
}


//描述
- (NSString *)description
{
    return [NSString stringWithFormat:@"TestData:%@(%i)",_name,_index];
}


//释放内存
- (void)dealloc
{
    NSLog(@"%@ is dealloc...",self);
}



@end
