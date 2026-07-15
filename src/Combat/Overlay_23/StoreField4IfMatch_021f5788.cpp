#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);
struct Struct0200fb08;
unsigned char NormalizeField5_0200fb08(struct Struct0200fb08* obj);
struct Struct02030b7c;
void* GetField4IfField0Zero(struct Struct02030b7c* s);

struct Global021fff08 { char pad[0x10]; void* field10; };
extern struct Global021fff08 data_ov023_021fff08;

// USA: func_ov023_021f5788
ARM int StoreField4IfMatch_021f5788(void* obj) {
    int a = GetIntFromVariant02030b0c((struct Variant02030b0c*)obj);
    int b = NormalizeField5_0200fb08((struct Struct0200fb08*)GetBattleStruct());
    if (a == b) {
        data_ov023_021fff08.field10 = GetField4IfField0Zero((struct Struct02030b7c*)((char*)obj + 0x8));
    }
    return 1;
}
