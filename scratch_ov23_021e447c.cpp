#include <globaldefs.h>

struct Words021e60c4 { unsigned int a, b, c; };
extern "C" void InitWordsQuad_021e60e0(void* obj, unsigned int val);
extern "C" void func_ov023_021e613c(struct Words021e60c4* dst, void* src);
extern "C" void SetFourWordBlocks_021e6088(void* obj, struct Words021e60c4* src);
extern "C" void func_ov023_021e6158(void* obj, int idx);

struct Obj_021e447c {
	char pad0[0x128];
	void* f128;
	void* f12c;
	char pad1[0x504];
	unsigned short f634;
};

// USA: func_ov023_021e447c
ARM void SwapAndSyncWordBlocks_021e447c(struct Obj_021e447c* obj) {
	if (!(obj->f634 & 8)) return;
	if (((unsigned char*)obj->f12c)[0xc12] != 0) return;
	if (obj->f634 & 0x40) {
		InitWordsQuad_021e60e0(obj->f128, 0x1eb);
		InitWordsQuad_021e60e0(obj->f12c, 0x1eb);
	} else {
		struct Words021e60c4 local;
		func_ov023_021e613c(&local, obj->f128);
		SetFourWordBlocks_021e6088(obj->f12c, &local);
	}
	void* tmp = obj->f128;
	obj->f128 = obj->f12c;
	obj->f12c = tmp;
	func_ov023_021e6158(obj->f12c, 0);
	func_ov023_021e6158(obj->f12c, 1);
	func_ov023_021e6158(obj->f12c, 5);
	func_ov023_021e6158(obj->f12c, 6);
	func_ov023_021e6158(obj->f12c, 2);
	func_ov023_021e6158(obj->f12c, 3);
	func_ov023_021e6158(obj->f12c, 4);
	obj->f634 &= ~8;
	obj->f634 &= ~0x40;
}
