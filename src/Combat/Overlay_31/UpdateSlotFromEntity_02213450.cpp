#include <globaldefs.h>

struct Slot02213450 {
	unsigned char pad0[9];
	unsigned char field9;
	unsigned char pad1[0xa];
	unsigned char field14;
	unsigned char field15;
	unsigned char field16;
};

struct Entity02213450 {
	unsigned char pad[0xd0d];
	unsigned char fieldd0d;
	unsigned char pad2[5];
	unsigned char fieldd13;
};

void* GetFieldPtrByMask_022133f8(unsigned int mask);
extern "C" unsigned int NormalizeIndex_022135ac(unsigned int);

// USA: func_ov031_02213450
ARM void UpdateSlotFromEntity_02213450(unsigned char v) {
	struct Slot02213450* p = (struct Slot02213450*)GetFieldPtrByMask_022133f8(1);
	struct Entity02213450* e = (struct Entity02213450*)GetFieldPtrByMask_022133f8(0x10);
	p->field9 = v;
	if (v >= 0x10) return;
	if (v <= p->field16) return;
	p->field16 = v;
	if (v <= 7) return;
	unsigned int idx = NormalizeIndex_022135ac(e->fieldd0d);
	p->field15 = idx;
	unsigned char e13 = e->fieldd13;
	p->field14 = *((unsigned char*)e + e13 * 4 + 0x444);
}
