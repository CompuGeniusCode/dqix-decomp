#include <globaldefs.h>

struct QueueStruct0215917c { unsigned char pad[0x589]; unsigned char count; unsigned char list[6]; };

// USA: func_ov003_0215917c
ARM void AppendFlagEvents_0215917c(struct QueueStruct0215917c* obj, int flags) {
    obj->count = 0;
    if (flags & 1) obj->list[obj->count++] = 0;
    if (flags & 2) obj->list[obj->count++] = 1;
    if (flags & 4) obj->list[obj->count++] = 2;
    if (flags & 8) obj->list[obj->count++] = 3;
    if (flags & 0x10) obj->list[obj->count++] = 4;
    if (flags & 0x20) obj->list[obj->count++] = 5;
}
