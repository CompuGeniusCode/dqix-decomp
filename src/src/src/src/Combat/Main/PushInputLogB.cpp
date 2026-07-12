#include <globaldefs.h>

extern "C" void func_020c9be0(void);
extern "C" void func_020a1940(int);
extern volatile unsigned char data_02109da4[2];
extern signed char data_020f1977[];
extern volatile signed char data_02109da6[];

// USA: func_020a1ef0
ARM void PushInputLogB(int id) {
    if (data_02109da4[1] >= 8) func_020c9be0();
    if ((unsigned int)id >= 7) return;
    func_020a1940(data_020f1977[id]);
    data_02109da6[data_02109da4[1]] = id;
    data_02109da4[1]++;
}
