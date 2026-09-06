#include <globaldefs.h>

struct Element02070b0c {
    unsigned char data[0x84];
};

struct Container02070b0c {
    unsigned int count : 12;
    struct Element02070b0c *elements;
};

typedef void (*ElementCallback02070b0c)(struct Container02070b0c *, struct Element02070b0c *);

// USA: func_02070b0c
ARM int ForEachElement02070b0c(struct Container02070b0c *container, ElementCallback02070b0c callback) {
    int count;
    struct Element02070b0c *elem = container->elements;
    int i;
    if (elem == NULL) goto ret_zero;
    count = container->count;
    if (count != 0 && callback != NULL) goto run_loop;
ret_zero:
    return 0;
run_loop:
    i = 0;
    while (i < count) {
        callback(container, elem);
        i++;
        elem++;
    }
    return 1;
}
