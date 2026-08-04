#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

int GetData02104304Field4(void);
extern "C" int func_0202fdd0(int listPtr, int handle);
extern "C" void func_020301c8(int listPtr, int handle);

void ResetAndUnlinkNode02037330(unsigned char* obj);

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);

struct Obj02036084;
void AllocateAndInitBuffer02036084(struct Obj02036084* obj, SafeAllocator* alloc, int b, int c, int e);

extern "C" void func_0207ea8c(void* p);

void AllocCopyDispatch020361a4(void* a, int b, SafeAllocator* alloc, void* src, unsigned int size);

struct Obj020363b4;
void LoadStreamIntoSlot020363b4(struct Obj020363b4* obj, SafeAllocator* alloc, void* header, int size);

extern "C" void* func_ov023_021e540c(void* obj);

void ResetStreamContext02037138(unsigned char* obj);
extern "C" void func_02036e34(void* obj, int* data, int flag);
extern "C" void func_0200f374(void* buf, int len);

struct Words021e60c4;
void SetWords_021e60c4_021e60c4(void* obj, struct Words021e60c4* src);
extern "C" void func_ov023_021e5e68(void* obj, int a, int b);

void CopyAndClampShorts_021e5fdc(void* unused, short* dst, short* src);

struct Container020dedd0;
struct Element020de650;
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);

extern int data_ov023_021fdce0;
extern int data_ov023_021fdce9;

struct BitByte021e540c { unsigned char pad0[0x14]; unsigned char bit0 : 1; };
struct BitWord021e540c { unsigned int pad0[2]; unsigned int pad1 : 4; unsigned int code : 5; };

struct Words021e60c4 { unsigned int a, b, c; };

// USA: func_ov023_021e5020
ARM void UpdateCombatOverlaySlots_021e5020(void* objRaw) {
    char* obj = (char*)objRaw;

    if (*(unsigned char*)(obj + 0xc12) != 0) {
        int dataResult = GetData02104304Field4();
        *(unsigned char*)(obj + 0xc12) = 0;

        for (int i = 0; i < 10; i++) {
            short* handle = (short*)(obj + 0xbf4) + i;
            if (*handle > -1) {
                if (func_0202fdd0(dataResult, *((short*)(obj + 0xbf4) + i))) {
                    ResetAndUnlinkNode02037330((unsigned char*)(obj + 0 + i * 0xac));
                    int allocOff = i * 0x14;
                    ((SafeAllocator*)(obj + 0x6b8 + allocOff))->Reset();
                    int out1, out2;
                    GetListEntryValues0202fec8((struct List0202fec8*)dataResult, *((short*)(obj + 0xbf4) + i), &out1, &out2);
                    if (out2 != 0) {
                        int pairOff = i * 0x70;
                        CopyInternalFields0207df50((struct Foo0207df50*)(obj + 0x794 + pairOff));
                        RestorePairTables0207df90(obj + 0x794 + pairOff);
                        AllocateAndInitBuffer02036084((struct Obj02036084*)(obj + 0 + i * 0xac), (SafeAllocator*)(obj + 0x6b8 + allocOff), out1, out2, 0);
                        BackupPairTables0207dfac(obj + 0x794 + pairOff);
                                            }
                    func_020301c8(dataResult, *((short*)(obj + 0xbf4) + i));
                    *((short*)(obj + 0xbf4) + i) = -1;
                } else {
                    *(unsigned char*)(obj + 0xc12) = 1;
                }
            }
        }

        short k1 = *(short*)(obj + 0xc08);
        if (k1 > -1) {
            if (func_0202fdd0(dataResult, k1)) {
                int out1, out2;
                GetListEntryValues0202fec8((struct List0202fec8*)dataResult, k1, &out1, &out2);
                if (out2 != 0) {
                    GetListEntryValues0202fec8((struct List0202fec8*)dataResult, k1, &out1, &out2);
                    if (out2 != 0) {
                        AllocCopyDispatch020361a4(obj, 0, (SafeAllocator*)(obj + 0x780), (void*)out1, out2);
                    }
                }
                func_020301c8(dataResult, k1);
                *(short*)(obj + 0xc08) = -1;
            } else {
                *(unsigned char*)(obj + 0xc12) = 1;
            }
        }

        short k2 = *(short*)(obj + 0xc0a);
        if (k2 > -1) {
            if (func_0202fdd0(dataResult, k2)) {
                int out1, out2;
                GetListEntryValues0202fec8((struct List0202fec8*)dataResult, k2, &out1, &out2);
                if (out2 != 0) {
                    GetListEntryValues0202fec8((struct List0202fec8*)dataResult, k2, &out1, &out2);
                    if (out2 != 0) {
                        LoadStreamIntoSlot020363b4((struct Obj020363b4*)obj, (SafeAllocator*)(obj + 0x780), (void*)out1, out2);
                    }
                }
                func_020301c8(dataResult, k2);
                *(short*)(obj + 0xc0a) = -1;
            } else {
                *(unsigned char*)(obj + 0xc12) = 1;
            }
        }
    }

    if (*(unsigned char*)(obj + 0xc12) == 0 && *(unsigned char*)(obj + 0xc1e) == 0) {
        func_ov023_021e540c(obj);
        *(unsigned char*)(obj + 0xc1e) = 1;
        *(unsigned char*)(obj + 0xc12) = 1;
    }

    if (*(unsigned char*)(obj + 0xc12) != 0) {
        return;
    }

    char* dataX = *(char**)(obj + 0xc18) + 0x488;
    if (*(unsigned char*)(obj + 0xc13) != 0) {
        int bit0 = ((struct BitByte021e540c*)dataX)->bit0;
        if (bit0 == 1 && *(unsigned char*)(obj + 0xc11) == 0) {
            if (*(short*)(obj + 2) >= 0) {
                ResetStreamContext02037138((unsigned char*)obj);
                func_02036e34(obj, &data_ov023_021fdce0, 0);
            }
        } else {
            if (*(short*)(obj + 2) >= 0) {
                ResetStreamContext02037138((unsigned char*)obj);
                func_02036e34(obj, &data_ov023_021fdce9, 0);
            }
        }

        struct Words021e60c4 localbuf;
        func_0200f374(&localbuf, 0xc);
        *(short*)((char*)&localbuf + 4) = *(short*)(obj + 0xc1c);
        SetWords_021e60c4_021e60c4(obj, &localbuf);
        SetWords_021e60c4_021e60c4(obj + 0x408, &localbuf);
        SetWords_021e60c4_021e60c4(obj + 0xac, &localbuf);
        SetWords_021e60c4_021e60c4(obj + 0x35c, &localbuf);
        func_ov023_021e5e68(obj, *(short*)(dataX + 0x18), *(short*)(dataX + 0x1a));
    }

    short dst[10];
    CopyAndClampShorts_021e5fdc((void*)(unsigned int)(*(unsigned char*)(obj + 0xc15)), dst, (short*)dataX);
    struct Element020de650* elem = FindElementByKey020dedd0(*(struct Container020dedd0**)(obj + 0xc0c), dst[8]);
    if (elem != 0 && ((struct BitWord021e540c*)elem)->code == 6) {
        *(unsigned char*)(obj + 0xc10) = 1;
        return;
    }
    *(unsigned char*)(obj + 0xc10) = 0;
}
