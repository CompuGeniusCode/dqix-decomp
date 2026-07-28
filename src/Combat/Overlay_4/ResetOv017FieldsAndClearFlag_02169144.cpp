#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov017_0218b5b0(void);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void ClearBitsInField8(unsigned int* obj, unsigned int mask);
void SetBitsInWord(unsigned int* obj, unsigned int mask);
void SetBitsInField4(unsigned int* obj, unsigned int mask);
void SetBitsInField8(unsigned int* obj, unsigned int mask);
extern "C" void* func_02012fe4(void);
struct S_e828;
extern "C" void _Z14SetFieldAt0x7eP6S_e828s(struct S_e828* p, unsigned short v);
extern "C" void func_ov017_021a967c(unsigned char* self, int id);
int GetGlobalField0x1c020421a0(void);
extern void* data_ov004_02171030;
struct FieldGroup02171030At100 { char pad[0x8c]; unsigned short field8c; };

// USA: func_ov004_02169144  (semantic: ResetOv017FieldsAndClearFlag_02169144)
extern "C" ARM int func_ov004_02169144(void) {
    GetBattleStruct();
    void* obj = func_ov017_0218b5b0();
    unsigned char* self = *(unsigned char**)((char*)obj + 0x3000 + 0xb84);
    ClearBitsInWord((unsigned int*)obj, -1);
    ClearBitsInField4((unsigned int*)obj, -1);
    ClearBitsInField8((unsigned int*)obj, -1);
    SetBitsInWord((unsigned int*)obj, *(unsigned int*)((char*)data_ov004_02171030 + 0x180));
    SetBitsInField4((unsigned int*)obj, *(unsigned int*)((char*)data_ov004_02171030 + 0x184));
    SetBitsInField8((unsigned int*)obj, *(unsigned int*)((char*)data_ov004_02171030 + 0x188));
    void* v = func_02012fe4();
    if (!v) return 0;
    struct S_e828* p = (struct S_e828*)((char*)v + 0x6c);
    if (!p) return 0;
    struct FieldGroup02171030At100* s100 = (struct FieldGroup02171030At100*)((char*)data_ov004_02171030 + 0x100);
    _Z14SetFieldAt0x7eP6S_e828s(p, s100->field8c);
    func_ov017_021a967c(self, -1);
    int g = GetGlobalField0x1c020421a0();
    g += 0x1000;
    *(unsigned char*)(g + 0x962) = 0;
    return 0;
}
