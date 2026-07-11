#include <globaldefs.h>

extern "C" void func_0200ee94(void* obj, int count, int size, void* initFn1, void* initFn2);
char* InitStruct0203be64(char* obj);
char* InitStruct0203be78(char* obj);
void ResetBattleState0203c304(char* obj);

// USA: func_0203c2c0
ARM char* InitBattleObject0203c2c0(char* obj) {
    func_0200ee94(obj + 4, 0x20, 0x28, (void*)InitStruct0203be64, (void*)InitStruct0203be78);
    ResetBattleState0203c304(obj);
    return obj;
}
