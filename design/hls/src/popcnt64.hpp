#ifndef _POPCNT64_
#define _POPCNT64_

#include <stdio.h>
#include <ap_int.h>

#define LUT_WIDTH 6
#define LUT_CNT 3
#define POP_CNT 7
#define POP_WIDTH 64

ap_uint<LUT_CNT> xilpopcnt(ap_uint<LUT_WIDTH> x);
void popcnt64(ap_uint<POP_WIDTH> x, ap_uint<POP_CNT> *bc); 
#endif
