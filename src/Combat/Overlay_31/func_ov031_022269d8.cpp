#include <globaldefs.h>

struct ElemArray_0223baa0;
extern "C" void* func_ov031_0223baa0(ElemArray_0223baa0* obj, int idx);
extern "C" int func_ov031_0223bdb0(int a, int b, int c);
struct Obj0223bcc8;
void SetEntryHalfword4Bits_0223bcc8(Obj0223bcc8* obj, int idx, int val);
extern "C" void func_ov031_0223bbd8(void* obj, int idx, int val0, int val1);

struct Obj_022269d8 {
    unsigned char pad0[0x58];
    void* field0x58;
    unsigned char pad1[0x63 - 0x5c];
    signed char state;
    signed char field64;
};
extern Obj_022269d8* data_ov031_02250c00;
extern unsigned short data_ov031_02248d02[];
extern unsigned short data_ov031_02248d04[];

// USA: func_ov031_022269d8
extern "C" ARM void func_ov031_022269d8(void) {
    signed char state = data_ov031_02250c00->state;
    int mode = (state <= 0xb) ? 0x44 : 0x45;
    void* arr = data_ov031_02250c00->field0x58;
    void* elem = func_ov031_0223baa0((ElemArray_0223baa0*)arr, 0);
    func_ov031_0223bdb0(0, mode, (int)elem);

    SetEntryHalfword4Bits_0223bcc8((Obj0223bcc8*)data_ov031_02250c00->field0x58, -1, 2);

    signed char state2 = data_ov031_02250c00->state;
    void* arr2 = data_ov031_02250c00->field0x58;
    unsigned short v0 = *(unsigned short*)((char*)data_ov031_02248d02 + state2 * 4);
    unsigned short v1 = *(unsigned short*)((char*)data_ov031_02248d04 + state2 * 4);
    func_ov031_0223bbd8(arr2, -1, v0, v1);
}
