#include <globaldefs.h>

extern "C" void GetFields1014_022274e4(int*, int*);
int Init_02222ce4(int);

// USA: func_ov031_02223568
#pragma optimize_for_size off
ARM int CallIfField14Is1_02223568(int a) {
	int v;
	GetFields1014_022274e4(NULL, &v);
	if (v != 1) return v;
	return Init_02222ce4(a);
}
