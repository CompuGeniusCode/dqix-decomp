#include <globaldefs.h>

extern "C" int func_ov017_021d4df8(void*, int);
extern "C" void func_ov017_021d4ce4(void*, int);
extern "C" void func_ov017_021d4ccc(void*);

struct TaskState0209ff6c {
    char unk_00[0x48];
    int flag_0x48;
    char unk_4c[0x14];
    int ticket_0x60;
    int lastTicket_0x64;
};

// USA: func_0209ff6c
ARM void PollOv017Task0209ff6c(TaskState0209ff6c* obj) {
    if (obj->ticket_0x60 >= 0) {
        if (func_ov017_021d4df8((char*)obj + 0xc, obj->ticket_0x60) == 0) {
            obj->ticket_0x60 = -1;
            return;
        }
        func_ov017_021d4ce4((char*)obj + 0xc, obj->ticket_0x60);
        obj->lastTicket_0x64 = obj->ticket_0x60;
        obj->ticket_0x60 = -1;
    } else {
        if (obj->lastTicket_0x64 < 0) return;
        func_ov017_021d4ccc((char*)obj + 0xc);
        if (obj->flag_0x48 != 0) {
            obj->lastTicket_0x64 = -1;
        }
    }
}
