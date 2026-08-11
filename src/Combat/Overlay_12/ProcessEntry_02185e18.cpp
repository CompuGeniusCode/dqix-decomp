#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

int GetData02104304Field4();

struct List0202fec8;
void GetListEntryValues0202fec8(List0202fec8* obj, int id, int* out1, int* out2);

struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);

extern "C" void func_020728ac(void* a, void* b, int c, int d, int e, int f, int g);
extern "C" void func_020301c8(int a, int b);

// USA: func_ov012_02185e18  (semantic: ProcessEntry_02185e18)
extern "C" ARM void func_ov012_02185e18(char* self) {
    int id = GetData02104304Field4();
    int field = *(int*)(self + 0x1380);
    int out1, out2;
    GetListEntryValues0202fec8((List0202fec8*)id, field, &out1, &out2);
    ((SafeAllocator*)(self + 0x34))->Reset();
    func_020728ac(self + 0x133c, self + 0x34, out1, out2, 0, 0, 0);
    *(void**)(self + 0x1378) = FindEntryByKey((struct TableA68*)(self + 0x133c), 0);
    func_020301c8(id, *(int*)(self + 0x1380));
    *(int*)(self + 0x1380) = -1;
}
