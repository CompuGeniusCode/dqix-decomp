#include <globaldefs.h>

extern "C" void _Z25SetFields5cAnd5e_021f65b4PvS_tt(void* a, void* b, short v1, short v2);
extern char* data_ov004_0217101c;

// USA: func_ov004_02165ef4  (semantic: SetFieldFromDividedStat_02165ef4)
extern "C" ARM void func_ov004_02165ef4(void* a) {
    short field = *(short*)(data_ov004_0217101c + 0x4c);
    short v = (field + 7) / 8;
    _Z25SetFields5cAnd5e_021f65b4PvS_tt(a, (void*)0x5b, 0, v);
}
