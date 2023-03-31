#pragma once
#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LinkNode;

void CreateNode(LinkNode*& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));//新建链表
	LinkNode* s, * p = L;
	int n,m;
	cout << "请输入集合项数：" << endl;
	cin >> n;
	cout << "请输入集合元素（不能重复）:" << endl;
	for (int i = 0; i < n; i++) {			//for循环中输入集合元素
		cin >> m;
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = m;
		s->next = NULL;
		p->next = s;
		p = p->next;
	}
}

void DestroyNode(LinkNode* L) {				//销毁链表
	free(L);
}

void CommonNode(LinkNode*& L1, LinkNode*& L2) {
	LinkNode* p = L1->next, * q = L2->next, * s,*pre=L1;
	while (p != NULL && q != NULL) {
		if (p->data < q->data) {
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else if (p->data > q->data) {
			p = p->next;
			pre = pre->next;
		}
		else {
			p = p->next;
			q = q->next;
			pre = pre->next;
		}
	}
}
void DispNode(LinkNode* L) {
	LinkNode* p = L->next;
	if (p->next == NULL) {
		cout << "交集为：NULL" << endl;
		exit(0);
	}
	cout << "交集为：" << endl;
	cout << "{";
	while (p != NULL) {
		cout << p->data ;
		if (p->next != NULL) cout << ",";
		p = p->next;
	}
	cout <<"}"<< endl;
}