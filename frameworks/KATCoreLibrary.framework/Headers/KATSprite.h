//
//  KATSprite.h
//  KATFramework
//
//  Created by Kantice on 16/3/23.
//  Copyright © 2016年 KatApp. All rights reserved.
//  精灵视图（用作基类或容器，方便使用动画和变形)(UIView关联的Layer不会有隐式动画)
//  为了防止循环引用，从父视图中删除时，会自动停止定时器


/*
 
 3D矩阵详解
 
 
 1    0    0    0
 0    1    0    0
 0    0    1    0
 tx  ty   tz    1
 
 
 struct CATransform3D
 {
    CGFloat     m11（x缩放）,    m12（y切变）,     m13（旋转）,     m14（）;
 
    CGFloat     m21（x切变）,    m22（y缩放）,     m23（）,        m24（）;
 
    CGFloat     m31（旋转）,     m32（ ）,        m33（）,         m34（透视效果，要操作的这个对象要有旋转的角度，否则没有效果。正直/负值都有意义）;
 
    CGFloat     m41（x平移）,    m42（y平移）,     m43（z平移）,    m44（）;
 };
 
 */


#import <UIKit/UIKit.h>
#import "KATQueue.h"
#import "KATColor.h"
#import "KATMacros.h"




#define SPRITE_TYPE_BASIC 1
#define SPRITE_TYPE_KEY_FRAME 2
#define SPRITE_TYPE_PATH 3
#define SPRITE_TYPE_GROUP 4

#define SPRITE_MODE_POSITION 1
#define SPRITE_MODE_OPACITY 2
#define SPRITE_MODE_BG_COLOR 3
#define SPRITE_MODE_BORDER_COLOR 4
#define SPRITE_MODE_BORDER_WIDTH 5
#define SPRITE_MODE_CORNER_RADIUS 6
#define SPRITE_MODE_ROTATION_X 7
#define SPRITE_MODE_ROTATION_Y 8
#define SPRITE_MODE_ROTATION_Z 9
#define SPRITE_MODE_SCALE_X 10
#define SPRITE_MODE_SCALE_Y 11
#define SPRITE_MODE_SCALE_Z 12
#define SPRITE_MODE_SCALE_XY 13
#define SPRITE_MODE_CONTENTS 20




#pragma -mark 常量

///动画键:类型(值为NSString *)
extern NSString * const kSpriteKeyType;

///动画键:模式(值为NSString *)
extern NSString * const kSpriteKeyMode;

///动画键:模式组(动画组属性)(值为KATArray *)
extern NSString * const kSpriteKeyModeGroup;

///动画键:终点位置(值为CGPoint)
extern NSString * const kSpriteKeyPosition;

///动画键:X轴旋转(值为float)
extern NSString * const kSpriteKeyRotationX;

///动画键:Y轴旋转(值为float)
extern NSString * const kSpriteKeyRotationY;

///动画键:Z轴旋转(值为float)
extern NSString * const kSpriteKeyRotationZ;

///动画键:X轴缩放(值为float)
extern NSString * const kSpriteKeyScaleX;

///动画键:Y轴缩放(值为float)
extern NSString * const kSpriteKeyScaleY;

///动画键:Z轴缩放(值为float)
extern NSString * const kSpriteKeyScaleZ;

///动画键:XY轴缩放(值为float)
extern NSString * const kSpriteKeyScaleXY;

///动画键:内容(值为UIImage)
extern NSString * const kSpriteKeyContents;

///动画键:3d变形(值为Transform3D)
extern NSString * const kSpriteKey3DTransform;

///动画键:转场类型
extern NSString * const kSpriteKeyTransition;

///动画键:不透明度(值为float)
extern NSString * const kSpriteKeyOpacity;

///动画键:背景色(值为UIColor *)
extern NSString * const kSpriteKeyBgColor;

///动画键:圆角半径(值为float)
extern NSString * const kSpriteKeyCornerRadius;

///动画键:边线宽(值为float)
extern NSString * const kSpriteKeyBorderWidth;

///动画键:边线色(值为UIColor *)
extern NSString * const kSpriteKeyBorderColor;

///动画键:名称(值为NSString *)
extern NSString * const kSpriteKeyName;

///动画默认值:名称
extern NSString * const kSpriteDefaultName;

