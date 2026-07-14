#include <globaldefs.h>
#include "std_library_functions.h"

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct Struct02030b7c;
void* GetField4IfField0Zero(struct Struct02030b7c* s);

struct TaggedValue02030b44;
float GetTaggedValueAsFloat(struct TaggedValue02030b44* v);

extern "C" int func_02030f30(int v);

extern int data_020ef2bc;
extern int data_020fdc14;

// USA: func_0201c5fc
ARM int InitFromVariantBlock0201c5fc(void* obj) {
    char* p = (char*)obj;

    if (data_020ef2bc != GetIntFromVariant02030b0c((struct Variant02030b0c*)(p + 0x0)))
        return 1;

    GetIntFromVariant02030b0c((struct Variant02030b0c*)(p + 0x8));
    GetField4IfField0Zero((struct Struct02030b7c*)(p + 0x10));
    GetIntFromVariant02030b0c((struct Variant02030b0c*)(p + 0x18));
    GetField4IfField0Zero((struct Struct02030b7c*)(p + 0x20));
    GetField4IfField0Zero((struct Struct02030b7c*)(p + 0x28));
    GetIntFromVariant02030b0c((struct Variant02030b0c*)(p + 0x30));
    GetField4IfField0Zero((struct Struct02030b7c*)(p + 0x38));
    GetIntFromVariant02030b0c((struct Variant02030b0c*)(p + 0x40));
    GetIntFromVariant02030b0c((struct Variant02030b0c*)(p + 0x48));
    GetIntFromVariant02030b0c((struct Variant02030b0c*)(p + 0x50));

    char* name = (char*)GetField4IfField0Zero((struct Struct02030b7c*)(p + 0x58));
    if (name != NULL) {
        strcpy(*(char**)((char*)&data_020fdc14 + 0x4), name);
    }

    GetIntFromVariant02030b0c((struct Variant02030b0c*)(p + 0x60));

    *(unsigned short*)(*(char**)((char*)&data_020fdc14 + 0x4) + 0x34) =
        (unsigned short)func_02030f30((int)(4096.0f * GetTaggedValueAsFloat((struct TaggedValue02030b44*)(p + 0x68))));

    *(int*)(*(char**)((char*)&data_020fdc14 + 0x4) + 0x38) =
        (int)(4096.0f * GetTaggedValueAsFloat((struct TaggedValue02030b44*)(p + 0x70)));

    *(int*)(*(char**)((char*)&data_020fdc14 + 0x4) + 0x3c) =
        (int)(4096.0f * GetTaggedValueAsFloat((struct TaggedValue02030b44*)(p + 0x78)));

    return 1;
}
