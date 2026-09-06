#include <globaldefs.h>

short FindMappedMemberId02080468(void* obj, int id);
extern "C" void func_ov003_02178548(void* self);
extern "C" void func_ov003_021767ec(void* self);
extern "C" void func_ov003_021769ec(void* self);
extern "C" void func_ov003_02176ed4(void* self);
extern "C" void func_ov003_02176f94(void* self);

// USA: func_ov003_021785d4  (semantic: AdjustMappedIndexAndRefresh_021785d4)
extern "C" ARM void func_ov003_021785d4(char* obj) {
    int flags = *(int*)(obj + 0xfe4);
    int delta = 0;
    if (flags & 0x10) {
        delta = 1;
    } else if (flags & 0x20) {
        delta -= 1;
    }

    *(short*)(obj + 0x1000 + 0x14) = *(short*)(obj + 0x1000 + 0x14) + delta;
    if (*(short*)(obj + 0x1000 + 0x16) <= *(short*)(obj + 0x1000 + 0x14)) {
        *(short*)(obj + 0x1000 + 0x14) = 0;
    }
    if (*(short*)(obj + 0x1000 + 0x14) < 0) {
        *(short*)(obj + 0x1000 + 0x14) = *(short*)(obj + 0x1000 + 0x16) - 1;
    }

    if (delta != 0) {
        void* p89c = *(void**)(obj + 0x89c);
        short id = FindMappedMemberId02080468(p89c, 3);
        *(short*)(*(void**)(obj + 0xff8)) = id;
        func_ov003_02178548(obj);
        func_ov003_021767ec(obj);
        func_ov003_021769ec(obj);
        func_ov003_02176ed4(obj);
        func_ov003_02176f94(obj);
    }

    func_ov003_02178548(obj);
    if (*(short*)(obj + 0x1000) == *(short*)(*(void**)(obj + 0xff8))) {
        return;
    }
    func_ov003_021767ec(obj);
    func_ov003_021769ec(obj);
    func_ov003_02176ed4(obj);
    func_ov003_02176f94(obj);
}
