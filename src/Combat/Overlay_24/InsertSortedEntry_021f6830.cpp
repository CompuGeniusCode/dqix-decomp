#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry_021f6830 { int pad0; float value; int pad2; };

// USA: func_ov024_021f6830  (semantic: InsertSortedEntry_021f6830)
extern "C" ARM void func_ov024_021f6830(struct Entry_021f6830* arr, struct Entry_021f6830* newItem) {
	if (newItem->value < arr[3].value) return;
	int i;
	for (i = 0; i < 4; i++) {
		if (newItem->value > arr[i].value) {
			int k;
			for (k = 2; k >= i; k--) {
				memcpy(&arr[i + 1], &arr[i], 0xc);
			}
			memcpy(&arr[i], newItem, 0xc);
			return;
		}
	}
}
