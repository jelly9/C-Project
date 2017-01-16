#ifndef __COMMET_CONVERT__
#define __COMMET_CONVERT__

#include <stdio.h>
#include <windows.h>
#include <assert.h>

#pragma warning(disable:4996)

#define INPUT_FILE "input.c"
#define OUTPUT_FILE "output.c"

typedef enum STATUS
{
	NORMAL_STATUS,
	C_STATUS,
	CPP_STATUS,
	END_STATUS,
}status_t;

extern status_t gStatus;
void convertBagin();

#endif