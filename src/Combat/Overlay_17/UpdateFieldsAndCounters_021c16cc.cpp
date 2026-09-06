#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Overlay_17/Struct44C8.h"

int CheckField0x14Or0x20Positive(int* obj);
void SetBothCounters(void* obj, int value, int frames);
extern "C" void func_ov017_021a2fa0(void* ov);

struct Obj021c16cc {
    unsigned char pad0[0x1];
    unsigned char field1;
    unsigned char pad1[0x6];
    signed char field8;
    unsigned char field9;
};

// USA: func_ov017_021c16cc  (semantic: UpdateFieldsAndCounters_021c16cc)
extern "C" ARM void func_ov017_021c16cc(Obj021c16cc* self) {
    Struct_ov017_44C8* ov = func_ov017_0218b5b0();
    int data = (int)BackgroundLoader::GetInstance();
    signed char state = self->field8;
    if (state == 0) {
        SetBothCounters(ov, -0x10, 0xf);
        self->field8 = self->field8 + 1;
        return;
    }
    if (state != 1) {
        return;
    }
    if (CheckField0x14Or0x20Positive((int*)ov) != 0) {
        return;
    }
    if (((BackgroundLoader*)((void*)data))->GetNumQueuedTasks() > 0) {
        return;
    }
    func_ov017_021a2fa0(ov);
    void* p = *(void**)((char*)ov + 0x3000 + 0x734);
    if (((unsigned char*)p)[2] == 0) {
        SetBothCounters(ov, 0, 0xf);
    }
    if (self->field9 != 0) {
        SetBothCounters(ov, -0x10, 0);
    }
    self->field1 = 1;
}
