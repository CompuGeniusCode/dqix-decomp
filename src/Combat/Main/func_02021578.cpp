#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct BattleStruct;
struct BattleStruct* GetBattleStruct();

extern "C" void* func_02012fe4(void);
extern "C" void* func_ov017_0218b5b0(void);
extern "C" void* func_0203bd08(void);
void* GetData02105254(void);
extern "C" void func_02021428(void* obj, int amount);

struct AxisFloats0203b5a0;
int IsAxisIntWithin16(struct AxisFloats0203b5a0* s, int axis);

extern "C" void VectorizedMemset(void*, int, int);

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);
struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);
struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);
extern "C" int func_020420e8(void* p, int flag);

extern "C" void func_02020720(char* obj);
extern "C" void func_02020838(char* obj);
extern "C" void _Z19TailForward0203b66cPc(char* obj);
extern "C" void _Z21InitSubObject0203bd78Pc(char* obj);
extern "C" void _Z25InitBattleContext0203bd24Pc(char* obj);
extern "C" void _Z24SetArraySlotFlag0203b718Pviii(void* objPtr, int mode, int idx, int fillByte);
extern "C" void func_0203ba74(void* obj);
struct Struct0205a198;
extern "C" void _Z12Init0205a198P14Struct0205a198(struct Struct0205a198* p);
extern "C" void _Z18InitStruct0205a444Pc(char* obj);

extern "C" int _Z26FormatAndCopyNames02020b98Pv(void* obj);
extern "C" void func_02020c18(char* obj, int* handle, SafeAllocator* alloc);
extern "C" void _Z20ClearRecords02026644Pc(char* obj);
extern "C" void func_020211b0(char* obj, int* handle);
extern "C" void func_02020aec(char* obj, int* handle, SafeAllocator* alloc);
extern "C" int _Z25InitAndCopyBuffer02023330Pvi(void* obj, int flag);
extern "C" void _Z26InitFourEntrySlots02020aa0Pv(void* obj);
extern "C" void func_02020fc4(void* obj, int* handle, SafeAllocator* alloc);
extern "C" void func_020210f8(char* obj, int* handle, SafeAllocator* alloc);
extern "C" void func_0202445c(void* obj);
extern "C" void func_ov017_02191234(void* obj);
void DelayThenSyncBit0(void);
extern "C" void func_0202343c(void* obj);
extern "C" void _Z32MarkActiveCombatantSlots02026b7cPh(unsigned char* obj);
extern "C" void func_02026bdc(void* obj, int flag);

extern int data_020ef460;
extern char data_020ef598;
extern char data_020ef5a5;
extern int data_020fdc4c;
extern int data_020ef4e8;
extern char data_020ef5b9;

struct Modes02012fe4 {
    char pad0[0xc];
    unsigned char mode : 4;
    unsigned char modeHigh : 4;
};

struct Entry02021578 {
    int field0;
    char* name;
    char pad8[0x1c];
};

