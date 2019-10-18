//
//  KATShapeUtil.h
//  KATFramework
//
//  Created by Kantice on 16/3/20.
//  Copyright © 2016年 KatApp. All rights reserved.
//  形状工具，用于获取常用的形状（KATShape）

#import <UIKit/UIKit.h>
#import "KATShape.h"
#import "KATColor.h"
#import "KATFloatArray.h"
#import "KATMath.h"


//默认线色
#define SHAPE_COLOR_STROKE_DEFAULT KCOLOR_GRAY

//默认填充色
#define SHAPE_COLOR_FILL_DEFAULT KCOLOR_CLEAR

//默认线宽
#define SHAPE_LINE_WIDTH_DEFAULT 1.0


//形状类型
typedef NS_ENUM(NSUInteger, KATShapeType)
{
    KATShapeTypeNone=0,
    KATShapeTypeEmpty=1,//空
    
    //线型
    KATShapeTypeLineHorizontal,
    KATShapeTypeLineVertical,
    KATShapeTypeLoading,
    KATShapeTypeCheck,
    KATShapeTypeCross,
    KATShapeTypePlus,
    KATShapeTypeJump,
    KATShapeTypeArrowUp,
    KATShapeTypeArrowDown,
    KATShapeTypeArrowLeft,
    KATShapeTypeArrowRight,
    KATShapeTypeDaisy,
    
    //封闭型
    KATShapeTypeRect,
    KATShapeTypeRoundRect,
    KATShapeTypeDiamond,
    KATShapeTypeOval,
    KATShapeTypeTriangle,
    
    //组合型
    KATShapeTypeSuccess,
    KATShapeTypeFail,
    KATShapeTypeAdd,
    
    //数字
    KATShapeTypeNumber0,
    KATShapeTypeNumber1,
    KATShapeTypeNumber2,
    KATShapeTypeNumber3,
    KATShapeTypeNumber4,
    KATShapeTypeNumber5,
    KATShapeTypeNumber6,
    KATShapeTypeNumber7,
    KATShapeTypeNumber8,
    KATShapeTypeNumber9,
    KATShapeTypeNumber10,
    
    //字母
    KATShapeTypeLetterA,
    KATShapeTypeLetterJ,
    KATShapeTypeLetterK,
    KATShapeTypeLetterQ,
    
    //花色
    KATShapeTypeSuitJoker,
    KATShapeTypeSuitSpade,
    KATShapeTypeSuitHeart,
    KATShapeTypeSuitClub,
    KATShapeTypeSuitDiamond
};


@interface KATShapeUtil : NSObject


#pragma -mark 通用方法

///获取形状的通用方法
+ (KATShape *)shapeWithType:(KATShapeType)type andWidth:(double)width andHeight:(double)height;

///通过路径获取形状
+ (KATShape *)shapeWithPath:(UIBezierPath *)path;

///形状合成(若非中心对齐，则根据frame为平移，fillRlue默认改为odd)
+ (KATShape *)shapeWithSize:(CGSize)size mergedShapes:(KATArray<KATShape *> *)shapes andAlignCenter:(BOOL)alignCenter;


#pragma -mark 线型

///获取直线
+ (KATShape *)lineShapeWithStartPoint:(CGPoint)startPoint andEndPoint:(CGPoint)endPoint;

///获取三点线型
+ (KATShape *)lineShapeWithPointA:(CGPoint)pa pointB:(CGPoint)pb pointC:(CGPoint)pc;

///获取四点线型
+ (KATShape *)lineShapeWithPointA:(CGPoint)pa pointB:(CGPoint)pb pointC:(CGPoint)pc pointD:(CGPoint)pd;

///获取五点线型
+ (KATShape *)lineShapeWithPointA:(CGPoint)pa pointB:(CGPoint)pb pointC:(CGPoint)pc pointD:(CGPoint)pd pointE:(CGPoint)pe;

///获取N点线型
+ (KATShape *)lineShapeWithPoints:(KATArray *)points andClosed:(BOOL)closed;

