#include <globaldefs.h>

struct Sub8_021f6d80 {
	char unk[0xa];
	unsigned short lower7 : 7;
	unsigned short field4 : 4;
	unsigned short upper5 : 5;
};

struct Obj_021f6d80 {
	char unk[0x8];
	struct Sub8_021f6d80* sub;
	char unk2[0x8];
	float x;
	float y;
	float sx;
	float sy;
};

// USA: func_ov024_021f6d80
ARM int ScaleVectorBy1_25IfField4Is11_021f6d80(struct Obj_021f6d80* obj) {
	struct Sub8_021f6d80* sub = obj->sub;
	if (sub && sub->field4 == 0xb) {
		obj->sx = obj->x * 1.25f;
		obj->sy = obj->y * 1.25f;
	}
	return 1;
}
