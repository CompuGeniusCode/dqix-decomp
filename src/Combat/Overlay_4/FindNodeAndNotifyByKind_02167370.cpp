#include <globaldefs.h>

extern "C" int func_ov004_021666bc(void* a1, int* out);
extern char* data_ov004_0217101c;
extern "C" void func_ov011_021848a0(void* obj, int val);

struct ValField02167370 {
    unsigned short sel : 2;
    unsigned short bit2 : 1;
    unsigned short bit3 : 1;
    unsigned short restBits : 12;
};

// USA: func_ov004_02167370
ARM int FindNodeAndNotifyByKind_02167370(void* a1) {
    int local;
    int key = func_ov004_021666bc(a1, &local);

    void* node = *(void**)(data_ov004_0217101c + 8);
    while (node != NULL) {
        if (*(short*)((char*)node + 0) == key) break;
        node = *(void**)((char*)node + 8);
    }

    if (node == NULL) goto end;

    {
        struct ValField02167370* vf = (struct ValField02167370*)((char*)node + 2);
        int msg = 0;
        switch (vf->sel) {
        case 0:
        case 1:
            msg = 0x6a;
            break;
        case 2:
            msg = (vf->bit3 == 1) ? 0x68 : 0x67;
            break;
        case 3:
            msg = 0x69;
            break;
        }

        if (msg != 0) {
            func_ov011_021848a0(a1, msg);
        }
    }
end:
    return 0;
}
