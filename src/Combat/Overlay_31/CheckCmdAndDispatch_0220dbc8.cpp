#include <globaldefs.h>

struct CmdCheckStruct_0220dbc8 {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    unsigned short f6;
};

extern int data_ov031_0224e53c;

extern "C" void func_ov031_0220da1c(int);
extern "C" void func_ov031_0220db6c(void);

// USA: func_ov031_0220dbc8
ARM void CheckCmdAndDispatch_0220dbc8(struct CmdCheckStruct_0220dbc8 *s) {
    if (s->f2 == 8 && s->f4 == 0x16 && s->f6 == 0x25) {
        int val = *(int*)((char*)data_ov031_0224e53c + 0x2260) - 8;
        switch (val) {
            case 0:
                func_ov031_0220da1c(0xc);
                break;
            case 1:
            case 4:
                func_ov031_0220db6c();
                break;
            case 2:
                func_ov031_0220da1c(0xc);
                break;
            case 3:
                break;
        }
    }
}
