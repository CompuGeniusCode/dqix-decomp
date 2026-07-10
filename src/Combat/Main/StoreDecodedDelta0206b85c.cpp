#include <globaldefs.h>

extern "C" void func_020696bc(int a, int* out, int c);
int GetWordFromTable02042648(int idx);

// USA: func_0206b85c
ARM int StoreDecodedDelta0206b85c(int input, int* target, int c) {
    int val;
    func_020696bc(input, &val, 1);
    *target = val - (GetWordFromTable02042648(c) + 1);
    return 0;
}
