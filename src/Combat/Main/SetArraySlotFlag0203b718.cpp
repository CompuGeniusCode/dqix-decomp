#include <globaldefs.h>
#include "std_library_functions.h"

extern char data_021065d8[];
extern char data_02105fd8[];

// USA: func_0203b718
ARM void SetArraySlotFlag0203b718(void* objPtr, int mode, int idx, int fillByte) {
    char* obj = (char*)objPtr;
    switch (mode) {
    case 0:
    case 1:
        switch (idx) {
        case 0:
            memset(data_021065d8, fillByte, 0x1000);
            break;
        case 1:
            memset(data_02105fd8, fillByte, 0x600);
            break;
        }
        break;
    }
    ((int*)(obj + 0x40))[idx + mode * 4] = 1;
}
