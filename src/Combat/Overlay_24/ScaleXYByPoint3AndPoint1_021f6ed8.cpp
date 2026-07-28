#include <globaldefs.h>

struct FloatXYScale_021f6ed8 { char pad[0x14]; float x; float y; float outX; float outY; };

// USA: func_ov024_021f6ed8  (semantic: ScaleXYByPoint3AndPoint1_021f6ed8)
extern "C" ARM int func_ov024_021f6ed8(struct FloatXYScale_021f6ed8* obj) {
	obj->outX = obj->x * 0.3f;
	obj->outY = obj->y * 0.1f;
	return 1;
}
