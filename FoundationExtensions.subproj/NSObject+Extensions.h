//---------------------------------------------------------------------------------------
//  NSObject+Extensions.h created by erik on Sun 06-Sep-1998
//  @(#)$Id: NSObject+Extensions.h,v 2.3 2003-02-10 21:23:15 erik Exp $
//
//  Copyright (c) 1998-2000 by Erik Doernenburg. All rights reserved.
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


#ifndef	__NSObject_Extensions_h_INCLUDE
#define	__NSObject_Extensions_h_INCLUDE


#import <Foundation/NSObject.h>

/*" Protocol used by the Deallocation Notification mechanism. See #{addDeallocObserver:} and related methods in #NSObject Extensions for more information. "*/

@protocol EDDeallocNotification
- (void)objectDeallocated:(id)object;
@end


/*" Various common extensions to #NSObject. "*/

@interface NSObject(EDExtensions)

/*" Developer notes "*/
- (volatile void)methodIsAbstract:(SEL)selector;
- (void)methodIsObsolete:(SEL)selector;
- (void)methodIsObsolete:(SEL)selector hint:(NSString *)hint;

/*" Class hierarchy "*/
+ (NSArray *)subclasses;

/*" Mapping an array "*/
- (NSArray *)mapArray:(NSArray *)anArray withSelector:(SEL)aSelector;

/*" Repeatedly performing a selector "*/
- (void)performSelector:(SEL)selector withObjects:(NSArray *)objectList;
- (void)performSelector:(SEL)selector withObjectsEnumeratedBy:(NSEnumerator *)enumerator;

/*" Managing deallocation observers "*/
+ (void)addDeallocObserver:(id <EDDeallocNotification>)anObserver;
+ (void)removeDeallocObserver:(id)anObserver;
- (void)addDeallocObserver:(id <EDDeallocNotification>)anObserver;
- (void)removeDeallocObserver:(id)anObserver;

@end


IMP EDGetFirstUnusedIMPForSelector(Class aClass, SEL aSelector, BOOL isClassMethod);
BOOL EDClassIsSuperclassOfClass(Class aClass, Class subClass);
NSArray *EDSubclassesOfClass(Class aClass);


#endif	/* __NSObject_Extensions_h_INCLUDE */
