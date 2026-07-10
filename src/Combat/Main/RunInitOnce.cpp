#include <globaldefs.h>

extern int data_02111738;
extern "C" void func_020ccdc4(int arg);

// USA: func_020cc730
ARM void RunInitOnce(int arg) {
    if (data_02111738 != 0) {
        return;
    }
    data_02111738 = 1;
    func_020ccdc4(arg);
}
