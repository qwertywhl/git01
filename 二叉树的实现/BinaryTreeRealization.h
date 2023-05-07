#pragma once
#include<iostream>
#include<stack>
#include<queue>
#define MaxSize 20
using namespace std;

typedef struct Node {
	char data;
	struct Node* lchild;//左孩子结点
	struct Node* rchild;//右孩子结点
}BTNode;

void InitNode(BTNode*& b) {//初始化根结点
	b = (BTNode*)malloc(sizeof(BTNode));
	b->lchild = b->rchild = NULL;
}

void DestroyBTree(BTNode*& b) {//销毁二叉树
	if (b != NULL) {
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}

void CreateChar(char* str) {//输入括号输入法表示的二叉树
	char ch;
	int i = 0;
	while (cin >> ch) {
		*(str + i) = ch;
		i++;
	}
}

void CreateBTree(BTNode*& b,char *str) {//创建二叉树（链式结构存储）
	BTNode* st[MaxSize],*p;				//定义结点数组，用于存储每一个根结点
	int j = 0, k = 0, top = -1;	//k=1表示将结点p作为栈顶结点的左孩子；k=2将结点p作为栈顶结点的右孩子
	char ch;
	ch = str[j];
	b = NULL;
	if (ch == '\0') return;				//若数组为空，退出程序
	p = (BTNode*)malloc(sizeof(BTNode));
	p->lchild = p->rchild = NULL;
	p->data = ch;
	while (ch != '\0') {				
		switch (ch) {
		case '(': {						//左括号表示下一个节点为左孩子结点
			top++; k = 1; 
			st[top] = p; break;//将结点p进栈
		}
		case ')': {			//右括号表示当前子树完毕
			top--; break;	//将结点p出栈
		}
		case ',': {			//逗号表示下一个结点为右孩子
			k = 2; break;
		}
		default: {
			p = (BTNode*)malloc(sizeof(BTNode));
			p->lchild = p->rchild = NULL;
			p->data = ch;
			if (b == NULL) {//b为空时，表示此时p为根节点
				b = p;
			}
			else{
				switch (k) {//将左孩子右孩子与根节点链接起来
				case 1: {
					st[top]->lchild = p; break;
				}
				case 2: {
					st[top]->rchild = p; break;
				}
				}
			}
		}
		}
		j++;
		ch = str[j];
	}
}

void PreOrder(BTNode*& b) {//先序遍历二叉树（非递归）根结点，左子树，右子树
	stack<BTNode*> st;		//结构体指针类型栈
	BTNode* p;
	if (b == NULL) { cout << "二叉树为空!" << endl; return; }//若二叉树为空，退出程序
	else {
		st.push(b);			//将根结点进栈
		while (!st.empty()) {
			p = st.top();
			st.pop();
			cout << p->data << " ";//输出根结点
			if (p->rchild != NULL) {//将右子树先进栈以避免后续找不到右孩子结点
				st.push(p->rchild);
			}
			if (p->lchild != NULL) {//左子树进栈
				st.push(p->lchild);
			}
		}
		cout << endl;
	}
}

void PreOrder2(BTNode*& b) {//先序遍历非递归算法2
	BTNode* p;			
	stack<BTNode*> st;	//栈存放遍历到的结点
	p = b;
	while (!st.empty() || p != NULL) {	
		while (p != NULL) {		//访问结点p并移动到其左孩子
			cout << p->data << " ";//输出当前访问结点
			st.push(p);			//将结点和左孩子进栈
			p = p->lchild;
		}
		if (!st.empty()) {	//若栈不空，移动到右孩子
			p = st.top();
			st.pop();
			p = p->rchild;
		}
	}
	cout << endl;
}

void InOrder(BTNode*& b) {//中序遍历二叉树（非递归）左子树，根结点，右子树
	BTNode* p;
	stack<BTNode*> st;		//栈保存结点
	p = b;
	while (!st.empty() || p != NULL) {
		while (p != NULL) {	//访问结点p及其所有左下结点并进栈
			st.push(p);
			p = p->lchild;	//移动到左结点
		}
		if (!st.empty()) {	
			p = st.top();
			st.pop();
			cout << p->data << " ";//出栈并输出
			p = p->rchild;		//转向处理右子树
		}
	}
	cout << endl;
}

void PostOrder(BTNode*& b) {//后序遍历二叉树（非递归）左子树，右子树，根结点
	BTNode* p, * r;
	stack<BTNode*> st;
	bool flag;		//标志位，标记是否可以开始处理栈顶结点
	p = b;
	do {
		while (p != NULL) {
			st.push(p);		//将p及其所有左子树进栈
			p = p->lchild;
		}
		r = NULL;			//r指向刚访问的结点，初始时为空
		flag = true;		//flag表示正在处理栈顶结点
		while (!st.empty() && flag) {
			p = st.top();
			if (p->rchild == r) {	//若当前节点右子树为刚刚访问过的结点，表示进行第三步遍历根结点
				cout << p->data << " ";
				st.pop();			//出栈
				r = p;
			}
			else {
				p = p->rchild;		//若不是，继续处理右子树
				flag = false;
			}
		}
	} while (!st.empty());	//栈空结束
	cout << endl;
}

void LevelOrder(BTNode*& b) {//层次遍历二叉树
	BTNode* p;
	queue<BTNode*> qu;		//队列
	qu.push(b);
	while (!qu.empty()) {
		p = qu.front();		//取队首元素
		qu.pop();
		cout << p->data << " ";
		if (p->lchild != NULL) qu.push(p->lchild);//左孩子进队
		if (p->rchild != NULL) qu.push(p->rchild);//右孩子进队
	}
}

BTNode* CreateBT1(char* pre, char* in, int n) {//先序序列和中序序列构造二叉树
	BTNode* b;
	char* p;
	int k;
	if (n <= 0) return NULL;
	b = (BTNode*)malloc(sizeof(BTNode));//创建二叉树节点b
	b->data = *pre;						
	for (p = in; p > in + n; p++) {//在中序序列中找到根结点位置
		if (*p == *pre) break;
	}
	k = p - in;								//确定根结点在中序序列中的位置
	b->lchild = CreateBT1(pre + 1, in, k);//递归构造左子树
	b->rchild = CreateBT1(pre + k + 1, p + 1, n - k - 1);//递归构造右子树
	return b;
}

BTNode* CreateBT2(char* post, char* in, int n) {//后序序列和中序序列构造二叉树
	BTNode* b;
	char r, * p;
	int k;
	if (n <= 0) return NULL;
	r = *(post + n - 1);
	b = (BTNode*)malloc(sizeof(BTNode));//创建二叉树节点b
	b->data = r;
	for (p = in; p < in + n; p++) {
		if (*p == r) break;
	}
	k = p - in;							//确定根结点在中序序列中的位置
	b->lchild = CreateBT2(post, in, k);//递归构造左子树
	b->rchild = CreateBT2(post + k, p + 1, n - k - 1);//递归构造右子树
}