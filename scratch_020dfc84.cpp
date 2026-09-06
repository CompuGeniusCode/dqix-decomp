#include <globaldefs.h>

struct Struct020dfc40;
void ResetStruct020dfc40(Struct020dfc40* p);

struct Obj020dfe88;
int ResetHandleState020dfe88(struct Obj020dfe88* obj);

int ReplaceBinExtensionWithNat020e05f8(char* dst, const char* fmt);

extern "C" void func_020dfd40(void* obj, const char* a, const char* b);

struct HandleObj020dfc84 {
    char pad0[0xc];
    short field_c;
    short field_e;
    int field_10;
    int field_14;
};

// USA: func_020dfc84
extern "C" ARM void func_020dfc84(HandleObj020dfc84* obj, int b, const char* c, const char* d, short e, short f) {
    ResetHandleState020dfe88((struct Obj020dfe88*)obj);
    ResetStruct020dfc40((Struct020dfc40*)obj);
    obj->field_14 = b;
    obj->field_c = f;
    obj->field_e = 1;
    if (e >= 0) {
        char buf1[0x40];
        ReplaceBinExtensionWithNat020e05f8(buf1, c);
        if (d) {
            char buf2[0x20];
            volatile short tmp = e;
            ReplaceBinExtensionWithNat020e05f8(buf2, d);
            func_020dfd40(obj, buf1, buf2);
        } else {
            func_020dfd40(obj, buf1, 0);
        }
    } else {
        if (d) {
            func_020dfd40(obj, c, d);
        } else {
            func_020dfd40(obj, c, 0);
        }
    }
}
