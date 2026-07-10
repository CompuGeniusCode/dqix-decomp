#include <globaldefs.h>

extern char data_02112160;

// USA: func_020d1940
ARM void ClearField4At02112160() {
    *(int*)(&data_02112160 + 4) = 0;
}
