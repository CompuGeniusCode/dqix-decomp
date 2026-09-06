#include <globaldefs.h>

struct Struct021931b4 { char pad[0x1a8]; int arr[32]; int count; };

// USA: func_ov015_021931b4
ARM void PushArrayValue021931b4(struct Struct021931b4* s, int v) {
	s->arr[s->count++] = v;
}
