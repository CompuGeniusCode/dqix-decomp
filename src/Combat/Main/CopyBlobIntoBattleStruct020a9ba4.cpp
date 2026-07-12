#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

struct Blob020a9ba4 {
    unsigned char first[0x200];
    unsigned char second[0x200];
    int trailer;
};

// USA: func_020a9ba4
ARM int CopyBlobIntoBattleStruct020a9ba4(void* src) {
    struct Blob020a9ba4 buf;
    struct BattleStruct* bs = GetBattleStruct();
    memcpy(&buf, src, sizeof(buf));
    memcpy((char*)bs + 0x6180, buf.second, 0x200);
    memcpy((char*)bs + 0x5f80, buf.first, 0x200);
    *(int*)((char*)bs + 0x5f7c) = buf.trailer;
    return 1;
}
