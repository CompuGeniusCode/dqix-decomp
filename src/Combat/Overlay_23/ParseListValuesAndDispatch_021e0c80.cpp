#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_02005a94(signed char* p);
extern "C" void func_ov023_021e0f44(void* obj);

int GetData02104304Field4();
extern "C" int func_0202fdd0(int a, int b);
struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);
extern "C" void func_020301c8(int a, int b);
extern "C" int func_020e0028(void* p, void* b, int out1, int out2, void* p2, int field84);

int CopyIndexedRegion0x75f0(void* unused, short* indices, int* dest, int count);

struct ListEntry021e0c80 {
    char unused0;
    unsigned char flag;
    short pad2;
    char* str;
};

struct ListHeader021e0c80 {
    short unused0;
    short count;
    struct ListEntry021e0c80* entries;
};

// USA: func_ov023_021e0c80  (semantic: ParseListValuesAndDispatch_021e0c80)
extern "C" ARM int func_ov023_021e0c80(void* obj) {
    int idxData[24];
    short values[24];
    unsigned char flags[24];
    int out1;
    int out2;

    memset((char*)obj + 0xbc, 0, 6);
    *(short*)((char*)obj + 0xc2) = 0;

    short n = 0;

    struct ListHeader021e0c80* list = *(struct ListHeader021e0c80**)((char*)obj + 0x84);
    if (list) {
        int i;
        short count;
        struct ListEntry021e0c80* e;
        e = list->entries;
        count = list->count;
        for (i = 0; i < count; i++, e++) {
            if (e->flag == 0 || e->str == 0) continue;
            signed char c = e->str[0];
            if (c < 0x30 || c > 0x39) continue;
            short val = func_02005a94((signed char*)e->str);
            short v = val;
            signed char flag = 0;
            if (10000 <= val) {
                v -= 10000;
                flag = 1;
            }
            values[n] = v;
            flags[n] = flag;
            n++;
            if (n >= 0x18) break;
        }
    }

    if (n > 0) {
        if (CopyIndexedRegion0x75f0(0, values, idxData, n)) {
            int j;
            for (j = 0; j < n; j++) {
                short v = values[j];
                if (v < 1 || v > 0x134) continue;
                unsigned char fl = flags[j];
                if (fl == 0) {
                    if (((unsigned int)(idxData[j] << 0xe) >> 0x19) != 0) goto store021e0c80;
                }
                if (fl != 0) {
                    if (((unsigned int)(idxData[j] << 0x7) >> 0x19) != 0) goto store021e0c80;
                }
                continue;
            store021e0c80:
                *(short*)((char*)obj + 0xbc + *(short*)((char*)obj + 0xc2) * 2) = v;
                *(short*)((char*)obj + 0xc2) = *(short*)((char*)obj + 0xc2) + 1;
                if (*(short*)((char*)obj + 0xc2) >= 3) break;
            }
        }
    }

    if (*(short*)((char*)obj + 0xc2) <= 0) {
        func_ov023_021e0f44(obj);
        return -1;
    }

    if (*(int*)((char*)obj + 0x750) == -1) {
        return -1;
    }

    int listPtr = GetData02104304Field4();
    if (!func_0202fdd0(listPtr, *(int*)((char*)obj + 0x750))) {
        goto retf_021e0c80;
    }

    GetListEntryValues0202fec8((struct List0202fec8*)listPtr, *(int*)((char*)obj + 0x750), &out1, &out2);
    if (out1 != 0 && out2 != 0) {
        unsigned short cnt = *(unsigned short*)((char*)obj + 0xc2);
        func_020e0028((char*)obj + 0xa4, (char*)obj + 0x28, out1, out2, (char*)obj + 0xbc, cnt);
    }

    func_020301c8(listPtr, *(int*)((char*)obj + 0x750));
    *(int*)((char*)obj + 0x750) = -1;
    func_ov023_021e0f44(obj);
    return -1;

retf_021e0c80:
    return 0xf;
}
