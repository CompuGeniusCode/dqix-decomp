#include <globaldefs.h>

extern char data_021112ec;

// USA: _Z21GetGlobalWord021112ecv
ARM int GetGlobalWord021112ec(void) {
    return *(int*)(&data_021112ec);
}
