#pragma once
#ifndef _Tree_H
#include <iostream>
typedef class TreeNode *Position;
typedef class TreeNode *SearchTree;

class TreeNode {
private:
	int Element;
	SearchTree Left;
	SearchTree Right;
public:
	SearchTree MakeEmpty(SearchTree T);
	Position Find(int X, SearchTree T);
	Position FindMin(SearchTree T);
	Position FindMax(SearchTree T);
	SearchTree Insert(int X, SearchTree T);
	SearchTree Delete(int X, SearchTree T);
	int Retrieve(Position P);
};

#endif