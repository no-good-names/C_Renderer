/*

Created by github user no-good-name
Created on 2023-07-31
Updated: 2023-08-18

*/

#ifndef __MAIN_TYPE__
#define __MAIN_TYPE__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef float           f32;
typedef double          f64;

#define PI              3.14159265359f
#define TAU             ( 2.0f * PI )
#define PI_2            ( PI / 2.0f )
#define PI_4            ( PI / 4.0f )

typedef enum boolean_t  { false, true } bool;

typedef struct          { int x; int y; } Point_t;
typedef struct          { int x; int y; int w; int h; } Rect_t;
typedef struct          { uint8_t r; uint8_t g; uint8_t b; uint8_t a; } color_t;

#endif // __MAIN_TYPE__