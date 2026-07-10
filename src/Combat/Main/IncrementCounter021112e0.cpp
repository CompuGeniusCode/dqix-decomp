#include <globaldefs.h>

struct Mgr021112e0 {
    char pad0[0x20];
    int counter;   /* 0x20 */
};
extern struct Mgr021112e0 data_021112e0;

// USA: func_020c71a4
ARM int IncrementCounter021112e0(void) {
    return ++data_021112e0.counter;
}
