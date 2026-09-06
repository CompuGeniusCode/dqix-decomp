#include <globaldefs.h>

struct Entry020bbc68 {
    unsigned char data[0x10];
};

struct EntryList020bbc68 {
    struct Entry020bbc68* base;  // 0x0
    char _04[0x04];              // 0x4..0x7
    unsigned short index;        // 0x8
};

// USA: func_020bbc68
ARM struct Entry020bbc68* GetIndexedEntry020bbc68(struct EntryList020bbc68* list) {
    return list->base + list->index;
}
