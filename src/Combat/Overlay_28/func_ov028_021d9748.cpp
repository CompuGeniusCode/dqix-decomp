#include <globaldefs.h>

struct Obj021d9b14_9748 {
    char pad[0xa8];
    unsigned long long ts;
};

extern struct Obj021d9b14_9748 data_ov028_021d9b14;

// USA: func_ov028_021d9748
extern "C" ARM unsigned long long func_ov028_021d9748() {
    return (data_ov028_021d9b14.ts << 6) / 0x82ea;
}
