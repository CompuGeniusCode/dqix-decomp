#include <globaldefs.h>

struct Holder0209aa40;
int GetContainerCount0209aa40(struct Holder0209aa40* holder);

struct IntField0x4_0209a670;
int GetIntAt0x4(struct IntField0x4_0209a670* obj);

// USA: func_ov002_0215edc8
ARM int HasPositiveContainerAndField_0215edc8(unsigned char* obj) {
    if (GetContainerCount0209aa40((struct Holder0209aa40*)(obj + 0x44 + 0x2400)) <= 0) {
        goto ret0;
    }
    if (GetIntAt0x4((struct IntField0x4_0209a670*)(obj + 0x3c + 0x2400)) > 0) {
        return 1;
    }
ret0:
    return 0;
}
