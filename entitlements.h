//
//  Entitlements
//
//  Example: has_entitlement("get-task-allow")
//  Link against Security.framework
//  -satori

#ifndef __Entitlements_checker__
#define __Entitlements_checker__

#import <CoreFoundation/CoreFoundation.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef const void *SecTaskRef;
SecTaskRef SecTaskCreateFromSelf(CFAllocatorRef allocator);
CFTypeRef SecTaskCopyValueForEntitlement(SecTaskRef task,
                                         CFStringRef entitlement,
                                         CFErrorRef *error);

static int has_entitlement(const char *entitlement) {
  if (!entitlement) return 0;
  
  int ret = 0;
  SecTaskRef task = SecTaskCreateFromSelf(kCFAllocatorDefault);

  CFStringRef str = CFStringCreateWithCString(kCFAllocatorDefault, entitlement,
                                              kCFStringEncodingUTF8);

  CFTypeRef tfp = SecTaskCopyValueForEntitlement(task, str, NULL);

  ret = !!tfp;

  CFRelease(tfp);
  CFRelease(str);

  return ret;
}

#ifdef __cplusplus
}
#endif

#endif
