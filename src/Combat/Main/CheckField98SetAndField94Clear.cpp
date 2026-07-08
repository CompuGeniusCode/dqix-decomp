#include <globaldefs.h>

struct FlagStruct {
    char unk0[0x94];
    int f94;
    int f98;
};

// USA: func_02037a64
ARM int CheckField98SetAndField94Clear(struct FlagStruct* obj) {
    if (obj->f98 != 0) {
        if (obj->f94 == 0) {
            return 1;
        }
    }
    return 0;
}
