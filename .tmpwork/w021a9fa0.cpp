#include <globaldefs.h>

struct BattleStruct;
struct BattleStruct* GetBattleStruct(void);
extern "C" int func_ov017_0218b5b0(void);
extern "C" unsigned short* func_02012fe4(void);
int GetFieldIfFlag4(char* obj);
void SetField0x23cTrue(void* obj);
int IsValueInRange0201b5d8(int x);
void InitContext020e1154(void* obj);

struct Ctx021a9fa0 { char pad0[1]; unsigned char byte1; };

// USA: func_ov017_021a9fa0
ARM void SetByte1AfterFieldCheck_021a9fa0(struct Ctx021a9fa0* self) {
    struct BattleStruct* bs = GetBattleStruct();
    func_ov017_0218b5b0();
    unsigned short* p = func_02012fe4();
    SetField0x23cTrue((void*)(long)GetFieldIfFlag4((char*)bs));
    if (IsValueInRange0201b5d8(*p) != 0) {
        InitContext020e1154((void*)0x3e8);
    }
    self->byte1 = 1;
}
