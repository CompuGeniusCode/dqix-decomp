#include <globaldefs.h>

int GetData02104304Field4(void);
int CallFunc0202fa38ZeroPad(int a, int b, int c);
extern "C" int func_0202fdd0(int a, int b);

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

extern "C" void func_ov023_021f5448(void* obj, int a, int b, int c);
extern "C" int func_ov023_021f5410(void* obj);
extern "C" int func_ov023_021f5340(void* obj);

extern int data_ov023_021fe334;

// USA: func_ov023_021f5340
extern "C" ARM int func_ov023_021f5340(void* objRaw) {
    char* obj = (char*)objRaw;
    int dataResult = GetData02104304Field4();
    short state = *(short*)(obj + 0xc);
    switch (state) {
    case 1:
        *(int*)(obj + 0x10) = CallFunc0202fa38ZeroPad(dataResult, data_ov023_021fe334, 0);
        *(short*)(obj + 0xc) = 2;
        return func_ov023_021f5340(obj);
    case 2:
        if (func_0202fdd0(dataResult, *(int*)(obj + 0x10)) == 0) return 0;
        *(short*)(obj + 0xc) = 3;
        return func_ov023_021f5340(obj);
    case 3: {
        int out1 = 0, out2 = 0;
        GetListEntryValues0202fec8((struct List0202fec8*)dataResult, *(int*)(obj + 0x10), &out1, &out2);
        func_ov023_021f5448(obj, *(int*)(obj + 0x14), out1, out2);
        func_ov023_021f5410(obj);
        return 1;
    }
    default:
        return 1;
    }
}
