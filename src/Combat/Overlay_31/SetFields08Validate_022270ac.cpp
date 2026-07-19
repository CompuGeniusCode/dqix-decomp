#include <globaldefs.h>

extern int data_ov031_02250c0c;

// USA: func_ov031_022270ac  (semantic: SetFields08Validate_022270ac)
extern "C" ARM int func_ov031_022270ac(int type, unsigned int flags) {
    *(unsigned char*)&data_ov031_02250c0c = (unsigned char)type;
    *(int*)((char*)&data_ov031_02250c0c + 0x8) = flags;

    if (type < 0 || type > 6) return 0;

    unsigned int nib = flags << 28;
    nib = nib >> 28;
    if (nib > 1) return 0;
    unsigned int rest = flags >> 4;
    if (rest & 2) return 0;
    if (type != 0) {
        if (rest & 1) return 0;
    }
    if (type == 0) {
        if (!(rest & 1)) return 0;
    }
    return 1;
}
