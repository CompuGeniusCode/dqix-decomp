#include <globaldefs.h>

short FindMappedMemberId02080468(void* obj, int id);

// USA: func_ov003_02178548  (semantic: UpdateMappedIndexAndRemainder_02178548)
extern "C" ARM void func_ov003_02178548(unsigned char* self) {
	void* obj89c = *(void**)(self + 0x89c);
	short id1 = FindMappedMemberId02080468(obj89c, 3);
	short base6 = *(short*)(self + 0x1006);
	int diff = base6 - id1;
	short mult = *(short*)(self + 0x1014);
	short idx = (short)(mult * 6 + diff);

	unsigned char byteVal = *(unsigned char*)(self + 0x835);
	if ((int)byteVal <= (int)idx) {
		idx = (short)(byteVal - 1);
	}

	short v = *(short*)(self + 0x800 + idx * 2 + 0x48);
	*(short*)(self + 0x1000 + 0x3a) = v;

	short id2 = FindMappedMemberId02080468(obj89c, 3);
	int rem = idx % 6;
	*(short*)(self + 0x1000 + 6) = (short)(rem + id2);
}