///获取N点平滑曲线(平滑度，0.382~0.618之间比较合适)
+ (KATShape *)curveShapeWithPoints:(KATArray *)points andSmooth:(double)smooth closed:(BOOL)closed;

///获取圆弧
+ (KATShape *)arcShapeWithRadius:(double)radius startAngle:(double)startAngle endAngle:(double)endAngle clockwise:(BOOL)clockwise;

///获取勾
+ (KATShape *)checkShapeWithWidth:(double)width andHeight:(double)height;

///获取叉
+ (KATShape *)crossShapeWithWidth:(double)width andHeight:(double)height;

///获取加号
+ (KATShape *)plusShapeWithWidth:(double)width andHeight:(double)height;

///获取跳跃抛物线轨迹
+ (KATShape *)jumpShapeWithStartPoint:(CGPoint)sp endPoint:(CGPoint)ep andHeight:(double)height;

///获取箭头(从上下箭头的角度看:高度为整体高度，宽度为箭头的宽度;左右箭头则相反，长度为箭头的余弦长)(方向:0左、1上、2右、3下)
+ (KATShape *)arrowShapeWithWidth:(double)width height:(double)height length:(double)length andDirection:(int)direction;

///获取菊花(宽度、内径、花瓣数)
+ (KATShape *)daisyShapeWithWidth:(double)width radius:(double)radius andAmounts:(int)amounts;



#pragma -mark 封闭形状

///获取矩形
+ (KATShape *)rectShapeWithWidth:(double)width andHeight:(double)height;

///获取圆角矩形
+ (KATShape *)roundedRectShapeWithWidth:(double)width andHeight:(double)height andCornerRadius:(double)radius;

///获取菱形
+ (KATShape *)diamondShapeWithWidth:(double)width andHeight:(double)height;

///获取圆形
+ (KATShape *)roundShapeWithRadius:(double)radius;

///获取切圆形
+ (KATShape *)cutRoundShapeWithRadius:(double)radius startAngle:(double)startAngle endAngle:(double)endAngle clockwise:(BOOL)clockwise;

///获取椭圆
+ (KATShape *)ovalShapeWithWidth:(double)width andHeight:(double)height;

///获取等腰三角形
+ (KATShape *)isoscelesTriangleShapeWithWidth:(double)width andHeight:(double)height;

///获取等边三角形
+ (KATShape *)equilateralTriangleShapeWithLength:(double)length;

///获取外切圆等边三角形
+ (KATShape *)triangleShapeWithRadius:(double)radius;

///获取三角形
+ (KATShape *)triangleShapeWithPointA:(CGPoint)pa andPointB:(CGPoint)pb andPointC:(CGPoint)pc;

///获取扇形
+ (KATShape *)sectorShapeWithRadius:(double)radius width:(double)width startAngle:(double)startAngle endAngle:(double)endAngle clockwise:(BOOL)clockwise;

///获取气泡(尺寸、圆角半径、箭头点、箭头宽度、箭头高度)(方向:0左、1上、2右、3下)
+ (KATShape *)bubbleShapeWithSize:(CGSize)size cornerRadius:(double)radius andArrowPoint:(CGPoint)point width:(double)width height:(double)height direction:(int)direction;



#pragma -mark 组合形状

///获取成功形状(圆圈＋勾)
+ (KATShape *)successShapeWithWidth:(double)width;

///获取失败形状(圆圈＋叉)
+ (KATShape *)failShapeWithWidth:(double)width;

///获取添加形状(圆圈＋加号)
+ (KATShape *)addShapeWithWidth:(double)width;



#pragma -mark 字符

///获取数字(0~10)
+ (KATShape *)shapeWithNumber:(int)number andWidth:(double)width;

///字母
+ (KATShape *)shapeWithLetter:(char)letter andWidth:(double)width;

///扑克花色(0:Joker、1:黑桃、2:红桃、3:梅花、4:方块)
+ (KATShape *)shapeWithPokerSuit:(int)suit andWidth:(double)width;


//盾形

//心形

//五边形

//五角星

//五芒星

//六边形

//六角星

//六芒星

//八边形

//八角星

//梯形

//圆锥型

//漏斗型

//月型

//杯型

//半圆




@end