///动画模式:位移
extern NSString * const kSpriteModePosition;

///动画模式:X轴旋转
extern NSString * const kSpriteModeRotationX;

///动画模式:Y轴旋转
extern NSString * const kSpriteModeRotationY;

///动画模式:Z轴旋转
extern NSString * const kSpriteModeRotationZ;

///动画模式:X轴缩放
extern NSString * const kSpriteModeScaleX;

///动画模式:Y轴缩放
extern NSString * const kSpriteModeScaleY;

///动画模式:Z轴缩放
extern NSString * const kSpriteModeScaleZ;

///动画模式:XY轴缩放
extern NSString * const kSpriteModeScaleXY;

///动画模式:内容
extern NSString * const kSpriteModeContents;

///动画模式:3d变形(包含了缩放和旋转)
extern NSString * const kSpriteMode3DTransform;

///动画模式:不透明度
extern NSString * const kSpriteModeOpacity;

///动画模式:背景色
extern NSString * const kSpriteModeBgColor;

///动画模式:圆角半径
extern NSString * const kSpriteModeCornerRadius;

///动画模式:线宽
extern NSString * const kSpriteModeBorderWidth;

///动画模式:边线色
extern NSString * const kSpriteModeBorderColor;

///动画类型:基础
extern NSString * const kSpriteTypeBasic;

///动画类型:关键帧
extern NSString * const kSpriteTypeKeyFrame;

///动画类型:路径
extern NSString * const kSpriteTypePath;

///动画类型:组
extern NSString * const kSpriteTypeGroup;

///动画类型:转场
extern NSString * const kSpriteTypeTransition;


///常用动画:心跳
extern NSString * const kSpriteAnimationHeartbeat;

///常用动画:闪烁
extern NSString * const kSpriteAnimationBlink;

///常用动画:旋转
extern NSString * const kSpriteAnimationRotate;

///常用动画:翻转
extern NSString * const kSpriteAnimationFlip;

///常用动画:摇晃
extern NSString * const kSpriteAnimationShake;

///常用动画:震动
extern NSString * const kSpriteAnimationShock;

///常用动画:抖动
extern NSString * const kSpriteAnimationDither;

///常用动画:消失
extern NSString * const kSpriteAnimationDisappear;

///常用动画:出现
extern NSString * const kSpriteAnimationAppear;

///常用动画:缩放消失
extern NSString * const kSpriteAnimationScaledDisappear;

///常用动画:缩放出现
extern NSString * const kSpriteAnimationScaledAppear;

///常用动画:焦点进入
extern NSString * const kSpriteAnimationZoomIn;

///常用动画:焦点出去
extern NSString * const kSpriteAnimationZoomOut;

///常用动画:滚动
extern NSString * const kSpriteAnimationRoll;

///常用动画:滚进
extern NSString * const kSpriteAnimationRollIn;

///常用动画:滚出
extern NSString * const kSpriteAnimationRollOut;

///常用动画:旋转进
extern NSString * const kSpriteAnimationRotateIn;

///常用动画:旋转出
extern NSString * const kSpriteAnimationRotateOut;

///常用动画:掉落
extern NSString * const kSpriteAnimationDrop;

///常用动画:飘落
extern NSString * const kSpriteAnimationFloat;

///常用动画:快速移动
extern NSString * const kSpriteAnimationMoveQuickly;

///常用动画:移动
extern NSString * const kSpriteAnimationMove;

///常用动画:移动进来
extern NSString * const kSpriteAnimationComeIn;

///常用动画:移动出去
extern NSString * const kSpriteAnimationGoOut;

///常用动画:跳跃
extern NSString * const kSpriteAnimationJump;



//内容自动调整尺寸类型枚举
typedef NS_ENUM(NSUInteger, KATSpriteResizeType)
{
    KATSpriteResizeTypeNone=0,//不自动调整尺寸
    KATSpriteResizeTypeDefault=1,//左上角位置不变，不超过原来的尺寸
    KATSpriteResizeTypeCenter=2,//中心位置不变，不超过原来的尺寸
    KATSpriteResizeTypeCenterHorizontal=3,//水平方向中心位置不变，不超过原来的尺寸
    KATSpriteResizeTypeCenterVertical=4,//垂直方向中心位置不变，不超过原来的尺寸
    KATSpriteResizeTypeOriginal=5,//左上角位置不变，图片原始尺寸
    KATSpriteResizeTypeCenterOriginal=6//中心位置不变，图片原始尺寸
};



