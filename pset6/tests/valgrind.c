// Test memory leak with Valgrind
// Alexandre Nobuharu Sato e Edson Sato, Ribeirão Pires, 2021/04/30
#include <stdlib.h>

typedef struct StructNode
{
    int x, y, z;
    struct StructNode* son;
}StructNode;


void
main(void)
{
    StructNode *Test = NULL;
    Test = (struct StructNode*) malloc(sizeof(struct StructNode));
    free(Test);
}