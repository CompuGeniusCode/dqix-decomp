#include <globaldefs.h>

struct HalfwordCursor020b2a58;
unsigned short ReadHalfwordAndAdvance(struct HalfwordCursor020b2a58*);
extern "C" void func_020b27c8(void*, void*);

struct HalfwordReader020b0e48 {
    int field0;                                                // 0x0
    unsigned short (*handler)(struct HalfwordCursor020b2a58*);  // 0x4
};

// USA: func_020b0e48
ARM void InitHalfwordReader(struct HalfwordReader020b0e48* obj, void* arg) {
    func_020b27c8(arg, obj);
    obj->handler = ReadHalfwordAndAdvance;
}
