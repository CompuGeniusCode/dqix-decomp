#include <globaldefs.h>

struct Elem8_0223baa0;
struct ElemArray_0223baa0;
extern "C" Elem8_0223baa0* func_ov031_0223baa0(ElemArray_0223baa0* obj, int idx);
extern "C" int func_ov031_0223bdb0(int, int, int);
struct Obj0223bcc8;
void SetEntryHalfword4Bits_0223bcc8(Obj0223bcc8* obj, int idx, int val);
extern "C" void func_ov031_0223bbd8(void* a, int b, int c, int d);

struct S02232f58 { unsigned char idx; char pad[3]; char* field4; };
extern S02232f58 data_ov031_02290cc0;
extern unsigned short data_ov031_02249082[];
extern unsigned short data_ov031_02249084[];

// USA: func_ov031_02232f58
extern "C" ARM void func_ov031_02232f58(void) {
    int r4 = data_ov031_02290cc0.idx - 4;
    Elem8_0223baa0* elem = func_ov031_0223baa0(
        (ElemArray_0223baa0*)*(void**)(data_ov031_02290cc0.field4 + r4 * 4 + 0x10), 0);
    func_ov031_0223bdb0(0, 0x32, (int)elem);

    func_ov031_0223bbd8(*(void**)(data_ov031_02290cc0.field4 + r4 * 4 + 0x10), -1,
        data_ov031_02249082[(r4 + 3) * 2], data_ov031_02249084[(r4 + 3) * 2]);

    SetEntryHalfword4Bits_0223bcc8(
        (Obj0223bcc8*)*(void**)(data_ov031_02290cc0.field4 + r4 * 4 + 0x10), -1, 3);
}
