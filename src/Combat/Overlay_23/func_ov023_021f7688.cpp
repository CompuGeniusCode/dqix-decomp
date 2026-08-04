#include <globaldefs.h>

struct Obj021f7ca0;
extern "C" void func_ov023_021f7ca0(struct Obj021f7ca0* obj, void* keyObj);

extern "C" void* func_ov011_021849c8(void* ctx);
int GetData02104304Field4();
extern "C" int func_ov023_021f6bb8(void* obj);
extern "C" void func_ov023_021f6bb0(void* obj, int v);
extern "C" int func_0202fdd0(int a, int b);

struct List0202fe68;
int LookupListValueByKey(struct List0202fe68* obj, int key);

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

extern "C" void func_020301c8(int a, int b);

struct Obj021f7aac;
struct Rec020467f0;
extern "C" void func_ov023_021f7aac(struct Obj021f7aac* obj, void* keyObj, struct Rec020467f0* entry, void* next);
extern "C" void func_ov023_021f7b98(struct Obj021f7aac* obj, void* keyObj, int flag, struct Rec020467f0* entry, void* next);

struct Obj021f7688 {
    char pad0[0xc];
    unsigned char fieldC;
    char pad0d[0x10 - 0xd];
    int field10;
    char pad14[0x1c - 0x14];
    int field1c;
};

// USA: func_ov023_021f7688
extern "C" ARM int func_ov023_021f7688(struct Obj021f7688* obj, void* keyObj) {
    if (obj->field10 == 0) {
        func_ov023_021f7ca0((struct Obj021f7ca0*)obj, keyObj);
        return 2;
    }

    void* node = func_ov011_021849c8(keyObj);
    int listPtr = GetData02104304Field4();
    int key = func_ov023_021f6bb8(node);
    int result;
    if (func_0202fdd0(listPtr, key)) {
        if (LookupListValueByKey((struct List0202fe68*)listPtr, key) == 2) {
            int v1, v2;
            GetListEntryValues0202fec8((struct List0202fec8*)listPtr, key, &v1, &v2);
            if (v1 != 0 && v2 != 0) {
                if (obj->fieldC & 0x2) {
                    func_ov023_021f7b98((struct Obj021f7aac*)obj, keyObj, 1, (struct Rec020467f0*)v1, (void*)v2);
                } else {
                    func_ov023_021f7aac((struct Obj021f7aac*)obj, keyObj, (struct Rec020467f0*)v1, (void*)v2);
                }
            }
        }

        func_020301c8(listPtr, key);
        func_ov023_021f6bb0(node, -1);
        result = 2;
    } else {
        result = obj->field1c;
    }
    return result;
}
