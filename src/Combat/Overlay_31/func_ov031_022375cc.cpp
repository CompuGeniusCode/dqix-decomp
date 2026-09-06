#include <globaldefs.h>

struct BattleCtx020d5340;
int SubmitBattleContextEntry020d5340(int a0, struct BattleCtx020d5340* ctx);
extern char* data_ov031_02290d0c;
extern "C" void func_ov031_022376fc(void);

// USA: func_ov031_022375cc  (semantic: SubmitContextEntry884_022375cc)
extern "C" ARM int func_ov031_022375cc(void) {
	int r = SubmitBattleContextEntry020d5340((int)func_ov031_022376fc, (struct BattleCtx020d5340*)(data_ov031_02290d0c + 0x374 + 0x1000));
	return r == 2;
}
