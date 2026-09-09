#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct List0202fec8;
struct ActiveEntry02046900;
extern "C" int CountPacEntries(struct ActiveEntry02046900* entry);
struct Rec020467f0;
extern "C" void* func_020467f0(struct Rec020467f0* rec, int index, void** out, int* out44);

extern "C" void ResetWindowElement(void* obj);
extern "C" void func_ov013_02187a58(void* obj, void* buf);
extern "C" void func_0204b174(void* list, void* payload, int a3, int a4);

struct EntryList0204af14;
extern "C" void* func_0204af14(struct EntryList0204af14* list, unsigned int index);
struct Tilemap0204ae44;
extern "C" void func_0204ae44(struct Tilemap0204ae44* obj, int palette);
struct Obj0204b988;
extern "C" void func_0204b988(struct Obj0204b988* obj, unsigned int index, int a3, int a4, unsigned short a5);
struct List0204b0e8;
extern "C" void UploadTilemapToBGScreen(struct List0204b0e8* obj, void* buf);

extern int strDataAniBgSknPac;

struct LocalBuf021878b0 {
    char pad0[0x8];
    void* field8;
    char pad10[0xa8 - 0xc];
    unsigned short halfA8;
    unsigned short halfAA;
    char padAC[0xb4 - 0xac];
    unsigned short halfB4;
    unsigned short halfB6;
    char padB8[0xe0 - 0xb8];
};

// Two-phase background loader driven by the counter at self+0x66: phase 0 clears the ten tilemap slots
// and queues data/ani/bg_skn.pac, phase 1 takes record 0 out of the loaded archive and builds the
// tilemap with the palette from self+0x67. The 0x20 and 0x18 it writes look like a full 32x24 tile
// screen, but nothing here reads them back as width and height. bg_skn.pac is referenced by no other
// overlay, and this is the skill-up overlay, so the screen is its own. What "skn" abbreviates is not
// established; every other file here spells skill "skl".
extern "C" ARM void LoadSkillScreenBackground(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    int g = (int)BackgroundLoader::GetInstance();
    unsigned char flag = o[0x66];

    if (flag == 0) {
        for (int i = 0; i < 10; i++) {
            (*(short**)(o + 0x50))[i] = -1;
            (*(short**)(o + 0x54))[i] = -1;
            (*(unsigned char**)(o + 0x58))[i] = 2;
        }
        *(signed char*)(o + 0x6a) = -1;
        ((BackgroundLoader*)((void*)g))->MaybeFreeAllocations();
        *(int*)(o + 0x5c) = ((BackgroundLoader*)(g))->QueueLoadFile((const char*)((int)&strDataAniBgSknPac), (SafeAllocator*)(0));
        o[0x66]++;
    } else if (flag == 1) {
        if (((BackgroundLoader*)((void*)g))->GetTaskStatus((int)(*(int*)(o + 0x5c))) != 0) {
            void* recOut;
            int out1, out2;
            int field44;
            ((BackgroundLoader*)((struct List0202fec8*)g))->GetLoadedFileByID((int)(*(int*)(o + 0x5c)), (void**)(&out1), (unsigned int*)(&out2));
            CountPacEntries((struct ActiveEntry02046900*)out1);
            void* end = func_020467f0((struct Rec020467f0*)out1, 0, &recOut, &field44);
            if (end != 0) {
                LocalBuf021878b0 buf;
                ResetWindowElement(&buf);
                buf.field8 = (char*)end + 0x10;
                buf.halfB4 = 0xa;
                buf.halfB6 = 0xb;
                buf.halfA8 = 0x20;
                buf.halfAA = 0x18;
                func_ov013_02187a58(obj, &buf);
                func_0204b174(o + 0x28, end, 0, field44);
            }
            ((BackgroundLoader*)(g))->RemoveTask((int)(*(int*)(o + 0x5c)));
            *(int*)(o + 0x5c) = -1;
            void* e = func_0204af14((struct EntryList0204af14*)(o + 0x28), 0);
            if (e != 0) {
                func_0204ae44((struct Tilemap0204ae44*)e, *(signed char*)(o + 0x67));
            }
            func_0204b988((struct Obj0204b988*)(o + 0x28), 0, 0, 0, 0xffff);
            UploadTilemapToBGScreen((struct List0204b0e8*)(o + 0x28), 0);
            o[0x66] = 0;
            o[0x69] &= ~1;
        }
    }
}
