#include <globaldefs.h>

int CheckField0x14FiveFlagsClear02088e04(unsigned char* obj);

// USA: func_02088dd8
ARM int IsValidAndFlag0x1000Clear02088dd8(unsigned char* obj) {
    if (CheckField0x14FiveFlagsClear02088e04(obj) == 0) {
        return 0;
    }
    return (*(int*)(obj + 0x18) & 0x1000) == 0;
}
