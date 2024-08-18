// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define TRI_LAYER_LOWER_LAYER 1
#define TRI_LAYER_UPPER_LAYER 2
#define TRI_LAYER_ADJUST_LAYER 3

//// For Inertia QMK mouse mode ////
#define MOUSEKEY_INERTIA udefined // Enable Inertia mode
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL      16
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED     32
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX   64
#define MOUSEKEY_FRICTION       6      // How quickly the cursor stops after releasing a key
#define MOUSEKEY_MOVE_DELTA     1     // How much to move on first frame (1 strongly recommended)
