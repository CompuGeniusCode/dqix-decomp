#include <globaldefs.h>

struct Container020e0310;
extern int GetData02104304Field4();
extern int GetFieldByKey020e0434(struct Container020e0310* c, int key);
extern int CallFunc0202fa38Mode2(int a, int b, int c, int d);
extern "C" int func_0202fdd0(int a, int b);

// USA: func_ov009_02184d70
ARM void UpdateCombatantState_02184d70(void* objRaw) {
    char* obj = (char*)objRaw;
    if (!(*(int*)(obj + 0xd9c) & 0x80)) {
        return;
    }
    if (*(unsigned char*)(obj + 0xd94) == 2) {
        return;
    }

    int r = GetData02104304Field4();
    unsigned char state = *(unsigned char*)(obj + 0xd94);
    char* p = obj + 0xc00;
    int id = *(signed char*)(p + 0x58);

    if (state == 0) {
        short val = (short)id;
        int c2 = (id == 2);
        int c3 = (id == 5);
        int c1 = (id == 3);
        if ((c2 | c3) | c1) {
            unsigned char b = *(unsigned char*)(obj + 0xda3);
            val = (short)(b * 100 + val);
        }
        short a = (short)(val + 0x32);
        int h1 = GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xe0), a);
        int h2 = GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xe0), val);
        *(int*)(obj + 0xd90) = CallFunc0202fa38Mode2(r, h2, h1, 0);
        *(unsigned char*)(obj + 0xd94) = 1;
    } else {
        if (state != 1) {
            return;
        }
        int x = func_0202fdd0(r, *(int*)(obj + 0xd90));
        if (x != 0) {
            *(unsigned char*)(obj + 0xd94) = 2;
        }
    }
}
