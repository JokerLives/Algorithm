#include"Header.h"
#include<iostream>

int Node::IsEmpty(Queue Q) {
	return Q->Next == NULL;
}

Queue Node::CreateQueue(void) {
	Queue Q;
	
	Q = new class Node;
	if (Q == NULL)
		std::cerr << "Out of Space" << std::endl;
	Q->Next = NULL;
	Q->size = 0;
	MakeEmpty(Q);
	return Q;
}

void Node::DisposeQueue(Queue Q) {
	Queue TmpCell;
	for (int i = 0;i < size;i++) {
		TmpCell = Q->Next;
		free(Q);
		Q = TmpCell;
	}
	free(Q);
}

void Node::MakeEmpty(Queue Q) {
	Queue TmpCell;

	if (!IsEmpty(Q))
		std::cerr << "It is Empty" << std::endl;
	else {
		Q->size = 0;
		Q = Q->Next;
		for (int i = 0;i < size-1;i++) {
			TmpCell = Q->Next;
			free(Q);
			Q = TmpCell;
		}
		free(Q);
	}
}

void Node::Enqueue(int X, Queue Q) {
	int size = Q->size;
	Q->size += 1;
	Queue TmpCell;

	TmpCell = new class Node;
	TmpCell->Element = X;
	for (int i = 0;i < size;i++) {
		Q = Q->Next;
	}
	Q->Next = TmpCell;
}
void Node::Dequeue(Queue Q) {
	int size = Q->size;
	Q->size -= 1;
	Queue TmpCell;
	if (!IsEmpty(Q)) {
		TmpCell = Q->Next;
		Q->Next = TmpCell->Next;
		free(TmpCell);
	}
	else
		std::cerr << "Queue is Empty" << std::endl;
}
int Node::Front(Queue Q) {
	if (!IsEmpty(Q))
		return Q->Next->Element;
	else
		std::cerr << "Queue is Empty" << std::endl;
}
int Node::FrontAndDequeue(Queue Q) {
	
}