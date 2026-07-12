#include <globaldefs.h>

extern "C" int func_ov017_021d4df8(void*, int);
extern "C" void func_ov017_021d4ce4(void*, int);
extern "C" void func_ov017_021d4ccc(void*);

struct TaskState0209fe18 {
    char unk_00[0x4c];
    int flag_0x4c;
    char unk_50[0x14];
    int ticket_0x64;
    int lastTicket_0x68;
};

// USA: func_0209fe18
ARM void PollOv017Task0209fe18(TaskState0209fe18* obj) {
    if (obj->ticket_0x64 >= 0) {
        if (func_ov017_021d4df8((char*)obj + 0x10, obj->ticket_0x64) == 0) {
            obj->ticket_0x64 = -1;
            return;
        }
        func_ov017_021d4ce4((char*)obj + 0x10, obj->ticket_0x64);
        obj->lastTicket_0x68 = obj->ticket_0x64;
        obj->ticket_0x64 = -1;
    } else {
        if (obj->lastTicket_0x68 < 0) return;
        func_ov017_021d4ccc((char*)obj + 0x10);
        if (obj->flag_0x4c != 0) {
            obj->lastTicket_0x68 = -1;
        }
    }
}
