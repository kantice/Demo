//
//  Styles.m
//  KATDemo
//
//  Created by Kantice on 2020/7/12.
//  Copyright © 2020 Kantice. All rights reserved.
//

#import "Styles.h"

@implementation Styles

//单例
static Styles *_syl=nil;


//获取单例
+ (instancetype)sharedStyles
{
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^
    {
        //初始化
        _syl=[[self alloc] init];
        
        //布局
        _syl.marginXXS=FIX(4.0);
        _syl.marginXS=FIX(8.0);
        _syl.marginS=FIX(16.0);
        _syl.margin=FIX(24.0);
        _syl.marginL=FIX(32.0);
        _syl.marginXL=FIX(48.0);
        _syl.marginXXL=FIX(64.0);
        
        _syl.paddingXXS=FIX(2.0);
        _syl.paddingXXS=FIX(4.0);
        _syl.paddingXXS=FIX(8.0);
        _syl.paddingXXS=FIX(12.0);
        _syl.paddingXXS=FIX(16.0);
        _syl.paddingXXS=FIX(24.0);
        _syl.paddingXXS=FIX(32.0);
        
        _syl.sizeXXS=SIZE(FIX(16.0), FIX(16.0));
        _syl.sizeXS=SIZE(FIX(24.0), FIX(24.0));
        _syl.sizeS=SIZE(FIX(32.0), FIX(32.0));
        _syl.size=SIZE(FIX(48.0), FIX(48.0));
        _syl.sizeL=SIZE(FIX(64.0), FIX(64.0));
        _syl.sizeXL=SIZE(FIX(128.0), FIX(128.0));
        _syl.sizeXXL=SIZE(FIX(256.0), FIX(256.0));
        
        _syl.cornerXS=FIX(4.0);
        _syl.cornerXS=FIX(6.0);
        _syl.cornerXS=FIX(8.0);
        _syl.cornerXS=FIX(12.0);
        _syl.cornerXS=FIX(16.0);
        
        _syl.lineXS=FIX(0.5);
        _syl.lineS=FIX(1.0);
        _syl.line=FIX(1.5);
        _syl.lineL=FIX(2.0);
        _syl.lineXL=FIX(3.0);
        
        //颜色
        _syl.colorBG=KCOLOR_BACKGROUND;
        _syl.colorLine=KCOLOR_LINE;
        _syl.colorPrimary=KCOLOR_BLUE;
        _syl.colorSecondary=KCOLOR_GREEN;
        _syl.colorTextTitle=KCOLOR_NIGHT;
        _syl.colorTextCotent=KCOLOR_DARK;
        
        //字体
        _syl.fontTitle=[UIFont systemFontOfSize:FIX(16.0)];
        _syl.fontContent=[UIFont systemFontOfSize:FIX(14.0)];
    });
    
    return _syl;
}


//重写alloc
+ (instancetype)alloc
{
    if(_syl)
    {
        return nil;
    }
    else
    {
        return [super alloc];
    }
}

@end
