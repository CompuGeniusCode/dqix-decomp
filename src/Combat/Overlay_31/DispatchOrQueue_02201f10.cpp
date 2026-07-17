#include <globaldefs.h>

struct Obj02201f10 {
    char pad[0x1c];
    int field1c;
};

int CheckOrDispatch_02201ef4(void);
extern "C" void func_ov031_02200730(int a);
extern "C" int func_ov031_02200ccc(void);
extern "C" int func_ov031_02201550(int a, int b, void* c, int d, int e);

extern int data_02111304;
extern char data_ov031_0224cbe8;

// USA: func_ov031_02201f10
#pragma optimize_for_size off
ARM int DispatchOrQueue_02201f10(Obj02201f10* obj, int b, int c) {
    int unused = ((volatile Obj02201f10*)obj)->field1c;
    (void)unused;
    if (CheckOrDispatch_02201ef4() == 0) {
        int* pa = &data_02111304;
        char* pb = &data_ov031_0224cbe8;
        int v = pa[1];
        if ((char*)v == pb) {
            goto special;
        }
    }
    return func_ov031_02201550(0, 0, obj, b, c);
special:
    func_ov031_02200730(obj->field1c);
    return func_ov031_02200ccc();
}
