//---------------------------------------------------------------------------------------
//  NSSet+Extensions.h created by erik on Sat 10-Mar-2001
//  $Id: NSSet+Extensions.h,v 2.0 2002-08-16 18:12:49 erik Exp $
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


#ifndef	__NSSet_Extensions_h_INCLUDE
#define	__NSSet_Extensions_h_INCLUDE


#import <Foundation/NSScanner.h>


/*" Various common extensions to #NSSet. "*/

@interface NSSet(EDExtensions)

/*" Adding objects "*/
- (NSSet *)setByAddingObjectsFromSet:(NSSet *)otherSet;
- (NSSet *)setByAddingObjectsFromArray:(NSArray *)anArray;

/*" Mapping the set "*/
- (NSSet *)setByMappingWithDictionary:(NSDictionary *)mapping;
- (NSSet *)setByMappingWithSelector:(SEL)selector; // similar to valueForKey:
- (NSSet *)setByMappingWithSelector:(SEL)selector withObject:(id)object;

@end

#endif	/* __NSSet_Extensions_h_INCLUDE */
