#include <globaldefs.h>

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
struct Struct02047230;
void MaybeInvoke0204719c(struct Struct02047230* obj);

struct Obj02155d38 {
	char pad0[4];
	struct Foo0207df50* f1;
	struct Struct02047230* f2;
	char pad2[0x18 - 0xc];
	short field18;
};

// USA: func_ov005_02155d38
ARM void RunTwoCallbacksAndReset02155d38(Obj02155d38* obj) {
	if (obj->f1) CopyInternalFields0207df50(obj->f1);
	if (obj->f2) MaybeInvoke0204719c(obj->f2);
	obj->field18 = -1;
}
