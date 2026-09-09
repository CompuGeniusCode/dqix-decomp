#include <globaldefs.h>
#include "std_library_functions.h"

extern char strCharaP_021ef778[];
extern char strCharaP_021ef781[];
extern char strChara_021ef78a[];
extern char strDataPackLv5CharaPcGp2_021ef791[];
extern char strCharaMp[];
extern char strCharaMp_021ef7b5[];
extern char strDataPackLv5CharaMpGp2_021ef7be[];

// Maps a "chara/..." reference onto the pack that holds it: "chara/p_" resolves to
// data/pack_lv5/chara_pc.gp2 and "chara/mp" to data/pack_lv5/chara_mp.gp2, with the member name
// being whatever follows "chara/". The mp members also sit loose in data/chara as mp0200be.chr and
// twelve siblings; the p_ ones ship only inside chara_pc.gp2. The backslash spellings are searched
// for and the result thrown away, so a path written with backslashes never resolves; that is what
// the ROM does, not a slip in this source.
extern "C" ARM int ResolveCharaArchiveForPath(char* s, char* out2, char* out1) {
    char* m = strstr(s, strCharaP_021ef778);
    if (!m) {
        strstr(s, strCharaP_021ef781);
    }
    if (m) {
        strcpy(out1, m + strlen(strChara_021ef78a));
        strcpy(out2, strDataPackLv5CharaPcGp2_021ef791);
        return 1;
    }
    m = strstr(s, strCharaMp);
    if (!m) {
        strstr(s, strCharaMp_021ef7b5);
    }
    if (!m) return 0;
    strcpy(out1, m + strlen(strChara_021ef78a));
    strcpy(out2, strDataPackLv5CharaMpGp2_021ef7be);
    return 1;
}
