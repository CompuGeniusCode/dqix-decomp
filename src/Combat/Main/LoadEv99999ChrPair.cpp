#include <globaldefs.h>
#include "Filesystem/GPC.h"
#include "std_library_functions.h"

struct Pair020daa58 { int a; int b; };

extern "C" void RestoreVramAllocatorCursors(char* obj);
extern "C" void SaveVramAllocatorState(char* obj);
extern "C" int func_02057924(void);
extern "C" int func_02057e6c(int, int, int, int, int, int);
extern const char strEv99999NumChr;

// Pulls two ev99999<n>.chr members out of the archive handed in and installs each through
// func_02057e6c under 0x14 and 0x15. The naming and the N / N+10 pairing match the ev99999NNNN.chr
// set in data/effect, but the four suffixes the only caller func_020da8e0 asks for -- 3100 and 3110
// in one branch, 3200 and 3210 in the other -- are not files there, so they come from the archive
// itself. The destination's pair tables are restored before each install and backed up again
// afterwards, and a missing member is skipped.
extern "C" ARM int LoadEv99999ChrPair(Pair020daa58* obj, GPCFile* gpc, int val1, int val2) {
    int x = func_02057924();
    int fd;
    int a = obj->a;
    int b = obj->b;
    if (!x || !a || !b) return 0;

    unsigned int fileSize = 0;
    void* fileData = NULL;
    char name[32];
    sprintf(name, &strEv99999NumChr, val1);
    if (GetUnknownGP2InnerFileDataByName(&fileData, &fileSize, gpc, name)) {
        fd = (int)fileData;
        RestoreVramAllocatorCursors((char*)b);
        func_02057e6c(x, 0x14, a, fd, fileSize, b);
        SaveVramAllocatorState((char*)b);
    }
    sprintf(name, &strEv99999NumChr, val2);
    if (GetUnknownGP2InnerFileDataByName(&fileData, &fileSize, gpc, name)) {
        fd = (int)fileData;
        RestoreVramAllocatorCursors((char*)b);
        func_02057e6c(x, 0x15, a, fd, fileSize, b);
        SaveVramAllocatorState((char*)b);
    }
    return 1;
}
