#include <globaldefs.h>

struct Rect02042c54 {
    int left;
    int top;
    int right;
    int bottom;
};

// USA: func_02042c54
ARM void SetRect02042c54(struct Rect02042c54* rect, int left, int top, int right, int bottom) {
    rect->left = left;
    rect->top = top;
    rect->right = right;
    rect->bottom = bottom;
}
