
#include <IOKit/IOService.h>

#ifndef IOKitTest_hpp
#define IOKitTest_hpp

class com_apple_driver_IOKitTest : public IOService {
    
    //一个宏定义，会自动生成该类的构造方法、析构方法和运行时
    OSDeclareDefaultStructors(com_apple_driver_IOKitTest);
    
public:
    // 该方法与cocoa中init方法和C++中构造函数类似
    virtual bool init(OSDictionary *dict = 0) APPLE_KEXT_OVERRIDE;
    // 该方法与cocoa中dealloc方法和c++中析构函数类似
    virtual void free(void) APPLE_KEXT_OVERRIDE;
    // 进行驱动匹配时调用
    virtual IOService *probe(IOService *provider, SInt32 *score) APPLE_KEXT_OVERRIDE;
    // 进行加载时调用
    virtual bool start(IOService *provider) APPLE_KEXT_OVERRIDE;
    // 进行卸载时调用
    virtual void stop(IOService *provider) APPLE_KEXT_OVERRIDE;
};

#endif /* IOKitTest_hpp */
