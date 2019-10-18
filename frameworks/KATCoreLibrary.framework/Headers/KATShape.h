//
//  KATShape.h
//  KATFramework
//
//  Created by Kantice on 16/6/21.
//  Copyright © 2016年 KatApp. All rights reserved.
//  带动画函数的CAShapeLayer(主要实现ShapeLayer特有的动画)

#import <UIKit/UIKit.h>
#import "KATQueue.h"


#define SHAPE_TYPE_BASIC 1
#define SHAPE_TYPE_KEY_FRAME 2
#define SHAPE_TYPE_PATH 3
#define SHAPE_TYPE_GROUP 4

#define SHAPE_MODE_POSITION 1
#define SHAPE_MODE_OPACITY 2
#define SHAPE_MODE_ROTATION_X 7
#define SHAPE_MODE_ROTATION_Y 8
#define SHAPE_MODE_ROTATION_Z 9
#define SHAPE_MODE_SCALE_X 10
#define SHAPE_MODE_SCALE_Y 11
#define SHAPE_MODE_SCALE_Z 12
#define SHAPE_MODE_SCALE_XY 13
#define SHAPE_MODE_STROKE_START 14
#define SHAPE_MODE_STROKE_END 15
#define SHAPE_MODE_LINE_WIDTH 16
#define SHAPE_MODE_FILL_COLOR 17
#define SHAPE_MODE_STROKE_COLOR 18


#pragma -mark 常量

///动画键:类型(值为NSString *)
extern NSString * const kShapeKeyType;

///动画键:模式(值为NSString *)
extern NSString * const kShapeKeyMode;

///动画键:模式组(动画组属性)(值为KATArray *)
extern NSString * const kShapeKeyModeGroup;

///动画键:绘制起始点(值为float)
extern NSString * const kShapeKeyStrokeStart;

///动画键:绘制结束点(值为float)
extern NSString * const kShapeKeyStrokeEnd;

///动画键:线宽(值为float)
extern NSString * const kShapeKeyLineWidth;

///动画键:填充色(值为UIColor *)
extern NSString * const kShapeKeyFillColor;

///动画键:绘制色(值为UIColor *)
extern NSString * const kShapeKeyStrokeColor;

///动画键:终点位置(值为CGPoint)
extern NSString * const kShapeKeyPosition;

///动画键:X轴旋转(值为float)
extern NSString * const kShapeKeyRotationX;

///动画键:Y轴旋转(值为float)
extern NSString * const kShapeKeyRotationY;

///动画键:Z轴旋转(值为float)
extern NSString * const kShapeKeyRotationZ;

///动画键:X轴缩放(值为float)
extern NSString * const kShapeKeyScaleX;

///动画键:Y轴缩放(值为float)
extern NSString * const kShapeKeyScaleY;

///动画键:Z轴缩放(值为float)
extern NSString * const kShapeKeyScaleZ;

///动画键:XY轴缩放(值为float)
extern NSString * const kShapeKeyScaleXY;

///动画键:3d变形(值为Transform3D)
extern NSString * const kShapeKey3DTransform;

///动画键:转场类型
extern NSString * const kShapeKeyTransition;

///动画键:不透明度(值为float)
extern NSString * const kShapeKeyOpacity;

///动画键:名称(值为NSString *)
extern NSString * const kShapeKeyName;

///动画默认值:名称
extern NSString * const kShapeDefaultName;

///动画模式:绘制起始点
extern NSString * const kShapeModeStrokeStart;

///动画模式:绘制结束点
extern NSString * const kShapeModeStrokeEnd;

///动画模式:线宽
extern NSString * const kShapeModeLineWidth;

///动画模式:填充色
extern NSString * const kShapeModeFillColor;

///动画模式:绘制色
extern NSString * const kShapeModeStrokeColor;

///动画模式:位移
extern NSString * const kShapeModePosition;

///动画模式:X轴旋转
extern NSString * const kShapeModeRotationX;

///动画模式:Y轴旋转
extern NSString * const kShapeModeRotationY;

///动画模式:Z轴旋转
extern NSString * const kShapeModeRotationZ;

///动画模式:X轴缩放
extern NSString * const kShapeModeScaleX;

///动画模式:Y轴缩放
extern NSString * const kShapeModeScaleY;

///动画模式:Z轴缩放
extern NSString * const kShapeModeScaleZ;

///动画模式:XY轴缩放
extern NSString * const kShapeModeScaleXY;

///动画模式:3d变形(包含了缩放和旋转)
extern NSString * const kShapeMode3DTransform;

///动画模式:不透明度
extern NSString * const kShapeModeOpacity;


///动画类型:基础
extern NSString * const kShapeTypeBasic;

///动画类型:关键帧
extern NSString * const kShapeTypeKeyFrame;

///动画类型:路径
extern NSString * const kShapeTypePath;

///动画类型:组
extern NSString * const kShapeTypeGroup;

///动画类型:转场
extern NSString * const kShapeTypeTransition;


///常用动画:心跳
extern NSString * const kShapeAnimationHeartbeat;

///常用动画:闪烁
extern NSString * const kShapeAnimationBlink;

