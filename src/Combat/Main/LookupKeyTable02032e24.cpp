#include <globaldefs.h>

struct KeyValue02032e24 {
    unsigned short value;
    unsigned short key;
};

// USA: func_02032e24
ARM unsigned short LookupKeyTable02032e24(unsigned short key, struct KeyValue02032e24* entries, int count) {
    count++;
    while (count-- != 0) {
        if (entries->key == key) return entries->value;
        entries++;
    }
    return 0x8140;
}
