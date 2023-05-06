#pragma once
#include<iostream>
#include<stack>
#define MaxSize 20
using namespace std;

typedef struct Node {
	char data;
	struct Node* lchild;//左孩子域
	struct Node* rchild;//右孩子域
}BTNode;

void CreateChar(char* str) {//输入二叉树
	char ch;
	int i = 0;
	while (cin >> ch) {
		*(str + i) = ch;
		i++;
	}
	*(str + i) = '\0';
}

void CreateNode(BTNode*& root, char* str) {//创建二叉树
	BTNode* St[MaxSize], * p;			//首先定义结点数组，用来存放每一个根结点
	int top = -1, j = 0, k = 0;			
	char ch;							//ch用于存放数组中元素
	root = NULL;							//二叉树初始时为空
	ch = str[j];
	if (ch == '\0') {					//若数组为空，退出程序
		return;
	}
	p = (BTNode*)malloc(sizeof(BTNode));//首先将数组首结点初始化为二叉树结点
	p->data = ch;
	p->lchild = p->rchild = NULL;		//左孩子右孩子均为空
	while (ch != '\0') {				//数组遍历完毕
		switch (ch) {
		case '(': {						//左括号代表上一个元素为根结点，将其存放在结点数组中
			top++; k = 1; St[top] = p; break;//k=1表示括号后可能为左孩子结点
		}
		case ')': {						//右括号代表本结点左孩子右孩子完毕，需要返回到上一个结点
			top--; break;
		}
		case ',': {						//逗号表示下一个元素可能为右孩子结点
			k = 2; break;				
		}
		default: {						//当元素不为上述时
			if (root == NULL) {
				root = p;
			}
			else {						//b不为空时
				p = (BTNode*)malloc(sizeof(BTNode));
				p->data = ch;
				p->lchild = p->rchild = NULL;
				switch (k) {			//设置其左孩子节点和右孩子结点
				case 1: {
					St[top]->lchild = p; break;//左孩子
				}
				case 2: {
					St[top]->rchild = p; break;//右孩子
				}
				}
			}
		}
		}
		j++;
		ch = str[j];//ch遍历下一个元素
	}
}

void DestroyNode(BTNode*& b) {//销毁二叉树
	if (b != NULL) {
		DestroyNode(b->lchild);
		DestroyNode(b->rchild);
		free(b);
	}
}

void PostNode(BTNode* root) {//后序遍历二叉树
	BTNode* p, * r;
	int flag;			//flag用于判断是否可以开始处理栈顶结点,2
	stack<BTNode*> s;	//设置栈用于存放二叉树结点
	p = root;
	do {
		while (p != NULL) {//从左孩子结点开始，将根结点及其后面的所有左孩子结点进栈
			s.push(p);
			p = p->lchild;//p指向左孩子结点
		}
		r = NULL;
		flag = 2;		//遍历到叶子，可以开始处理栈顶元素
		while (!s.empty() && flag==2) {//栈不为空且flag==2
			p = s.top();	//将栈顶元素取出给p
			if (p->rchild == r) {	//若右孩子结点为r，输出当前结点元素
				cout << p->data << " ";
				s.pop();	//出栈顶元素
				r = p;		//r指向刚访问过得结点
			}
			else {
				p = p->rchild;
				flag = 1;//表示当前不是处理栈顶结点
			}
		}
	} while (!s.empty());//栈空时退出循环
	cout << endl;
}