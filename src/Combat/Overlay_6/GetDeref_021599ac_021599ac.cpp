#include <globaldefs.h>

// USA: func_ov006_021599ac
ARM int GetDeref_021599ac_021599ac(void** p) {
	void* q = *p;
	return q != NULL ? *(unsigned short*)q : 0;
}
