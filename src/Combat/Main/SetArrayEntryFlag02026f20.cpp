#include <globaldefs.h>

extern char data_020fdccc;

// USA: func_02026f20
ARM void SetArrayEntryFlag02026f20(int a, int index) {
    (&data_020fdccc)[index << 5] = 1;
}
