#include <globaldefs.h>

struct Elem02153744 {
	short key;
	char pad0[0x10 - 0x2];
	unsigned int field10;
	char pad1[0x20 - 0x14];
};

struct List02153744;

extern "C" Elem02153744* func_02071d60(List02153744* list, int key);

struct KeyFlags02153744 {
	short key;
	unsigned short bit0 : 1;
	unsigned short bit1 : 1;
	unsigned short rest : 14;
};

// USA: func_ov006_02153744
ARM void ApplyFlagsToEntries02153744(void* unused, List02153744* list, KeyFlags02153744* arr, int count) {
	for (int i = 0; i < count; i++, arr++) {
		Elem02153744* e = func_02071d60(list, arr->key);
		if (e == NULL) {
			continue;
		}
		int val = (arr->bit0 || arr->bit1) ? 1 : 0;
		unsigned int f = e->field10;
		unsigned int shifted = ((unsigned int)val << 31) >> 9;
		e->field10 = (f & ~0x400000) | shifted;
	}
}
