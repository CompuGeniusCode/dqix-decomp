#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
extern "C" int func_ov017_021d6134(void*, int);

struct ActiveGrottoClass {
    ActiveGrottoClass* BlankFunction() const;
};

// USA: func_0209dbac
ARM int NotifyOv017WithGrottoByte0x50(void* arg) {
    ActiveGrottoClass* g = (ActiveGrottoClass*)((char*)func_02012fe4() + 0x23EC);
    if (g == NULL) return 0;
    ActiveGrottoClass* r = g->BlankFunction();
    if (r == NULL) return 0;
    if (*((unsigned char*)r + 0x1) != 1) return 0;
    func_ov017_021d6134(arg, *((unsigned char*)r + 0x50));
    return 1;
}
