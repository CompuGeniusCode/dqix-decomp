#include <globaldefs.h>
#include "std_library_functions.h"

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};
extern int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct Struct02030b7c;
extern void* GetField4IfField0Zero(struct Struct02030b7c* s);

struct Name0201e3c4 { char c[9]; };
struct Code0201e3c4 { char c[5]; };
struct Elem0201e3c4 {
    unsigned short id;
    struct Name0201e3c4 name;
    struct Code0201e3c4 code;
};
struct List0201e3c4;
extern void AppendRecordCapped0201e3c4(struct List0201e3c4* list, struct Elem0201e3c4* src);

struct GlobalList020fdc20_0201c8d0 {
    int pad0;
    void* pad4;
    struct List0201e3c4* list;
};
extern struct GlobalList020fdc20_0201c8d0 data_020fdc20;

// USA: func_0201c8d0
ARM int BuildAndAppendRecord0201c8d0(unsigned char* src) {
    struct Elem0201e3c4 elem;
    elem.id = GetIntFromVariant02030b0c((struct Variant02030b0c*)src);
    struct Struct02030b7c* strFieldPtr = (struct Struct02030b7c*)(src + 8);
    src += 0x10;
    char* namePtr = (char*)GetField4IfField0Zero(strFieldPtr);
    strcpy(elem.code.c, namePtr);
    int i;
    for (i = 0; i < 9; i++) {
        elem.name.c[i] = (char)GetIntFromVariant02030b0c((struct Variant02030b0c*)src);
        src += 8;
    }
    AppendRecordCapped0201e3c4(data_020fdc20.list, &elem);
    return 1;
}
