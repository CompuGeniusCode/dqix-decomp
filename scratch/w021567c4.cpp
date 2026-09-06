#include <globaldefs.h>

extern "C" void* _Z15GetBattleStructv();
extern "C" void* func_ov017_0218b5b0(void);
extern "C" void* _Z25GetCombatantAtField0x397cP12BattleStruct(void* battle);
extern "C" void* _Z15GetFieldIfFlag4Pc(void* battle);
extern "C" void func_ov001_02154da0(void);
extern "C" void _Z15SetBothCountersPvii(void* obj, int a, int b);
extern "C" void _Z17SetField0x238TruePv(void* p);
extern "C" void _Z22ApplyVecFromField0x246Pc(void* p);
extern "C" void func_0209c2e0(void* a, void* b, int c);
extern "C" void _Z31ClearMultipleFieldBits_02156b20v(void* obj);
extern "C" void func_ov017_021bb27c(void* obj);

extern char data_02109bf4;

struct S021567c4 { char pad0; char flag1; char pad[0x8]; unsigned short fieldA; char pad2[0x94 - 0xc]; void* field94; };

// USA: func_ov001_021567c4
ARM unsigned short func_ov001_021567c4(struct S021567c4* obj) {
	void* battle = _Z15GetBattleStructv();
	void* ov17 = func_ov017_0218b5b0();
	_Z25GetCombatantAtField0x397cP12BattleStruct(battle);
	void* field = _Z15GetFieldIfFlag4Pc(battle);
	struct S3719 { char pad0; char flag1; };
	unsigned char one = 1;
	char* tmp3000 = (char*)ov17 + 0x3000;
	struct S3719* p2 = *(struct S3719**)(tmp3000 + 0x718);
	p2->flag1 = one;
	func_ov001_02154da0();
	_Z15SetBothCountersPvii(ov17, 0, 0x1e);
	_Z17SetField0x238TruePv(field);
	_Z22ApplyVecFromField0x246Pc(field);
	func_0209c2e0(&data_02109bf4, obj->field94, 0);
	_Z31ClearMultipleFieldBits_02156b20v(obj);
	func_ov017_021bb27c(obj);
	obj->flag1 = 1;
	return obj->fieldA;
}
