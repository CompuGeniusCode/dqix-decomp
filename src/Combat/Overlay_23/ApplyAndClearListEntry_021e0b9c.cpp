#include <globaldefs.h>

int GetData02104304Field4();

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

extern "C" {
    int func_0202fdd0(int a, int b);
    void func_020df850(void* a, void* b, int out1, int out2, int fifth);
    void func_020301c8(int a, int b);
}

struct Obj021e0b9c {
    char pad28[0x28];
    int field28;
    char pad4c[0x4c - 0x2c];
    void* field4c;
    char pad7c[0x7c - 0x50];
    int field7c;
    char pad74c[0x74c - 0x80];
    int handle;
};

// USA: func_ov023_021e0b9c  (semantic: ApplyAndClearListEntry_021e0b9c)
extern "C" ARM int func_ov023_021e0b9c(struct Obj021e0b9c* obj) {
    if (obj->handle == -1) {
        return -1;
    }

    int listPtr = GetData02104304Field4();
    if (func_0202fdd0(listPtr, obj->handle)) {
        int out1, out2;
        GetListEntryValues0202fec8((struct List0202fec8*)listPtr, obj->handle, &out1, &out2);
        if (out1 != 0 && out2 != 0) {
            int v = *(short*)((char*)obj->field4c + 0x18);
            func_020df850(&obj->field7c, &obj->field28, out1, out2, v);
        }

        func_020301c8(listPtr, obj->handle);
        obj->handle = -1;
        return 0xf;
    }

    return 0xd;
}
