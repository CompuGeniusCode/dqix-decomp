#include <globaldefs.h>

struct Flags_021ed7e0 {
	unsigned int fieldA : 10;
	unsigned int fieldB : 1;
	unsigned int fieldC : 7;
	unsigned int fieldD : 7;
	unsigned int rest : 7;
};

// USA: func_ov023_021ed7e0
ARM void ClearFlagBits10to24_021ed7e0(struct Flags_021ed7e0* s) {
	s->fieldA = 0;
	s->fieldB = 0;
	s->fieldC = 0;
	s->fieldD = 0;
}
