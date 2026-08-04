#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Variant02030b0c;
int GetIntFromVariant02030b0c(Variant02030b0c*);

struct Entry02108ff4 {
    unsigned short a;
    unsigned char b;
    unsigned char c;
};
extern Entry02108ff4 data_02108ff4[];

// USA: func_0208e2c0  (semantic: StoreVariantTriple0208e2c0)
extern "C" ARM int func_0208e2c0(char* v) {
    unsigned char* battleField = (unsigned char*)GetBattleStruct();
    Entry02108ff4* table = data_02108ff4;
    int idRaw = GetIntFromVariant02030b0c((Variant02030b0c*)v);
    v += 8;
    unsigned char id = (unsigned char)idRaw;
    battleField = battleField + 0x5000;
    for (int i = 0; i < 8; i++) {
        unsigned short aVal = (unsigned short)GetIntFromVariant02030b0c((Variant02030b0c*)v);
        unsigned char bVal = (unsigned char)GetIntFromVariant02030b0c((Variant02030b0c*)(v + 8));
        char* arg3 = v + 0x10;
        v += 0x18;
        unsigned char cVal = (unsigned char)GetIntFromVariant02030b0c((Variant02030b0c*)arg3);
        if (i == battleField[0xcda]) {
            table[id].a = aVal;
            table[id].b = bVal;
            table[id].c = cVal;
            return 1;
        }
    }
    return 0;
}
