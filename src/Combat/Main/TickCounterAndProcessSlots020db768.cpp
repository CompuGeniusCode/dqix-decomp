#include <globaldefs.h>

struct Entity020db3a8;
extern int CheckActiveState020db3a8(Entity020db3a8* s);
extern int IsFlagBit0x2At0x24020de13c(unsigned char* obj);
extern int IsFlagBit0x4At0x24020de148(unsigned char* obj);
extern "C" void func_020ddea0(void* elem, unsigned short field6e, unsigned char idx, void* p, unsigned char field3c, int val);

struct Entity020db768 {
    unsigned char pad1[0x3c];
    unsigned char field3c;
    unsigned char pad2[0x6e - 0x3c - 1];
    unsigned short field6e;
    unsigned char arr[3][0x28];
};

// USA: func_020db768
ARM void TickCounterAndProcessSlots020db768(Entity020db768* s, void* other) {
    s->field6e = (s->field6e + 1) % 0xbe;
    for (int i = 0; i < 3; i++) {
        unsigned char* elem = s->arr[i];
        void* p = other;
        if (IsFlagBit0x2At0x24020de13c(elem)) {
            p = (char*)other + 4;
        } else if (IsFlagBit0x4At0x24020de148(elem)) {
            p = (char*)other + 8;
        }
        int val = 0xf;
        if (CheckActiveState020db3a8((Entity020db3a8*)s)) val = 0xe;
        func_020ddea0(elem, s->field6e, (unsigned char)(i * 4 + 4), p, s->field3c, val);
    }
}
