#include <globaldefs.h>
#include "System/Memory.h"

struct Allocator022496a4_02206e0c {
	char pad[0x18];
	void* (*alloc)(unsigned int size);
	void (*free)(void*);
};
extern Allocator022496a4_02206e0c* data_ov031_022496a4;

extern "C" void* func_ov031_02204c84(void* obj);
void SetField164_02203164(int v);
void ClearField164_02203178(void);

struct RingBufferDesc02206e0c {
	char pad0[0x3c];
	int field3c;
	void* field40;
	char pad1[4];
	int field48;
	void* field4c;
	char pad2[0x14];
};

#pragma optimize_for_size off
// USA: func_ov031_02206e0c
extern "C" ARM void* func_ov031_02206e0c(void* obj) {
	if (obj == 0) return 0;

	void* buf = data_ov031_022496a4->alloc(0xfd0);
	if (buf == 0) return 0;

	RingBufferDesc02206e0c desc;
	VectorizedMemset(&desc, 0, 0x64);
	char* ringStart = (char*)buf + 0x368;
	desc.field40 = buf;
	desc.field3c = 0xb68;
	desc.field4c = ringStart + 0x800;
	desc.field48 = 0x466;
	SetField164_02203164((int)&desc);

	void* result = func_ov031_02204c84(obj);
	ClearField164_02203178();
	data_ov031_022496a4->free(buf);
	return result;
}
