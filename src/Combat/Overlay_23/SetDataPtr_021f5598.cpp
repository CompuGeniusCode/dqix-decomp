#include <globaldefs.h>

struct Data021fff08 {
    char pad[0x4];
    void *ptr;
};

extern struct Data021fff08 data_ov023_021fff08;

// USA: func_ov023_021f5598
ARM void SetDataPtr_021f5598(void *value) {
    data_ov023_021fff08.ptr = value;
}
