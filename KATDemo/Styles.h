//
//  Styles.h
//  KATDemo
//
//  Created by Kantice on 2020/7/12.
//  Copyright © 2020 Kantice. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface Styles : NSObject

#pragma -mark 布局

//Margin
@property(nonatomic,assign) CGFloat marginXXS;
@property(nonatomic,assign) CGFloat marginXS;
@property(nonatomic,assign) CGFloat marginS;
@property(nonatomic,assign) CGFloat margin;
@property(nonatomic,assign) CGFloat marginL;
@property(nonatomic,assign) CGFloat marginXL;
@property(nonatomic,assign) CGFloat marginXXL;

//Padding
@property(nonatomic,assign) CGFloat paddingXXS;
@property(nonatomic,assign) CGFloat paddingXS;
@property(nonatomic,assign) CGFloat paddingS;
@property(nonatomic,assign) CGFloat padding;
@property(nonatomic,assign) CGFloat paddingL;
@property(nonatomic,assign) CGFloat paddingXL;
@property(nonatomic,assign) CGFloat paddingXXL;

//Size
@property(nonatomic,assign) CGSize sizeXXS;
@property(nonatomic,assign) CGSize sizeXS;
@property(nonatomic,assign) CGSize sizeS;
@property(nonatomic,assign) CGSize size;
@property(nonatomic,assign) CGSize sizeL;
@property(nonatomic,assign) CGSize sizeXL;
@property(nonatomic,assign) CGSize sizeXXL;

//Corner
@property(nonatomic,assign) CGFloat cornerXS;
@property(nonatomic,assign) CGFloat cornerS;
@property(nonatomic,assign) CGFloat corner;
@property(nonatomic,assign) CGFloat cornerL;
@property(nonatomic,assign) CGFloat cornerXL;

//Line
@property(nonatomic,assign) CGFloat lineXS;
@property(nonatomic,assign) CGFloat lineS;
@property(nonatomic,assign) CGFloat line;
@property(nonatomic,assign) CGFloat lineL;
@property(nonatomic,assign) CGFloat lineXL;


#pragma -mark 颜色
@property(nonatomic,strong) UIColor *colorBG;
@property(nonatomic,strong) UIColor *colorLine;
@property(nonatomic,strong) UIColor *colorPrimary;
@property(nonatomic,strong) UIColor *colorSecondary;
@property(nonatomic,strong) UIColor *colorTextTitle;
@property(nonatomic,strong) UIColor *colorTextCotent;


#pragma -mark 字体
@property(nonatomic,strong) UIFont *fontTitle;
@property(nonatomic,strong) UIFont *fontContent;


#pragma -mark 类方法

///获取单例
+ (instancetype)sharedStyles;

@end


