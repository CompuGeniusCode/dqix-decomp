#include <globaldefs.h>
#include "Filesystem/FileIO.h"

int GetData02104304Field4();
extern "C" int func_ov011_021849d8(void* p);
extern "C" int func_0202fdd0(void* a, int b);

struct List0202fe68;
int LookupListValueByKey(struct List0202fe68* obj, int key);

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

char* FindEntryAndGetNext(void* a, char* b, void** outField44);

extern "C" void func_ov023_021fab48(void* obj, void* keyObj, int out1, int out2);

struct Obj021faa60 {
    char pad0[0x10];
    char* f10;
    char pad1c[0x1c - 0x14];
    int field1c;
};

// USA: func_ov023_021faa60
extern "C" ARM void func_ov023_021faa60(struct Obj021faa60* obj, void* keyObj) {
    void* listPtr = (void*)GetData02104304Field4();
    int key = func_ov011_021849d8(keyObj);
    if (key < 0) {
        return;
    }
    if (!func_0202fdd0(listPtr, key)) {
        return;
    }
    if (LookupListValueByKey((struct List0202fe68*)listPtr, key) != 2) {
        return;
    }

    int out1, out2;
    GetListEntryValues0202fec8((struct List0202fec8*)listPtr, key, &out1, &out2);

    void* p;
    unsigned int n;
    if (GetFileInNarc((void*)out1, obj->f10, (const void**)&p, &n, 0)) {
        func_ov023_021fab48(obj, keyObj, out1, out2);
        obj->field1c = 2;
        return;
    }

    p = FindEntryAndGetNext((void*)out1, obj->f10, (void**)&n);
    if (p == NULL) {
        return;
    }

    func_ov023_021fab48(obj, keyObj, out1, out2);
    obj->field1c = 2;
}
