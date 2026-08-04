#include <globaldefs.h>

int GetData02104304Field4();
struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);
extern "C" {
    int func_0202fdd0(int a, int b);
    void func_020301c8(int a, int b);
}
extern "C" void func_ov023_021db314(void* obj, short* out, short* outCount);
extern "C" int func_020e0028(void* p, void* b, int out1, int out2, void* p2, int field84);
void InitAndAppendTextB_021e0eb8(void* obj);

// USA: func_ov023_021e0a90  (semantic: DispatchListEntryCodes_021e0a90)
extern "C" ARM int func_ov023_021e0a90(void* obj) {
    if (*(int*)((char*)obj + 0x748) == -1) {
        return 0xd;
    }

    int listPtr = GetData02104304Field4();
    if (func_0202fdd0(listPtr, *(int*)((char*)obj + 0x748))) {
        int out1;
        int out2;
        GetListEntryValues0202fec8((struct List0202fec8*)listPtr, *(int*)((char*)obj + 0x748), &out1, &out2);
        if (out1 != 0 && out2 != 0) {
            short codes[12];
            short count;
            func_ov023_021db314((char*)obj + 0x6c, codes, &count);
            func_020e0028((char*)obj + 0x8c, (char*)obj + 0x28, out1, out2, codes, (unsigned short)count);
        }

        func_020301c8(listPtr, *(int*)((char*)obj + 0x748));
        *(int*)((char*)obj + 0x748) = -1;
        InitAndAppendTextB_021e0eb8(obj);
        return 0xd;
    }

    return 0xb;
}
