#include <globaldefs.h>

struct Entry02080fa8 { int value; };
struct List0207f6ac { struct Entry02080fa8* entries; short count; };
struct Container02080fa8 { char pad[4]; struct List0207f6ac list; };
void SetEntryFirstField02080fa8(struct Container02080fa8* obj, int id, int value);

struct Wrapper02168088 { char pad[0x10]; struct Container02080fa8* c; };

// USA: func_ov003_02168088
ARM void SetEntryFieldsForRange_02168088(struct Wrapper02168088* obj, int* arr) {
	struct Container02080fa8* c;
	short id;
	unsigned char i;
	if (!arr) return;
	c = obj->c;
	id = 0x13;
	for (i = 0; i < 0xc; i++) {
		SetEntryFirstField02080fa8(c, id, arr[i]);
		id++;
	}
}
