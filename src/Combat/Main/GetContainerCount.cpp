#include <globaldefs.h>

struct Container0209aa40 {
    char pad[0x108];
    int count;
};
struct Holder0209aa40 {
    struct Container0209aa40* container;
};

// USA: func_0209aa40
ARM int GetContainerCount0209aa40(struct Holder0209aa40* holder) {
    struct Container0209aa40* c = holder->container;
    if (c != NULL) {
        return c->count;
    }
    return 0;
}
