#include <globaldefs.h>
#include "System/Interrupts.h"

extern "C" int FastIntModulus(int, int);
extern "C" void func_020c9be0(void);

struct Struct0223bf48 {
	unsigned short field0;
	unsigned char field2;
	unsigned char volatile field3;
	int arr[64];
};

// USA: func_ov031_0223bf48  (semantic: StoreEntryAndAdvance_0223bf48)
extern "C" ARM void func_ov031_0223bf48(struct Struct0223bf48* p, int value) {
	unsigned int state = DisableSpecificInterrupts(1);
	int rem = FastIntModulus(p->field3 + 1, p->field0);
	if (rem == p->field2) {
		func_020c9be0();
	}
	p->arr[p->field3] = value;
	p->field3 = rem;
	EnableSpecificInterrupts(state);
}
