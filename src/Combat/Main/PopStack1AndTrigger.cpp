#include <globaldefs.h>

extern "C" void func_020a1940(int);
extern volatile unsigned char data_02109da4[2];
extern signed char data_02109da6[];
extern signed char data_020f1977[];

// USA: func_020a1f4c
ARM void PopStack1AndTrigger(int flag) {
    if (data_02109da4[1] == 0) return;
    data_02109da4[1]--;
    if (flag == 0 || data_02109da4[1] == 0) return;
    signed char i = data_02109da6[data_02109da4[1] - 1];
    func_020a1940(data_020f1977[i]);
}
