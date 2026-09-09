#include <globaldefs.h>
extern "C" void func_0205d904(unsigned char*);

struct Struct_0205bf3c;

extern "C" void func_0205d6e4(void* a, int count);
extern "C" void func_0205bf3c(struct Struct_0205bf3c* s);

struct Entry_0205d6a0 {
    char pad0[0x98];
    int f98;
    int f9c;
    char pad1[0xb3 - 0xa0];
    unsigned char fb3;
};

// Closes text windows from the top of the container's array: one, or as many as the array holds
// at +0xb3 when the flag is set -- func_0205d6e4 stops early once the open count at +0xb4 reaches
// zero, so passing the length closes all of them. The entries are the 0xe0-byte windows
// FindTextWindowById searches, and the teardown at func_0204c804 puts each id back to 0xff.
// Afterwards func_0205d904 re-reads whichever window is now on top and recomputes the container's
// position from its tile coordinates, shifted left three, i.e. tiles to pixels.
extern "C" ARM void CloseWindows(struct Entry_0205d6a0* a, int flag) {
    int count;
    if (a->f98 == 0 || a->f9c == 0) return;
    count = 1;
    if (flag) count = a->fb3;
    func_0205d6e4(a, count);
    func_0205bf3c((struct Struct_0205bf3c*)((char*)a + 0x54));
    func_0205d904((unsigned char*)(a));
}
