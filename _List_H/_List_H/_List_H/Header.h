#pragma once
#ifndef _List_H

class Node;
typedef class Node* PtrToList;
typedef PtrToList List;
typedef PtrToList Position;

class Node {
public:
	int Element;
	Position Next;
	Position Previous;
	List MakeEmpty(List L);
	int IsEmpty(List L);
	int IsLast(Position P, List L);
	Position Find(int X, List L);
	void Delete(int X, List L);
	void Insert(int X, List L, Position P);
	void DeleteList(List L);
	Position Header(List L);
	Position First(List L);
	Position Advance(Position P);
	int Retrieve(Position P);
};

#endif; //_List_H