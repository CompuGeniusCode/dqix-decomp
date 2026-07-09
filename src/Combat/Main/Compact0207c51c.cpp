#include <globaldefs.h>

// USA: func_0207c51c
ARM int Compact0207c51c(unsigned char* base, int key) {
    int found;
    int i;
    short* p;
    signed char* q;
    int limit;
    int write;
    int j;

    found = -1;
    for (i = 0; i < 8; i++) {
        if (key == *(base + i + 0xc20)) {
            found = i;
            break;
        }
    }
    if (found == -1) return 0;

    p = *(short**)(base + found * 4 + 0xbd0);
    q = *(signed char**)(base + found * 4 + 0xbf0);
    limit = *(short*)(base + found * 2 + 0xc10);

    write = 0;
    for (j = 0; j < limit; j++) {
        if (write == j) {
            if (p[j] < 0) write = j;
            else write = write + 1;
        } else if (write != j && p[j] >= 0) {
            p[write] = p[j];
            q[write] = q[j];
            p[j] = -1;
            q[j] = 0;
            do {
                write++;
            } while (p[write] >= 0);
        }
    }
    return 1;
}
