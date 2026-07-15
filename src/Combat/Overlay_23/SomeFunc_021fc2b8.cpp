#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021f6bb8(void*);
extern "C" void func_ov023_021f6bb0(void*, int);
int GetData02104304Field4();
int CallFunc0202fa38Mode2(int a, int b, int c, int d);

extern char data_ov023_021ff480;
extern char data_ov023_021ff496;

struct Self021fc2b8 { char pad[0x1c]; int field1c; };

// USA: func_ov023_021fc2b8
ARM int SomeFunc_021fc2b8(struct Self021fc2b8* self, void* arg1) {
    void* sub = func_ov011_021849c8(arg1);
    int v = func_ov023_021f6bb8(sub);
    if (v >= 0) {
        return self->field1c;
    }
    int getter = GetData02104304Field4();
    int result = CallFunc0202fa38Mode2(getter, (int)&data_ov023_021ff480, (int)&data_ov023_021ff496, 0);
    func_ov023_021f6bb0(sub, result);
    return 1;
}
