#import <Foundation/Foundation.h>

@interface QtBridge : NSObject
+ (void)saveLastIPAddress:(NSString *)ipAddress;
+ (NSString *)getLastIPAddress;
@end
