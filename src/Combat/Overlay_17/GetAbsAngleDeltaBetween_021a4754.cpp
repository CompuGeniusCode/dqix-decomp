#include <globaldefs.h>

struct Vec3 { int x, y, z; };
short GetAngleDeltaBetween_021a4700(struct Vec3* p0, int baseAngle, struct Vec3* p2);
extern "C" int _Z8fix32absi(int x);

// USA: func_ov017_021a4754
ARM short GetAbsAngleDeltaBetween_021a4754(struct Vec3* p0, int baseAngle, struct Vec3* p2) {
	return (short)_Z8fix32absi(GetAngleDeltaBetween_021a4700(p0, baseAngle, p2));
}
