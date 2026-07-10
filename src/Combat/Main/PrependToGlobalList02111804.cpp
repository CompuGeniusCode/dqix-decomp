#include <globaldefs.h>

struct ListHeadCEE54;
struct NodeCEE54;
ARM void PrependNode(struct ListHeadCEE54*, struct NodeCEE54*);

extern int data_02111804;

// USA: func_020cef34
ARM void PrependToGlobalList02111804(struct NodeCEE54* node) {
    PrependNode((struct ListHeadCEE54*)&data_02111804, node);
}
