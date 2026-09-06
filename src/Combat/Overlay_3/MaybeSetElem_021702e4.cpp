#include <globaldefs.h>

struct Obj0216dee4;
void SetElemFields0216dee4(struct Obj0216dee4* obj, int idx, int v14, int v18, int v22, int v25, int v26);

struct S021702e4 {
	char pad0[0x1];
	signed char field1;
	char pad1[0xc - 0x2];
	signed short field0c;
	char pad2[0x68 - 0xe];
};

// USA: func_ov003_021702e4
ARM void MaybeSetElem_021702e4(struct S021702e4* self) {
	signed char flag = self->field1;
	if (flag == 0)
		return;
	if (flag == 1)
		return;
	short v = self->field0c;
	int a = 7, b = 4;
	if (v == 5) {
		a = 6;
		b = 3;
	}
	SetElemFields0216dee4((struct Obj0216dee4*)((char*)self + 0x68), a, 0xcc, 0xb, -1, b, 3);
}
