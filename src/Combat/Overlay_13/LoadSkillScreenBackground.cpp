#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct BackgroundLoaderSelf;
struct PacArchive;
extern "C" int CountPacEntries(struct PacArchive* entry);
struct PacArchive;
extern "C" void* GetPacEntryByIndex(struct PacArchive* rec, int index, void** out, int* out44);

extern "C" void ResetWindowElement(void* self);
extern "C" void func_ov013_02187a58(void* self, void* buf);
extern "C" void func_0204b174(void* list, void* payload, int a3, int payloadLength);

struct TilemapList;
extern "C" void* func_0204af14(struct TilemapList* list, unsigned int index);
struct TilemapEntry;
extern "C" void func_0204ae44(struct TilemapEntry* self, int palette);
struct TilemapList;
extern "C" void func_0204b988(struct TilemapList* self, unsigned int index, int a3, int a4, unsigned short a5);
struct TilemapList;
extern "C" void UploadTilemapToBGScreen(struct TilemapList* self, void* buf);

extern int strDataAniBgSknPac;

struct WindowElement {
    char unknown0[0x8];
    void* buffer;
    char unknownC[0xa8 - 0xc];
    unsigned short halfA8;
    unsigned short halfAA;
    char unknownAC[0xb4 - 0xac];
    unsigned short halfB4;
    unsigned short halfB6;
    char unknownB8[0xe0 - 0xb8];
};

// Two-phase background loader driven by the counter at self+0x66: phase 0 clears the ten tilemap slots
// and queues data/ani/bg_skn.pac, phase 1 takes record 0 out of the loaded archive and builds the
// tilemap with the palette from self+0x67. The 0xe0-byte local is a window element, the struct
// ResetWindowElement clears, and its +0x8 is the buffer func_0204ffc0 memcpy's into -- here the pac
// payload past its own 0x10-byte header. The 0x20 and 0x18 it writes look like a full 32x24 tile
// screen, but nothing here reads them back as width and height, and the 0xa and 0xb at +0xb4 and
// +0xb6 only rewrite the defaults ResetWindowElement has already put there. bg_skn.pac is
// referenced by no other overlay, and this is the skill-up overlay, so the screen is its own. What
// "skn" abbreviates is not established; every other file here spells skill "skl".
extern "C" ARM void LoadSkillScreenBackground(void* self) {
    unsigned char* o = (unsigned char*)self;
    int g = (int)BackgroundLoader::GetInstance();
    unsigned char phase = o[0x66];

    if (phase == 0) {
        for (int slot = 0; slot < 10; slot++) {
            (*(short**)(o + 0x50))[slot] = -1;
            (*(short**)(o + 0x54))[slot] = -1;
            (*(unsigned char**)(o + 0x58))[slot] = 2;
        }
        *(signed char*)(o + 0x6a) = -1;
        ((BackgroundLoader*)((void*)g))->MaybeFreeAllocations();
        *(int*)(o + 0x5c) = ((BackgroundLoader*)(g))->QueueLoadFile((const char*)((int)&strDataAniBgSknPac), (SafeAllocator*)(0));
        o[0x66]++;
    } else if (phase == 1) {
        if (((BackgroundLoader*)((void*)g))->GetTaskStatus((int)(*(int*)(o + 0x5c))) != 0) {
            void* recOut;
            int out1, out2;
            int payloadLength;
            ((BackgroundLoader*)((struct BackgroundLoaderSelf*)g))->GetLoadedFileByID((int)(*(int*)(o + 0x5c)), (void**)(&out1), (unsigned int*)(&out2));
            CountPacEntries((struct PacArchive*)out1);
            void* end = GetPacEntryByIndex((struct PacArchive*)out1, 0, &recOut, &payloadLength);
            if (end != 0) {
                WindowElement buf;
                ResetWindowElement(&buf);
                buf.buffer = (char*)end + 0x10;
                buf.halfB4 = 0xa;
                buf.halfB6 = 0xb;
                buf.halfA8 = 0x20;
                buf.halfAA = 0x18;
                func_ov013_02187a58(self, &buf);
                func_0204b174(o + 0x28, end, 0, payloadLength);
            }
            ((BackgroundLoader*)(g))->RemoveTask((int)(*(int*)(o + 0x5c)));
            *(int*)(o + 0x5c) = -1;
            void* e = func_0204af14((struct TilemapList*)(o + 0x28), 0);
            if (e != 0) {
                func_0204ae44((struct TilemapEntry*)e, *(signed char*)(o + 0x67));
            }
            func_0204b988((struct TilemapList*)(o + 0x28), 0, 0, 0, 0xffff);
            UploadTilemapToBGScreen((struct TilemapList*)(o + 0x28), 0);
            o[0x66] = 0;
            o[0x69] &= ~1;
        }
    }
}
