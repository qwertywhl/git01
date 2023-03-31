#include"有序集合链表.h"
int main() {
	LinkNode* L1, * L2;
	CreateNode(L1);
	CreateNode(L2);
	CommonNode(L1, L2);
	DispNode(L1);
	DestroyNode(L1);
	DestroyNode(L2);
}