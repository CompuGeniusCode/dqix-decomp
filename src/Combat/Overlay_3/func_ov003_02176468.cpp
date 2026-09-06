#include <globaldefs.h>

struct Obj2081;
void SetElementFlag0x20(struct Obj2081* obj, int key);
extern "C" void func_020813ec(void* obj, int key);

struct Obj0208203c;
void ResetWithSub0208203c(struct Obj0208203c* obj);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;

struct Obj020e280c;
void ResetAndReposition020e280c(struct Obj020e280c* self, void* b);

// USA: func_ov003_02176468  (semantic: ResetElementFieldsAndDispatch_02176468)
extern "C" ARM void func_ov003_02176468(unsigned char* self) {
    *(short*)(self + 0xffe) = 1;
    *(short*)(self + 0x1000) = *(short*)(self + 0x1002) = 2;
    *(short*)((char*)(*(struct Obj2081**)(self + 0x89c)) + 0x36) = *(short*)(self + 0x1002);
    func_020813ec(*(struct Obj2081**)(self + 0x89c), *(short*)(self + 0xffe));
    ResetWithSub0208203c((struct Obj0208203c*)(self + 0x88c));
    *(void**)(self + 0xff8) = 0;
    DispatchWithShortB4_0205eaa0(&data_02108760, 5, 0);
    if (*(void**)self == 0) {
        return;
    }
    SetElementFlag0x20(*(struct Obj2081**)(self + 0x89c), *(short*)(self + 0xffe));
    ResetAndReposition020e280c((struct Obj020e280c*)(*(void**)self), (void*)-1);
}
