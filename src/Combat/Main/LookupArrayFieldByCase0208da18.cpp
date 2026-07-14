#include <globaldefs.h>

struct Elem0208d994 {
    short h0;
    int w4;
    int w8;
    int wc;
    int w10;
    int w14;
};

struct List0208d994 {
    struct Elem0208d994* base;
    short count;
};

struct Elem0208d994* FindElementByKey0208d994(struct List0208d994* l, int key);

// USA: func_0208da18
ARM int LookupArrayFieldByCase0208da18(struct List0208d994* list, int key, int caseIdx) {
    int result;
    struct Elem0208d994* e;
    int* arr;
    result = 0;
    e = FindElementByKey0208d994(list, key);
    if (e != NULL) {
    switch (caseIdx) {
        case 1:
            arr = (int*)e->wc;
            result = arr[0];
            break;
        case 2:
            arr = (int*)e->wc;
            result = arr[1];
            break;
        case 3:
            arr = (int*)e->wc;
            result = arr[2];
            break;
        case 4:
            arr = (int*)e->wc;
            result = arr[3];
            break;
        case 5:
            arr = (int*)e->wc;
            result = arr[4];
            break;
        case 6:
            arr = (int*)e->wc;
            result = arr[5];
            break;
        case 7:
            arr = (int*)e->wc;
            result = arr[6];
            break;
        case 8:
            arr = (int*)e->wc;
            result = arr[7];
            break;
        default:
            break;
    }
    }
    return result;
}
