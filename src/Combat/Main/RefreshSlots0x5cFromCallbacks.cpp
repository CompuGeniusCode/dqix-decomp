#include <globaldefs.h>

typedef int (*FnPtr020db964)(void);
extern FnPtr020db964 data_020f28fc[];

struct Obj020db964 { char pad[0x5c]; int slots[2]; };

// USA: func_020db964
ARM void RefreshSlots0x5cFromCallbacks(struct Obj020db964* obj) {
    int i;
    for (i = 0; i < 2; i++) {
        int result = data_020f28fc[i]();
        if (result != 0x10) {
            if (result != obj->slots[i]) {
                obj->slots[i] = result;
            }
        }
    }
}
