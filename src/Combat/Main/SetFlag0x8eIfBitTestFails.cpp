#include <globaldefs.h>

extern "C" void* func_0205ec34(void);
int TestBitInByteArray(int unused, unsigned char* arr, int index);

// USA: func_02023a9c
ARM int SetFlag0x8eIfBitTestFails(char* base, int index) {
    void* g = func_0205ec34();
    int offset = index * 0x1c;
    char* entry = base;
    entry += offset;
    entry += 0x700;

    unsigned short f8c = *(unsigned short*)(entry + 0x8c);
    if (f8c == 0) return 0;

    unsigned short f8a = *(unsigned short*)(entry + 0x8a);
    if (f8a == 0) {
        unsigned short f84 = *(unsigned short*)(entry + 0x84);
        if (TestBitInByteArray((int)g, (unsigned char*)g + 0x8c, f84 + 0x12 + 0x200)) {
            char* entry2 = base;
            entry2 += offset;
            entry2 += 0x700;
            *(unsigned short*)(entry2 + 0x8e) = 0;
            return 0;
        }
    }
    return 1;
}
