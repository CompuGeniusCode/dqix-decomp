#include <globaldefs.h>

extern "C" int FindOpenWindowById(void *obj, int id);
extern "C" int func_0207f0ac(void *list, int id);
extern "C" int func_02081e18(void *obj, int x);
extern "C" int func_02081de0(void *obj);
extern "C" int func_020804fc(void *obj, int id);
extern "C" int func_0204f160(void *a, int c, int id);
extern "C" int func_02081498(void *obj, void *a, void *b);
extern "C" int func_02081574(void *obj, void *a, void *b);
extern "C" int func_0204fbf8(void *a);

// Opens the window with the given id, out of the layout records the manager loaded from
// <name>_wnd.bin -- func_0207f914 queues that file alongside <name>_txt.bin and <name>_<LG>.bin for
// this same object, and ov006's func_ov006_0215a5fc hands both it and this the same pointer. If no
// element is bound to the id yet it takes a free one, meaning one still carrying 0xff in byte 0xc4,
// fills it in and stamps the id, then seems to draw the frame and walk the record's part list.
// Returns 1 only for a negative id or one no record carries; a failed bind still returns 0.
extern "C" ARM int OpenWindowById(void *obj, int id) {
    if (id < 0) {
        return 1;
    }

    int a = FindOpenWindowById(obj, id);
    int b = func_0207f0ac((char *)obj + 0xc, id);
    if (b == 0) {
        return 1;
    }

    unsigned char byteVal = *((unsigned char *)obj + 0x3a);
    int c = func_02081e18(obj, byteVal);

    if (a == 0) {
        a = func_02081de0(obj);
        func_020804fc(obj, id);
    }

    if (a != 0) {
        func_0204f160((void *)a, c, id);
        func_02081498(obj, (void *)a, (void *)b);
        func_02081574(obj, (void *)a, (void *)b);
        func_0204fbf8((void *)a);
    }

    return 0;
}