@class KATSprite;

@protocol KATSpriteDelegate <NSObject>

@optional

///动画开始
- (void)sprite:(KATSprite *)sprite didStartAnimation:(NSString *)animation;

///动画停止
- (void)sprite:(KATSprite *)sprite didStopAnimation:(NSString *)animation finished:(BOOL)flag;

///更改内容(图片)
- (void)spriteDidChangeContent:(KATSprite *)sprite;

///调整尺寸
- (void)spriteDidResize:(KATSprite *)sprite;

@end




@interface KATSprite : UIView <CAAnimationDelegate>


#pragma -mark 属性


///等待执行动画队列
@property(nonatomic,retain) KATQueue<__kindof CAAnimation *> *animationQueue;

///是否在执行动画
@property(nonatomic,assign) BOOL animating;

///是否在动画结束后回到原来位置
@property(nonatomic,assign) BOOL restoreAfterAnimating;

///是否在动画进行时交互
@property(nonatomic,assign) BOOL interactInAnimating;

///是否在动画停止时保持当前状态
@property(nonatomic,assign) BOOL keepStateOnStop;

///是否手动停止动画
@property(nonatomic,assign) BOOL animationStoped;

///执行的动画
@property(nonatomic,retain) CAAnimation *animation;

///x轴旋转角度
@property(nonatomic,assign) float angleX;

///y轴旋转角度
@property(nonatomic,assign) float angleY;

///z轴旋转角度
@property(nonatomic,assign) float angleZ;

///x轴尺寸比例
@property(nonatomic,assign) float sizeX;

///y轴尺寸比例
@property(nonatomic,assign) float sizeY;

///z轴尺寸比例
@property(nonatomic,assign) float sizeZ;

///XY轴等比例
@property(nonatomic,assign) float sizeXY;

///透视点(x轴或y轴旋转时才有效果)，负数表示透视点在后，一般在-0.001~-0.002之间比较合适，越接近0效果越少，用公式表示则为-1/d(透视点在后)，d为眼睛离屏幕的距离，单位为像素
@property(nonatomic,assign) float perspective;

///原始内容(图片)
@property(nonatomic,retain) UIImage *contents;

///当前展示图层
@property(nonatomic,readonly) CALayer *presentLayer;

///是否自动调整尺寸(在内容发生变化时)
@property(nonatomic,assign) BOOL isAutoResize;

///调整尺寸类型
@property(nonatomic,assign) KATSpriteResizeType resizeType;

///代理
@property(nonatomic,assign) id<KATSpriteDelegate> spriteDelegate;


///动画计算模式(作用于关键帧、路径动画)
///kCAAnimationLinear(线性模式,默认)
///kCAAnimationPaced(均匀模式,会忽略keyTimes)
///kCAAnimationDiscrete(离散模式，没有过渡动画)
///kCAAnimationCubic(平滑模式，对于位置变动关键帧动画运行轨迹更平滑)
///kCAAnimationCubicPaced(平滑均匀模式)
@property(nonatomic,copy) NSString *animationCalculationMode;

///动画填充模式(作用于关键帧、路径动画)
///kCAFillModeRemoved(默认填充模式，无填充)
///kCAFillModeForwards(前段填充模式)
///kCAFillModeBackwards(后段填充模式)
///kCAFillModeBoth(前后段填充模式)
@property(nonatomic,copy) NSString *animationFillMode;

///动画转向模式(作用于位移关键帧、路径动画)(默认为空，不改变方向)
///kCAAnimationRotateAuto(自动模式，沿轨迹改变方向)
///kCAAnimationRotateAutoReverse(自动反转模式)
@property(nonatomic,copy) NSString *animationRotateMode;

///动画时间模式
///kCAMediaTimingFunctionDefault(默认，先加速后减速)
///kCAMediaTimingFunctionLinear(线性)
///kCAMediaTimingFunctionEaseIn(加速)
///kCAMediaTimingFunctionEaseOut(减速)
///kCAMediaTimingFunctionEaseInEaseOut(先加速后减速)
@property(nonatomic,copy) NSString *animationTimingMode;

