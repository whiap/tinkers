#include "stackli.h"
#include <stdio.h>

int main()
{
    Stack S = CreateStack();
    for (int i = 0; i < 10; i++) {
        Push(i, S);
    }

    while (!IsEmpty(S)) {
        ElementType Data;
        Top(S, &Data);
        printf("%d\n", Data);
        Pop(S);
    }
    DisposeStack(S);
    return 0;
}
