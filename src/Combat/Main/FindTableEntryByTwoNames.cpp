#include <globaldefs.h>

extern "C" void func_020d970c(void);
extern "C" void func_020d974c(void);
extern "C" int strcmp(const char*, const char*);

struct FormatObj0202f760;
extern int FormatPathWithTableEntry_0202f760(struct FormatObj0202f760*, char*);

struct SearchObj0202ffd8 {
    char pad0[0x124];
    int count;
};

struct Entry0202ffd8 {
    char pad0[0x18];
    char name2[0x30 - 0x18];
    short field30;
    signed char field32 : 4;
    unsigned char field33;
    char pad34[0x38 - 0x34];
    int field38;
    int field3c;
    char pad40[0x44 - 0x40];
};

// USA: func_0202ffd8
ARM int FindTableEntryByTwoNames(SearchObj0202ffd8* obj, char* name1, char* name2, int* out1, int* out2) {
    int result = -1;
    char buf[0x50];
    Entry0202ffd8* entry;
    int i;

    func_020d970c();
    *out1 = 0;
    *out2 = 0;
    entry = (Entry0202ffd8*)((char*)obj + 0x128);
    for (i = 0; i < obj->count; i++, entry = (Entry0202ffd8*)((char*)entry + 0x44)) {
        FormatPathWithTableEntry_0202f760((struct FormatObj0202f760*)entry, buf);
        if (strcmp(buf, name1) == 0 && strcmp(entry->name2, name2) == 0) {
            if (entry->field32 == 2) {
                *out1 = entry->field38;
                *out2 = entry->field3c;
            }
            result = entry->field30;
            break;
        }
    }
    func_020d974c();
    return result;
}
