#include <globaldefs.h>

extern int data_02111754;
extern "C" int func_020cc3d0(void* ctx, int a, int b, int c);

// USA: func_020ccf5c
ARM int ForwardToFunc020cc3d0(int a, int b) {
    return func_020cc3d0(&data_02111754, a, b, a);
}
