#ifndef LIBRETRO_CAP32_H
#define LIBRETRO_CAP32_H 1

#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define Uint8 unsigned char
#define Uint16 unsigned short int
#define Uint32 unsigned int

#include <stdbool.h>

#define TEX_WIDTH 640
#define TEX_HEIGHT 480
#define CROP_WIDTH 640
#define CROP_HEIGHT 400

#define NPLGN 10
#define NLIGN 5
#define NLETT 5

#define XSIDE  (CROP_WIDTH/NPLGN -1)
#define YSIDE  (CROP_HEIGHT/8 -1)

#define YBASE0 (CROP_HEIGHT - NLIGN*YSIDE -8)
#define XBASE0 0+4+2
#define XBASE3 0
#define YBASE3 YBASE0 -4

#define STAT_DECX 120
#define STAT_YSZ  20

#define RGB565(r, g, b)  (((r) << (5+6)) | ((g) << 6) | (b))

//ZOOM GAME RES
#define MXZO 384
#define MYZO 272

typedef struct mres{
	int x,y;
}MRES;


#endif
