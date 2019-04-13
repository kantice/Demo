//
//  KATTabBar.h
//  KATFramework
//
//  Created by Yi Yu on 2017/5/26.
//  Copyright © 2017年 KatApp. All rights reserved.
//  标签栏，与路由器结合
//  这个控件的通用性比较差，不建议单独使用
//  圆点徽标、文本徽标在进入该host时，会自动清除，数字徽标不会，需要手动设置


#import "KATSprite.h"
#import "KATShapeUtil.h"
#import "KATMacros.h"
#import "KATLabel.h"


#define TAB_BAR_COUNT_MAX 12


///tab是否点击的key，有该值则为点击
extern NSString *const kTabBarClickingKey;


//样式
typedef NS_ENUM(NSUInteger, KATTabBarStyle)
{
    KATTabBarStyleImageLabel=0,//带图片和标签
    KATTabBarStyleImage,//只有图片
    KATTabBarStyleLabel//只有标签
};


//标签点击动画
typedef NS_ENUM(NSUInteger, KATTabBarAnimation)
{
    KATTabBarAnimationNone=0,//无动画
    KATTabBarAnimationShake,//晃动
    KATTabBarAnimationBlink,//闪烁
    KATTabBarAnimationHeartBeat,//心跳
    KATTabBarAnimationZoom,//聚焦
    KATTabBarAnimationRotate,//逆时针旋转
    KATTabBarAnimationRotateClockwise,//顺时针旋转
    KATTabBarAnimationFlipHorizontal,//水平翻转
    KATTabBarAnimationFlipVertical//垂直翻转
};




@interface KATTabBar : KATSprite <KATSpriteDelegate>


#pragma -mark 属性

///风格
@property(nonatomic,assign) KATTabBarStyle style;

///标签数
@property(nonatomic,assign,readonly) unsigned tabCount;

///选中的标签
@property(nonatomic,assign) unsigned selectedIndex;

///高度
@property(nonatomic,assign) double height;

///间距
@property(nonatomic,assign) double padding;

///图片高度
@property(nonatomic,assign) double imageHeight;

///标签高度
@property(nonatomic,assign) double labelHeight;

///未选中颜色
@property(nonatomic,retain) UIColor *unselectedColor;

///选中颜色
@property(nonatomic,retain) UIColor *selectedColor;

///未选中按钮数组
@property(nonatomic,retain) KATArray<UIImage *> *unselectedImageArray;

///选中的按钮数组
@property(nonatomic,retain) KATArray<UIImage *> *selectedImageArray;

///标签数组
@property(nonatomic,retain) KATArray<NSString *> *textArray;

///关联的host数组
@property(nonatomic,retain) KATArray<NSString *> *hostArray;

///模糊背景视图
@property(nonatomic,retain) UIVisualEffectView *blurView;

///转场动画风格
@property(nonatomic,assign) NSUInteger transitionStyle;

///转场动画时长
@property(nonatomic,assign) double transitionDuration;

///标签点击动画
@property(nonatomic,assign) KATTabBarAnimation tapAnimation;

///是否为中心按钮模式
@property(nonatomic,assign,readonly) BOOL isCenterButtonMode;

///是否有动画
@property(nonatomic,assign) BOOL hasAnimation;

///动画时长
@property(nonatomic,assign) double animationDuration;

///中心按钮
@property(nonatomic,retain,readonly) KATSprite *centerButton;

///标记点颜色
@property(nonatomic,retain) UIColor *badgeColor;

///数字徽标样式
@property(nonatomic,retain) KATTextStyle *numberBadgeStyle;

///文本徽标样式
@property(nonatomic,retain) KATTextStyle *textBadgeStyle;

///标签按钮点击事件
@property(nonatomic,copy) void (^buttonTapedAction)(NSString *host);



#pragma -mark 类方法

///获取实例(纯文本风格)
+ (instancetype)tabBarWithUnselectedColor:(UIColor *)uColor selectedColor:(UIColor *)sColor text:(KATArray<NSString *> *)text andHosts:(KATArray<NSString *> *)hosts;


///获取实例(纯图片风格)
+ (instancetype)tabBarWithUnselectedImages:(KATArray<UIImage *> *)uImages selectedImages:(KATArray<UIImage *> *)sImages andHosts:(KATArray<NSString *> *)hosts;


