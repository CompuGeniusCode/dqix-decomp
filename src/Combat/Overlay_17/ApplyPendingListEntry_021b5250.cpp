#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"

struct List0202fe68;
struct List0202fec8;
extern "C" void __clear(void* buf, int size);
struct HalfwordArray {
    unsigned short arr[12];
    unsigned short count;
};
ARM unsigned short CopyHalfwordArrayByCount(struct HalfwordArray* src, struct HalfwordArray* dst);
void* Clear12Bytes0206efc4(void* obj);
extern "C" void func_0206f230(void* a, int b, int c, int d, void* e, int f, int g, int h);

extern char data_ov017_021d7bc3;

struct Obj021b5250 {
    char pad0[8];
    void* sub;
    int key;
    unsigned char field10;
    char pad1[3];
    int field14;
};

// USA: func_ov017_021b5250  (semantic: ApplyPendingListEntry_021b5250)
extern "C" ARM void func_ov017_021b5250(struct Obj021b5250* obj) {
    GetBattleStruct();
    int list = (int)BackgroundLoader::GetInstance();
    if (!((BackgroundLoader*)(list))->GetTaskStatus((int)(obj->key))) {
        return;
    }

    if (((BackgroundLoader*)((struct List0202fe68*)list))->GetDetailedTaskStatus((int)(obj->key)) == 2) {
        int out2, out1;
        ((BackgroundLoader*)((struct List0202fec8*)list))->GetLoadedFileByID((int)(obj->key), (void**)(&out1), (unsigned int*)(&out2));
        if (out1 != 0) {
            char* sub = (char*)obj->sub;
            unsigned short buf[12];
            __clear(buf, 0x18);
            short signedCount = (short)CopyHalfwordArrayByCount((struct HalfwordArray*)(sub + 0x44), (struct HalfwordArray*)buf);
            sub = (char*)obj->sub;
            Clear12Bytes0206efc4(sub + 0x2f8);
            char* sub2 = (char*)obj->sub;
            func_0206f230(sub + 0x2f8, *(int*)(sub2 + 0x10), out1, out2, buf, signedCount, *(int*)(sub2 + 0x14), obj->field14);
        }
    }

    ((BackgroundLoader*)(list))->RemoveTask((int)(obj->key));
    obj->key = -1;
    obj->key = ((BackgroundLoader*)(list))->QueueLoadFile((const char*)((int)&data_ov017_021d7bc3), (SafeAllocator*)(0));
    obj->field10 = 7;
}
