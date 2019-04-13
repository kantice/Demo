//
//  KATImage.h
//  KATFramework
//
//  Created by Yi Yu on 2017/6/28.
//  Copyright © 2017年 KatApp. All rights reserved.
//  图片类，集成了远程下载、GIF播放、全屏展示等功能

#import <ImageIO/ImageIO.h>
#import "KATSprite.h"
#import "KATImageUtil.h"
#import "KATHttpRequest.h"
#import "KATButton.h"
#import "KATPercentRing.h"



@interface KATImage : KATSprite <NSCopying,UIGestureRecognizerDelegate>


#pragma -mark 属性

///图片的链接地址
@property(nonatomic,copy,readonly) NSString *url;

///图片的文件路径
@property(nonatomic,copy,readonly) NSString *path;

///帧数
@property(nonatomic,assign,readonly) unsigned long long frameCount;

///图片帧数组
@property(nonatomic,retain,readonly) KATArray<__kindof UIImage *> *frames;

///帧动画
@property(nonatomic,retain,readonly) CAAnimation *frameAnimation;

///帧动画时长
@property(nonatomic,assign,readonly) double frameAnimationDuration;

///是否自动播放GIF格式图片的动画(默认为YES)
@property(nonatomic,assign) BOOL isAutoPlayAnimation;

///是否点击全屏显示
@property(nonatomic,assign) BOOL isTapToShow;

///是否异步解析图片(默认为否，若为是，则显示的图片会自动裁剪)
@property(nonatomic,assign) BOOL isParsingImageAsync;

///图片资源
@property(nonatomic,retain,readonly) UIImage *source;

///占位图
@property(nonatomic,retain) UIImage *holderImg;

///破损图
@property(nonatomic,retain) UIImage *brokenImg;


#pragma -mark 类方法

///获取实例
+ (instancetype)image;

///设置缓存目录
+ (void)setCacheDir:(NSString *)dir;

///获取缓存目录
+ (NSString *)cacheDir;

///设置占位图片
+ (void)setHolderImage:(UIImage *)image;

///获取占位图片
+ (UIImage *)holderImage;

///设置失败图片
+ (void)setBrokenImage:(UIImage *)image;

///获取失败图片
+ (UIImage *)brokenImage;

///清空缓存(删除几天前的缓存图片，0为删除所有)
+ (void)clearCacheBeforeDays:(int)days;

///文件名转化
+ (NSString *)fileNameWithUrl:(NSString *)url;

///设置百分比环高度(若小于等于0则不展示,若小于等于1.0,则按图片高宽小者百分比)(默认0)
+ (void)setPercentRingHeight:(double)height;


#pragma -mark 对象方法

///直接加载图片
- (void)loadWithImage:(UIImage *)image;

///通过文件路径加载图片
- (void)loadWithPath:(NSString *)path;

///通过URL加载图片，先考虑缓存中的图片，且下载的图片会保存在缓存中
- (void)loadWithURL:(NSString *)url;

//通过URL加载图片，先考虑缓存中的图片，且下载的图片会保存在缓存中，图片下载设置完成后回调
- (void)loadWithURL:(NSString *)url andCompletion:(void (^)(BOOL success))completion;

///重新加载
- (void)reload;

///播放(多帧时才能播放)
- (void)play;

///停止播放
- (void)stop;

///清除图片
- (void)clearImage;

///显示某一帧(多帧时才能生效)
- (void)displayWithFrame:(int)frame;

///全屏显示
- (void)fullScreenShow;

///移除点击手势
- (void)removeTapGesture;

///恢复点击手势
- (void)restoreTapGesture;

///取消下载(针对网络加载的图片)
- (void)cancelDownload;

///释放内存
- (void)dealloc;


@end
