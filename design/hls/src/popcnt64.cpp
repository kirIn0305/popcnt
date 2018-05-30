#include "popcnt64.hpp"

//Optimized for 6-input LUT
ap_uint<LUT_CNT> xilpopcnt(ap_uint<LUT_WIDTH> x) { 
    switch (x) {
        case  0: return 0;
        case  1: return 1;
        case  2: return 1;
        case  3: return 2;
        case  4: return 1;
        case  5: return 2;
        case  6: return 2;
        case  7: return 3;
        case  8: return 1;
        case  9: return 2;
        case 10: return 2;
        case 11: return 3;
        case 12: return 2;
        case 13: return 3;
        case 14: return 3;
        case 15: return 4;
        case 16: return 1;
        case 17: return 2;
        case 18: return 2;
        case 19: return 3;
        case 20: return 2;
        case 21: return 3;
        case 22: return 3;
        case 23: return 4;
        case 24: return 2;
        case 25: return 3;
        case 26: return 3;
        case 27: return 4;
        case 28: return 3;
        case 29: return 4;
        case 30: return 4;
        case 31: return 5;
        case 32: return 1;
        case 33: return 2;
        case 34: return 2;
        case 35: return 3;
        case 36: return 2;
        case 37: return 3;
        case 38: return 3;
        case 39: return 4;
        case 40: return 2;
        case 41: return 3;
        case 42: return 3;
        case 43: return 4;
        case 44: return 3;
        case 45: return 4;
        case 46: return 4;
        case 47: return 5;
        case 48: return 2;
        case 49: return 3;
        case 50: return 3;
        case 51: return 4;
        case 52: return 3;
        case 53: return 4;
        case 54: return 4;
        case 55: return 5;
        case 56: return 3;
        case 57: return 4;
        case 58: return 4;
        case 59: return 5;
        case 60: return 4;
        case 61: return 5;
        case 62: return 5;
        case 63: return 6;
    }
    return 0;
}

void popcnt64(ap_uint<POP_WIDTH> x, ap_uint<POP_CNT> *bc) {
    #pragma HLS INTERFACE ap_ctrl_none port=x
    #pragma HLS INTERFACE ap_ctrl_none port=bc
    #pragma HLS PIPELINE
    *bc = xilpopcnt(x(63,60)) + xilpopcnt(x(59,54)) + xilpopcnt(x(53,48)) + 
          xilpopcnt(x(47,42)) + xilpopcnt(x(41,36)) + xilpopcnt(x(35,30)) +
          xilpopcnt(x(29,24)) + xilpopcnt(x(23,18)) + xilpopcnt(x(17,12)) +
          xilpopcnt(x(11,6)) + xilpopcnt(x(5,0));
} 
