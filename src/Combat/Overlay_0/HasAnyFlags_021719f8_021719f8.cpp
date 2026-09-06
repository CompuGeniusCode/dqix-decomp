#include <globaldefs.h>

// USA: func_ov000_021719f8
ARM int HasAnyFlags_021719f8_021719f8(int* obj) {
    int flags = obj[0xa];
    int a = (flags & 1) != 0;
    int acc = a != 0;
    acc = acc | ((flags & 0x10) != 0);
    acc = acc != 0;
    acc = acc | ((flags & 0x80000) != 0);
    acc = acc != 0;
    acc = acc | ((flags & 8) != 0);
    acc = acc != 0;
    return acc;
}
