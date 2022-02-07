#include "stackli.h"
#include "fatal.h"

struct Node {
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S) { return S->Next == NULL; }

Stack CreateStack()
{
    Stack S = malloc(sizeof(struct Node));
    if (S == NULL) {
        Error("out of memory space");
    }
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void MakeEmpty(Stack S)
{
    if (S == NULL) {
        Error("create stack first");
    } else {
        while (!IsEmpty(S)) {
            Pop(S);
        }
    }
}

void DisposeStack(Stack S)
{
    MakeEmpty(S);
    free(S);
}

void Push(ElementType X, Stack S)
{
    PtrToNode Cell = malloc(sizeof(struct Node));
    if (Cell == NULL) {
        Error("out of space");
    } else {
        Cell->Element = X;
        Cell->Next = S->Next;
        S->Next = Cell;
    }
}

int Top(Stack S, ElementType* Data)
{
    if (!IsEmpty(S)) {
        *Data = S->Next->Element;
        return 0;
    }
    Error("empty stack");
    return 1;
}

void Pop(Stack S)
{
    if (IsEmpty(S)) {
        Error("empty stack");
    } else {
        PtrToNode Cell = S->Next;
        S->Next = S->Next->Next;
        free(Cell);
    }
}