///获取实例(纯图片风格，通过KATButton来构造)
+ (instancetype)tabBarWithButtonTypes:(NSArray<NSNumber *> *)types lineWidth:(float)lineWidth scale:(float)scale unselectedColor:(UIColor *)uColor selectedColor:(UIColor *)sColor andHosts:(KATArray<NSString *> *)hosts;


///获取实例(通过KATButton来构造)
+ (instancetype)tabBarWithButtonTypes:(NSArray<NSNumber *> *)types lineWidth:(float)lineWidth scale:(float)scale unselectedColor:(UIColor *)uColor selectedColor:(UIColor *)sColor text:(KATArray<NSString *> *)text andHosts:(KATArray<NSString *> *)hosts;


///获取实例(全参数)
+ (instancetype)tabBarWithStyle:(KATTabBarStyle)style count:(unsigned)count unselectedColor:(UIColor *)uColor selectedColor:(UIColor *)sColor unselectedImages:(KATArray<UIImage *> *)uImages selectedImages:(KATArray<UIImage *> *)sImages text:(KATArray<NSString *> *)text andHosts:(KATArray<NSString *> *)hosts;



#pragma -mark 对象方法

///添加中心按钮(标签数为偶数个，且为带图片标签风格才能添加中心按钮)
- (void)addCenterButton:(KATSprite *)button withOnClickAction:(void (^)(void))action;

///删除中心按钮
- (void)removeCenterButton;

///更新内容
- (void)update;

///选中索引
- (void)selectWithIndex:(unsigned)index;

///选中host
- (void)selectWithHost:(NSString *)host;

///通过index判断标签栏项目是否有圆点徽标
- (BOOL)hasBadgeWithIndex:(unsigned)index;

///通过host判断标签栏项目是否有圆点徽标
- (BOOL)hasBadgeWithHost:(NSString *)host;

///通过index添加标签栏的圆点徽标
- (void)addBadgeWithIndex:(unsigned)index;

///通过host添加标签栏的圆点徽标
- (void)addBadgeWithHost:(NSString *)host;

///通过index删除标签栏的圆点徽标
- (void)removeBadgeWithIndex:(unsigned)index;

///通过host删除标签栏的圆点徽标
- (void)removeBadgeWithHost:(NSString *)host;

///通过index获取标签栏项目的徽标数字
- (int)badgeNumberWithIndex:(unsigned)index;

///通过host获取标签栏项目的徽标数字
- (int)badgeNumberWithHost:(NSString *)host;

///通过index设置标签栏项目的数字徽标
- (void)setBadgeNumber:(int)number withIndex:(unsigned)index;

///通过host设置标签栏项目的数字徽标
- (void)setBadgeNumber:(int)number withHost:(NSString *)host;

///通过index获取标签栏项目的徽标文本
- (NSString *)badgeTextWithIndex:(unsigned)index;

///通过host获取标签栏项目的徽标文本
- (NSString *)badgeTextWithHost:(NSString *)host;

///通过index设置标签栏项目的文本徽标
- (void)setBadgeText:(NSString *)text withIndex:(unsigned)index;

///通过host设置标签栏项目的文本徽标
- (void)setBadgeText:(NSString *)text withHost:(NSString *)host;

///清除所有的徽标
- (void)clearBadges;

///更改图片
- (void)changeWithUnselectedImage:(UIImage *)uImage selectedImage:(UIImage *)sImage forHost:(NSString *)host;

///更改图片
- (void)changeWithUnselectedImage:(UIImage *)uImage selectedImage:(UIImage *)sImage forIndex:(unsigned)index;

///更改文本
- (void)changeWithText:(NSString *)text forHost:(NSString *)host;

///更改文本
- (void)changeWithText:(NSString *)text forIndex:(unsigned)index;

///获取选中的host
- (NSString *)selectedHost;

///获取选中的URI
- (NSString *)selectedURI;

///判断host是否与tab栏关联
- (BOOL)isHostInTab:(NSString *)host;

///判断VC是否与tab栏关联
- (BOOL)isInstanceInTab:(UIViewController *)instance;

///显示
- (void)show;

///隐藏
- (void)hide;



@end


