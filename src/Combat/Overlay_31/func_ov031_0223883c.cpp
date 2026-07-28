#include <globaldefs.h>
#include "Filesystem/NitroVM.h"
#include "Filesystem/FileAccessor.h"
#include "Filesystem/LowNitroHandle.h"

struct Req0223883c { char* path; };

extern void* data_ov031_02290d14;
int ComputeReadAheadSize_021d9e1c(NitroVM* vm);
extern "C" int func_ov027_021d9e9c(NitroVM* vm, void* val, unsigned int size);
extern "C" int func_ov027_021da38c(Req0223883c* req, void* val);

#pragma optimize_for_size off
// USA: func_ov031_0223883c
extern "C" ARM int func_ov031_0223883c(Req0223883c* req) {
	NitroVM vm;
	NitroVM* vmPtr;
	int result = 0;

	if (req->path == NULL) {
		vmPtr = NULL;
	} else {
		NitroVM_Initialize(&vm);
		if (!NitroVM_PrepareReadFileByPath(&vm, req->path)) {
			return result;
		}
		vmPtr = &vm;
	}

	if (ComputeReadAheadSize_021d9e1c(vmPtr) != 0) {
		*(void**)((char*)data_ov031_02290d14 + 0x1b000 + 0x144) = (char*)data_ov031_02290d14 + 0x2c;
		void* val = *(void**)((char*)data_ov031_02290d14 + 0x1b000 + 0x144);
		if (val != NULL) {
			if (func_ov027_021d9e9c(vmPtr, val, 0x10000) != 0) {
				if (func_ov027_021da38c(req, *(void**)((char*)data_ov031_02290d14 + 0x1b000 + 0x144)) != 0) {
					result = 1;
				}
			}
		}
	}

	if (vmPtr == &vm) {
		NitroVM_FinishRead(&vm);
	}
	return result;
}
