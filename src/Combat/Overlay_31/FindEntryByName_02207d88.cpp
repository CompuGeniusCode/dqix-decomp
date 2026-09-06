#include <globaldefs.h>
#include "std_library_functions.h"

struct NamedEntry02207d88 {
	const char* name;
};

struct SearchList02207d88 {
	char pad[0x814];
	NamedEntry02207d88** items;
	int count;
};

// USA: func_ov031_02207d88  (semantic: FindEntryByName_02207d88)
extern "C" ARM NamedEntry02207d88* func_ov031_02207d88(SearchList02207d88* obj, const char* key) {
	int i = 0;
	NamedEntry02207d88** items;
	int count = obj->count;
	if (count > 0) {
		items = obj->items;
		do {
			NamedEntry02207d88* e = items[i];
			if (strcmp(e->name, key) == 0) {
				return e;
			}
			i++;
		} while (i < count);
	}
	return 0;
}
