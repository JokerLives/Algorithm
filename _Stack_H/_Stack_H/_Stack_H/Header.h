#pragma once
#ifndef _Stack_H

class Node;
typedef  class Node* PtrToNode;
typedef PtrToNode Stack;

class Node {
private:
	int Element;
	PtrToNode Next;
public:
	int IsEmpty(Stack S);
	Stack CreateStack(void);
	void DisposeStack(Stack S);
	void MakeEmpty(Stack S);
	void Push(int X,Stack S);
	int Top(Stack S);
	void Pop(Stack S);
};

#endif //_Stack_H