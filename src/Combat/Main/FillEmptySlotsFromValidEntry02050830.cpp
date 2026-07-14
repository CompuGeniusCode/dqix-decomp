#include <globaldefs.h>

struct Entry02050830 {
    int state;
    int a;
    int b;
    int c;
    unsigned short d;
    int e;
    unsigned char arr[0x20];
};

// USA: func_02050830
ARM void FillEmptySlotsFromValidEntry02050830(struct Entry02050830* entries) {
    int cur;
    for (cur = 0; cur < 4; cur++) {
        int idx;
        int tries;
        if (entries[cur].state == 1) continue;
        idx = cur;
        for (tries = 0; tries < 3; tries++) {
            idx--;
            if (idx < 0) idx = 3;
            if (entries[idx].state == 1) break;
            if (tries == 3) {
                int j, i;
                for (j = 0; j < 4; j++)
                    for (i = 0; i < 0x20; i++)
                        entries[j].arr[i] = 0;
                return;
            }
        }
        entries[cur].a = entries[idx].a;
        entries[cur].b = entries[idx].b;
        entries[cur].c = entries[idx].c;
        entries[cur].d = entries[idx].d;
        entries[cur].e = entries[idx].e;
        {
            int i;
            for (i = 0; i < 0x20; i++) entries[cur].arr[i] = entries[idx].arr[i];
        }
    }
}
