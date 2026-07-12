#include <globaldefs.h>

struct Struct0202f700;
void ClearFieldsAndSetLowNibble(struct Struct0202f700* s);

extern "C" void func_020d970c(void);
extern "C" void func_020c9be0(void);
extern "C" void func_020d974c(void);

struct Entry0202fd54 {
    char pad[0x30];
    short field30;
    signed char lowNibble : 4;
    signed char highNibble : 4;
};

// USA: func_0202fd54
ARM void AddEntryOrOverflow(unsigned char* obj) {
    func_020d970c();
    if (*(volatile int*)(obj + 0x124) > 0) {
        if (*(volatile int*)(obj + 0x124) >= 0x18) {
            func_020c9be0();
        } else {
            struct Entry0202fd54* entry = (struct Entry0202fd54*)(obj + 0x128 + *(volatile int*)(obj + 0x124) * 0x44);
            ClearFieldsAndSetLowNibble((struct Struct0202f700*)entry);
            entry->field30 = -1;
            entry->lowNibble = 5;
            *(volatile int*)(obj + 0x124) += 1;
            *(volatile int*)(obj + 0x78c) &= ~1;
        }
    }
    func_020d974c();
}
