#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
ARM void GenCrc16Table(unsigned short* table, unsigned short poly);
ARM int Check_0221aff8_0221aff8(int v);
extern void* data_ov031_02290cfc;

// USA: func_ov031_02235c18
ARM void InitAndBuildCrcTable_02235c18(void) {
    void* p = func_ov031_0223cf4c(0x6f8, 0x20);
    data_ov031_02290cfc = p;
    char* sub = (char*)p + 0xf8;
    GenCrc16Table((unsigned short*)(sub + 0x400), 0xa001);
    Check_0221aff8_0221aff8((int)data_ov031_02290cfc);
}
