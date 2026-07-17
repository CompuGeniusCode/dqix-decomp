#include <globaldefs.h>

struct SubObj_022053a0 {
	char pad0[0x68];
	void* field68;
	char pad1[4];
	unsigned short field70;
	char pad2[1];
	signed char field73;
};

void SetField164_02203164(int v);
extern "C" void func_ov031_0220603c(void);

void CopyField164_02203270(void* obj);
void InitSessionFields_0220321c(void);
void ResetSessionState02203190(void);
void SetField38IfPresent_02203288(int value);

// USA: func_ov031_022053a0
ARM int RunSessionCase_022053a0(void* obj) {
	SubObj_022053a0* sub = *(SubObj_022053a0**)((char*)obj + 4);
	SetField164_02203164((int)sub);
	void* base = sub->field68;
	switch (sub->field73) {
		case 0:
		case 4:
			CopyField164_02203270((char*)base + 0x20);
			InitSessionFields_0220321c();
			break;
		case 1:
			InitSessionFields_0220321c();
			ResetSessionState02203190();
			SetField38IfPresent_02203288((int)func_ov031_0220603c);
			break;
		case 2:
			ResetSessionState02203190();
			break;
		default:
			break;
	}
	sub->field70 = 1;
	return 0;
}
