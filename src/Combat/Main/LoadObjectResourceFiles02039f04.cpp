#include <globaldefs.h>
#include "Filesystem/FileIO.h"

extern "C" void func_02047b40(void* dest, const void* data, int flag);

struct TableEntry02039f04 {
    const char* name;
    void* ptr;
};

union Scratch02039f04 {
    unsigned int raw[20];
    struct TableEntry02039f04 entries[10];
};

extern const union Scratch02039f04 data_020e7844;

// USA: func_02039f04
ARM void LoadObjectResourceFiles02039f04(char* obj, int flag, const void* narc) {
    union Scratch02039f04 table;
    int i;

    table = data_020e7844;

    table.entries[0].ptr = obj + 0x000;
    table.entries[1].ptr = obj + 0x088;
    table.entries[2].ptr = obj + 0x110;
    table.entries[3].ptr = obj + 0x198;
    table.entries[4].ptr = obj + 0x220;
    table.entries[5].ptr = obj + 0x2a8;
    table.entries[6].ptr = obj + 0x330;
    table.entries[7].ptr = obj + 0x3b8;
    table.entries[8].ptr = obj + 0x440;
    table.entries[9].ptr = obj + 0x4c8;

    for (i = 0; i < 10; i++) {
        unsigned int fileSize = 0;
        const void* fileData = 0;
        void* ptr;
        GetFileInNarc(narc, table.entries[i].name, &fileData, &fileSize, 0);
        ptr = table.entries[i].ptr;
        func_02047b40(ptr, fileData, flag);
        *(int*)ptr = 0x3e;
    }
}
