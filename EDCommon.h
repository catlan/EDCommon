//---------------------------------------------------------------------------------------
//  EDCommon.h created by erik on Sat 05-Sep-1998
//  @(#)$Id: EDCommon.h,v 2.7 2005-09-26 12:24:08 znek Exp $
//
//  Copyright (c) 1998-2003 by Erik Doernenburg. All rights reserved.
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


#ifndef	__EDCommon_h_INCLUDE
#define	__EDCommon_h_INCLUDE

#ifdef MAC_OS_X_VERSION_10_2
#ifndef EDCOMMON_OSXBUILD
#define EDCOMMON_OSXBUILD
#endif
#endif

#ifdef MAC_OS_X_VERSION_10_3
#ifndef EDCOMMON_OSXBUILD
#define EDCOMMON_OSXBUILD
#endif
#endif

#ifdef MAC_OS_X_VERSION_10_4
#ifndef EDCOMMON_OSXBUILD
#define EDCOMMON_OSXBUILD
#endif
#endif

#import <Foundation/Foundation.h>

#include "EDCommonDefines.h"
#include "EDObjcRuntime.h"

#include "NSArray+Extensions.h"
#include "NSAttributedString+Extensions.h"
#include "NSData+Extensions.h"
#include "NSDate+Extensions.h"
#include "NSDictionary+Extensions.h"
#include "NSFileHandle+Extensions.h"
#include "NSHost+Extensions.h"
#include "NSInvocation+Extensions.h"
#include "NSObject+Extensions.h"
#include "NSProcessInfo+Extensions.h"
#include "NSScanner+Extensions.h"
#include "NSSet+Extensions.h"
#include "NSString+Extensions.h"
#include "EDSocket.h"
#include "EDIPSocket.h"
#include "EDTCPSocket.h"
#include "EDUDPSocket.h"
#include "EDStream.h"
#include "EDTextWriter.h"
//#include "functions.h"

#include "EDBitmapCharset.h"
#include "EDIRCObject.h"
#include "EDLightWeightLock.h"
#include "EDLRUCache.h"
#include "EDMutableObjectPair.h"
#include "EDNumberSet.h"
#include "EDObjectPair.h"
#include "EDObjectReference.h"
#include "EDRange.h"
#include "EDSortedArray.h"
#include "EDSparseClusterArray.h"
#include "EDStack.h"
#include "EDStringScanner.h"
#include "EDStringWriter.h"

#include "EDMLParser.h"
#include "EDMLTagProcessorProtocol.h"
#include "EDAOMTagProcessor.h"

#include "EDXMLAttribute.h"
#include "EDXMLCharacterData.h"
#include "EDXMLDocument.h"
#include "EDXMLDocumentFragment.h"
#include "EDXMLElement.h"
#include "EDXMLNode.h"
#include "EDXMLText.h"

#include "EDXMLDOMTagProcessor.h"
#include "EDXMLNamedNodeMap.h"
#include "EDXMLNodeList.h"
#include "EDXMLTreeWalker.h"

#ifndef EDCOMMON_WOBUILD

#import <AppKit/AppKit.h>

#include "NSApplication+Extensions.h"
#include "NSAttributedString+AppKitExtensions.h"
#include "NSMatrix+Extensions.h"
#include "NSPasteboard+Extensions.h"
#include "NSTableColumn+Extensions.h"
#include "NSTableView+Extensions.h"
#include "NSWindow+Extensions.h"
#include "NSWorkspace+Extensions.h"
#include "EDApplication.h"
#include "EDKeyControlWindow.h"
#include "EDActivityIndicator.h"
#include "EDCanvas.h"
#include "EDObjectWell.h"
#include "EDTableView.h"
#include "EDTVScrollView.h"
#include "EDSwapView.h"

#endif // EDCOMMON_WOBUILD

#endif	/* __EDCommon_h_INCLUDE */
