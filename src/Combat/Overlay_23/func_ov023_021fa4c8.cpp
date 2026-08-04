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
extern "C" void func_ov023_021fa644(void* obj, void* arg1, char* entry, void* next);

struct Obj021fa4c8 {
    char pad[0x1c];
    int field1c;
};

// USA: func_ov023_021fa4c8
extern "C" ARM int func_ov023_021fa4c8(struct Obj021fa4c8* obj, void* ctx) {
    void* node = func_ov011_021849c8(ctx);
    int listPtr = GetData02104304Field4();
    int key = func_ov023_021f6bb8(node);
    if (func_0202fdd0(listPtr, key)) {
        if (LookupListValueByKey((struct List0202fe68*)listPtr, key) == 2) {
            int v1, v2;
            GetListEntryValues0202fec8((struct List0202fec8*)listPtr, key, &v1, &v2);
            if (v1 != 0 && v2 != 0) {
                func_ov023_021fa644(obj, ctx, (char*)v1, (void*)v2);
            }
        }
        func_020301c8(listPtr, key);
        func_ov023_021f6bb0(node, -1);
        return 2;
    }
    return obj->field1c;
}
