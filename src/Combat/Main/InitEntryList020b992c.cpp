#include <globaldefs.h>

extern int data_020f1c70;

struct EntryList020b992c {
    char pad0[8];
    int field8;
    int fieldc;
    char pad10[9];
    unsigned char count;
    unsigned short entries[1];
};

struct EntrySource020b992c {
    char pad0[0x17];
    unsigned char count;
};

// USA: func_020b992c
ARM void InitEntryList020b992c(struct EntryList020b992c* list, int a1, struct EntrySource020b992c* source) {
    unsigned int i;
    list->fieldc = data_020f1c70;
    list->count = source->count;
    list->field8 = a1;
    i = 0;
    if (i < list->count) {
        do {
            list->entries[i] = i | 0x100;
            i++;
        } while (i < list->count);
    }
}
