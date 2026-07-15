#include <globaldefs.h>

struct Obj02205194;
extern int GetField64OrField68_02205194(Obj02205194* obj);
extern "C" int func_ov031_0220520c(int v, void* extra);

// USA: func_ov031_0220529c
ARM int GetField64OrField68Then0220520c_0220529c(Obj02205194* obj, void* extra) {
	int v = GetField64OrField68_02205194(obj);
	return func_ov031_0220520c(v, extra);
}
