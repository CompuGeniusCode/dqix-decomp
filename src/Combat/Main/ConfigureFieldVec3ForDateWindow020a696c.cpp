#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_02012fe4(struct BattleStruct* battleStruct);
void* GetField0x3f8Address(struct BattleStruct* battleStruct);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
struct Vec3Target020a6aa4 { int x; int y; int z; };
void SetVec3At0x0020a6aa4(struct Vec3Target020a6aa4* obj, int x, int y, int z);

// USA: func_020a696c
ARM void ConfigureFieldVec3ForDateWindow(void* unused0, int value1, int value2) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    void* base = func_02012fe4(battleStruct);
    void* fieldPtr = GetField0x3f8Address(battleStruct);

    if (value2 == 0x170c) {
        if ((value1 >= 0x4e20 && value1 <= 0x752f) || value1 == 0x76c) {
            unsigned char* p = (unsigned char*)fieldPtr;
            if (p[0x5] == 0 && p[0x62] == 0) {
                unsigned short u = *(unsigned short*)((char*)base + 0x2786);
                *(unsigned short*)fieldPtr = u;
                switch (u) {
                case 0:
                case 1:
                {
                    int localBuf[3];
                    int code = 0x170c;
                    *(unsigned short*)fieldPtr = code;
                    SetVec3At0x0020a6aa4((struct Vec3Target020a6aa4*)localBuf, -0x7000, code >> 3, 0x5e66);
                    _ZN8Vector3iaSERKS_((int*)((char*)fieldPtr + 0x10), localBuf);
                    p[0x7] = 1;
                    break;
                }
                default:
                    if (u != 0x76c) {
                        *(int*)((char*)fieldPtr + 0x10) = 0x100000;
                        *(int*)((char*)fieldPtr + 0x14) = 0;
                        *(int*)((char*)fieldPtr + 0x18) = 0x100000;
                        p[0x7] = 1;
                    }
                    break;
                }
            }
        }
    }

    if (value1 == 0x2710 && value2 >= 0x4e20 && value2 <= 0x752f) {
        *(int*)((char*)base + 0x278c) = *(int*)((char*)base + 0x44);
        *(int*)((char*)base + 0x2790) = *(int*)((char*)base + 0x48);
    }
}
