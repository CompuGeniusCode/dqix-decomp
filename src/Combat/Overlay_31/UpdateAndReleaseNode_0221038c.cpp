#include <globaldefs.h>

struct RefNode020c80f8;
void ReleaseNodeRef020c80f8(RefNode020c80f8* node);

extern "C" void* func_020c8074(void* a, int b);

struct Struct0224e588 {
    char pad[4];
    int field4;
};

extern Struct0224e588* data_ov031_0224e588;

// USA: func_ov031_0221038c
ARM void UpdateAndReleaseNode_0221038c(int arg) {
    Struct0224e588* p = data_ov031_0224e588;
    if (p == NULL) return;
    func_020c8074((char*)p + 8, p->field4);
    p = data_ov031_0224e588;
    if (p->field4 != 2) {
        p->field4 = arg;
    }
    ReleaseNodeRef020c80f8((RefNode020c80f8*)((char*)data_ov031_0224e588 + 8));
}
