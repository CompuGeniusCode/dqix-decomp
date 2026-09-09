#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/Cache.h"
#include "std_library_functions.h"

extern "C" void* func_02094a00();
extern "C" void* _Z15GetBattleStructv();
extern "C" void* func_0200fb8c(void* battle);
extern "C" void CancelBackgroundLoadTasks(void*);
extern "C" void func_02094b34(void*, int, int, int, int);
extern "C" int func_02094b4c(void*);
extern "C" void func_020dc2bc();
extern "C" void SaveMainBGControlRegisters(void*);
extern "C" unsigned int func_0203b498(unsigned int*);
extern "C" unsigned int func_0203b4d0(unsigned int*);
extern "C" unsigned int func_0203b508(unsigned int*);
extern "C" void func_0203b4d8(unsigned int*, unsigned int);
extern "C" void SetBothScreensBrightness(void*, int, int);

struct FieldSet02097bc4;
extern "C" void func_02097bc4(struct FieldSet02097bc4*, int);
extern "C" void func_02097c18(void*, int, int, int, int, int, int, int);

extern "C" void ResetBackgroundLayer(void*);
extern "C" void func_0204b11c(void*, int);
extern "C" void SetBackgroundScroll(void*, int, int);
extern "C" void func_0204b2e0(void*, char*);
extern "C" void func_0204b3a0(void*, char*);

extern "C" void LoadToSubBGStandardPalette(int, int, unsigned int);
extern "C" void LoadToSubBG1ScreenData(int, int, unsigned int);
extern "C" void LoadToSubBG1CharacterData(int, int, unsigned int);

extern "C" void func_ov028_021d98e0(void*, void*, int, int);
extern "C" int IsScreenFadeActive(void*);

extern int strDataEvsptLv5StaffrollBin;

// One frame of the staff roll. The state byte at +0x81 walks 0 to 6: bring the sub screen up, fill
// its BG1 character and screen data, queue data/evspt_lv5/staffroll.bin, hand the loaded file to
// func_ov028_021d98e0 to be parsed into the allocator at +0x44, then sit on a 0x1e counter,
// presumably frames, before setting the done flag at +0x80 and rewinding the state to 0. ov028 is
// "sub_hoge", hoge being the Japanese stand-in for foo, so the overlay name says nothing. The staff
// .pac models in data/chara_sub (horii, hino, sugiyama, toriyama, tobe_<lang>) fit, none loaded here.
extern "C" ARM void StepStaffRollSequence(unsigned char* self) {
    void* g = func_02094a00();
    void* data = BackgroundLoader::GetInstance();
    void* battle = _Z15GetBattleStructv();
    void* word = func_0200fb8c(battle);
    unsigned char state = self[0x81];

    if (state == 0) {
        CancelBackgroundLoadTasks(g);
        func_02094b34(g, 0x7a, 0x20b, 0, 0);
        self[0x81] = self[0x81] + 1;
    } else if (state == 1) {
        if (func_02094b4c(g) != 0) {
            self[0x81] = self[0x81] + 1;
        }
    } else if (state == 2) {
        func_020dc2bc();
        SaveMainBGControlRegisters(self + 0xc);
        *(unsigned int*)(self + 0x74) = func_0203b498((unsigned int*)word);
        *(unsigned int*)(self + 0x78) = func_0203b4d0((unsigned int*)word);
        *(unsigned int*)(self + 0x7c) = func_0203b508((unsigned int*)word);
        func_0203b4d8((unsigned int*)word, 0x90);
        void* buf40 = *(void**)(self + 0x40);
        func_02097bc4((struct FieldSet02097bc4*)(self + 0x20), 2);
        func_02097c18(self + 0x20, 2, 0, 0, 0, 0, 0x180, 0);

        unsigned short* reg400100a = (unsigned short*)0x400100a;
        *reg400100a = (*reg400100a & 0x43) | 0x1000;

        unsigned char list[0x20];
        ResetBackgroundLayer(list);
        unsigned char v = list[0x1c];
        v = (v & ~0xf) | 1;
        v = v & 0xff;
        v = (v & ~0xf0) | 0x10;
        list[0x1c] = v;
        func_0204b11c(list, 0);
        SetBackgroundScroll(list, 0, 0);
        int tag = *(int*)((char*)word + 0x2c);
        func_0204b2e0(list, (char*)tag);
        func_0204b3a0(list, (char*)tag);

        unsigned short tmpVal = 0x67f5;
        memcpy(buf40, &tmpVal, 2);
        CleanInvalidateCacheRange(buf40, 2);
        LoadToSubBGStandardPalette((int)buf40, 0xa, 2);

        unsigned short* p = (unsigned short*)buf40;
        for (unsigned short i = 0; i < 0x400; i++) {
            p[i] = i;
        }

        CleanInvalidateCacheRange(buf40, 0x800);
        LoadToSubBG1ScreenData((int)buf40, 0, 0x800);
        memset(buf40, 0x11111111, 0x8000);
        CleanInvalidateCacheRange(buf40, 0x8000);
        LoadToSubBG1CharacterData((int)buf40, 0, 0x8000);
        void* buf2 = *(void**)(self + 0x40);
        memset(buf2, 0x11111111, 0x8000);
        buf2 = *(void**)(self + 0x40);
        CleanInvalidateCacheRange(buf2, 0x8000);

        unsigned short* r1008 = (unsigned short*)0x4001008;
        r1008[0] = (r1008[0] & ~3) | 1;
        r1008[1] = r1008[1] & ~3;
        r1008[2] = (r1008[2] & ~3) | 2;
        r1008[3] = (r1008[3] & ~3) | 3;
        unsigned int* reg0 = (unsigned int*)0x4000000;
        *reg0 = (*reg0 & ~0x1f00) | 0x1100;
        unsigned int* reg1 = (unsigned int*)0x4001000;
        *reg1 = (*reg1 & ~0x1f00) | 0x200;

        self[0x81] = self[0x81] + 1;
    } else if (state == 3) {
        int r = ((BackgroundLoader*)((int)data))->QueueLoadFile((const char*)((int)&strDataEvsptLv5StaffrollBin), (SafeAllocator*)(0));
        *(int*)(self + 0x70) = r;
        self[0x81] = self[0x81] + 1;
    } else if (state == 4) {
        if (((BackgroundLoader*)(data))->GetTaskStatus((int)(*(int*)(self + 0x70))) != 0) {
            int a, b;
            ((BackgroundLoader*)(data))->GetLoadedFileByID((int)(*(int*)(self + 0x70)), (void**)(&a), (unsigned int*)(&b));
            if (a != 0 && b != 0) {
                ((SafeAllocator*)(self + 0x44))->Reset();
                func_ov028_021d98e0(self, self + 0x44, a, b);
            }
            ((BackgroundLoader*)(data))->RemoveTask((int)(*(int*)(self + 0x70)));
            *(int*)(self + 0x70) = -1;
            self[0x81] = self[0x81] + 1;
        }
    } else if (state == 5) {
        self[0x81] = state + 1;
        SetBothScreensBrightness(word, 0, 0x1e);
    } else if (state == 6) {
        if (IsScreenFadeActive(word) == 0) {
            self[0x80] = 1;
            self[0x81] = 0;
        }
    }
}
