#include <globaldefs.h>
#include "std_library_functions.h"

// Clears the twelve-byte noun descriptor the message system formats a name through: two string
// pointers and a word of packed 6-bit article codes. func_020e46fc, func_020e4810 and func_020e47bc
// add 100, 200 and 300 to those codes and look them up in data_021536ac, which
// LoadStandardStringAndArticleTables fills from data/prm/article.gp2, and func_020e462c then writes
// the article, a space unless it ends in "<1>", and the noun. func_020e4bf4 opens with this same
// clear before filling one in from a combatant; func_ov004_02167b78 clears one and gives it two
// 0x80-byte name buffers.
extern "C" ARM void* ResetArticleContext(void* p) {
    return memset(p, 0, 0xc);
}
