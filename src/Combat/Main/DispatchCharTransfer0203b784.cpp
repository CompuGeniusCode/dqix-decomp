#include <globaldefs.h>
#include "System/Cache.h"

extern "C" int LoadToMainBG0CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToMainBG2CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToMainBG3CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToSubBG0CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToSubBG1CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToSubBG2CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToSubBG3CharacterData(int arg0, int arg1, unsigned int arg2);

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
        case 0: LoadToMainBG0CharacterData(addr, old1, len); break;
        case 1: LoadToMainBG1CharacterData(addr, old1, len); break;
        case 2: LoadToMainBG2CharacterData(addr, old1, len); break;
        case 3: LoadToMainBG3CharacterData(addr, old1, len); break;
        }
        break;
    case 1:
        switch (category) {
        case 0: LoadToSubBG0CharacterData(addr, old1, len); break;
        case 1: LoadToSubBG1CharacterData(addr, old1, len); break;
        case 2: LoadToSubBG2CharacterData(addr, old1, len); break;
        case 3: LoadToSubBG3CharacterData(addr, old1, len); break;
        }
        break;
    }
    return old2;
}
