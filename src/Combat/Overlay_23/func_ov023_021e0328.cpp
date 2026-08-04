#include <globaldefs.h>

int GetData02104304Field4();
extern "C" int func_0202fdd0(int a, int b);

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

struct InitStruct2075;
void ClearStructFields(struct InitStruct2075* p);

extern "C" void _ZN13SafeAllocator5ResetEv(void* thisPtr);
extern "C" void func_02076080(void* a, void* b, int c, int d);
extern "C" void func_020301c8(int a, int b);

// USA: func_ov023_021e0328
extern "C" ARM int func_ov023_021e0328(void* obj) {
    if (*(int*)((char*)obj + 0x738) == -1) {
        return 5;
    }

    int listPtr = GetData02104304Field4();
    if (func_0202fdd0(listPtr, *(int*)((char*)obj + 0x738))) {
        int out1, out2;
        GetListEntryValues0202fec8((struct List0202fec8*)listPtr, *(int*)((char*)obj + 0x738), &out1, &out2);
        ClearStructFields(*(struct InitStruct2075**)((char*)obj + 0xc8));

        if (out1 != 0 && out2 != 0) {
            _ZN13SafeAllocator5ResetEv(*(void**)((char*)obj + 0x40));
            func_02076080(*(void**)((char*)obj + 0xc8), *(void**)((char*)obj + 0x40), out1, out2);
            *(unsigned short*)((char*)obj + 0x774) &= ~8;
        }

        func_020301c8(listPtr, *(int*)((char*)obj + 0x738));
        *(int*)((char*)obj + 0x738) = -1;

        int tmpC4 = *(int*)((char*)obj + 0xc4);
        *(int*)((char*)obj + 0xc4) = *(int*)((char*)obj + 0xc8);
        *(int*)((char*)obj + 0xc8) = tmpC4;

        int tmp3c = *(int*)((char*)obj + 0x3c);
        *(int*)((char*)obj + 0x3c) = *(int*)((char*)obj + 0x40);
        *(int*)((char*)obj + 0x40) = tmp3c;

        *(unsigned short*)((char*)obj + 0x774) |= 2;
        return 5;
    }

    return 3;
}
