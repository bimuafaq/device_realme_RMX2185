LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_PACKAGE_NAME := RMX2180_overlay
LOCAL_SDK_VERSION := current
LOCAL_PRODUCT_MODULE := true

include $(BUILD_RRO_PACKAGE)
