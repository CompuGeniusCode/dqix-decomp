#include <globaldefs.h>

struct Obj2081 {
    char pad[0x36];
    unsigned short field36;
};

struct Obj0208203c;
struct Obj020e280c;
struct Obj0205eaa0;

extern "C" int func_020813ec(void *obj, int id);
void ResetWithSub0208203c(struct Obj0208203c *obj);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
void SetElementFlag0x20(struct Obj2081* obj, int key);
void ResetAndReposition020e280c(struct Obj020e280c* self, void* b);

extern struct Obj0205eaa0 data_02108760;

struct Ctx021612c0 {
    char pad0[0x308];
    char sub308[0x324 - 0x308];
    struct Obj2081* field324;
    char pad1[0x390 - 0x328];
    struct Obj020e280c* field390;
    char pad2[0x470 - 0x394];
    int field470;
    short field474;
    char pad3[0x488 - 0x476];
    short field488;
    char pad4[0x49c - 0x48a];
    short field49c;
};

// USA: func_ov003_021612c0  (semantic: ConfigureAndDispatchElement_021612c0)
extern "C" ARM void func_ov003_021612c0(struct Ctx021612c0* self) {
    self->field488 = 9;
    self->field474 = self->field49c = 0x2c;
    self->field324->field36 = self->field49c;
    func_020813ec(self->field324, self->field488);
    ResetWithSub0208203c((struct Obj0208203c*)self->sub308);
    self->field470 = 0;
    DispatchWithShortB4_0205eaa0(&data_02108760, 5, 0);
    if (self->field390 == NULL) {
        return;
    }
    SetElementFlag0x20(self->field324, self->field488);
    ResetAndReposition020e280c(self->field390, (void*)-1);
}