///常用动画:旋转
extern NSString * const kShapeAnimationRotate;

///常用动画:翻转
extern NSString * const kShapeAnimationFlip;

///常用动画:摇晃
extern NSString * const kShapeAnimationShake;

///常用动画:震动
extern NSString * const kShapeAnimationShock;

///常用动画:抖动
extern NSString * const kShapeeAnimationDither;

///常用动画:消失
extern NSString * const kShapeAnimationDisappear;

///常用动画:出现
extern NSString * const kShapeAnimationAppear;

///常用动画:缩放消失
extern NSString * const kShapeAnimationScaledDisappear;

///常用动画:缩放出现
extern NSString * const kShapeAnimationScaledAppear;

///常用动画:焦点进入
extern NSString * const kShapeAnimationZoomIn;

///常用动画:焦点出去
extern NSString * const kShapeAnimationZoomOut;

///常用动画:滚动
extern NSString * const kShapeAnimationRoll;

///常用动画:滚进
extern NSString * const kShapeAnimationRollIn;

///常用动画:滚出
extern NSString * const kShapeAnimationRollOut;

///常用动画:旋转进
extern NSString * const kShapeAnimationRotateIn;

///常用动画:旋转出
extern NSString * const kShapeAnimationRotateOut;

///常用动画:掉落
extern NSString * const kShapeAnimationDrop;

///常用动画:飘落
extern NSString * const kShapeAnimationFloat;

///常用动画:快速移动
extern NSString * const kShapeAnimationMoveQuickly;

///常用动画:移动
extern NSString * const kShapeAnimationMove;

///常用动画:移动进来
extern NSString * const kShapeAnimationComeIn;

///常用动画:移动出去
extern NSString * const kShapeAnimationGoOut;

///常用动画:描绘
extern NSString * const kShapeAnimationDraw;

///常用动画:擦除
extern NSString * const kShapeAnimationErase;

///常用动画:闪现路径
extern NSString * const kShapeAnimationShowPath;

///常用动画:绘制范围
extern NSString * const kShapeAnimationStrokeRange;

///常用动画:跳跃
extern NSString * const kShapeAnimationJump;



@class KATShape;

@protocol KATShapeDelegate <NSObject>

@optional

///动画开始
- (void)shape:(KATShape *)shape didStartAnimation:(NSString *)animation;

///动画停止
- (void)shape:(KATShape *)shape didStopAnimation:(NSString *)animation finished:(BOOL)flag;

@end


@interface KATShape : CAShapeLayer <CAAnimationDelegate>


#pragma -mark 属性

///标记
@property(nonatomic,assign) long long int tag;

///等待执行动画队列
@property(nonatomic,retain) KATQueue<__kindof CAAnimation *> *animationQueue;

///是否在执行动画
@property(nonatomic,assign) BOOL animating;

///是否在动画结束后回到原来位置
@property(nonatomic,assign) BOOL restoreAfterAnimating;

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

///当前展示图层
@property(nonatomic,readonly) CAShapeLayer *presentLayer;

///代理
@property(nonatomic,assign) id<KATShapeDelegate> shapeDelegate;


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



#pragma -mark 类方法

///获取实例
+ (instancetype)shape;


#pragma -mark 获取动画

///获取描绘起始点动画(起始结束值在0~1之间)
- (CABasicAnimation *)animationStrokeStartToValue:(float)value withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取描绘结束点动画(起始结束值在0~1之间)
- (CABasicAnimation *)animationStrokeEndToValue:(float)value withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取线宽动画
- (CABasicAnimation *)animationLineWidth:(float)width withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取填充色动画
- (CABasicAnimation *)animationFillColor:(UIColor *)color withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取描绘色动画
- (CABasicAnimation *)animationStrokeColor:(UIColor *)color withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取位移动画
- (CABasicAnimation *)animationToPosition:(CGPoint)position withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取不透明度动画
- (CABasicAnimation *)animationToOpacity:(float)opacity withDuration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

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

///获取关键帧动画
- (CAKeyframeAnimation *)animationWithMode:(int)mode keyValues:(NSArray *)values keyTimes:(NSArray *)times duration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;

///获取动画组
- (CAAnimationGroup *)animationWithGroup:(NSArray<CAAnimation *> *)group duration:(double)duration repeat:(float)repeat autoreverses:(BOOL)autoreverses delay:(float)delay;


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
- (void)transformScaleToWidth:(float)width andHeight:(float)height;

///复位
- (void)restoreShape;


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

///绘制
- (void)drawShapeReverse:(BOOL)reverse withDuration:(double)duration;

///擦除
- (void)eraseShapeReverse:(BOOL)reverse withDuration:(double)duration;

///显示路径(范围为0~1)
- (void)showPathRange:(float)range reverse:(BOOL)reverse withDuration:(double)duration;

///绘制范围
- (void)strokeRangeWithStart:(float)start end:(float)end duration:(double)duration;

///跳跃
- (void)jumpToPosition:(CGPoint)position withHeight:(float)height andDuration:(double)duration;

///释放内存
- (void)dealloc;


@end








