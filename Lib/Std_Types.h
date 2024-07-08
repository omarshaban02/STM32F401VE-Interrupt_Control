/**
 * Std_Types.h
 *  Created on: Sat Apr 19 2024
 *  Author    : Mahmoud Mohamed Ali
 */

#ifndef STD_TYPES_H
#define STD_TYPES_H


typedef signed char         	sint8;          /*        -128 .. +127            */
typedef unsigned char       	uint8;          /*           0 .. 255             */
typedef signed short        	sint16;         /*      -32768 .. +32767          */
typedef unsigned short      	uint16;         /*           0 .. 65535           */
typedef signed long         	sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long      		uint32;         /*           0 .. 4294967295      */
typedef unsigned long long  	uint64;         /*       0..18446744073709551615  */
typedef signed long long    	sint64;         /*       0..18446744073709551615  */
typedef float               	float32;        /* 1.1754943635e-38 to 3.4028235e+38 */
typedef double              	float64;        /* 2.2250738585072015e-308 to 1.7976931348623158e+308 */

typedef volatile unsigned int   vuint32_t;		/* Volatile unsigned 32-bit integer */
typedef volatile signed int     vsint32_t;		/* Volatile signed 32-bit integer */
typedef volatile unsigned char  vuint8_t;       /* Volatile unsigned 8-bit integer */
typedef volatile signed char    vsint8_t;       /* Volatile signed 8-bit integer */
typedef unsigned char       	boolean;        /* for use with TRUE/FALSE        */
typedef uint32              	return_status;  /* Return status code             */


typedef uint8 Rcc_PeripheralIdType;				/* Type for peripheral ID ]*/

typedef int 					*IntPtr;        /* Pointer to an integer */
typedef char 					*CharPtr;       /* Pointer to a character */
typedef float 					*FloatPtr;      /* Pointer to a float */
typedef void 					*VoidPtr;       /* Generic pointer type */


#endif /* STD_TYPES_H */
