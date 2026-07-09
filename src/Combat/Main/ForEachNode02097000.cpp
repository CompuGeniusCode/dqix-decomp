#include <globaldefs.h>

struct ForEachNode02097000Node { char pad[0x30]; };
struct ForEachNode02097000Container { unsigned short count; char pad[6]; struct ForEachNode02097000Node* nodes; };
typedef void (*ForEachNode02097000Func)(struct ForEachNode02097000Container*, struct ForEachNode02097000Node*);

// USA: func_02097000
ARM int ForEachNode02097000(struct ForEachNode02097000Container* c, ForEachNode02097000Func fn) {
    int n;
    struct ForEachNode02097000Node* p;
    int i;
    p = c->nodes;
    if (p == NULL || (n = c->count) == 0 || fn == NULL) return 0;
    for (i = 0; i < n; p++) {
        fn(c, p);
        i++;
    }
    return 1;
}
