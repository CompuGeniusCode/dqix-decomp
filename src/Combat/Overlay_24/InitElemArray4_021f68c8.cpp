#include <globaldefs.h>

struct FieldSetTarget_021f6820;
void SetFields_021f6820(struct FieldSetTarget_021f6820*, short, char, char);

struct Elem_021f68c8 {
	short f0;
	char f2;
	char f3;
	float f4;
	char pad[4];
};

// USA: func_ov024_021f68c8
ARM void InitElemArray4_021f68c8(struct Elem_021f68c8* arr) {
	for (int i = 0; i < 4; i++) {
		SetFields_021f6820((struct FieldSetTarget_021f6820*)&arr[i], 0, -1, 0);
		arr[i].f4 = -1.0f;
	}
}
