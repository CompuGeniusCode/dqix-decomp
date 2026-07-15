#include <globaldefs.h>

struct Struct02165800 {
    int counter;
};
extern struct Struct02165800 data_ov001_02165800;

// USA: func_ov001_021536e0
ARM int IncrementCounterBy1_021536e0(void) {
    data_ov001_02165800.counter += 1;
    return 1;
}