// USA: func_02021578
#pragma opt_propagation off
extern "C" ARM void func_02021578(char* self) {
    void* fileData;
    unsigned int fileLength;
    char buf[0x40];
    char local[0x430];

    GetBattleStruct();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    struct Modes02012fe4* modes = *(struct Modes02012fe4**)((char*)func_02012fe4() + 8);
    void* axis = func_ov017_0218b5b0();
    char* battleCtx = (char*)func_0203bd08();
    char* table = (char*)GetData02105254();
    int state = *(signed char*)(self + 0x9c2);
    SafeAllocator* alloc = (SafeAllocator*)((char*)axis + 0x128);

    if (state == 0) {
        *(unsigned char*)(self + 0x9c7) = 0;
        func_02021428(self, 0x19);
        loader->AddFence();
        *(int*)(self + 0x9f8) = loader->QueueLoadFileInGP2(
            *(const char**)((char*)&data_020ef460 + 4),
            *(const char**)((char*)&data_020ef460), (SafeAllocator*)0);
        loader->AddFence();
        *(int*)(self + 0x9d0) = _Z26FormatAndCopyNames02020b98Pv(self);
        *(int*)(self + 0xa30) = loader->QueueLoadFileInGP2(
            *(const char**)((char*)&data_020ef460 + 8),
            &data_020ef598, (SafeAllocator*)0);
        *(int*)(self + 0x9cc) = loader->QueueLoadFile(&data_020ef5a5, (SafeAllocator*)0);
        *(signed char*)(self + 0x9c2) = *(signed char*)(self + 0x9c2) + 1;
    } else if (state == 1) {
        if (loader->GetTaskStatus(*(int*)(self + 0x9f8)) == 0) return;
        VectorizedMemset(self + 0xba2, 0, 0x40);
        *(int*)((char*)&data_020fdc4c + 4) = 0;
        *(int*)(self + 0xbe4) = 0;
        *(int*)(self + 0xbe8) = 0;
        *(unsigned short*)(self + 0xbec) = 0;
        *(unsigned short*)(self + 0xbee) = 0;
        loader->GetLoadedFileByID(*(int*)(self + 0x9f8), &fileData, &fileLength);
        _ZN6Script10InitializeEv((struct ResetStruct*)local);
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_020ef4e8);
        _ZN6Script4LoadEPKvj((struct StreamState*)local, (struct StreamHeader*)fileData, fileLength);
        _ZN6Script7ExecuteEv((struct Struct02030774*)local);
        char* name = *(char**)((char*)&data_020fdc4c + 4);
        if (name != 0) {
            memcpy(self + 0xba2, name, strlen(name));
            *(int*)(self + 0xbe4) = func_020420e8(self + 0xba2, 0);
        }
        BackgroundLoader::GetInstance()->RemoveTask(*(int*)(self + 0x9f8));
        *(int*)(self + 0x9f8) = -1;
        *(signed char*)(self + 0x9c2) = *(signed char*)(self + 0x9c2) + 1;
    } else if (state == 2) {
        func_02021428(self, 0x19);
        if (IsAxisIntWithin16((struct AxisFloats0203b5a0*)axis, 1) != 0) return;
        func_02020720(self);
        func_02020838(self);
        _Z19TailForward0203b66cPc(table);
        alloc->Reset();
        _Z21InitSubObject0203bd78Pc(battleCtx);
        _Z25InitBattleContext0203bd24Pc(battleCtx);
        _Z24SetArraySlotFlag0203b718Pviii(table, 1, 0, 0);
        _Z24SetArraySlotFlag0203b718Pviii(table, 1, 1, 0);
        func_0203ba74(table);
        for (int i = 0; i < 0x1c; i++) {
            _Z12Init0205a198P14Struct0205a198((struct Struct0205a198*)(self + 0xe8 + i * 0x28));
        }
        _Z18InitStruct0205a444Pc(self + 0x94);
        *(unsigned char*)(self + 0xe4) = 1;
        *(char**)(self + 0xd4) = self + 0xe8;
        *(unsigned short*)(self + 0xe0) = 0x1c;
        int mode = modes->mode;
        if (mode == 0) {
            *(int*)(self + 0x14) = 3;
        } else if (mode == 7) {
            *(int*)(self + 0x14) = 1;
        } else {
            *(int*)(self + 0x14) = 0;
        }
        *(signed char*)(self + 0x9c2) = *(signed char*)(self + 0x9c2) + 1;
    } else if (state == 3) {
        int status = loader->GetTaskStatus(*(int*)(self + 0x9d0));
        if (status == 0) return;
        *(int*)(self + 0x24) = 0;
        *(int*)(self + 0x30) = 0;
        if (status == -1) {
            *(signed char*)(self + 0x9c2) = 0x64;
            BackgroundLoader::GetInstance()->RemoveTask(*(int*)(self + 0x9d0));
            *(int*)(self + 0x9d0) = -1;
            BackgroundLoader::GetInstance()->RemoveTask(*(int*)(self + 0xa30));
            *(int*)(self + 0xa30) = -1;
            BackgroundLoader::GetInstance()->RemoveTask(*(int*)(self + 0x9cc));
            *(int*)(self + 0x9cc) = -1;
            *(unsigned char*)(self + 0x9c7) = 1;
            return;
        }
        func_02020c18(self, (int*)(self + 0x9d0), alloc);
        if (*(unsigned char*)(self + 0x779) != 0) {
            *(unsigned char*)(self + 0x9b8) = 1;
            *(unsigned char*)(self + 0x9b9) = 0;
            _Z20ClearRecords02026644Pc(self);
        }
        loader->AddFence();
        sprintf(buf, &data_020ef5b9, self + 0x548);
        *(int*)(self + 0x9d4) = loader->QueueLoadFileInGP2(
            *(const char**)((char*)&data_020ef460 + 8), buf, (SafeAllocator*)0);
        for (int i = 0; i < *(int*)(self + 0x24); i++) {
            sprintf(buf, &data_020ef5b9,
                    (*(struct Entry02021578**)(self + 0x20))[i].name);
            *(int*)(self + 0x9d8 + i * 4) = loader->QueueLoadFileInGP2(
                *(const char**)((char*)&data_020ef460 + 8), buf, (SafeAllocator*)0);
        }
        *(signed char*)(self + 0x9c2) = *(signed char*)(self + 0x9c2) + 1;
    }

    if (*(signed char*)(self + 0x9c2) == 4) {
        if (loader->GetTaskStatus(*(int*)(self + 0xa30)) == 0) return;
        func_020211b0(self, (int*)(self + 0xa30));
        *(signed char*)(self + 0x9c2) = *(signed char*)(self + 0x9c2) + 1;
    }
    if (*(signed char*)(self + 0x9c2) == 5) {
        if (loader->GetTaskStatus(*(int*)(self + 0x9cc)) == 0) return;
        func_02020aec(self, (int*)(self + 0x9cc), alloc);
        memcpy(self + 0xbf0, (char*)0x6600000 + 0x2c20, 0x40);
        _Z25InitAndCopyBuffer02023330Pvi(self, 1);
        _Z26InitFourEntrySlots02020aa0Pv(self);
        *(signed char*)(self + 0x9c2) = *(signed char*)(self + 0x9c2) + 1;
    }
    if (*(signed char*)(self + 0x9c2) == 6) {
        if (loader->GetTaskStatus(*(int*)(self + 0x9d4)) == 0) return;
        func_02020fc4(self, (int*)(self + 0x9d4), alloc);
        *(signed char*)(self + 0x9c2) = *(signed char*)(self + 0x9c2) + 1;
    }
    if (*(signed char*)(self + 0x9c2) == 7) {
        for (int i = 0; i < *(int*)(self + 0x24); i++) {
            if (loader->GetTaskStatus(*(int*)(self + 0x9d8 + i * 4)) == 0) return;
        }
        func_020210f8(self, (int*)(self + 0x9d8), alloc);
        func_0202445c(self);
        func_ov017_02191234(axis);
        *(unsigned char*)(self + 0x55c) = 1;
        *(unsigned char*)(self + 0x9c4) = 1;
        *(unsigned char*)(self + 0x9c8) = 0;
        *(unsigned char*)(self + 0x9c3) = 0;
        *(signed char*)(self + 0x9c2) = *(signed char*)(self + 0x9c2) + 1;
        DelayThenSyncBit0();
        func_0202343c(self);
        func_0202445c(self);
        _Z32MarkActiveCombatantSlots02026b7cPh((unsigned char*)self);
        func_02026bdc(self, 0);
    }
}
