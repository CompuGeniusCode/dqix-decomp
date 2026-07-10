#include <globaldefs.h>

void InitStruct0203be8c(char* obj);

// USA: func_0203c54c
ARM void ReleaseEntry0203c54c(char* obj, short* idxPtr) {
    short idx = *idxPtr;
    int cnt;
    char* entry;
    if (idx < 0) return;
    entry = obj + 4 + idx * 0x28;
    *idxPtr = -1;
    cnt = ((unsigned char*)entry)[0x24];
    if (cnt == 0) return;
    cnt = cnt - 1;
    ((unsigned char*)entry)[0x24] = cnt;
    if ((cnt & 0xff) != 0) return;
    InitStruct0203be8c(entry);
    *(unsigned short*)(obj + 0x512) -= 1;
}
