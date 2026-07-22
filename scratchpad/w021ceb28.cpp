#include <globaldefs.h>

void* GetData02153637(void);
extern "C" int func_0202c508(void* state);
extern "C" void func_020e321c(void*, int, int);
extern "C" void func_020e33b4(void*, int, int);

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

struct Entry020e3054;
struct Entry020e3054* FindEntryByField1(struct Entry020e3054* list, int key);

struct Obj021ceb28 {
    char pad0[4];
    unsigned char f4;
    unsigned char f5;
    char pad6;
    unsigned char f7;
};

// USA: func_ov017_021ceb28
#pragma optimize_for_size off
ARM void DispatchEntryOrTag_021ceb28(int val, struct Obj021ceb28* obj, int unused2, int unused3, struct SearchStruct0202c1a4* extra) {
    void* data = GetData02153637();

    if (func_0202c508(extra) != 0 && val > 0) {
        unsigned char b4 = obj->f4;
        unsigned char b5 = obj->f5;
        unsigned char b7 = obj->f7;
        if (b4 == 0) goto elseCall;
        {
            void* d1 = data;
            func_020e321c(d1, b5, b7);
        }
        return;
    elseCall:
        {
            void* d2 = data;
            func_020e33b4(d2, b5, b7);
        }
        return;
    }

    if (val != 0) return;
    signed char cur = GetSearchStructCurrentArrEntry(extra);
    if (obj->f7 != cur) return;

    struct Entry020e3054* entry = FindEntryByField1((struct Entry020e3054*)data, obj->f5);
    if (entry == NULL) return;

    *((unsigned char*)entry + 2) = (obj->f4 != 0) ? 1 : 3;
}
