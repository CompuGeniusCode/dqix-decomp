#include <globaldefs.h>

struct Obj020dbf70;
void ReleaseHandle020dbf70(struct Obj020dbf70* o);
extern "C" int func_02057924(void);
extern "C" void func_02057f00(int a, int b);

struct BattleTask020dbedc {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
};

// USA: func_020dbedc
ARM void UpdateTaskState020dbedc(struct BattleTask020dbedc* a) {
    int s = a->f10;
    if (s == 1) {
        ReleaseHandle020dbf70((struct Obj020dbf70*)a);
        return;
    }
    if (s != 2) return;
    func_02057f00(func_02057924(), a->f8);
    a->f10 = 0;
}
