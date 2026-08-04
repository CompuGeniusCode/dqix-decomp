#include <globaldefs.h>

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
extern "C" void func_ov023_021f7b98(void* obj, void* ctx, int flag, int v1, int v2);
extern "C" void func_0204b088(void* p, int flag);

struct Obj021f78a4 {
    char pad0[0xc];
    unsigned char flags0xc;
    char pad0d[0x1c - 0xd];
    int field1c;
    void* field20;
};

// USA: func_ov023_021f78a4
extern "C" ARM void func_ov023_021f78a4(struct Obj021f78a4* obj) {
    if (obj->flags0xc & 0x2) {
        void* ctx = obj->field20;
        void* node = func_ov011_021849c8(ctx);
        int listPtr = GetData02104304Field4();
        int key = func_ov023_021f6bb8(node);
        if (func_0202fdd0(listPtr, key)) {
            if (LookupListValueByKey((struct List0202fe68*)listPtr, key) == 2) {
                int v1, v2;
                GetListEntryValues0202fec8((struct List0202fec8*)listPtr, key, &v1, &v2);
                if (v1 != 0 && v2 != 0) {
                    func_ov023_021f7b98(obj, ctx, 0, v1, v2);
                }
            }
            func_020301c8(listPtr, key);
            func_ov023_021f6bb0(node, -1);
            obj->field1c = 2;
        }
    }

    if (!(obj->flags0xc & 0x1)) {
        func_0204b088((char*)obj + 0x28, 0);
    }
}
