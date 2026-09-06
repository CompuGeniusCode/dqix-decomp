#include <globaldefs.h>

struct LookupEntry020dee58 {
    short key;
    short val;
};

extern struct LookupEntry020dee58 data_020ee798[];
extern struct LookupEntry020dee58 data_020ee7c8[];

struct Obj020dee58 {
    unsigned char pad[8];
    unsigned int lowNibble : 4;
    unsigned int midField : 5;
    unsigned int rest : 23;
};

// USA: func_020dee58
ARM short LookupValueFromField8(struct Obj020dee58* obj) {
    struct LookupEntry020dee58* entry;
    short key;
    if (obj == NULL) {
        return 0x13;
    }
    key = obj->midField;
    entry = data_020ee7c8;
    if (obj->lowNibble != 0) {
        key = obj->lowNibble;
        entry = data_020ee798;
    }
    while (entry->key >= 0) {
        if (entry->key == key) {
            return entry->val;
        }
        entry++;
    }
    return 0x13;
}
