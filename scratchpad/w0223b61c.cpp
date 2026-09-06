#include <globaldefs.h>
#include "Filesystem/NitroVM.h"
#include "Filesystem/FileAccessor.h"
#include "Filesystem/LowNitroHandle.h"

struct Inner0223b61c { unsigned char pad[0x84]; void* field84; };

extern "C" void func_020c9be0(void);
extern "C" void* func_ov031_0223cf4c(int size, int align);
extern "C" int func_ov031_0223bfa0(int);
extern "C" int func_ov031_0223b744(const char* path, void* defaultAllocDesc, int flag);
extern "C" void func_020ca7e8(const void* src, void* dst);
extern "C" void func_ov031_0223cf70(void* p);

extern Inner0223b61c* data_ov031_02290d24;
extern void* data_ov031_0224c56c;

// USA: func_ov031_0223b61c
#pragma optimize_for_size off
ARM void* LoadFileWithFallback_0223b61c(const char* path, unsigned int* outSize, int fallback) {
	func_ov031_0223bfa0((int)data_ov031_02290d24->field84);

	NitroVM machine;
	NitroVM_Initialize(&machine);
	if (!NitroVM_PrepareReadFileByPath(&machine, path)) {
		func_020c9be0();
	}

	unsigned int size = machine.regbase_abc.c.u32 - machine.regbase_abc.b.u32;
	if (outSize != NULL) {
		*outSize = size;
	}

	int allocFlag = (func_ov031_0223b744(path, &data_ov031_0224c56c, 2) != 0) ? -4 : fallback;

	void* buffer = func_ov031_0223cf4c(size, allocFlag);
	NitroVM_ReadSync(&machine, buffer, size);
	NitroVM_FinishRead(&machine);
	if (allocFlag > 0) {
		return buffer;
	}

	unsigned int decompSize = *(unsigned int*)buffer >> 8;
	if (outSize != NULL) {
		*outSize = decompSize;
	}
	void* newBuffer = func_ov031_0223cf4c(decompSize, fallback);
	func_020ca7e8(buffer, newBuffer);
	func_ov031_0223cf70(&buffer);
	return newBuffer;
}
