#include <globaldefs.h>

unsigned short GetTableValue(void* obj);
extern "C" double func_0200b074(int);
extern "C" double func_0200b0f0(double, double);

struct Obj_021f729c { void* ptr0; char pad[0x18]; float sx; float sy; };

// USA: func_ov024_021f729c  (semantic: ComputeScaledSizeVec_021f729c)
extern "C" ARM int func_ov024_021f729c(struct Obj_021f729c* obj) {
	int v = GetTableValue(obj->ptr0) * 2;
	if (v < 0x23) v = 0x23;
	obj->sx = (float)v;
	obj->sy = (float)func_0200b0f0(0.85, func_0200b074(v));
	return 1;
}
