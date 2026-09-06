#include <globaldefs.h>

struct Node02187520 {
	struct Node02187520* next;
};

struct S02187520 {
	unsigned char pad0[0xb8];
	struct Node02187520* head;
	struct Node02187520* target;
};

// USA: func_ov014_02187520
ARM short FindIndexDiv16_02187520(struct S02187520* s) {
	struct Node02187520* n = s->head;
	short i = 0;
	while (n != NULL) {
		if (n == s->target) return i / 16;
		n = n->next;
		i++;
	}
	return -1;
}
