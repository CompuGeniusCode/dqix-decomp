#include <globaldefs.h>

struct Entry02157368 {
	short id;
	char pad[0x16];
};

struct Container02157368 {
	char pad0[0x8];
	Entry02157368* entries;
	char pad1[0x14-0xc];
	unsigned short count;
};

Entry02157368* FindEntryById02157368(Container02157368* c, short id) {
	Entry02157368* entries = c->entries;
	if (entries == NULL) {
		return NULL;
	}
	unsigned short count = c->count;
	if (count == 0) {
		return NULL;
	}
	for (unsigned short i = 0; i < count; i++) {
		short v = entries[i].id;
		if (v == id) {
			return &entries[i];
		}
	}
	return NULL;
}
