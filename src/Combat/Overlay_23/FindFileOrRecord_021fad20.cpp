#include <globaldefs.h>
#include "Filesystem/FileIO.h"

struct Rec020467f0 {
    char tag;
    char pad1[0x3f];
    int size40;
    int field44;
    int size48;
};

int FindMatchingRecords0204684c(struct Rec020467f0* table, const char* name, void** outData, int maxCount, int* outField44, void** outRec);

// USA: func_ov023_021fad20
ARM int FindFileOrRecord_021fad20(const void* narcBuffer, const char* name, const void** outData, unsigned int* outSize) {
    if (FindFilesInNarcBySubstring(narcBuffer, name, outData, outSize, 1) != 0) {
        return 1;
    }
    return FindMatchingRecords0204684c((struct Rec020467f0*)narcBuffer, name, (void**)outData, 1, (int*)outSize, NULL) != 0;
}
