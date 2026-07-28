#include <globaldefs.h>

struct Elem8_0223baa0;
struct ElemArray_0223baa0;
extern "C" Elem8_0223baa0* func_ov031_0223baa0(ElemArray_0223baa0* obj, int idx);
extern "C" int func_ov031_0223bdb0(int, int, int);
struct Obj0223bcc8;
void SetEntryHalfword4Bits_0223bcc8(Obj0223bcc8* obj, int idx, int val);
extern "C" void func_ov031_0223bbd8(void* a, int b, int c, int d);

extern unsigned short data_ov031_02248d02[];
extern unsigned short data_ov031_02248d04[];

struct Obj022269d8 {
    unsigned char pad[0x58];
    void* field58;
    unsigned char pad2[0x63 - 0x58 - 4];
    signed char state;
};
extern Obj022269d8* data_ov031_02250c00;

// USA: func_ov031_022269d8
extern "C" ARM void func_ov031_022269d8(void) {
    int idxVal = (data_ov031_02250c00->state <= 0xb) ? 0x44 : 0x45;
    Elem8_0223baa0* elem = func_ov031_0223baa0((ElemArray_0223baa0*)data_ov031_02250c00->field58, 0);
    func_ov031_0223bdb0(0, idxVal, (int)elem);
    SetEntryHalfword4Bits_0223bcc8((Obj0223bcc8*)data_ov031_02250c00->field58, -1, 2);
    signed char state2 = data_ov031_02250c00->state;
    func_ov031_0223bbd8(data_ov031_02250c00->field58, -1,
        data_ov031_02248d02[state2 * 2], data_ov031_02248d04[state2 * 2]);
}
