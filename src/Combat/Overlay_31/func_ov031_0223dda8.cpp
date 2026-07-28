#include <globaldefs.h>

int ResetVramBanks02111226();
int ResetVramBanks02111228();
int ClearDispcntBit30AndResetVramBanks();
int ClearDispcntBit31AndResetVramBanks();
int ResetVramBanks0211122c();
int func_020c4a70();
int func_020c4a84();
int func_020c4ac0();
int ProcessFlagWord02111238();
int DisableSubBgExtPalette020c4ae8(void);
int DisableSubObjExtPalette020c4b10(void);
int func_020c4a98(void);
int func_020c4aac(void);
void SetVramBankFlag020c44e4(int flag);
extern "C" void func_ov031_0223df4c(void);

struct VramFields0223dda8 {
	int field0;
	int field4;
	int field8;
	int fieldC;
	int field10;
	int field14;
	int field18;
	int field1c;
	int field20;
	int field24;
	int field28;
	int field2c;
	int field30;
};
extern VramFields0223dda8 data_ov031_02290d68;

// USA: func_ov031_0223dda8  (semantic: InitVramBankFieldsAndClear_0223dda8)
extern "C" ARM void func_ov031_0223dda8(void) {
	data_ov031_02290d68.field0 = ResetVramBanks02111226();
	data_ov031_02290d68.field4 = ResetVramBanks02111228();
	data_ov031_02290d68.field8 = ClearDispcntBit30AndResetVramBanks();
	data_ov031_02290d68.fieldC = ClearDispcntBit31AndResetVramBanks();
	data_ov031_02290d68.field10 = ResetVramBanks0211122c();
	data_ov031_02290d68.field14 = func_020c4a70();
	data_ov031_02290d68.field18 = func_020c4a84();
	data_ov031_02290d68.field1c = func_020c4ac0();
	data_ov031_02290d68.field20 = ProcessFlagWord02111238();
	data_ov031_02290d68.field24 = DisableSubBgExtPalette020c4ae8();
	data_ov031_02290d68.field28 = DisableSubObjExtPalette020c4b10();
	data_ov031_02290d68.field2c = func_020c4a98();
	data_ov031_02290d68.field30 = func_020c4aac();

	SetVramBankFlag020c44e4(data_ov031_02290d68.field2c);
	func_ov031_0223df4c();
}
