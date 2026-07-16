#include <globaldefs.h>

extern "C" void func_ov006_02156e54(void* p);
int GetData02104304Field4();
void AddEntryOrOverflow(unsigned char* obj);
int CallFunc0202fa38Mode2(int a, int b, int c, int d);
extern int data_020f2a38;
extern int data_020f2a30;

struct Obj0215a33c {
    char pad0[0x10];
    void* field10;
    char pad14[0x354 - 0x14];
    int field354;
};

// USA: func_ov006_0215a33c
ARM void Func_0215a33c(struct Obj0215a33c* obj) {
    int a;
    func_ov006_02156e54(obj->field10);
    a = GetData02104304Field4();
    AddEntryOrOverflow((unsigned char*)a);
    obj->field354 = CallFunc0202fa38Mode2(a, data_020f2a38, data_020f2a30, 0);
}