///系统刷屏定时器
@property(nonatomic,retain) CADisplayLink *displayLinkTimer;

///系统刷屏动作是否进行
@property(nonatomic,assign) BOOL displayLinkActionsRunning;

///系统刷屏动作
@property(nonatomic,copy) void (^displayLinkActions)(void);


#pragma -mark 类方法

///获取实例
+ (instancetype)sprite;

/** 获取转场动画
 
    动画类型  说明              对应常量 是否支持方向设置
 
    公开API
    fade    淡出效果            kCATransitionFade      是
    movein  新视图移动到旧视图上  kCATransitionMoveIn    是
    push    新视图推出旧视图     kCATransitionPush      是
    reveal  移开旧视图显示新视图  kCATransitionReveal    是
 
    私有API	 	私有API只能通过字符串访问
    cube	立方体翻转效果	无	是
    oglFlip	翻转效果	无	是
    suckEffect	收缩效果	无	否
    rippleEffect    水滴波纹效果	无	否
    pageCurl	向上翻页效果	无	是
    pageUnCurl	向下翻页效果	无	是
    cameralIrisHollowOpen	摄像头打开效果	无	否
    cameraIrisHollowClose	摄像头关闭效果	无	否
 
    动画子类型                    说明
    kCATransitionFromRight      从右侧转场
    kCATransitionFromLeft       从左侧转场
    kCATransitionFromTop        从顶部转场
    kCATransitionFromBottom     从底部转场
 */
+ (CATransition *)transitionWithType:(NSString *)type subtype:(NSString *)subType duration:(double)duration delay:(float)delay;



#pragma -mark 获取动画

///获取位移动画
- (CABasicAnimation *)animationToPosition:(CGPoint)position withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取不透明度动画
- (CABasicAnimation *)animationToOpacity:(float)opacity withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取背景色动画
- (CABasicAnimation *)animationBgToColor:(UIColor *)color withDuration:(double)duration repeat:(float)repeat delay:(float)delay;

///获取边线色动画
- (CABasicAnimation *)animationBorderToColor:(UIColor *)color withDuration:(double)duration repeat:(float)repeat delay:(float)delay;

///获取边线宽动画
- (CABasicAnimation *)animationBorderToWidth:(float)width withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取圆角半径动画
- (CABasicAnimation *)animationCornerToRadius:(float)radius withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取X轴旋转动画
- (CABasicAnimation *)animationRotationXToAngle:(float)angle withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取Y轴旋转动画
- (CABasicAnimation *)animationRotationYToAngle:(float)angle withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取Z轴旋转动画
- (CABasicAnimation *)animationRotationZToAngle:(float)angle withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取X轴缩放动画
- (CABasicAnimation *)animationScaleXToSize:(float)size withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取Y轴缩放动画
- (CABasicAnimation *)animationScaleYToSize:(float)size withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取Z轴(2D关系没有效果)缩放动画
- (CABasicAnimation *)animationScaleZToSize:(float)size withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取XY轴(等比例)缩放动画
- (CABasicAnimation *)animationScaleXYToSize:(float)size withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取路径动画(特殊的位移关键帧动画，优先级高于位移关键帧)
- (CAKeyframeAnimation *)animationWithPath:(UIBezierPath *)path duration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取关键帧动画（!颜色属性无效果）(!Z轴旋转会使XY缩放反向)
- (CAKeyframeAnimation *)animationWithMode:(int)mode keyValues:(NSArray *)values keyTimes:(NSArray *)times duration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取动画组
- (CAAnimationGroup *)animationWithGroup:(NSArray *)group duration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;


#pragma -mark 动画执行

///开始动画(设置动画名字),同一时间只能执行一个动画（组）
- (void)startAnimation:(CAAnimation *)animation withName:(NSString *)name andDelay:(double)delay;

///开始动画(默认动画名字),同一时间只能执行一个动画（组）
- (void)startAnimation:(CAAnimation *)animation andDelay:(double)delay;

///停止并移除当前动画
- (void)stopAnimation;

///暂停动画
- (void)pauseAnimation;

///恢复动画
- (void)resumeAnimation;

