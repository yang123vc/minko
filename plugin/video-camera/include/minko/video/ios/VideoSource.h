/*
Copyright (c) 2015 Aerys

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#import <AVFoundation/AVFoundation.h>

#include "minko/video/AbstractVideoCamera.hpp"

@interface VideoSource : NSObject
{
@public
    minko::Signal<const std::vector<unsigned char>&, int, int> frameReceived;
    std::vector<unsigned char> frameData;
}

@property (nonatomic, strong) AVCaptureSession * captureSession;
@property (nonatomic, strong) AVCaptureDeviceInput * deviceInput;

- (BOOL)initializeWithDevicePosition:(AVCaptureDevicePosition)devicePosition;
- (void)start;
- (void)stop;

@end

// C++

namespace minko
{
    namespace video
    {
        struct VideoSourceImpl
        {
            VideoSourceImpl();
            
            void
            initialize();
            
            void
            start();
            
            void
            stop();
            
            VideoSource *const proxy;
            std::shared_ptr<Signal<const std::vector<unsigned char>&, int, int>> frameReceived;
        };
    }
}
