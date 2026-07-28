#include <globaldefs.h>

int GetData02104304Field4();
extern "C" int func_ov011_021849d8(void* p);
extern "C" int func_0202fdd0(void* a, int b);

struct List0202fe68;
int LookupListValueByKey(struct List0202fe68* obj, int key);

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

char* FindEntryAndGetNext(void* a, char* b, void** outField44);
extern "C" void func_ov023_021f7aac(void* obj, void* arg1, char* entry, void* next);

struct Obj021f7a08 {
    char pad0[0x10];
    char* f10;
};

// USA: func_ov023_021f7a08  (semantic: DispatchIfEntryFound_021f7a08)
extern "C" ARM void func_ov023_021f7a08(struct Obj021f7a08* obj, void* keyObj) {
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
    if (out1 == 0 || out2 == 0) {
        return;
    }

    void* next;
    char* entry = FindEntryAndGetNext((void*)out1, obj->f10, &next);
    if (entry == NULL) {
        return;
    }

    func_ov023_021f7aac(obj, keyObj, entry, next);
}
