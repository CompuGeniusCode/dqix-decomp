#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry0218afbc { char str[5]; };
extern struct Entry0218afbc data_ov012_0218afbc[];
int FindEntryIndexByKey020424e4(int key, int tableIdx);

struct Obj021845f8 {
    char pad[0x18];
    char unk18[0xc];
    int field24;
    short field28;
    unsigned char field2a[15];
};

// USA: func_ov012_021845f8  (semantic: InitEntry_021845f8)
extern "C" ARM void func_ov012_021845f8(struct Obj021845f8* obj) {
    memset(obj->unk18, 0, 0xc);
    obj->field24 = 0;
    obj->field28 = 0;
    unsigned char* out = obj->field2a;
    int i;
    for (i = 0; i < 15; i++) {
        *out++ = (unsigned char)FindEntryIndexByKey020424e4((int)&data_ov012_0218afbc[i], 1);
    }
}
