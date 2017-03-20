#include "Header.h"
#include<iostream>
List Node::MakeEmpty(List L){

};

int Node::IsEmpty(List L) {
	return L->Next == NULL;
};

int Node::IsLast(Position P, List L) {
	return P->Next == NULL;
};

Position Node::Find(int X, List L) {
	Position P;
	P = L->Next;
	while (P != NULL&&P->Element != X)
		P = P->Next;

	return P;
};
void Node::Delete(int X, List L) {
	Position P, B, TmpCell;

	TmpCell = Find(X, L);
	P = TmpCell->Previous;

	if (!IsLast(P, L)) {
		B = TmpCell->Next;
		P->Next = TmpCell->Next;
		B->Previous = TmpCell->Previous;
		free(TmpCell);
	}
	else {
		P->Next = NULL;
		free(TmpCell);
	}
};
void Node::Insert(int X, List L, Position P) {
	Position TmpCell,B;
	B = P->Next;

	TmpCell=new class Node;
	if (TmpCell == NULL) {
		std::cerr << "Out of Space!" << std::endl;
	}
	
	TmpCell->Element = X;
	TmpCell->Next = B;
	P->Next = TmpCell;
	TmpCell->Previous = P;
	B->Previous = TmpCell;
};

void Node::DeleteList(List L) {
	Position P,Tmp;

	P = L->Next;
	L->Next = NULL;
	while (P != NULL) {
		Tmp = P->Next;
		free(Tmp);
		P = Tmp;
	}
};
Position Node::Header(List L) {};
Position Node::First(List L) {};
Position Node::Advance(Position P) {};
int Node::Retrieve(Position P) {};