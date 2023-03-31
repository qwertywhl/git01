#pragma once
#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LinkNode;

void CreateNode(LinkNode*& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));//�½�����
	LinkNode* s, * p = L;
	int n,m;
	cout << "�����뼯��������" << endl;
	cin >> n;
	cout << "�����뼯��Ԫ�أ������ظ���:" << endl;
	for (int i = 0; i < n; i++) {			//forѭ�������뼯��Ԫ��
		cin >> m;
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = m;
		s->next = NULL;
		p->next = s;
		p = p->next;
	}
}

void DestroyNode(LinkNode* L) {				//��������
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
		cout << "����Ϊ��NULL" << endl;
		exit(0);
	}
	cout << "����Ϊ��" << endl;
	cout << "{";
	while (p != NULL) {
		cout << p->data ;
		if (p->next != NULL) cout << ",";
		p = p->next;
	}
	cout <<"}"<< endl;
}