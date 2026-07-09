#include <globaldefs.h>

struct PairEntry0209a93c {
    unsigned short a;
    unsigned short b;
};
struct PairContainer0209a93c {
    struct PairEntry0209a93c entries[0x42];
    int count;
};
struct PairHolder0209a93c {
    struct PairContainer0209a93c* container;
};

// USA: func_0209a93c
ARM void AppendPairCapped0209a93c(struct PairHolder0209a93c* holder, struct PairEntry0209a93c* src) {
    struct PairContainer0209a93c* c = holder->container;
    int n;
    if (c == NULL) {
        return;
    }
    n = c->count;
    if (n >= 0x42) {
        return;
    }
    c->count = n + 1;
    {
        struct PairEntry0209a93c* dst = &holder->container->entries[n];
        dst->a = src->a;
        dst->b = src->b;
    }
}
