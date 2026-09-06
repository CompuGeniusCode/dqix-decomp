#include <globaldefs.h>

struct Obj02205194;
extern int GetField64OrField68_02205194(Obj02205194* obj);
extern "C" int func_ov031_022051a8(int v, void* extra);

// USA: func_ov031_022051f4
ARM int GetField64OrField68Then022051a8_022051f4(Obj02205194* obj, void* extra) {
	int v = GetField64OrField68_02205194(obj);
	return func_ov031_022051a8(v, extra);
}
