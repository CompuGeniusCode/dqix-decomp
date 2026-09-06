#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern int data_02108760;
extern int data_02109bf4;
void ShutdownAndReinit0205e92c(void* obj);
void ResetAndReinit0209c278(void* obj);
int Dispatch0203a974With0xA2000(void* ctx);
int Dispatch0203a974With0x57000(void* ctx);
void SetupContextForMode0205ea20(void* objRaw, int mode);

// USA: func_ov001_02163a5c
ARM int SelectModeAndDispatch_02163a5c(void* self) {
    int cond = func_ov017_021d60f4(self);
    if (cond != 0) {
        ShutdownAndReinit0205e92c(&data_02108760);
        ResetAndReinit0209c278(&data_02109bf4);
        Dispatch0203a974With0xA2000(&data_02109bf4);
    } else {
        ResetAndReinit0209c278(&data_02109bf4);
        Dispatch0203a974With0x57000(&data_02109bf4);
        SetupContextForMode0205ea20(&data_02108760, 0x64);
    }
    return 1;
}
