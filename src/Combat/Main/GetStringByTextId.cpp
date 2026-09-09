#include <globaldefs.h>

struct Container020e0310;
extern "C" int func_020e0440(struct Container020e0310 *c, int key);

// Returns the text for one id out of a loaded string table. The tables are the ones built from the
// localized .nat archives -- data_02153694[0] from strstd_<LG>.nat and [1] from article_<LG>.nat --
// and per-object tables such as the one at +0x620 in ov013's message builder. The value is a char*:
// func_020e046c strcpy's it and ov013 hands it to the string appender. All the work is in
// func_020e0440, which binary-searches the table by the 16-bit id at the head of each 8-byte entry.
extern "C" ARM int GetStringByTextId(struct Container020e0310 *c, int key) {
    return func_020e0440(c, key);
}
