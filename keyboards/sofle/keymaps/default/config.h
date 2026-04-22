// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4

/* clear default encoder def */
#undef TAP_CODE_DELAY

/* encoder support */
#define TAP_CODE_DELAY 100

/* trackball */
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_ROTATION_90
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_TASK_THROTTLE_MS 8

/* WPM */
#define SPLIT_WPM_ENABLE
#define SPLIT_OLED_ENABLE
