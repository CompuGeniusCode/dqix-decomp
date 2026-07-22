#include <globaldefs.h>

extern "C" void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct TableEntry021c6254 {
    unsigned char pad0[2];
    unsigned char data[8];
    unsigned char countNibble : 4;
    unsigned char restNibble : 4;
    unsigned char pad1[0x18 - 0xb];
};

struct TableHolder021c6254 {
    unsigned int count;
    struct TableEntry021c6254 entries[1];
};

struct LocalEvt021c6254 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short field4;
    unsigned short field6;
    unsigned char data[0xc];
};

// USA: func_ov017_021c6254
ARM void EnqueueEntryDataEvent_021c6254(unsigned char* obj, int idx) {
    void* p = GetData02100044();
    struct TableHolder021c6254* holder = (struct TableHolder021c6254*)((char*)obj + 0x1b0 + 0x8000);
    LocalEvt021c6254 evt;
    evt.tag = 0x62;
    unsigned char* header = *(unsigned char**)((char*)obj + 0x8000 + 0xe18);
    struct TableEntry021c6254* entry = &holder->entries[idx];
    unsigned short* fields = &evt.field4;
    fields[1] = idx;
    fields[0] = *(unsigned short*)(header + 8);
    int i;
    for (i = 0; i < entry->countNibble; i++) {
        evt.data[i] = 0;
        evt.data[i] = entry->data[i];
    }
    func_0205e330(p, &evt, 0);
}
