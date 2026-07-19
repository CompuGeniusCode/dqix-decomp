#include <globaldefs.h>

struct Elem8_0223baa0 { int a, b; };
struct ElemArray_0223baa0 { int pad0, pad1; Elem8_0223baa0* arr; };

// USA: func_ov031_0223baa0
ARM Elem8_0223baa0* GetElemPtr_0223baa0(ElemArray_0223baa0* obj, int idx) {
	return &obj->arr[idx];
}
