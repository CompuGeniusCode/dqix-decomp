#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry02207d88 {
	const char* name;
};

struct SearchList02207d88 {
	char pad[0x814];
	Entry02207d88** items;
	int count;
};

// USA: func_ov031_02207d88
ARM void* FindByName_02207d88(SearchList02207d88* list, const char* name) {
	int i = 0;
	Entry02207d88** items;
	int count = list->count;
	if (count <= 0) goto notfound;
	items = list->items;
	for (; i < count; i++) {
		Entry02207d88* e = items[i];
		if (strcmp(e->name, name) == 0) {
			return e;
		}
	}
notfound:
	return NULL;
}
