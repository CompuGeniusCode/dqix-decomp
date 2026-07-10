#include <globaldefs.h>

struct NarcHeader020afb58 {
    unsigned int magic;      // 0x0
    unsigned short bom;      // 0x4
    unsigned short version;  // 0x6
};

// USA: func_020afb58
ARM int IsValidNarcHeader(struct NarcHeader020afb58* h) {
    if (h->magic != 0x4352414e) return 0;
    if (h->bom != 0xfffe) return 0;
    return h->version == 0x100;
}
