//---------------------------------------------------------------------------------------
//  NSProcessInfo+Extensions.m created by znek on Sat 23-Sep-2000
//  $Id: NSProcessInfo+Extensions.m,v 1.1 2000-10-23 23:22:40 erik Exp $
//
//  Copyright (c) 2000 by Erik Doernenburg. All rights reserved.
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
#import "NSProcessInfo+Extensions.h"

#ifndef WIN32
#	include <sys/types.h>
#	include <unistd.h>
#else
// need this for GetCurrentProcessId()
// hard to believe, but true ...
#	import <winsock.h>
#endif


//---------------------------------------------------------------------------------------
    @implementation NSProcessInfo(EDExtensions)
//---------------------------------------------------------------------------------------

- (int)pid
{
#ifndef WIN32
    return getpid();
#else
    return (int)GetCurrentProcessId();
#endif
}

//---------------------------------------------------------------------------------------
  @end
//---------------------------------------------------------------------------------------