/*
 * Copyright (C) 2020 LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string>
#include <fstream>
#include <sys/sysinfo.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"

void property_override(char const prop[], char const value[])
{
    prop_info *pi;
    pi = (prop_info *)__system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void setRMX(unsigned int variant)
{
    std::string device;
    std::string fingerprint;

    switch (variant) {
        case 0:
            device = "RMX2180";
            fingerprint = "realme/RMX2180T2/RMX2180:10/QP1A.190711.020/1622100863:user/release-keys";
            break;
        case 1:
            device = "RMX2189";
            fingerprint = "realme/RMX2189T2/RMX2189:10/QP1A.190711.020/1622100863:user/release-keys";
            break;
        default:
            device = "RMX2185";
            fingerprint = "realme/RMX2185T2/RMX2185:10/QP1A.190711.020/1622100863:user/release-keys";
            break;
    }

    std::string name = device + "T2";
    std::string description = "full_oppo6765-user 10 QP1A.190711.020 bedd37e98646d3a1 release-keys";

    property_override("ro.build.description", description.c_str());
    property_override("ro.build.fingerprint", fingerprint.c_str());
    property_override("ro.build.product", device.c_str());

    property_override("ro.bootimage.build.fingerprint", fingerprint.c_str());
    property_override("ro.odm.build.fingerprint", fingerprint.c_str());
    property_override("ro.product.build.fingerprint", fingerprint.c_str());
    property_override("ro.system.build.fingerprint", fingerprint.c_str());
    property_override("ro.system_ext.build.fingerprint", fingerprint.c_str());
    property_override("ro.vendor.build.fingerprint", fingerprint.c_str());
    property_override("ro.vendor.oppo.fingerprint", fingerprint.c_str());

    property_override("ro.product.device", device.c_str());
    property_override("ro.product.model", device.c_str());
    property_override("ro.product.name", name.c_str());
    property_override("ro.product.system.device", device.c_str());
    property_override("ro.product.system.model", device.c_str());
    property_override("ro.product.product.device", device.c_str());
    property_override("ro.product.product.model", device.c_str());
    property_override("ro.product.system_ext.device", device.c_str());
    property_override("ro.product.system_ext.model", device.c_str());
    property_override("ro.product.vendor.device", device.c_str());
    property_override("ro.product.vendor.model", device.c_str());
    property_override("ro.product.vendor.name", name.c_str());
    property_override("ro.product.odm.device", device.c_str());
    property_override("ro.product.odm.model", device.c_str());
    property_override("ro.product.odm.name", name.c_str());
    property_override("ro.product.bootimage.name", name.c_str());
    property_override("ro.vendor.oppo.product.name", name.c_str());
}

void set_dalvik()
{
    char const *heapstartsize;
    char const *heapgrowthlimit;
    char const *heapsize;
    char const *heapminfree;
    char const *heapmaxfree;
    char const *heaptargetutilization;

    struct sysinfo sys;
    sysinfo(&sys);

    if (sys.totalram > 3072ull * 1024 * 1024) {
        heapstartsize = "8m";
        heapgrowthlimit = "192m";
        heapsize = "512m";
        heaptargetutilization = "0.6";
        heapminfree = "8m";
        heapmaxfree = "16m";
    } else {
        heapstartsize = "8m";
        heapgrowthlimit = "128m";
        heapsize = "256m";
        heaptargetutilization = "0.75";
        heapminfree = "2m";
        heapmaxfree = "8m";
    }

    property_override("dalvik.vm.heapstartsize", heapstartsize);
    property_override("dalvik.vm.heapgrowthlimit", heapgrowthlimit);
    property_override("dalvik.vm.heapsize", heapsize);
    property_override("dalvik.vm.heaptargetutilization", heaptargetutilization);
    property_override("dalvik.vm.heapminfree", heapminfree);
    property_override("dalvik.vm.heapmaxfree", heapmaxfree);
    property_override("dalvik.vm.foreground-heap-growth-multiplier", "4.0");
}

void vendor_load_properties()
{
    std::ifstream fin;
    std::string buf;
    fin.open("/proc/cmdline");
    while (std::getline(fin, buf, ' '))
      if (buf.find("board_id") != std::string::npos)
          break;
    fin.close();

    if (buf.find("S98635AA1") != std::string::npos) {
        setRMX(0);
    } else if (buf.find("S98639AA1") != std::string::npos) {
        setRMX(1);
    } else {
        setRMX(2);
    }

    set_dalvik();
}
