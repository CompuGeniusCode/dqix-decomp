#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"
#include "Filesystem/FileIO.h"

struct List0202fe68;
struct List0202fec8;
struct InitStruct;
extern "C" ARM void func_020280b0(struct InitStruct* s);
struct Struct0202811c;
extern "C" void func_02028104(struct Struct0202811c* s, int b, int c, int d);
extern "C" void func_02028214(void* a, int b);

extern char data_ov017_021d7b4f;
extern char strDataPrmEncmonsBin;

struct Obj021b498c {
    char pad0[8];
    void* sub;
    int key;
    unsigned char field10;
    char pad1[3];
    int field14;
};

// Runs the encmons script once its background load reports success. data/prm/encmons.bin is a NARC;
// the member whose name contains "bin" goes to func_02028048 along with the freshly initialized
// structure at sub+0x18, which it publishes in the global opcode handler pair at data_020fdd30, so
// the script presumably fills it -- func_0202811c reads it back -- and sub[0xc] then
// marks it ready. encmons sits with encfld.bin, encbtl.bin and enchab.gp2 in data/prm, so it is
// presumably the encounter monster table. On the way out it removes the task and re-queues the same
// file, leaving state 3; why it reloads is not established.
extern "C" ARM void RunEncmonsScriptWhenLoaded(struct Obj021b498c* obj) {
    GetBattleStruct();
    int list = (int)BackgroundLoader::GetInstance();
    if (!((BackgroundLoader*)(list))->GetTaskStatus((int)(obj->key))) {
        return;
    }

    if (((BackgroundLoader*)((struct List0202fe68*)list))->GetDetailedTaskStatus((int)(obj->key)) == 2) {
        int out2, out1;
        ((BackgroundLoader*)((struct List0202fec8*)list))->GetLoadedFileByID((int)(obj->key), (void**)(&out1), (unsigned int*)(&out2));
        if (out1 != 0) {
            unsigned int fileSize;
            const void* filePtr;
            FindFilesInNarcBySubstring((const void*)out1, &data_ov017_021d7b4f, &filePtr, &fileSize, 1);
            if (filePtr != 0) {
                char* sub = (char*)obj->sub;
                func_020280b0((struct InitStruct*)(sub + 0x18));
                func_02028104((struct Struct0202811c*)(sub + 0x18), *(int*)((char*)obj->sub + 0x10), (int)filePtr, (int)fileSize);
                func_02028214(sub + 0x18, *(int*)((char*)obj->sub + 0x10));
                sub[0xc] = 1;
            }
        }
    }

    ((BackgroundLoader*)(list))->RemoveTask((int)(obj->key));
    obj->key = -1;
    obj->key = ((BackgroundLoader*)(list))->QueueLoadFile((const char*)((int)&strDataPrmEncmonsBin), (SafeAllocator*)(0));
    obj->field10 = 3;
}
