#include <globaldefs.h>

struct Obj020bd984;
extern "C" void func_020bd984(struct Obj020bd984*);
extern "C" void func_0203a914(void*);
extern "C" extern void* func_020bd914(void* start, unsigned int size);
struct Holder020bd110;
extern "C" int func_020bd110(struct Holder020bd110* obj, const char* path, int arg2, int arg3);
extern "C" int func_020be6c4(void* obj);
extern "C" void func_020be9e8(void* arg0, void* arg1);
struct Obj020bdac0;
extern "C" int func_020bdac0(struct Obj020bdac0*);

struct Obj0203a974 {
    void* field0;
    char pad[0x9c];
    int field_a0;
};

// USA: OpenFileStreamInRegion
extern "C" ARM void OpenFileStreamInRegion(struct Obj0203a974* obj, const char* path, void* start, unsigned int size, void* arg5) {
    void* p;
    if (size <= 1) {
        return;
    }
    p = obj->field0;
    if (p == 0) {
        goto skip_both;
    }
    if (p == 0) {
        goto skip_destroy;
    }
    func_020bd984((struct Obj020bd984*)p);
skip_destroy:
    func_0203a914(obj);
skip_both:
    obj->field0 = func_020bd914(start, size);
    func_020bd110((struct Holder020bd110*)((char*)obj + 4), path, (int)obj->field0, 0);
    if (func_020be6c4(obj->field0) == 0) {
        return;
    }
    if (arg5 != 0) {
        func_020be9e8(0, obj->field0);
    }
    obj->field_a0 = func_020bdac0((struct Obj020bdac0*)obj->field0);
}
