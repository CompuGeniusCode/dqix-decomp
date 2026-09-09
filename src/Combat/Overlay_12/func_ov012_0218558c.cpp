#include <globaldefs.h>

struct Owner0218558c {
    int field0;
    int field4;
    char* base;
};

struct Table0218558c {
    char* entries[7];
    unsigned char field1c;
    unsigned char field1d;
    unsigned char count;
};

// USA: func_ov012_0218558c
extern "C" ARM int func_ov012_0218558c(struct Owner0218558c* owner, struct Table0218558c* table) {
    int i = 0;
    while (i < table->count) {
        int missing = 1;
        int offset = (int)(table->entries[i] - (char*)0);
        char* value;
        if (offset != -1 && owner->base != 0) {
            missing = 0;
        }
        if (missing) {
            value = 0;
        } else {
            value = owner->base + offset;
        }
        table->entries[i] = value;
        i++;
    }
    return 1;
}
