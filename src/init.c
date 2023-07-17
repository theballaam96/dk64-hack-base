#include "../include/common.h"

static s8 initialized = 0;

void initHack(void) {
    /**
     * @brief Everything you expect to run upon booting your hack up, and nowhere else.
     */
    if (!initialized) {
        // Enable stack trace upon crash
        *(s8 *)(0x807563B4) = 1;
        *(s32 *)(0x80731F78) = 0;
        initStackTrace();
        // TAG ANYWHERE STUFF
        // START
        *(int*)(0x806F6D94) = 0; // Prevent delayed collection
        // Standard Ammo
        *(short*)(0x806F5B68) = 0x1000;
        *(int*)(0x806F5BE8) = 0x0C000000 | (((int)&tagAnywhereAmmo & 0xFFFFFF) >> 2);
        // Bunch
        *(short*)(0x806F59A8) = 0x1000;
        *(int*)(0x806F5A08) = 0x0C000000 | (((int)&tagAnywhereBunch & 0xFFFFFF) >> 2);
        *(int*)(0x806F6CAC) = 0x9204001A; // LBU $a0, 0x1A ($s0)
        *(int*)(0x806F6CB0) = 0x86060002; // LH $a2, 0x2 ($s0)
        *(int*)(0x806F6CB4) = 0x0C000000 | (((int)&tagAnywhereInit & 0xFFFFFF) >> 2);
        *(int*)(0x806F53AC) = 0; // Prevent LZ case
        // Minor Bug Fixes
        grab_lock_timer = -1;
        tag_locked = 0;
        writeFunction(0x8072F1E8, &handleGrabbingLock);
        writeFunction(0x8072F458, &handleActionSet); // Actor grabbables
        writeFunction(0x8072F46C, &handleActionSet); // Model 2 grabbables
        writeFunction(0x806CFC64, &handleActionSet); // Ledge Grabbing
        // FINISH
        initialized = 1;
    }
}