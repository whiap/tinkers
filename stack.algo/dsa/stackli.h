typedef int ElementType;

#ifndef _STACK_LI_H_
#define _STACK_LI_H_

struct Node;

typedef struct Node* PtrToNode;

typedef PtrToNode Stack;

int IsEmpty(Stack S);

Stack CreateStack(void);

void MakeEmpty(Stack S);

void DisposeStack(Stack S);

void Push(ElementType X, Stack S);

int Top(Stack S, ElementType* Data);

void Pop(Stack S);

#endif /* END */
