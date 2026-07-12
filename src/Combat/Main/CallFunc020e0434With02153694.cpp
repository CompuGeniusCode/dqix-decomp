#include <globaldefs.h>
int GetFieldByKey020e0434(struct Container020e0310 *, int);

extern int data_02153694;

// USA: func_020e51cc
ARM int CallFunc020e0434With02153694(int value) {
    return GetFieldByKey020e0434((struct Container020e0310 *)(&data_02153694), (int)(value));
}
