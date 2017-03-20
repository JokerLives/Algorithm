#include"Header.h"
#include<iostream>

int Node::IsEmpty(Stack S) {
	return S->Next == NULL;
}

Stack Node::CreateStack(void) {
	Stack S;
	S = new class Node;
	if (S == NULL)
		std::cerr << "Out of Node" << std::endl;
	S->Next = NULL;
	return S;
}

void Node::MakeEmpty(Stack S) {
	if (S == NULL)
		std::cerr << "Must Use CreatStack First" << std::endl;
	else
		while (!IsEmpty(S))
			Pop(S);
}

void Node::Push(int X, Stack S) {
	PtrToNode TmpCell;

	TmpCell = new class Node;
	if (TmpCell == NULL)
		std::cerr << "Out of Space" << std::endl;
	else {
		TmpCell->Element = X;
		TmpCell->Next = NULL;
		while (S->Next != NULL)
			S = S->Next;
		S->Next = TmpCell;
	}
}

int Node::Top(Stack S) {
	if (!IsEmpty(S)) {
		while (S->Next != NULL)
			S = S->Next;
		return S->Element;
	}
	else std::cerr << "Empty Stack" << std::endl;
	return 0;
}

void Node::Pop(Stack S) {
	PtrToNode FirstCell;

	if (IsEmpty(S))
		std::cerr << "Empty Stack" << std::endl;
	else {
		while (S->Next != NULL)
			S = S->Next;
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}

