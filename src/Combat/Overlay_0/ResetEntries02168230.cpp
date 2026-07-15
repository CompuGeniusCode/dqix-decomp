#include <globaldefs.h>

struct Entry02168268 { signed char a; unsigned char b; short c; short d; };
void ResetEntry02168268(struct Entry02168268* obj);

// USA: func_ov000_02168230
ARM void ResetEntries02168230(char* p) {
    int i;
    p[0x77ee] = 0;
    for (i = 0; i < 4; i++) {
        ResetEntry02168268((struct Entry02168268*)(p + 0x77d6 + i * 6));
    }
}
