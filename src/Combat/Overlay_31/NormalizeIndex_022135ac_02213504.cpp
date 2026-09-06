#include <globaldefs.h>

void InvalidateDataCacheRange(const void* addr, unsigned int size);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);
ARM unsigned int NormalizeIndex_022135ac(unsigned int idx);
ARM void CopyBufferIfMatch_02215778(int a, void* b);
extern "C" void* func_ov031_0220f084(int a);

struct NameObj02213504 {
	unsigned char pad0[0x17];
	unsigned char field17;
	char name[0xa];
	unsigned char field22;
};

struct GlobalRef0224e5c4 {
	unsigned char pad0[0xc];
	NameObj02213504* obj;
};

extern GlobalRef0224e5c4 data_ov031_0224e5c4;

// USA: func_ov031_02213504
extern "C" ARM void func_ov031_02213504(unsigned int idx) {
	NameObj02213504* obj = data_ov031_0224e5c4.obj;
	unsigned int norm = obj->field22;
	if (norm == 0) {
		norm = NormalizeIndex_022135ac(idx);
	}

	obj = data_ov031_0224e5c4.obj;
	obj->field17 = norm;
	void* p = func_ov031_0220f084(0);
	if (p != NULL) {
		InvalidateDataCacheRange(p, 0x20);
		obj = data_ov031_0224e5c4.obj;
		CopyBufferIfMatch_02215778((int)p, obj->name);
	}

	int i = 0;
	char* cur = (char*)data_ov031_0224e5c4.obj;
	NameObj02213504* base = data_ov031_0224e5c4.obj;
	do {
		signed char c = *(cur + 0x18);
		if (c < 0x20 || c > 0x7e) {
			VectorizedMemset(base->name, 0, 0xa);
			return;
		}
		i++;
		cur++;
	} while (i < 0xa);
}
