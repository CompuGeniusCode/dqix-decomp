#include <globaldefs.h>

extern "C" void* _Z15GetBattleStructv();
int GetData02104304Field4();
extern "C" {
    int func_0202fdd0(int a, int b);
    void func_020301c8(int a, int b);
}
extern "C" void* func_02012fe4(void);
extern "C" void* func_0205ec34(void);
extern "C" void func_0206461c(void* a, int b);
int CallFunc0202fa38ZeroPad(int a, int b, int c);
extern int data_ov017_021d7c3c;

struct List0202fe68;
int LookupListValueByKey(struct List0202fe68* obj, int key);

struct Entry021b8c84 {
    unsigned char pad0;
    unsigned char flag;
    unsigned char pad1[6];
    int key;
};

// USA: func_ov017_021b8c84
ARM void ApplyOrAdvanceListEntry_021b8c84(struct Entry021b8c84* obj) {
    _Z15GetBattleStructv();
    int listPtr = GetData02104304Field4();
    if (obj->key == -1) {
        obj->key = CallFunc0202fa38ZeroPad(listPtr, (int)&data_ov017_021d7c3c, 0);
        return;
    }
    if (!func_0202fdd0(listPtr, obj->key)) return;
    if (LookupListValueByKey((struct List0202fe68*)listPtr, obj->key) == 2) {
        void* a = func_0205ec34();
        func_0206461c(a, *(int*)((char*)func_02012fe4() + 8));
    }
    func_020301c8(listPtr, obj->key);
    obj->key = -1;
    obj->flag = 1;
}
