//---------------------------------------------------------------------------------------
//  NSFileHandle+NetExt.h created by erik
//  @(#)$Id: NSFileHandle+Extensions.h,v 2.0 2002-08-16 18:12:48 erik Exp $
//
//  Copyright (c) 1997 by Erik Doernenburg. All rights reserved.
//
//  Permission to use, copy, modify and distribute this software and its documentation
//  is hereby granted, provided that both the copyright notice and this permission
//  notice appear in all copies of the software, derivative works or modified versions,
//  and any portions thereof, and that both notices appear in supporting documentation,
//  and that credit is given to Erik Doernenburg in all documents and publicity
//  pertaining to direct or indirect use of this code or its derivatives.
//
//  THIS IS EXPERIMENTAL SOFTWARE AND IT IS KNOWN TO HAVE BUGS, SOME OF WHICH MAY HAVE
//  SERIOUS CONSEQUENCES. THE COPYRIGHT HOLDER ALLOWS FREE USE OF THIS SOFTWARE IN ITS
//  "AS IS" CONDITION. THE COPYRIGHT HOLDER DISCLAIMS ANY LIABILITY OF ANY KIND FOR ANY
//  DAMAGES WHATSOEVER RESULTING DIRECTLY OR INDIRECTLY FROM THE USE OF THIS SOFTWARE
//  OR OF ANY DERIVATIVE WORK.
//---------------------------------------------------------------------------------------

#import <Foundation/Foundation.h>

@interface NSFileHandle(EDExtensions)

/*" Endpoints for socket handles "*/

- (unsigned short)localPort;
- (NSString *)localAddress;

- (unsigned short)remotePort;
- (NSString *)remoteAddress;
#if !defined(TARGET_OS_IPHONE) || !TARGET_OS_IPHONE
- (NSHost *)remoteHost;
#endif

/*" Shutdown "*/

- (void)shutdown;
- (void)shutdownInput;
- (void)shutdownOutput;

/*" Non-blocking reads on sockets "*/

- (NSData *)availableDataNonBlocking;
- (NSData *)readDataToEndOfFileNonBlocking;
- (NSData *)readDataOfLengthNonBlocking:(unsigned int)length;

@end
