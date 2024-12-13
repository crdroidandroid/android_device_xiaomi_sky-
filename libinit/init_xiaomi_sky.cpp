/*
 * Copyright (C) 2021-2022 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_variant.h>
#include <libinit_utils.h>

#include "vendor_init.h"

#define FINGERPRINT_POCO_IN "POCO/sky_p_in/sky:14/UKQ1.231003.002/OS2.0.3.0.VMWINXM:user/release-keys"
#define FINGERPRINT_REDMI_IN "Redmi/sky_in/sky:14/UKQ1.231003.002/OS2.0.3.0.VMWINXM:user/release-keys"
#define FINGERPRINT_CHINA "Redmi/sky/sky:14/UKQ1.231003.002/V816.0.9.0.UMWCNXM:user/release-keys"
#define FINGERPRINT_GLOBAL_NFC "Redmi/river_global/river:14/UKQ1.231003.002/V816.0.11.0.UMWMIXM:user/release-keys"
#define FINGERPRINT_JPN "Redmi/XIG03_jp_kdi/XIG03:14/UKQ1.230917.001/V816.0.5.0.UMWJPKD:user/release-keys"

static const variant_info_t sky_poco_info = {
    .hwc_value = "India",
    .boardid = "S88019EP1",

    .brand = "POCO",
    .device = "sky",
    .marketname = "POCO M6 Pro 5G",
    .model = "23076PC4BI",
    .mod_device = "sky_global",
    .build_fingerprint = FINGERPRINT_POCO_IN,
};

static const variant_info_t sky_redmi_info = {
    .hwc_value = "India",
    .boardid = "S88018EA1",

    .brand = "Redmi",
    .device = "sky",
    .marketname = "Redmi 12 5G",
    .model = "23076RN4BI",
    .mod_device = "sky_global",
    .build_fingerprint = FINGERPRINT_REDMI_IN,
};

static const variant_info_t sky_redmi2_info = {
    .hwc_value = "India",
    .boardid = "S88019EA1",

    .brand = "Redmi",
    .device = "sky",
    .marketname = "Redmi 12 5G",
    .model = "23076RN4BI",
    .mod_device = "sky_global",
    .build_fingerprint = FINGERPRINT_REDMI_IN,
};

static const variant_info_t sky_china_info = {
    .hwc_value = "CN",
    .boardid = "S88019BA1",

    .brand = "Redmi",
    .device = "river",
    .marketname = "Redmi Note 12R",
    .model = "23076RA4BC",
    .mod_device = "sky_global",
    .build_fingerprint = FINGERPRINT_CHINA,
};


static const variant_info_t sky2_china_info = {
    .hwc_value = "CN",
    .boardid = "S88019OA1",

    .brand = "Redmi",
    .device = "sky",
    .marketname = "Redmi 12R",
    .model = "23076RA4BC",
    .mod_device = "sky_global",
    .build_fingerprint = FINGERPRINT_REDMI_IN,
};

static const variant_info_t river_info_S88029AA1 = {
    .hwc_value = "Global",
    .boardid = "S88029AA1",

    .brand = "Redmi",
    .device = "river",
    .marketname = "Redmi 12 5G",
    .model = "23076RN8DY",
    .mod_device = "sky_global",
    .build_fingerprint = FINGERPRINT_GLOBAL_NFC,
};

static const variant_info_t river_info_S88019BP1 = {
    .hwc_value = "CN",
    .boardid = "S88019BP1",

    .brand = "Redmi",
    .device = "river",
    .marketname = "Redmi 12 5G",
    .model = "23077RABDC",
    .mod_device = "sky_global",
    .build_fingerprint = FINGERPRINT_GLOBAL_NFC,
};

static const variant_info_t river_info_S88018PA1 = {
    .hwc_value = "Global",
    .boardid = "S88018PA1",

    .brand = "Redmi",
    .device = "river",
    .marketname = "Redmi 12 5G",
    .model = "23077RABDC",
    .mod_device = "sky_global",
    .build_fingerprint = FINGERPRINT_GLOBAL_NFC,
};

static const variant_info_t river_info_S88029EA1 = {
    .hwc_value = "Japan",
    .boardid = "S88029EA1",

    .brand = "Redmi",
    .device = "XIG03",
    .marketname = "Redmi 12 5G",
    .model = "XIG03",
    .mod_device = "xig03_jp_kdi",
    .build_fingerprint = FINGERPRINT_JPN,
};

static const variant_info_t river_info_S88029JA1 = {
    .hwc_value = "Japan",
    .boardid = "S88029JA1",

    .brand = "Redmi",
    .device = "river",
    .marketname = "Redmi 12 5G",
    .model = "23076RA4BR",
    .mod_device = "sky_global",
    .build_fingerprint = FINGERPRINT_GLOBAL_NFC,
};

static const std::vector<variant_info_t> variants = {
    sky_poco_info,
    sky_redmi_info,
    sky_redmi2_info,
    sky_china_info,
    sky2_china_info,
    river_info_S88029AA1,
    river_info_S88019BP1,
    river_info_S88018PA1,
    river_info_S88029EA1,
    river_info_S88029JA1,
};

void vendor_load_properties() {
    search_variant(variants);
}
