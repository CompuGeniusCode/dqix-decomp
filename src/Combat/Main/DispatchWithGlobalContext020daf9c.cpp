#include <globaldefs.h>
void InitCombatantVisualState(void*, int, int, int, int);

extern int data_0214e4c8;

// USA: func_020daf9c
ARM void DispatchWithGlobalContext020daf9c(int a, int b, int c, int d) {
    InitCombatantVisualState((void*)(&data_0214e4c8), (int)(a), (int)(b), (int)(c), (int)(d));
}
