#include <globaldefs.h>

struct Struct021707d8_021570f0 { char pad[8]; char* ptr; };
extern Struct021707d8_021570f0 data_ov004_021707d8;

// USA: func_ov004_021570f0
ARM signed char GetFlagByte_021570f0(int idx) {
    if (idx < 0) return -1;
    char* ptr = data_ov004_021707d8.ptr;
    short count = *(short*)(ptr + 0x3a);
    if (idx >= count) return -1;
    return (signed char)(*(short*)(ptr + idx * 2 + 0x32));
}
