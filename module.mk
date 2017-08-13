MODULE_DIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

C_SOURCES += $(MODULE_DIR)/Src/user_at24cxx.c

C_INCLUDES += -I$(MODULE_DIR)/Inc
