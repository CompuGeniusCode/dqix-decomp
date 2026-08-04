#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void* ctx);
int GetData02104304Field4();

struct List0202fe68;
int LookupListValueByKey(struct List0202fe68* obj, int key);

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

extern "C" {
    int func_0202fdd0(int a, int b);
    int func_ov023_021f6bb8(void* obj);
    void func_ov023_021f6bb0(void* obj, int v);
    void func_020301c8(int a, int b);
    void func_ov023_021f7290(void* obj, void* ctx, int p2, int p3);
}

struct Obj021f707c {
    char pad[0x1c];
    int field1c;
};

// USA: func_ov023_021f707c  (semantic: DispatchOrReturnField1c_021f707c)
extern "C" ARM int func_ov023_021f707c(struct Obj021f707c* obj, void* ctx) {
    void* node = func_ov011_021849c8(ctx);
    int listPtr = GetData02104304Field4();
    int key = func_ov023_021f6bb8(node);
    if (func_0202fdd0(listPtr, key)) {
        if (LookupListValueByKey((struct List0202fe68*)listPtr, key) == 2) {
            int v1, v2;
            GetListEntryValues0202fec8((struct List0202fec8*)listPtr, key, &v1, &v2);
            func_ov023_021f7290(obj, ctx, v1, v2);
        }

        func_020301c8(listPtr, key);
        func_ov023_021f6bb0(node, -1);
        return 2;
    }
    return obj->field1c;
}
