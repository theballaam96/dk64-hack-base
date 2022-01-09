#include "../include/common.h"

void cFuncLoop(void) {
	// Enable stack trace upon crash
	*(s8 *)(0x807563B4) = 1;
	*(s32 *)(0x80731F78) = 0;
	/*
		This function is run every frame. Place c code which you are wanting to be run every frame
	*/
}
