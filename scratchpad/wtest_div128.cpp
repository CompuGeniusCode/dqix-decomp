#include <globaldefs.h>

extern "C" int probe(int x) {
    short v = (short)((x + 15) / 16);
    return v;
}
