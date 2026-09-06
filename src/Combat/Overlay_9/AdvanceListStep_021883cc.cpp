#include <globaldefs.h>

extern "C" void* _Z15GetBattleStructv();
extern "C" int* _Z10GetWord0x0Pi(void* battle);
void SetBothCounters(void* obj, int value, int frames);
extern "C" int _Z28CheckField0x14Or0x20PositivePi(int* word);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(void* p, int flag);
extern "C" void ColorEffect_ConfigureBrightnessAdjust(unsigned short* dst, int flag, int value);
extern "C" void _Z20SetStatValue021855dcPhi(unsigned char *self, int val);

// USA: func_ov009_021883cc  (semantic: AdvanceListStep_021883cc)
extern "C" ARM void func_ov009_021883cc(unsigned char *self) {
    int* word = _Z10GetWord0x0Pi(_Z15GetBattleStructv());
    unsigned char flag = self[0xc59];
    if (flag == 0) {
        SetBothCounters(word, -16, 15);
        self[0xc59] = self[0xc59] + 1;
        return;
    }
    if (flag != 1) return;
    if (_Z28CheckField0x14Or0x20PositivePi(word) != 0) return;
    _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(self + 0x1f8, 1);
    _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(self + 0x2b4, 1);
    ColorEffect_ConfigureBrightnessAdjust((unsigned short*)0x04001050, 1, 0);
    _Z20SetStatValue021855dcPhi(self, 0xc);
}
