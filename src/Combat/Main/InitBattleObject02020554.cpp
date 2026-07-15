#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void func_02020720(int);
extern "C" void InitStruct_0201f9b8(void*);
extern "C" void InitStopwatch0201f9e8(void*);
void ClearRecords02026644(char* obj);

extern char data_020fdcb0;
extern char data_020fdcce;
extern char data_020fdc60;

// USA: func_02020554
ARM void InitBattleObject02020554(char* obj) {
    VectorizedMemset(obj, 0, 0xc30);
    obj[0x9c1] = 0;
    obj[0x9c2] = 0;
    obj[0x9c3] = 0;
    obj[0x9c4] = 0;
    obj[0x9c6] = 0;
    obj[0xa96] = 0;
    func_02020720((int)obj);
    for (int i = 0; i < 4; i++) {
        InitStruct_0201f9b8((char*)&data_020fdcb0 + i * 0x20);
        (&data_020fdcce)[i * 0x20] = 0;
        InitStopwatch0201f9e8((char*)&data_020fdc60 + i * 0x14);
    }
    *(int*)(obj + 0x5a4) |= 1;
    obj[0x765] = 1;
    obj[0x5a8] = 0;
    obj[0x12] = 0;
    obj[0x9c7] = 0;
    obj[0x778] = 0;
    obj[0x9c5] = 0;
    *(int*)(obj + 0x76c) = 0;
    *(int*)(obj + 0x770) = 0;
    *(int*)(obj + 0x774) = 0;
    obj[0x779] = 0;
    obj[0x9ba] = 0;
    *(int*)(obj + 0x77c) = 0;
    obj[0x780] = 0;
    ClearRecords02026644(obj);
    obj[0x9b8] = 0;
    obj[0x9b9] = 0;
    obj[0x9c8] = 0;
    obj[0x55d] = 0xf;
    obj[0x55e] = 0;
    *(int*)(obj + 0x9cc) = -1;
    *(int*)(obj + 0x9f8) = -1;
    *(int*)(obj + 0x9d0) = -1;
    *(int*)(obj + 0x9d4) = -1;
    *(int*)(obj + 0x9fc) = -1;
    *(int*)(obj + 0xa00) = -1;
    *(int*)(obj + 0xa04) = -1;
    *(int*)(obj + 0xa08) = -1;
    *(int*)(obj + 0xa0c) = -1;
    *(int*)(obj + 0xa10) = -1;
    *(int*)(obj + 0xa14) = -1;
    *(int*)(obj + 0xa18) = -1;
    *(int*)(obj + 0xa1c) = -1;
    *(int*)(obj + 0xa20) = -1;
    *(int*)(obj + 0xa24) = -1;
    *(int*)(obj + 0xa28) = -1;
    *(int*)(obj + 0xa2c) = -1;
    *(int*)(obj + 0xa30) = -1;
    for (int i = 0; i < 8; i++) {
        *(int*)(obj + 0x9d8 + i * 4) = -1;
    }
    *(unsigned char*)(obj + 0xa34) = 0xff;
    VectorizedMemset(obj + 0xa35, 0, 0x10);
    VectorizedMemset(obj + 0xa45, 0, 0x10);
    VectorizedMemset(obj + 0xa55, 0, 0x20);
    obj[0xa95] = 0;
    obj[0xa97] = 0;
    VectorizedMemset(obj + 0xba2, 0, 0x40);
    *(int*)(obj + 0xbe4) = 0;
    *(int*)(obj + 0xbe8) = 0;
    *(short*)(obj + 0xbec) = 0;
    *(short*)(obj + 0xbee) = 0;
}
