include tools.inc

export USER_INCLUDES := common base

export INCLUDE_PATH := $(addprefix(-D,$(USER_INCLUDES))

all: compile link

compile: 

xaitcollector_origin = appmanager/xait/collector/
xaitcollector_src = $(addprefix $(xaitcollector_origin),xaitcollector.cpp)
xaitcollector_obj = $(subst .cpp,.o,$(xaitcollector_src))
xaitcollector_testsrc = $(addprefix $(xaitcollector_origin),testapp.cpp)


xaitcollector: 
	$(CXX) $(xaitcollector_src) -c -o $(xaitcollector_obj)

xaitcollector_test: xaitcollector
	$(CXX) $(xaitcollector_testsrc) $(xaitcollector_obj) -o $(xaitcollector_origin)$@

xaitcollector_clean:
	$(RMF) $(xaitcollector_obj) $(xaitcollector_origin)xaitcollector_test

print:
	@$(ECHO) $(xaitcollector_origin)
	@$(ECHO) $(xaitcollector_src)
	@$(ECHO) $(xaitcollector_obj)
	@$(ECHO) $(xaitcollector_testsrc)

