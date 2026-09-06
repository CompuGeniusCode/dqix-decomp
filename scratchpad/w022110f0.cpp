#include <globaldefs.h>

extern "C" int func_ov031_022113c0(void);
void SetGlobal0224e598IfNotNine_02211864(int a, int b);

struct StateObj02211440 {
    int field0;
    void* field4;
    char pad[0x34];
    void (*field3c)(void*);
};
extern StateObj02211440* data_ov031_0224e590;

// USA: func_ov031_022110f0
ARM void RegisterField3cCallback_022110f0(void (*a0)(void*)) {
    if (data_ov031_0224e590 == NULL || func_ov031_022113c0() != 0) {
        SetGlobal0224e598IfNotNine_02211864(9, 9 - 0xb);
        return;
    }
    data_ov031_0224e590->field3c = a0;
}
