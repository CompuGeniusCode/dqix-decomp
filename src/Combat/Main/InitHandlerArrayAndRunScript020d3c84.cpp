#include <globaldefs.h>
#include "std_library_functions.h"

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, int*);

struct HandlerSlotArray020d3c84 {
    unsigned char entries[0xb4];
    int count;
};
extern struct HandlerSlotArray020d3c84* data_021142c4;
extern int data_020f22d0;

// USA: func_020d3c84
ARM void InitHandlerArrayAndRunScript020d3c84(struct HandlerSlotArray020d3c84* arr, struct StreamHeader* buffer, int length) {
    char local[0x430];
    memset(arr, 0, 0xb4);
    arr->count = 0;
    data_021142c4 = arr;
    ResetFieldsReturnTrue((struct ResetStruct*)local);
    func_0203066c((struct ResetStruct*)local, &data_020f22d0);
    InitBufferReader((struct StreamState*)local, buffer, length);
    RunLoopIfValid02030774((struct Struct02030774*)local);
}
