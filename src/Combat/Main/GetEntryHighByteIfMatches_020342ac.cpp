#include <globaldefs.h>

extern "C" void* func_0202ae18(void* obj);
extern "C" void* func_ov017_0218b5b0(void);
int CheckField0NonZero(int* obj);
extern "C" int func_0202c508(void* obj);
struct SearchStruct;
void* GetEntryBySignedByteIndex(struct SearchStruct* obj, int value);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

struct FlagsByte0xc1_020342ac {
    unsigned char lowBits2 : 2;
};

struct EntryField0_020342ac {
    unsigned short lowByte : 8;
    unsigned short highByte : 8;
};

// USA: func_020342ac  (semantic: GetEntryHighByteIfMatches_020342ac)
extern "C" ARM int func_020342ac(void* obj) {
    void* thing = func_0202ae18(obj);
    func_ov017_0218b5b0();
    if (!CheckField0NonZero((int*)thing)) {
        goto fallback;
    }
    if (!func_0202c508(thing)) {
        goto fallback;
    }
    short field4 = *(short*)((char*)obj + 4);
    if (!GetEntryBySignedByteIndex((struct SearchStruct*)thing, field4)) {
        goto fallback;
    }
    field4 = *(short*)((char*)obj + 4);
    signed char cur = GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)thing);
    if (cur == field4) {
        goto fallback;
    }
    FlagsByte0xc1_020342ac* flags = (FlagsByte0xc1_020342ac*)((char*)obj + 0xc1);
    if (!(flags->lowBits2 & 2)) {
        goto fallback;
    }
    field4 = *(short*)((char*)obj + 4);
    EntryField0_020342ac* entry = (EntryField0_020342ac*)GetEntryBySignedByteIndex((struct SearchStruct*)thing, field4);
    return entry->highByte;
fallback:
    return *(unsigned char*)((char*)obj + 0xbe);
}
