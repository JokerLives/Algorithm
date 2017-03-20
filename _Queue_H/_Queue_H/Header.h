#pragma once
#ifndef _Queue_H

class Node;
typedef class Node* PtrToNode;
typedef PtrToNode Queue;

class Node {
private:
	int  Element;
	int size;
	PtrToNode Next;
public:
	int IsEmpty(Queue Q);
	Queue CreateQueue(void);
	void DisposeQueue(Queue Q);
	void MakeEmpty(Queue Q);
	void Enqueue(int X, Queue Q);
	void Dequeue(Queue Q);
	int Front(Queue Q);
	int FrontAndDequeue(Queue Q);
};

#endif /_Queue_H