#include <globaldefs.h>

int DispatchNodeIfType7_02156e2c(void* a, int key);
void* GetEntryFor_021570a4(void* obj, int index);
void CallVTableFnAt240_021f66bc(void* a, int key, void* arg3);
int NotifyCountedEvents_02159384(void* self);

struct Struct021707d8_0215c494 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215c494 data_ov004_021707d8;

// USA: func_ov004_0215c494  (semantic: ResetCounterAndNotify_0215c494)
extern "C" ARM int func_ov004_0215c494(void* obj) {
    int key = DispatchNodeIfType7_02156e2c(obj, 0x5b);
    if (key < 0) {
        return 0;
    }
    void* entry = GetEntryFor_021570a4(obj, (unsigned char)key);
    if (!entry) {
        return 0;
    }
    unsigned char old = data_ov004_021707d8.ptr[0x11];
    data_ov004_021707d8.ptr[0x11] = 1;
    if (data_ov004_021707d8.ptr[0x11] < old) {
        CallVTableFnAt240_021f66bc(obj, 0x25c, (void*)1);
    }
    NotifyCountedEvents_02159384(obj);
    return 0;
}
