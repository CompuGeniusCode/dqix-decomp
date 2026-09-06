#include <globaldefs.h>

struct Obj2081 { char pad[0x36]; unsigned short field36; };
struct Obj0208203c;
struct Obj020e280c;
struct Obj0205eaa0;

extern "C" int func_020813ec(void *obj, int id);
void ResetWithSub0208203c(struct Obj0208203c *obj);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
void SetElementFlag0x20(struct Obj2081* obj, int key);
void ResetAndReposition020e280c(struct Obj020e280c* self, void* b);
void SetFieldsAt0x4And0x8(int* obj, int a, int b);

extern struct Obj0205eaa0 data_02108760;

struct Ctx02159db0 {
    char pad0[0x14];
    struct Obj2081* field14;
    void* field18;
    char pad1[0x44 - 0x1c];
    int field44;
    char pad2[0x35e - 0x48];
    short field35e;
    char pad3[0x36c - 0x360];
    short field36c;
    short field36e;
};

// USA: func_ov006_02159db0
extern "C" ARM void func_ov006_02159db0(struct Ctx02159db0* self) {
    DispatchWithShortB4_0205eaa0(&data_02108760, 5, 0);

    self->field36e = 7;
    self->field35e = self->field36c = 0x22;
    self->field14->field36 = self->field36c;
    func_020813ec(self->field14, self->field36e);

    ResetWithSub0208203c((struct Obj0208203c*)((char*)self + 0x9c));
    self->field44 = 0;

    if (self->field18 == NULL) {
        return;
    }

    SetElementFlag0x20(self->field14, self->field36e);
    ResetAndReposition020e280c((struct Obj020e280c*)self->field18, (void*)-1);

    SetFieldsAt0x4And0x8((int*)((char*)*(void**)((char*)self->field18 + 0x10) + 0x28), 0x18, 1);
}
