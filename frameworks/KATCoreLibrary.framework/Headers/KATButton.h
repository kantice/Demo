//
//  KATButton.h
//  KATFramework
//
//  Created by Kantice on 14-6-11.
//  Copyright (c) 2014年 KatApp. All rights reserved.
//  常用的简单图形按钮
//
//  注意点:
//  1.类型为None则返回nil，类型为Empty则返回一个空白内容的按钮;
//  2.eventDelegate和onClickAction(构造函数中传递的action，也可以构造完设置)都不为空时，先执行onClickAction的block代码，后执行代理的回调函数，按钮的交互事件会自动设置;
//  3.scale属性只影响按钮的显示效果，交互范围由按钮的frame决定;
//  4.按钮的宽高比例尽量为1:1，不然有些图形会显示非预期的效果;
//  5.点击动画效果可以在doClickAnimation方法中修改，或者修改animatedOnClick属性，设置禁用或者启用点击动画;
//  6.添加或修改按钮类型的显示效果，可以在drawRect:方法中修改;
//  7.该类采用MRC方式管理内存，若添加到使用ARC环境的项目，需修改部分代码，或者在targets的build phases选项下Compile Sources下选择该文件，双击它，输入 -fno-objc-arc 即可。


#import <UIKit/UIKit.h>
#import "KATSprite.h"




//按钮类型枚举
typedef NS_ENUM(NSUInteger, KATButtonType)
{
    KATButtonTypeNone=0,
    KATButtonTypeEmpty=10,//空
    KATButtonTypeFilled=20,//填充
    
    //方向
    KATButtonTypeUp=101,
    KATButtonTypeDown,
    KATButtonTypeLeft,
    KATButtonTypeRight,
    KATButtonTypeDoubleUp=111,
    KATButtonTypeDoubleDown,
    KATButtonTypeDoubleLef,
    KATButtonTypeDoubleRight,
    KATButtonTypeUpSide=121,
    KATButtonTypeDownSide,
    KATButtonTypeLeftSide,
    KATButtonTypeRightSide,
    KATButtonTypeArrowUp=131,
    KATButtonTypeArrowDown,
    KATButtonTypeArrowLeft,
    KATButtonTypeArrowRight,
    KATButtonTypeRoundUp=141,
    KATButtonTypeRoundDown,
    KATButtonTypeRoundLeft,
    KATButtonTypeRoundRight,
    
    //形状
    KATButtonTypeRectangle=201,
    KATButtonTypeTriangle,
    KATButtonTypeRound,
    KATButtonTypeRoundedRectangle,
    KATButtonTypeStar,
    KATButtonTypeHeart,
    KATButtonTypeSharpRectangle=211,
    KATButtonTypeSharpTriangle,
    KATButtonTypeFilledRectangle=221,
    KATButtonTypeFilledTriangle,
    KATButtonTypeFilledRound,
    KATButtonTypeFilledRoundedRectangle,
    KATButtonTypeFilledStar,
    KATButtonTypeFilledHeart,
    KATButtonTypeFilledSharpRectangle=231,
    KATButtonTypeFilledSharpTriangle,
    KATButtonTypePentagram=251,
    KATButtonTypeHexagram,
    KATButtonTypePoint=299,
    
    //播放
    KATButtonTypePlayerPlay=301,
    KATButtonTypePlayerPause,
    KATButtonTypePlayerStop,
    KATButtonTypePlayerFilledPlay=311,
    KATButtonTypePlayerFilledPause,
    KATButtonTypePlayerFilledStop,
    KATButtonTypePlayerLinearPlay=321,
    KATButtonTypePlayerLinearPause,
    KATButtonTypePlayerSoundOn=351,
    KATButtonTypePlayerSoundOff,
    
    //编辑
    KATButtonTypeOK=401,
    KATButtonTypeClose,
    KATButtonTypeEdit,
    KATButtonTypeRemove,
    KATButtonTypeAdd,
    KATButtonTypeReduce=406,
    KATButtonTypeCheck,
    KATButtonTypeBackspace,
    KATButtonTypeSetting,
    KATButtonTypeEnter,
    KATButtonTypeLeave=411,
    KATButtonTypeSort,
    KATButtonTypePick,
    
    //图标
    KATButtonTypeSearch=501,
    KATButtonTypeZoomIn,
    KATButtonTypeZoomOut,
    KATButtonTypeUser,
    KATButtonTypePlus,
    KATButtonTypeMinus=506,
    KATButtonTypeMultiply,
    KATButtonTypeDivision,
    KATButtonTypePercent,
    KATButtonTypeReload,
    KATButtonTypeUpdate=511,
    KATButtonTypeDownload,
    KATButtonTypeUpload,
    KATButtonTypeRefresh,
    KATButtonTypeLocation,
    KATButtonTypeNearby=516,
    KATButtonTypeCoordinate,
    KATButtonTypeSend,
    KATButtonTypeMail,
    KATButtonTypeComment,
    KATButtonTypeChat=521,
    KATButtonTypeFocus,
    KATButtonTypeRoundedFocus,
    KATButtonTypeScan,
    KATButtonTypeRoundedScan,
    KATButtonTypeCamera=526,
    KATButtonTypeCalendar,
    KATButtonTypeBluetooth,
    KATButtonTypeBrightness,
    KATButtonTypeNight,
    KATButtonTypeMicphone=531,
    KATButtonTypeFlying,
    KATButtonTypeHome,
    KATButtonTypeMore,
    KATButtonTypeList,
    KATButtonTypeClock=536,
    KATButtonTypeDocument,
    KATButtonTypeBalance,
    KATButtonTypeBooking,
    KATButtonTypeCure,
    KATButtonTypeAid=541,
    KATButtonTypeMicroscope,
    KATButtonTypeWifi,
    KATButtonTypeBroadcast,
    KATButtonTypeBroadcast2,
    KATButtonTypeSubscription=546,
    KATButtonTypeNorth,
    KATButtonTypeArticle,
    KATButtonTypeCloud,
    KATButtonTypeCloudDownload,
    KATButtonTypeCloudUpload=551,
    KATButtonTypeLock,
    KATButtonTypeImage,
    KATButtonTypeBrokenImage,
    KATButtonTypeFemale,
    KATButtonTypeMale=556,
    KATButtonTypeSun,
    KATButtonTypeMoon,
    KATButtonTypeLightning,
    KATButtonTypeInfomation,
    KATButtonTypeForbid=561,
    KATButtonTypeBan,
    KATButtonTypeQuestion,
    KATButtonTypeCaution,
    KATButtonTypeTarget,
    KATButtonTypeCall=566,
    KATButtonTypePhone,
    KATButtonTypeAries,
    KATButtonTypeTaurus,
    KATButtonTypeGemini,
    KATButtonTypeCancer=571,
    KATButtonTypeLeo,
    KATButtonTypeVirgo,
    KATButtonTypeLibra,
    KATButtonTypeScorpio,
    KATButtonTypeSagittarius=576,
    KATButtonTypeCapricorn,
    KATButtonTypeAquarius,
    KATButtonTypePisces,
    
    //图表
    KATButtonTypeLineChart=701,
    KATButtonTypeLineChart2,
    KATButtonTypeLineChart3,
    KATButtonTypeAreaChart,
    KATButtonTypeAreaChart2,
    KATButtonTypeBarChart=706,
    KATButtonTypeBarChart2,
    KATButtonTypeStackChart,
    KATButtonTypePieChart,
    
    //键盘
    KATButtonTypeKeyboard0=800,
    KATButtonTypeKeyboard1,
    KATButtonTypeKeyboard2,
    KATButtonTypeKeyboard3,
    KATButtonTypeKeyboard4,
    KATButtonTypeKeyboard5,
    KATButtonTypeKeyboard6,
    KATButtonTypeKeyboard7,
    KATButtonTypeKeyboard8,
    KATButtonTypeKeyboard9,
    KATButtonTypeKeyboardPoint=810,
    KATButtonTypeKeyboardEqual,
    KATButtonTypeKeyboardPlus,
    KATButtonTypeKeyboardMinus,
    KATButtonTypeKeyboardMultipy,
    KATButtonTypeKeyboardDivision=815,
    KATButtonTypeKeyboardPower,
    KATButtonTypeKeyboardPercent,
    KATButtonTypeKeyboardLeftBrackets,
    KATButtonTypeKeyboardRightBrackets,
    KATButtonTypeKeyboardBlank=820,
    KATButtonTypeKeyboardReturn,
    KATButtonTypeKeyboardSlash,
    KATButtonTypeKeyboardShape,
    
    //字符
    KATButtonTypeCharA=901
};




