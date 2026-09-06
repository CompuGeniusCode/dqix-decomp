#include <globaldefs.h>
#include "System/Memory.h"

typedef void* (*FetchFn0221883c)(void*, int);
typedef void (*NotifyFn0221883c)(void*, void*, int);

struct Cfg0221883c {
	unsigned char pad0[0x10];
	FetchFn0221883c fetch;
	NotifyFn0221883c notify;
};

struct StreamState0221883c {
	void* field0;
	int field4;
	int field8;
	int fieldc;
};

extern int data_ov031_02249f14;
extern int data_ov031_02249f00;

// USA: func_ov031_0221883c
extern "C" ARM int func_ov031_0221883c(void* obj, StreamState0221883c* b, int len) {
	Cfg0221883c* cfg = (Cfg0221883c*)((char*)obj + 0x1000);
	FetchFn0221883c fetch = cfg->fetch;
	NotifyFn0221883c notify = cfg->notify;
	if (len <= 0) return 0;

	void* r4 = fetch(&data_ov031_02249f14, b->fieldc + len);
	if (r4 == NULL) return 0;

	VectorizedInvertedMemcpy(b->field0, r4, (unsigned int)b->fieldc);
	notify(&data_ov031_02249f00, b->field0, 0);
	if (r4 == NULL) return 0;

	b->field4 = b->field4 + ((int)r4 - (int)b->field0);
	b->fieldc = b->fieldc + len;
	b->field0 = r4;
	b->field8 = (int)r4 + b->fieldc;
	return 1;
}
