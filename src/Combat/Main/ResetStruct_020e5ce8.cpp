#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct Struct_020401e4;
extern "C" void _Z13Reset020404acP15Struct_020401e4(struct Struct_020401e4* obj);

extern struct Struct_020401e4 data_021077dc;

// USA: func_020e5ce8
extern "C" __declspec(initcode) ARM void ResetStruct_020e5ce8(void) {
    _Z13Reset020404acP15Struct_020401e4(&data_021077dc);
}
