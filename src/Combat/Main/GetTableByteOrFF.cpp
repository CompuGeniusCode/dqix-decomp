#include <globaldefs.h>

struct GetTableByteOrFFData { unsigned char pad[0xac]; unsigned char tbl[0xcc]; };

// USA: func_020965ac
ARM unsigned char GetTableByteOrFF(struct GetTableByteOrFFData *s, unsigned int idx) {
    if (idx < 0xcc) {
        return s->tbl[idx];
    }
    return 0xff;
}
