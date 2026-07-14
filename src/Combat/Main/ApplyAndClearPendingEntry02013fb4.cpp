#include <globaldefs.h>

int GetData02104304Field4();

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

extern "C" {
    int func_0202fdd0(int a, int b);
    void func_0201c724(int a, void* b, int c, int d);
    void func_020301c8(int a, int b);
    void func_0201403c(void* obj);
}

struct Obj02013fb4 {
    unsigned short field0;
    char pad[0x430 - 2];
    int field0x430;
};

// USA: func_02013fb4
ARM int ApplyAndClearPendingEntry02013fb4(struct Obj02013fb4* obj) {
    if (obj->field0x430 < 0) {
        return 1;
    }

    int listPtr = GetData02104304Field4();
    if (!func_0202fdd0(listPtr, obj->field0x430)) {
        return 0;
    }

    int out1, out2;
    GetListEntryValues0202fec8((struct List0202fec8*)listPtr, obj->field0x430, &out1, &out2);
    func_0201c724(obj->field0, (char*)obj + 0xc, out1, out2);
    func_020301c8(listPtr, obj->field0x430);
    obj->field0x430 = -1;
    func_0201403c(obj);
    return 1;
}
