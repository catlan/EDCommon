//---------------------------------------------------------------------------------------
//  NSFileHandle+NetExt.m created by erik
//  @(#)$Id: NSFileHandle+Extensions.m,v 2.1 2003-04-08 16:51:35 znek Exp $
//
//  Copyright (c) 1997,1999 by Erik Doernenburg. All rights reserved.
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
#include "osdep.h"
#include "functions.h"
#include "NSFileHandle+Extensions.h"

#ifdef WIN32
#import <System/windows.h>  // move this to osdep.h?
#endif

#ifdef WIN32
#define EDSOCKETHANDLE ((int)[self nativeHandle])
#else
#define EDSOCKETHANDLE [self fileDescriptor]
#endif

//---------------------------------------------------------------------------------------
    @implementation NSFileHandle(EDExtensions)
//---------------------------------------------------------------------------------------

/*" Various useful extensions to #NSFileHandle. Most only work with file handles that represent sockets but this is in a category on NSFileHandle, and not in its subclass #EDIPSocket, because this functionality is also useful for plain NSFileHandles that represent sockets. The latter are often created through invocations such as #acceptConnectionInBackgroundAndNotify. "*/


/*" Returns the port of the local endpoint of the socket. "*/

- (unsigned short)localPort
{
    int 			sockaddrLength;
    struct sockaddr_in sockaddr;
    
    sockaddrLength = sizeof(struct sockaddr_in);
    if(getsockname(EDSOCKETHANDLE, (struct sockaddr *)&sockaddr, &sockaddrLength) == -1)
        [NSException raise:NSFileHandleOperationException format:@"Cannot get local port number for socket: %s", strerror(ED_ERRNO)];
    return sockaddr.sin_port;
}


/*" Returns the address of the local endpoint of the socket in the "typical" dotted numerical notation. "*/

- (NSString *)localAddress
{
    int 			sockaddrLength;
    struct sockaddr_in sockaddr;
    
    sockaddrLength = sizeof(struct sockaddr_in);
    if(getsockname(EDSOCKETHANDLE, (struct sockaddr *)&sockaddr, &sockaddrLength) == -1)
        [NSException raise:NSFileHandleOperationException format:@"Cannot get local port number for socket: %s", strerror(ED_ERRNO)];
    return EDStringFromInAddr(sockaddr.sin_addr);
}


/*" Returns the port of the remote endpoint of the socket. "*/

- (unsigned short)remotePort
{
    int 			sockaddrLength;
    struct sockaddr_in sockaddr;

    sockaddrLength = sizeof(struct sockaddr_in);
    if(getpeername(EDSOCKETHANDLE, (struct sockaddr *)&sockaddr, &sockaddrLength) == -1)
        [NSException raise:NSFileHandleOperationException format:@"Failed to get peer: %s", strerror(ED_ERRNO)];
    return sockaddr.sin_port;
}


/*" Returns the address of the remote endpoint of the socket in the "typical" dotted numerical notation. "*/

- (NSString *)remoteAddress
{
    int 			sockaddrLength;
    struct sockaddr_in sockaddr;

    sockaddrLength = sizeof(struct sockaddr_in);
    if(getpeername(EDSOCKETHANDLE, (struct sockaddr *)&sockaddr, &sockaddrLength) == -1)
        [NSException raise:NSFileHandleOperationException format:@"Failed to get peer: %s", strerror(ED_ERRNO)];
    return EDStringFromInAddr(sockaddr.sin_addr);
}


/*" Returns the host for the remote endpoint of the socket. "*/

- (NSHost *)remoteHost
{
    return [NSHost hostWithAddress:[self remoteAddress]];
}


/*" Causes the full-duplex connection on the socket to be shut down. "*/

- (void)shutdown
{
    if(shutdown(EDSOCKETHANDLE, 2) == -1)
        [NSException raise:NSFileHandleOperationException format:@"Failed to shutdown socket: %s", strerror(ED_ERRNO)];
}


/*" Causes part of the full-duplex connection on the socket to be shut down; further receives will be disallowed. "*/

- (void)shutdownInput
{
    if(shutdown(EDSOCKETHANDLE, 0) == -1)
        [NSException raise:NSFileHandleOperationException format:@"Failed to shutdown input of socket: %s", strerror(ED_ERRNO)];
}


/*" Causes part of the full-duplex connection on the socket to be shut down; further sends will be disallowed. "*/

- (void)shutdownOutput
{
    if(shutdown(EDSOCKETHANDLE, 1) == -1)
        [NSException raise:NSFileHandleOperationException format:@"Failed to shutdown output of socket: %s", strerror(ED_ERRNO)];
}


- (unsigned int)_availableByteCountNonBlocking
{
#ifdef WIN32
    DWORD lpTotalBytesAvail;
    BOOL peekSuccess;

    peekSuccess = PeekNamedPipe(EDSOCKETHANDLE, NULL, 0L, NULL, &lpTotalBytesAvail, NULL);

    if (peekSuccess == NO)
        [NSException raise: NSFileHandleOperationException
                    format: @"PeekNamedPipe() NT Error # %d", GetLastError()];

    return lpTotalBytesAvail;
#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(linux)
    int numBytes;

    if(ioctl(EDSOCKETHANDLE, FIONREAD, (char *) &numBytes) == -1)
        [NSException raise: NSFileHandleOperationException
                    format: @"ioctl() error # %d", errno];

    return numBytes;
#else
#warning Non-blocking I/O not supported on this platform....
    abort();
    return 0;
#endif
}


/*" Calls #{readDataOfLengthNonBlocking:} with a length of !{UINT_MAX}, effectively reading as much data as is available. "*/

- (NSData *)availableDataNonBlocking
{
    return [self readDataOfLengthNonBlocking:UINT_MAX];
}

/*" Calls #{readDataOfLengthNonBlocking:} with a length of !{UINT_MAX}, effectively reading as far towards the end of the file as possible. "*/

- (NSData *)readDataToEndOfFileNonBlocking
{
    return [self readDataOfLengthNonBlocking:UINT_MAX];
}


/*" Tries to read length bytes of data. If less data is available it does not block to wait for more but returns whatever is available. If no data is available this method returns !{nil} and not an empty instance of #NSData. "*/

- (NSData *)readDataOfLengthNonBlocking:(unsigned int)length
{
    unsigned int available;

    available = [self _availableByteCountNonBlocking];
    if(available == 0)
        return nil;

    return [self readDataOfLength:((available < length) ? available : length)];
}


//---------------------------------------------------------------------------------------
    @end
//---------------------------------------------------------------------------------------
