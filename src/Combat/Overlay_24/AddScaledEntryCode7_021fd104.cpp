#include <globaldefs.h>

struct AddEntryList_021f6a1c;
void AddEntryIfUnderLimit16_021f6a1c(struct AddEntryList_021f6a1c* obj, void* src);

struct Entry3W_021fd104 { unsigned int v[3]; };
struct EntryFields_021fd104 {
    float value;
    unsigned char id;
    unsigned char pad5;
    unsigned char pad6;
    unsigned char hundred;
    unsigned char code;
    unsigned char pad9, pad10, pad11;
};
union EntryU_021fd104 {
    Entry3W_021fd104 raw;
    EntryFields_021fd104 f;
};

// USA: func_ov024_021fd104  (semantic: AddScaledEntryCode7_021fd104)
extern "C" ARM void func_ov024_021fd104(char* self, unsigned char id) {
    union EntryU_021fd104 e;
    e.raw = *(Entry3W_021fd104*)(self + 0x65c);
    short s = *(short*)(*(char**)(self + 0x64c) + 0x32);
    float v = (float)s;
    e.f.id = id;
    e.f.hundred = 0x64;
    e.f.code = 7;
    e.f.value = v;
    AddEntryIfUnderLimit16_021f6a1c(*(struct AddEntryList_021f6a1c**)(self + 0x658), &e);
}
