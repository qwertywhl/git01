#include"BinaryTreeRealization.h"
int main() {
	BTNode* root;
	char str[MaxSize] = {};
	cout << "请输入二叉树：" << endl;
	CreateChar(str);	//括号表示法输入二叉树
	CreateBTree(root, str);//将二叉树用链式存储结构存储
	cout << "先序遍历二叉树：" << endl;
	PreOrder(root);		//先序遍历二叉树
	cout << "中序遍历二叉树：" << endl;
	InOrder(root);		//中序遍历二叉树
	cout << "后序遍历二叉树：" << endl;
	PostOrder(root);		//后序遍历二叉树
	cout << "层次遍历二叉树：" << endl;
	LevelOrder(root);		//层次遍历二叉树
	DestroyBTree(root); //销毁二叉树
}