LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_PACKAGE_NAME := CarrierConfigOverlayVars
LOCAL_SDK_VERSION := current
LOCAL_CERTIFICATE := platform
LOCAL_PRODUCT_MODULE := true

include $(BUILD_RRO_PACKAGE)
