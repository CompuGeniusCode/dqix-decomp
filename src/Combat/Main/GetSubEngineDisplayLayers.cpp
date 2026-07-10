#include <globaldefs.h>

// USA: func_020dc008
ARM int GetSubEngineDisplayLayers() {
    return (*(unsigned int*)0x4001000 & 0x1f00) >> 8;
}
