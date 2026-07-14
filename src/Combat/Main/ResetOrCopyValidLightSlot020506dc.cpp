#include <globaldefs.h>

struct LightSlots020506dc {
    float vec[4][3];
    unsigned char gap1[0x24];
    int timer1[4];
    unsigned char gap2[0xC];
    int timer2[4];
    unsigned char gap3[0xC];
    unsigned short s0[4];
    unsigned char gap4[6];
    unsigned short s1[4];
    unsigned char gap5[6];
    unsigned short s2[4];
    unsigned char gap6[6];
    unsigned short s3[4];
    unsigned char gap7[6];
    unsigned short s4[4];
    unsigned char gap8[6];
    unsigned short s5[4];
    unsigned char gap9[6];
    unsigned char active[4];
};

// USA: func_020506dc
ARM void ResetOrCopyValidLightSlot020506dc(struct LightSlots020506dc* s) {
    int cur;
    for (cur = 0; cur < 4; cur++) {
        int idx;
        int tries;
        if (s->active[cur] == 1) continue;
        idx = cur;
        for (tries = 0; tries < 3; tries++) {
            idx--;
            if (idx < 0) idx = 3;
            if (s->active[idx] == 1) break;
            if (tries == 3) {
                int j;
                for (j = 0; j < 4; j++) {
                    s->vec[j][0] = 1.0f;
                    s->vec[j][1] = 1.0f;
                    s->vec[j][2] = 1.0f;
                    s->timer1[j] = 0;
                    s->timer2[j] = 0;
                    s->s0[j] = 0;
                    s->s1[j] = 0;
                    s->s2[j] = 0x7fff;
                    s->s3[j] = 0x7fff;
                    s->s4[j] = 0x7fff;
                    s->s5[j] = 0x1086;
                }
                return;
            }
        }
        s->vec[cur][0] = s->vec[idx][0];
        s->vec[cur][1] = s->vec[idx][1];
        s->vec[cur][2] = s->vec[idx][2];
        s->timer1[cur] = s->timer1[idx];
        s->timer2[cur] = s->timer2[idx];
        s->s0[cur] = s->s0[idx];
        s->s1[cur] = s->s1[idx];
        s->s2[cur] = s->s2[idx];
        s->s3[cur] = s->s3[idx];
        s->s4[cur] = s->s4[idx];
        s->s5[cur] = s->s5[idx];
    }
}
