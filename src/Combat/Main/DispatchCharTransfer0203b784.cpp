#include <globaldefs.h>
#include "System/Cache.h"

int TransferBg0CharData(int arg0, int arg1, unsigned int arg2);
int TransferBg1CharData(int arg0, int arg1, unsigned int arg2);
int TransferBg2CharData(int arg0, int arg1, unsigned int arg2);
int TransferToBg3Char(int arg0, int arg1, unsigned int arg2);
int TransferSubBg0CharData(int arg0, int arg1, unsigned int arg2);
int TransferSubBg1CharData(int arg0, int arg1, unsigned int arg2);
int TransferToSubBg2Char(int arg0, int arg1, unsigned int arg2);
int TransferToSubBg3Char(int arg0, int arg1, unsigned int arg2);

// USA: func_0203b784
ARM int DispatchCharTransfer0203b784(int* arr1, int idx, int category, int addr, unsigned int len, unsigned int len2) {
    int* arr2 = (int*)((char*)arr1 + 0x20);
    int old1 = arr1[idx];
    arr1[idx] = old1 + len;
    int old2 = *(int*)((char*)&arr1[idx] + 0x20);
    int t2 = arr2[idx];
    arr2[idx] = t2 + len2;
    CleanInvalidateCacheRange((void*)addr, len);
    switch (idx) {
    case 0:
        switch (category) {
        case 0: TransferBg0CharData(addr, old1, len); break;
        case 1: TransferBg1CharData(addr, old1, len); break;
        case 2: TransferBg2CharData(addr, old1, len); break;
        case 3: TransferToBg3Char(addr, old1, len); break;
        }
        break;
    case 1:
        switch (category) {
        case 0: TransferSubBg0CharData(addr, old1, len); break;
        case 1: TransferSubBg1CharData(addr, old1, len); break;
        case 2: TransferToSubBg2Char(addr, old1, len); break;
        case 3: TransferToSubBg3Char(addr, old1, len); break;
        }
        break;
    }
    return old2;
}
