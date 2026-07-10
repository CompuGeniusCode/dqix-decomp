#include <globaldefs.h>

int CheckStateByType020d8a68(unsigned char* obj);

// USA: func_020d917c
ARM int CheckOwnerAndState020d917c(void** owner, unsigned char* obj) {
    return *owner != NULL && CheckStateByType020d8a68(obj) != 0;
}
