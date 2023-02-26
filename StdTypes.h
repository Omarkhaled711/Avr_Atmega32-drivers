/*
 *  Author: Omar Khaled
 */

#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef unsigned char u8;
typedef signed char   s8;

typedef unsigned int u16;
typedef signed int   s16;

typedef unsigned long u32;
typedef signed long   s32;

#define NULL_PTR     ((*void)0)

typedef enum {
	FALSE,
	TRUE,
	}bool;
typedef enum {
	OK,
	NOT_OK,
	NULL,
	OUT_OF_RANGE,
	}Error_types;

#define MAX_U16   ((u16)65535)
#define MAX_S16   ((s16)32767)
#define MIN_U16   ((u16)0)
#define MIN_S16   ((s16)-32768) 
#endif /* STDTYPES_H_ */