#include <globaldefs.h>

int GetData02104304Field4();
int CallFunc0202fa38ZeroPad(int a, int b, int c);

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

struct StreamHeader;
void InitAndRunScriptIfValid02097ac0(void* param0, void* param1, struct StreamHeader* param2, int param3);

extern "C" {
    int func_0202fdd0(int a, int b);
    void func_020301c8(int a, int b);
}

extern int data_020f14ec;

struct Obj02097a04 {
    char pad0[0x18];
    int f18;
    unsigned char f1c;
    unsigned char f1d;
};

// USA: func_02097a04  (semantic: TryRunPendingScript02097a04)
extern "C" ARM int func_02097a04(struct Obj02097a04* obj) {
    int listPtr = GetData02104304Field4();
    unsigned char f1c = obj->f1c;
    if (f1c == 0) {
        obj->f18 = CallFunc0202fa38ZeroPad(listPtr, (int)&data_020f14ec, 0);
        obj->f1c = obj->f1c + 1;
        goto ret0;
    }
    if (f1c != 1 || !func_0202fdd0(listPtr, obj->f18)) {
        goto ret0;
    }
    {
        int out1, out2;
        GetListEntryValues0202fec8((struct List0202fec8*)listPtr, obj->f18, &out1, &out2);
        if (out1 != 0) {
            InitAndRunScriptIfValid02097ac0(obj, (void*)obj->f1d, (struct StreamHeader*)out1, out2);
        }
    }
    func_020301c8(listPtr, obj->f18);
    obj->f18 = -1;
    obj->f1c = 0;
    return 1;
ret0:
    return 0;
}
