#include <globaldefs.h>

void InitStruct0203be8c(char* obj);

// USA: func_0203c304
ARM void ResetBattleState0203c304(char* obj) {
    int i;
    for (i = 0; i < 0x20; i++) {
        InitStruct0203be8c(obj + 4 + i * 0x28);
    }
    *(int*)obj = 0;
    *(short*)(obj + 0x512) = 0;
    *(int*)(obj + 0x504) = 1;
    *(int*)(obj + 0x50c) = 0;
    *(int*)(obj + 0x508) = 0;
    *(short*)(obj + 0x510) = 4;
}