///开始系统刷屏动作(interval表示每间隔几帧刷屏执行一次，1代表每帧执行一次，约为每秒60次),不能同时进行多个刷屏动作，新的会替换旧的
- (void)startDisplayLinkActions:(void (^)(void))actions withFrameInterval:(int)interval;

///停止并移除系统刷屏动作
- (void)stopDisplayLinkActions;

///清除所有动画(包括当前动画和队列里的动画)
- (void)clearAnimations;


#pragma -mark 变形

///旋转(相对初始值)
- (void)transformRotateToAngle:(float)angle;

///旋转X轴（上下转）
- (void)transformRotateXToAngle:(float)angle;

///旋转Y轴（左右转）
- (void)transformRotateYToAngle:(float)angle;

///水平镜像(相对初始值)
- (void)transformHorizontalMirror;

///垂直镜像(相对初始值)
- (void)transformVerticalMirror;

///缩放(相对初始值)(宽高,比例,1为原始值)
- (void)transformScaleToWitdh:(float)width andHeight:(float)height;

///复位
- (void)restoreSprite;

///内容调整尺寸
- (void)resizeForContents;


#pragma -mark 常用动画

///心跳(等比缩放)(参数小于0则用默认值)
- (void)heartbeatWithScale:(float)scale duration:(double)duration repeat:(float)repeat;

///闪烁(透明变化)(参数小于0则用默认值)
- (void)blinkWithAlpha:(float)alpha duration:(double)duration repeat:(float)repeat;

///转动(Z轴旋转)(参数小于0则用默认值)
- (void)rotateWithDuration:(double)duration repeat:(float)repeat clockwise:(BOOL)clockwise;

///翻转(XY轴旋转)(参数小于0则用默认值)
- (void)flipWithDuration:(double)duration repeat:(float)repeat clockwise:(BOOL)clockwise vertical:(BOOL)vertical;

///摇晃(左右)(参数小于0则用默认值)
- (void)shakeWithDegree:(float)degree duration:(double)duration repeat:(float)repeat;

///震动(上下)(参数小于0则用默认值)
- (void)shockWithDegree:(float)degree duration:(double)duration repeat:(float)repeat;

///抖动(旋转)(参数小于0则用默认值)
- (void)ditherWithDegree:(float)degree duration:(double)duration repeat:(float)repeat;

///消失(透明变化)
- (void)disappearWithDuration:(double)duration;

///出现(透明变化)
- (void)appearWithDuration:(double)duration;

///消失(缩放变化)
- (void)scaledDisappearWithDuration:(double)duration;

///出现(缩放变化)
- (void)scaledAppearWithDuration:(double)duration;

///焦点出(缩放、透明变化)
- (void)zoomOutWithScale:(float)scale duration:(double)duration;

///焦点进(缩放、透明变化)
- (void)zoomInWithScale:(float)scale duration:(double)duration;

///滚动(旋转、位移变化)
- (void)rollToPosition:(CGPoint)position withDuration:(double)duration;

///滚进(旋转、位移、透明变化)
- (void)rollInToPosition:(CGPoint)position withDuration:(double)duration;

///滚出(旋转、位移、透明变化)
- (void)rollOutToPosition:(CGPoint)position withDuration:(double)duration;

///转进(旋转、缩放、透明变化)
- (void)rotateInWithCircles:(int)circles duration:(double)duration;

///转出(旋转、缩放、透明变化)
- (void)rotateOutWithCircles:(int)circles duration:(double)duration;

///掉落
- (void)dropToPosition:(CGPoint)position withDuration:(double)duration;

///飘落
- (void)floatToPosition:(CGPoint)position withDuration:(double)duration;

///快速移动
- (void)moveQuicklyToPosition:(CGPoint)position withDegree:(float)degree duration:(double)duration;

///移动
- (void)moveToPosition:(CGPoint)position withDuration:(double)duration;

///移动出现
- (void)comeInToPosition:(CGPoint)position withDuration:(double)duration;

///移动消失
- (void)goOutToPosition:(CGPoint)position withDuration:(double)duration;

///跳跃
- (void)jumpToPosition:(CGPoint)position withHeight:(float)height andDuration:(double)duration;



#pragma -mark 播放(空实现,为了方便调用子类的播放动画方法)

///重新播放
- (void)replay;

///播放（继续播放）
- (void)play;

///停止
- (void)stop;




///释放内存
- (void)dealloc;




@end
