#include <globaldefs.h>

int GetData02104304Field4();

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

void* GetGlobalPtr02105244();
extern "C" void* func_0203bd08(void);
extern "C" void* func_0203be4c(void);

struct Rec020467f0;
int ProcessRecords0205a498(void* a, struct Rec020467f0* b, int flag, void* d);

extern "C" void func_020301c8(int a, int b);

void SetBitfieldStoreBytes0205af38(int a, char* obj, int c, int d);

// USA: func_02020aec  (semantic: ApplyGlobalTableAndFinalize02020aec)
extern "C" ARM void func_02020aec(char* self, int* handle, int arg2) {
    int listPtr = GetData02104304Field4();
    int out1 = 0, out2 = 0;
    GetListEntryValues0202fec8((struct List0202fec8*)listPtr, *handle, &out1, &out2);

    char* g = (char*)GetGlobalPtr02105244();
    *(int*)(g + 0x508) = 0x2000;
    func_0203bd08();

    char* p = (char*)func_0203be4c() + 0x2c0;
    g = (char*)GetGlobalPtr02105244();
    *(char**)g = p;

    ProcessRecords0205a498(self + 0x94, (struct Rec020467f0*)out1, out2, (void*)arg2);

    listPtr = GetData02104304Field4();
    func_020301c8(listPtr, *handle);
    *handle = -1;

    SetBitfieldStoreBytes0205af38((int)(self + 0x94), self + 0x250, 1, 1);
    SetBitfieldStoreBytes0205af38((int)(self + 0x94), self + 0x2a0, 1, 1);
}
