#include"BinaryTree.h"
int main() {
	char str[MaxSize] = "";
	cout << "请输入用括号表示法表示的二叉树：" << endl;
	CreateChar(str);	//输入二叉树
	BTNode* b;
	CreateNode(b, str); //将括号表示法表示的二叉树用链式结构存储
	cout << "后序遍历二叉树为：" << endl;
	PostNode(b);		//后序遍历二叉树
	DestroyNode(b);		//销毁二叉树
}