#import "QtBridge.h"
#include "VpnBackend.h"

@implementation QtBridge

+ (void)saveLastIPAddress:(NSString *)ipAddress {
    VpnBackend::instance().saveLastIPAddress([ipAddress UTF8String]);
}

+ (NSString *)getLastIPAddress {
    std::string ip = VpnBackend::instance().getLastIPAddress();
    return [NSString stringWithUTF8String:ip.c_str()];
}

@end
