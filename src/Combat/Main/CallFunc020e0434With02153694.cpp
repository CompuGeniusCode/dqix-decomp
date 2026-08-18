#include <globaldefs.h>
int GetFieldByKey020e0434(struct Container020e0310 *, int);

extern int data_02153694;

// USA: _Z28CallFunc020e0434With02153694i
ARM int CallFunc020e0434With02153694(int value) {
    return GetFieldByKey020e0434((struct Container020e0310 *)(&data_02153694), (int)(value));
}
