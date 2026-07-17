#include <globaldefs.h>

extern "C" void func_ov031_0223ba20(void*);
extern void* data_ov031_02250bf0;

// USA: func_ov031_022238cc
ARM void ClearNonNullElems_022238cc(void) {
	int i = 0;
	do {
		void* elem = ((void**)data_ov031_02250bf0)[i];
		if (elem != 0) {
			func_ov031_0223ba20(elem);
			((void**)data_ov031_02250bf0)[i] = 0;
		}
		i++;
	} while (i < 4);
}
