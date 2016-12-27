
#include "IOKitTest.hpp"
#include <IOKit/IOService.h>
#include <IOKit/IOLib.h>

// 类似cocoa中 super关键字
#define super IOService

// 和头文件中的宏定义类似, 自动生成一些特定的代码
OSDefineMetaClassAndStructors(com_apple_driver_IOKitTest, IOService);

bool com_apple_driver_IOKitTest::init(OSDictionary *dict)
{
    bool result = super::init(dict);
    IOLog("IOKitTest : did init !! \n");  // IOlog() 生成log日志, 存在在system.log里
    
    
    /** 遍历OSDictionary */
    OSCollectionIterator *iter = OSCollectionIterator::withCollection(dict);
    if (iter)
    {
        OSObject *object = NULL;
        while ((object = iter->getNextObject()))
        {
            OSSymbol *key = OSDynamicCast(OSSymbol, object);
            IOLog("iRedTest : key:%s  ",key->getCStringNoCopy());
            OSString *value = OSDynamicCast(OSString, dict->getObject(key));
            if (value != NULL)
            {
                IOLog("iRedTest : value:%s\n",value->getCStringNoCopy());
            }
        }
    }
    
    return result;
}

void com_apple_driver_IOKitTest::free(void)
{
    IOLog("IOKitTest : free \n");
    super::free();
}

IOService *com_apple_driver_IOKitTest::probe(IOService *provider, SInt32 *score)
{
    IOService *probe = super::probe(provider, score);
    return probe;
}

bool com_apple_driver_IOKitTest::start(IOService *provider)
{
    bool result = super::start(provider);
    IOLog("IOKitTest : start \n");
    return result;
}

void com_apple_driver_IOKitTest::stop(IOService *provider)
{
    IOLog("IOKitTest : stop \n");
    super::stop(provider);
}


