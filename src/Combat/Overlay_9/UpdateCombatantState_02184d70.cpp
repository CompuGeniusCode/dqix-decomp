#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Container020e0310;
extern int GetFieldByKey020e0434(struct Container020e0310* c, int key);

// USA: func_ov009_02184d70
ARM void UpdateCombatantState_02184d70(void* objRaw) {
    char* obj = (char*)objRaw;
    if (!(*(int*)(obj + 0xd9c) & 0x80)) {
        return;
    }
    if (*(unsigned char*)(obj + 0xd94) == 2) {
        return;
    }

    int r = (int)BackgroundLoader::GetInstance();
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
        *(int*)(obj + 0xd90) = ((BackgroundLoader*)(r))->QueueLoadFileInGP2((const char*)(h2), (const char*)(h1), (SafeAllocator*)(0));
        *(unsigned char*)(obj + 0xd94) = 1;
    } else {
        if (state != 1) {
            return;
        }
        int x = ((BackgroundLoader*)(r))->GetTaskStatus((int)(*(int*)(obj + 0xd90)));
        if (x != 0) {
            *(unsigned char*)(obj + 0xd94) = 2;
        }
    }
}
