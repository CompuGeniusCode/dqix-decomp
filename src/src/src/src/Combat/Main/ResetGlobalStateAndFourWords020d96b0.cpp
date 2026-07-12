#include <globaldefs.h>

int GetGlobalWord021112ec(void);
extern "C" void func_020c745c();

struct FourWords;
void ClearFourWords(struct FourWords* p);
extern struct FourWords data_0214e4b0;

struct GlobalState0214e4a8 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char pad3;
    int field4;
};
extern GlobalState0214e4a8 data_0214e4a8;

// USA: func_020d96b0
ARM void ResetGlobalStateAndFourWords020d96b0(void) {
    if (GetGlobalWord021112ec() == 0) {
        func_020c745c();
    }
    ClearFourWords(&data_0214e4b0);
    data_0214e4a8.byte2 = 1;
    data_0214e4a8.byte0 = 1;
    data_0214e4a8.byte1 = 1;
    data_0214e4a8.field4 = 0;
}
