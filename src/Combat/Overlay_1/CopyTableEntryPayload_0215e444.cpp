#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov017_021d60f4(void*);

struct Data8c_e444 { char pad0[0x8c]; unsigned char field8c; char pad1[0x9c - 0x8c - 1]; unsigned char field9c; };
extern Data8c_e444 data_ov001_021658b8;

struct Table_02153884;
void* FindTableEntry_02153884(struct Table_02153884* t, int key);
extern struct Table_02153884 data_ov001_021658d8;

struct Entry_02153884 { int key; int val; };

extern unsigned char data_ov001_02165944[0x11];

// USA: func_ov001_0215e444
ARM int CopyTableEntryPayload_0215e444(void* self) {
    data_ov001_021658b8.field8c = 0;
    int key = func_ov017_021d60f4(self);
    if (key < 0) return 1;
    struct Entry_02153884* entry = (struct Entry_02153884*)FindTableEntry_02153884(&data_ov001_021658d8, key);
    if (entry == NULL) return 0;
    if (entry->val == 0) return 0;
    memcpy(data_ov001_02165944, (void*)entry->val, 0x11);
    data_ov001_021658b8.field9c = 0;
    return 1;
}
