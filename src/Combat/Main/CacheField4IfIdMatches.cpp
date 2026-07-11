#include <globaldefs.h>

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};
struct Struct02030b7c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);
void* GetField4IfField0Zero(struct Struct02030b7c* s);
extern "C" void* func_02012fe4(void);

struct Global020fdc4c_f950 {
    int pad0;
    void* field4;
};
extern struct Global020fdc4c_f950 data_020fdc4c;

// USA: func_0201f950
ARM int CacheField4IfIdMatches(struct Variant02030b0c* v) {
    int val;
    if (data_020fdc4c.field4 != 0) return 1;
    val = GetIntFromVariant02030b0c(v);
    if (val == *(unsigned short*)func_02012fe4()) {
        data_020fdc4c.field4 = GetField4IfField0Zero((struct Struct02030b7c*)(v + 1));
    }
    return 1;
}
