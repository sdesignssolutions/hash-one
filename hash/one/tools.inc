CROSS_COMPILE := 

CC      = $(CROSS_COMPILE)gcc
CXX     = $(CROSS_COMPILE)g++
AR      = $(CROSS_COMPILE)ar
NM      = $(CROSS_COMPILE)nm
STRIP   = $(CROSS_COMPILE)strip
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
RANLIB  = $(CROSS_COMPILE)ranlib

# These are operations common to all environments.
MKDIR   = mkdir -p
MV      = mv
CPP     = $(CC) -E
CPA	    = cp -a
CP      = cp -f
CPA	    = cp -a
RMF     = rm -f
RMDIR   = rm -rf
SORT    = sort
SED     = sed
TOUCH   = touch
AWK     = awk
ECHO    = echo

