#include <globaldefs.h>

extern void* data_ov031_0224e53c;
extern "C" void func_ov031_0220da1c(int);
extern "C" void func_ov031_0220db6c(void);
extern "C" void func_ov031_0220d984(short, int, int, int);
extern "C" void func_ov031_0220f394(int);
void CallCallback28_0220ef9c(char*);
void InvalidateDataCacheRange(const void* addr, unsigned int size);

struct EventStruct0220e584 {
    unsigned char pad0[2];
    unsigned short field2;
    unsigned short field4;
    unsigned char pad6[2];
    void* field8;
};

// USA: func_ov031_0220e584
ARM void Dispatch_0220e584(EventStruct0220e584* obj) {
    unsigned short f2 = obj->field2;
    switch (f2) {
    case 0: {
        switch (obj->field4) {
        case 0xe: {
            int v = *(int*)((char*)data_ov031_0224e53c + 0x2260);
            if (v == 0xc) {
                func_ov031_0220da1c(8);
                func_ov031_0220db6c();
                return;
            }
            func_ov031_0220da1c(9);
            func_ov031_0220d984(0, (int)((char*)data_ov031_0224e53c + 0x2140), 0, 0x872);
            return;
        }
        case 0xf: {
            unsigned short v = *(unsigned short*)((char*)obj->field8 + 0xe);
            func_ov031_0220f394((v >> 8) & 0xff);
            InvalidateDataCacheRange(obj->field8, 0x620);
            CallCallback28_0220ef9c((char*)obj->field8);
            return;
        }
        default:
            func_ov031_0220da1c(0xb);
            func_ov031_0220d984(7, (int)((char*)data_ov031_0224e53c + 0x2140), obj->field4, 0x881);
            return;
        }
    }
    case 4:
    default:
        func_ov031_0220da1c(0xb);
        func_ov031_0220d984(7, (int)((char*)data_ov031_0224e53c + 0x2140), 0, 0x88c);
    }
}
