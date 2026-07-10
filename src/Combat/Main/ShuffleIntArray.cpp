#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0203232c
ARM void ShuffleIntArray(int* arr, int count) {
    int i;
    for (i = 0; i < count / 2; i++) {
        int j = rand() % count;
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
