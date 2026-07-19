#include <globaldefs.h>

struct Struct022359e0;
struct BattleCtx020d5340;
int SubmitBattleContextEntry020d5340(int a0, struct BattleCtx020d5340* ctx);
extern char* data_ov031_02290cf8;
extern "C" void func_ov031_022359e0(void);

// USA: func_ov031_022358b4  (semantic: SubmitContextEntry1648_022358b4)
extern "C" ARM int func_ov031_022358b4(struct Struct022359e0* obj) {
	int r = SubmitBattleContextEntry020d5340((int)func_ov031_022359e0, (struct BattleCtx020d5340*)(data_ov031_02290cf8 + 0x248 + 0x1400));
	return r == 2;
}
