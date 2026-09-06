#include <globaldefs.h>
extern "C" void LoadToMainBG1CharacterData(int, int, unsigned int);
extern "C" void LoadToSubBG0CharacterData(int, int, unsigned int);

extern void* data_020fe9a4;

// USA: func_020290ac
ARM void FlushOrClearBuffer020290ac(int flag) {
    if (data_020fe9a4 == NULL) return;
    if (flag == 0) {
        LoadToMainBG1CharacterData((int)(data_020fe9a4), (int)(0), (unsigned int)(0x6000));
    } else {
        LoadToSubBG0CharacterData((int)(data_020fe9a4), (int)(0), (unsigned int)(0x6000));
    }
}
