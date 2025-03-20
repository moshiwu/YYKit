//
//  YYImage.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 14/10/20.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

#if __has_include(<YYKit/YYKit.h>)
#import <YYKit/YYAnimatedImageView.h>
#import <YYKit/YYImageCoder.h>
#else
#import "YYAnimatedImageView.h"
#import "YYImageCoder.h"
#endif

NS_ASSUME_NONNULL_BEGIN

/**
 A YYImage object is a high-level way to display animated image data.
 
 @discussion It is a fully compatible `UIImage` subclass. It extends the UIImage
 to support animated WebP, APNG and GIF format image data decoding. It also 
 support NSCoding protocol to archive and unarchive multi-frame image data.
 
 If the image is created from multi-frame image data, and you want to play the 
 animation, try replace UIImageView with `YYAnimatedImageView`.
 
 Sample Code:
 
     // animation@3x.webp
     YYImage *image = [YYImage imageNamed:@"animation.webp"];
     YYAnimatedImageView *imageView = [YYAnimatedImageView alloc] initWithImage:image];
     [view addSubView:imageView];
    
 */
@interface YYImage : UIImage <YYAnimatedImage>

+ (nullable YYImage *)imageNamed:(NSString *)name; // no cache!
+ (nullable YYImage *)imageWithContentsOfFile:(NSString *)path;
+ (nullable YYImage *)imageWithData:(NSData *)data;
+ (nullable YYImage *)imageWithData:(NSData *)data scale:(CGFloat)scale;

/**
 @return downsampleFactor the downsample factor, default is `1.2`.
 */
+ (CGFloat)downsampleFactor;

/**
 If an image is need to downsample, will downsample to pixel size: maxPixelSize * downsampleFactor.
 
 @param downsampleFactor the downsample factor, real pixel size = maxPixelSize * factor. Default is `1.2`. Set downsampleFactor to `0` could disable the downsample feature.
 */
+ (void)setDownsampleFactor:(CGFloat)downsampleFactor;

+ (CGSize)imagePixelSizeFromData:(NSData *)data;

/**
 Just affective for YYImageTypeJPEG and YYImageTypePNG.
 If downsample failed, will return data passed in.
 */
+ (NSData *)downsampleImageWithData:(NSData*)data maxPixelSize:(int32_t)maxPixelSize;

/**
 If the image is no need to display, set 'decodeForDisplay' to NO.
 */
- (instancetype)initWithData:(NSData *)data scale:(CGFloat)scale decodeForDisplay:(BOOL)decodeForDisplay;

/**
 If the image is need to downsample, set 'maxPixelSize' to > 0.
 */
- (instancetype)initWithData:(NSData *)data scale:(CGFloat)scale decodeForDisplay:(BOOL)decodeForDisplay maxPixelSize:(int32_t)maxPixelSize;


/**
 If the image is created from data or file, then the value indicates the data type.
 */
@property (nonatomic, readonly) YYImageType animatedImageType;

/**
 If the image is created from animated image data (multi-frame GIF/APNG/WebP),
 this property stores the original image data.
 */
@property (nullable, nonatomic, readonly) NSData *animatedImageData;

/**
 The total memory usage (in bytes) if all frame images was loaded into memory.
 The value is 0 if the image is not created from a multi-frame image data.
 */
@property (nonatomic, readonly) NSUInteger animatedImageMemorySize;

/**
 Preload all frame image to memory.
 
 @discussion Set this property to `YES` will block the calling thread to decode 
 all animation frame image to memory, set to `NO` will release the preloaded frames.
 If the image is shared by lots of image views (such as emoticon), preload all
 frames will reduce the CPU cost.
 
 See `animatedImageMemorySize` for memory cost.
 */
@property (nonatomic) BOOL preloadAllAnimatedImageFrames;

@end

NS_ASSUME_NONNULL_END
