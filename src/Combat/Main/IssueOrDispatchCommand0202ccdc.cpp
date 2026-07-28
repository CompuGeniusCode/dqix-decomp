#include <globaldefs.h>

extern "C" void _Z28SetField0x48UnlessState9Or10i(int slot);
extern "C" void _Z35TryIssueBattleCommandAndUpdateStatev(void);
extern "C" int _Z23IssueBattleCommandSlot9i(int callback);
extern "C" int _Z36DispatchField0x2OrSetState1_0202cd28Pt(unsigned short*);

struct S0202ccdc {
    char pad0[2];
    unsigned short f2;
};

// USA: func_0202ccdc  (semantic: IssueOrDispatchCommand0202ccdc)
extern "C" ARM void func_0202ccdc(struct S0202ccdc* obj) {
    if (obj->f2 != 0) {
        _Z28SetField0x48UnlessState9Or10i(obj->f2);
        _Z35TryIssueBattleCommandAndUpdateStatev();
        return;
    }
    int result = _Z23IssueBattleCommandSlot9i((int)_Z36DispatchField0x2OrSetState1_0202cd28Pt);
    int done;
    if (result == 2) {
        done = 1;
    } else {
        _Z28SetField0x48UnlessState9Or10i(result);
        done = 0;
    }
    if (done) return;
    _Z35TryIssueBattleCommandAndUpdateStatev();
}
