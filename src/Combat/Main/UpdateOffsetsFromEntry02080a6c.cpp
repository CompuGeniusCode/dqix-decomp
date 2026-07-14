#include <globaldefs.h>

struct List0207f0ac;
struct List0207f6ac;
void* FindEntryByShortId0207f0ac(struct List0207f0ac* list, int id);
void* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);

struct FoundEntry02080a6c {
    short* arr;
    char pad1[0xa - 4];
    short fieldA;
    short fieldC;
    char pad2[0x13 - 0xe];
    unsigned char count;
};

struct Result2_02080a6c {
    char pad[6];
    short f6;
    short f8;
    short fa;
    short fc;
};

// USA: func_02080a6c
ARM void UpdateOffsetsFromEntry02080a6c(void* param0, int id, short param2, short* param3, short* param4, short* param5, short* param6) {
    struct FoundEntry02080a6c* result = (struct FoundEntry02080a6c*)FindEntryByShortId0207f0ac((struct List0207f0ac*)((char*)param0 + 0xc), id);
    if (!result) {
        return;
    }
    *param3 = (short)(result->fieldA << 3);
    *param4 = (short)(result->fieldC << 3);
    unsigned char i;
    for (i = 0; i < result->count; i++) {
        if (result->arr[i] == param2) {
            struct Result2_02080a6c* result2 = (struct Result2_02080a6c*)FindEntryByShortId0207f6ac((struct List0207f6ac*)((char*)param0 + 4), param2);
            if (!result2) {
                return;
            }
            *param3 = *param3 + result2->f6;
            *param4 = *param4 + result2->f8;
            *param5 = result2->fa;
            *param6 = result2->fc;
            return;
        }
    }
}
