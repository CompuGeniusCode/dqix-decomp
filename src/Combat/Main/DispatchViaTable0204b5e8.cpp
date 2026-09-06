#include <globaldefs.h>

extern int (*data_020f01b8[][4])(int, int);

struct Obj0204b5e8 {
    char pad[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

// USA: func_0204b5e8
ARM int DispatchViaTable0204b5e8(struct Obj0204b5e8* obj, int a, int b) {
    return data_020f01b8[obj->lo][obj->hi](a, b);
}
