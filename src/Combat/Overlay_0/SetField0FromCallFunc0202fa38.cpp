#include <globaldefs.h>

int GetData02104304Field4();
int CallFunc0202fa38Mode2(int a, int b, int c, int d);

extern int data_ov000_02183fcc;
extern int data_ov000_02183fe0;

struct Struct0216fd0c {
	int field0;
};

// USA: func_ov000_0216fd0c
ARM void SetField0FromCallFunc0202fa38(struct Struct0216fd0c* obj) {
	obj->field0 = CallFunc0202fa38Mode2(GetData02104304Field4(), (int)&data_ov000_02183fcc, (int)&data_ov000_02183fe0, 0);
}
