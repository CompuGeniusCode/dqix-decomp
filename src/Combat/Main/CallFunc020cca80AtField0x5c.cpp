#include <globaldefs.h>

struct Action020cca80;
void *SetupEffectType8(struct Action020cca80 *);

// USA: func_020c00b8
ARM void *CallFunc020cca80AtField0x5c(void *obj) {
    return SetupEffectType8((struct Action020cca80 *)((char *)obj + 0x5c));
}
