#include "header.h"

SearchTree TreeNode::MakeEmpty(SearchTree T) {
	if (T != NULL) {
		MakeEmpty(T->Right);
		MakeEmpty(T->Left);
		free(T);
	}
	return NULL;
}

Position TreeNode::Find(int X, SearchTree T) {
	if (T == NULL)
		return NULL;
	if (X < T->Element)
		return Find(X, T->Left);
	else if (X > T->Element)
		return Find(X, T->Right);
	else
		return T;
}

Position TreeNode::FindMin(SearchTree T) {
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return NULL;
	else 
		return FindMin(T->Left);
}

Position TreeNode::FindMax(SearchTree T) {
	if (T == NULL)
		return NULL;
	else if (T->Right == NULL)
		return NULL;
	else
		return FindMax(T->Right);
}

SearchTree TreeNode::Insert(int X, SearchTree T) {
	if (T == NULL) {
		T = new (class TreeNode);
		if (T == NULL)
			std::cerr << "Out of Space";
		else {
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->Element)
		T->Left = Insert(X, T->Left);
	else if (X > T->Element)
		T->Right = Insert(X, T->Right);
	return T;
}

SearchTree TreeNode::Delete(int X, SearchTree T) {
	Position TmpCell;
	if (T = NULL)
		std::cerr << "Element not Found";
	else if (X < T->Element)
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)
		T->Right = Delete(X, T->Right);
	else if (T->Left&&T->Right) {
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else {
		TmpCell = T;
		if (T->Left == NULL)
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		free(TmpCell);
	}
	return T;
}