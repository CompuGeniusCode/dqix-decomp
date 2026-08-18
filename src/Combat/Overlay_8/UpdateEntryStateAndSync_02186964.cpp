#include <globaldefs.h>

struct Struct_0205bef8;
void Init0205bef8(struct Struct_0205bef8* s);

struct Struct_0205ba68;
void SetupPointerTable0205ba68(struct Struct_0205ba68* s, int a, int b, int mode);

struct Node0205bacc;
void SetField0AndPropagate0205bacc(struct Node0205bacc* s, int val);

struct SelfBB04;
extern "C" void func_0205bb04(struct SelfBB04* self, int value);

struct Obj02186964 {
    char pad0[0x744];
    unsigned char tbl744[8];
    unsigned char f74c;
    char pad1[0xb10 - 0x74d];
    signed char b10;
    char pad2[0xb18 - 0xb11];
    unsigned int flags_b18;
    char pad3[0xb28 - 0xb1c];
    unsigned char b28;
    unsigned char b29;
};

// USA: func_ov008_02186964
extern "C" ARM void UpdateEntryStateAndSync_02186964(struct Obj02186964* obj) {
    int count = 1;
    int propagateVal = 1;
    int matchIdx = 0;

    if (obj->b10 == 3) {
        int i;
        count = obj->f74c;
        propagateVal = count;
        for (i = 0; i < count; i++) {
            if (obj->b28 == obj->tbl744[i]) {
                matchIdx = i;
                break;
            }
        }
        if (count > 6) {
            int b29 = obj->b29;
            obj->flags_b18 |= 0x10;
            if (matchIdx > b29 + 5) {
                obj->b29 = matchIdx - 5;
            } else if (matchIdx < b29) {
                obj->b29 = matchIdx;
            }
        }
    }

    Init0205bef8((struct Struct_0205bef8*)((char*)obj + 0x750));
    SetupPointerTable0205ba68((struct Struct_0205ba68*)((char*)obj + 0x750), 1, count, 0);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)((char*)obj + 0x750), propagateVal);
    *(int*)((char*)obj + 0x754) = 1;
    func_0205bb04((struct SelfBB04*)((char*)obj + 0x750), matchIdx);
}
