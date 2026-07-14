#include <globaldefs.h>

extern "C" void func_020c9be0(void);
extern "C" void func_020a1940(int);
extern volatile unsigned char data_02109da4;
extern signed char data_020f1962[];
extern volatile signed char data_02109dae[];

// USA: func_020a1df8
ARM void PushInputLogA(int id) {
    if (data_02109da4 >= 8) func_020c9be0();
    if ((unsigned int)id >= 7) return;
    func_020a1940(data_020f1962[id]);
    data_02109dae[data_02109da4] = id;
    data_02109da4++;
}
