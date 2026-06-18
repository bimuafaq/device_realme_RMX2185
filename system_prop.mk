# Bootanimation
PRODUCT_PRODUCT_PROPERTIES += \
    ro.config.nocheckin=1

# Display
PRODUCT_PRODUCT_PROPERTIES += \
    ro.sf.lcd_density=320

# IMS
PRODUCT_SYSTEM_DEFAULT_PROPERTIES += \
    persist.dbg.volte_avail_ovr=1 \
    persist.dbg.vt_avail_ovr=1 \
    persist.dbg.wfc_avail_ovr=1

# OMX
PRODUCT_SYSTEM_DEFAULT_PROPERTIES += \
    vendor.mtk_thumbnail_optimization=true \
    media.stagefright.thumbnail.prefer_hw_codecs=true

# Privapp permissions whitelisting
PRODUCT_PRODUCT_PROPERTIES += \
    ro.control_privapp_permissions=log

# Memory optimizations
PRODUCT_PROPERTY_OVERRIDES += \
    dalvik.vm.madvise-random=true \
    ro.statsd.enable=false \
    ro.config.per_app_memcg=false \
    ro.surface_flinger.set_idle_timer_ms=100 \
    ro.surface_flinger.set_touch_timer_ms=200 \
    ro.surface_flinger.support_kernel_idle_timer=true
