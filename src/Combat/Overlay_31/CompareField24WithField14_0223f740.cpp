#include <globaldefs.h>

struct Struct022412e8;
int GetField24_022412e8(Struct022412e8*, int*);

struct Obj0223f740 {
	char pad[0x14];
	int field14;
};

// USA: func_ov031_0223f740
ARM int CompareField24WithField14_0223f740(Struct022412e8* self, Obj0223f740* other) {
	int local;
	int result = GetField24_022412e8(self, &local);
	return result == other->field14;
}
