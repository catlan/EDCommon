#
# Generated by the NeXT Project Builder.
#
# NOTE: Do NOT change this file -- Project Builder maintains it.
#
# Put all of your customizations in files called Makefile.preamble
# and Makefile.postamble (both optional), and Makefile will include them.
#

NAME = EDCommon

PROJECTVERSION = 2.8
PROJECT_TYPE = Framework

HFILES = EDCommon.h EDCommonDefines.h

MFILES = useful.m framework.m

SUBPROJECTS = FoundationExtensions.subproj DataStructures.subproj\
              AppKitExtensions.subproj Widgets.subproj

TOOLS = mvcompose.tproj

OTHERSRCS = Makefile.preamble Makefile Makefile.postamble h.template\
            m.template


MAKEFILEDIR = $(MAKEFILEPATH)/pb_makefiles
CURRENTLY_ACTIVE_VERSION = YES
DEPLOY_WITH_VERSION_NAME = A
CODE_GEN_STYLE = DYNAMIC
MAKEFILE = framework.make
NEXTSTEP_INSTALLDIR = $(LOCAL_LIBRARY_DIR)/Frameworks
WINDOWS_INSTALLDIR = $(LOCAL_LIBRARY_DIR)/Frameworks
PDO_UNIX_INSTALLDIR = $(LOCAL_LIBRARY_DIR)/Frameworks
LIBS = 
DEBUG_LIBS = $(LIBS)
PROF_LIBS = $(LIBS)


NEXTSTEP_PB_LDFLAGS = -seg1addr 0x50000000
WINDOWS_PB_CFLAGS = -D_BUILDING_EDCOMMON_DLL
FRAMEWORKS = -framework AppKit -framework Foundation
PUBLIC_HEADERS = EDCommon.h EDCommonDefines.h

PROJECT_HEADERS = EDCommonDefines.h



NEXTSTEP_OBJCPLUS_COMPILER = /usr/bin/cc
WINDOWS_OBJCPLUS_COMPILER = $(DEVDIR)/gcc
PDO_UNIX_OBJCPLUS_COMPILER = $(NEXTDEV_BIN)/gcc
NEXTSTEP_JAVA_COMPILER = /usr/bin/javac
WINDOWS_JAVA_COMPILER = $(JDKBINDIR)/javac.exe
PDO_UNIX_JAVA_COMPILER = $(JDKBINDIR)/javac

include $(MAKEFILEDIR)/platform.make

-include Makefile.preamble

include $(MAKEFILEDIR)/$(MAKEFILE)

-include Makefile.postamble

-include Makefile.dependencies