@class KATButton;


//按钮事件协议
@protocol KATButtonDelegate <NSObject>

@optional

/**
 点击事件

 @param button 被点击的按钮
 */
- (void)clickButton:(KATButton *)button;

@end




@interface KATButton : KATSprite


#pragma -mark 属性

///颜色
@property(nonatomic,retain) UIColor *color;

///类型
@property(nonatomic,assign) KATButtonType type;

///线宽
@property(nonatomic,assign) float lineWidth;

///缩放比例
@property(nonatomic,assign) float scale;

///连样式
@property(nonatomic,assign) CGLineJoin lineJoin;

///点样式
@property(nonatomic,assign) CGLineCap lineCap;

///点击动画(置空则无动画)
@property(nonatomic,retain) CAAnimation *onClickAnimation;

///事件代理
@property(nonatomic,assign) id<KATButtonDelegate> eventDelegate;

///点击事件代码块
@property(nonatomic,copy) void (^onClickAction)(void);


#pragma -mark 携带值

///int值
@property(nonatomic,assign) long long index;

///double值
@property(nonatomic,assign) double value;

///字符串值
@property(nonatomic,copy) NSString *message;

///id值
@property(nonatomic,retain) id object;



#pragma -mark 类方法


/**
 获取实例(简化方法)

 @param frame 左上角位置和宽高
 @return 按钮实例
 */
+ (instancetype)buttonWithFrame:(CGRect)frame;


/**
 获取实例(全参数方法)

 @param frame 左上角位置和宽高
 @param type 类型
 @param color 颜色
 @param lineWidth 线宽
 @param scale 缩放比例(1.0为正常的显示比例，小于1.0则显示更小的按钮形状，但不影响点击范围，点击范围由frame决定)
 @param action 点击事件代码块(可以为nil)
 @return 按钮实例
 */
+ (instancetype)buttonWithFrame:(CGRect)frame type:(KATButtonType)type color:(UIColor *)color lineWidth:(float)lineWidth scale:(float)scale andOnClickAction:(void (^)(void))action;



#pragma -mark 对象方法


/**
 按钮转化为图片

 @return 内容为按钮形状的图片
 */
- (UIImage *)button2Image;


/**
 释放内存,解除绑定的内容
 */
- (void)dealloc;


@end



