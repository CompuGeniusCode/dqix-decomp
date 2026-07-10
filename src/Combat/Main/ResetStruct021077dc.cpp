#include <globaldefs.h>

struct Struct_020401e4;
ARM void* Reset020404ac(struct Struct_020401e4* obj);

extern int data_021077dc;

// USA: func_020e5ce8
ARM void* ResetStruct021077dc(void) {
    return Reset020404ac((struct Struct_020401e4*)&data_021077dc);
}
