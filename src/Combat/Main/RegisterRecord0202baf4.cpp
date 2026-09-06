#include <globaldefs.h>

struct Record0202ba08;
ARM struct Record0202ba08* CopyRecord0202ba08(struct Record0202ba08* dst, struct Record0202ba08* src);

struct Bytes6_0202baf4 { unsigned char v[6]; };
struct Bytes32_0202baf4 { char v[0x20]; };
struct Words32_0202baf4 { unsigned int v[0x20]; };

struct Record0202baf4 {
    unsigned short h0;
    unsigned short h2;
    struct Bytes6_0202baf4 b4;
    unsigned short ha;
    struct Bytes32_0202baf4 bc;
    unsigned short h2c;
    unsigned short h2e;
    unsigned short h30;
    unsigned short h32;
    unsigned short h34;
    unsigned short h36;
    unsigned short h38;
    unsigned short h3a;
    unsigned short h3c;
    unsigned short h3e;
    struct Words32_0202baf4 w40;
};

struct Container0202baf4 {
    char pad0[0xc];
    int count;
    struct Record0202baf4 records[10];
    int timers[10];
};

extern struct Record0202baf4 data_020feffc[];

// USA: func_0202baf4
ARM void RegisterRecord0202baf4(struct Container0202baf4* obj, struct Record0202baf4* item) {
    signed char flag50 = *(signed char*)((char*)item + 0x50);
    if (flag50 == 0) {
        return;
    }
    unsigned char flag4a = *(unsigned char*)((char*)item + 0x4a);
    if (flag4a == 0) {
        return;
    }

    int count = obj->count;
    if (count > 0) {
        int i;
        for (i = 0; i < count; i++) {
            struct Record0202baf4* cand = (struct Record0202baf4*)((char*)data_020feffc + i * 0xc0);
            int match = cand->b4.v[0] == item->b4.v[0] && cand->b4.v[1] == item->b4.v[1] &&
                        cand->b4.v[2] == item->b4.v[2] && cand->b4.v[3] == item->b4.v[3] &&
                        cand->b4.v[4] == item->b4.v[4] && cand->b4.v[5] == item->b4.v[5];
            if (match) {
                break;
            }
        }
        if (i != count) {
            CopyRecord0202ba08((struct Record0202ba08*)&obj->records[i], (struct Record0202ba08*)item);
            obj->timers[i] = 0xfa0;
            return;
        }
    }

    if (count >= 0xa) {
        return;
    }
    CopyRecord0202ba08((struct Record0202ba08*)&obj->records[count], (struct Record0202ba08*)item);
    obj->timers[obj->count] = 0xfa0;
    obj->count = obj->count + 1;
}
