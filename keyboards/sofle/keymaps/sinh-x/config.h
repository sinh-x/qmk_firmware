// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4

//// For Inertia QMK mouse mode ////
#define MOUSEKEY_INERTIA      undefined   //Enable Inertia mode
#define MOUSEKEY_DELAY        150    //Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL     16     //Time between cursor movements in milliseconds (16 = 60fps)
#define MOUSEKEY_MAX_SPEED    32     //Maximum cursor speed at which acceleration stops
#define MOUSEKEY_TIME_TO_MAX  64     //Number of frames until maximum cursor speed is reached
#define MOUSEKEY_FRICTION     12     //How quickly the cursor stops after releasing a key
#define MOUSEKEY_MOVE_DELTA   1      //How much to move on first frame (1 strongly recommended)