#include <globaldefs.h>

struct Out0215fb54 { int x0; int x1; };
int FindRecordByKey0215fb54(int unused, short key, struct Out0215fb54* out);

// USA: func_ov000_0215fb9c
ARM int CheckKeyMatch_0215fb9c(int unused, short key) {
    struct Out0215fb54 out;
    int result = FindRecordByKey0215fb54(unused, key, &out);
    if (result > 0 || key == 0xf2 || key == 0x1da) {
        return 1;
    }
    return 0;
}
