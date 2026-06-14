LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CERTIFICATE := PRESIGNED
LOCAL_MODULE := nuke
LOCAL_MODULE_CLASS := APPS
LOCAL_SRC_FILES := /dev/null
LOCAL_UNINSTALLABLE_MODULE := true
LOCAL_OVERRIDES_PACKAGES := \
    AudioFX \
    Backgrounds \
    Eleven \
    Etar \
    Jelly \
    Camera2 \
    Seedvault \
    Stk \
    Updater \
    Traceur \
    MatLog \
    crDroidMusic \
    LineageSetupWizard \
    Email \
    ExactCalculator \
    Exchange2 \
    Recorder \
    APlayer \
    FontLatoOverlay \
    FontNotoSerifSourceOverlay \
    FontRubikOverlay \
    fonts_customization.xml \
    AccentColorBlackOverlay \
    AccentColorCinnamonOverlay \
    AccentColorOceanOverlay \
    AccentColorOrchidOverlay \
    AccentColorSpaceOverlay \
    AccentColorGreenOverlay \
    AccentColorPurpleOverlay \
    AccentColorPaletteOverlay \
    AccentColorCarbonOverlay \
    AccentColorSandOverlay \
    AccentColorAmethystOverlay \
    AccentColorAquamarineOverlay \
    AccentColorTangerineOverlay \
    DisplayCutoutEmulationCornerOverlay \
    DisplayCutoutEmulationDoubleOverlay \
    DisplayCutoutEmulationHoleOverlay \
    DisplayCutoutEmulationTallOverlay \
    DisplayCutoutEmulationWaterfallOverlay \
    IconPackVictorAndroidOverlay \
    IconPackVictorLauncherOverlay \
    IconPackVictorSettingsOverlay \
    IconPackVictorSystemUIOverlay \
    IconPackVictorThemePickerOverlay \
    IconPackKaiAndroidOverlay \
    IconPackKaiLauncherOverlay \
    IconPackKaiSettingsOverlay \
    IconPackKaiSystemUIOverlay \
    IconPackKaiThemePickerOverlay \
    IconPackSamAndroidOverlay \
    IconPackSamLauncherOverlay \
    IconPackSamSettingsOverlay \
    IconPackSamSystemUIOverlay \
    IconPackSamThemePickerOverlay \
    IconPackRoundedAndroidOverlay \
    IconPackRoundedLauncherOverlay \
    IconPackRoundedSettingsOverlay \
    IconPackRoundedSystemUIOverlay \
    IconPackRoundedThemePickerOverlay \
    IconShapePebbleOverlay \
    IconShapeRoundedRectOverlay \
    IconShapeSquircleOverlay \
    IconShapeTaperedRectOverlay \
    IconShapeTeardropOverlay \
    IconShapeVesselOverlay \
    IconShapeSquareOverlay
include $(BUILD_PREBUILT)
