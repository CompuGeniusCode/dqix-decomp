#include <globaldefs.h>
void BuildAndIssueTransformMatrix(void*);
void BuildAndIssueRotationMatrixY(int);
void BuildAndIssueRotationMatrixX(int);

struct Obj02036024 {
    unsigned char pad[0x50];
    void* field50;
    void* field54;
    void* field58;
};


// USA: func_02036024
ARM void ProcessOptionalPtrFields02036024(struct Obj02036024* obj) {
    if (obj->field58 != NULL) BuildAndIssueTransformMatrix((void*)(obj->field58));
    if (obj->field54 != NULL) BuildAndIssueRotationMatrixY((int)(obj->field54));
    if (obj->field50 != NULL) BuildAndIssueRotationMatrixX((int)(obj->field50));
}
