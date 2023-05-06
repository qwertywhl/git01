#pragma once
#include<iostream>
#include<stack>
#define MaxSize 20
using namespace std;

typedef struct Node {
	char data;
	struct Node* lchild;//������
	struct Node* rchild;//�Һ�����
}BTNode;

void CreateChar(char* str) {//���������
	char ch;
	int i = 0;
	while (cin >> ch) {
		*(str + i) = ch;
		i++;
	}
	*(str + i) = '\0';
}

void CreateNode(BTNode*& root, char* str) {//����������
	BTNode* St[MaxSize], * p;			//���ȶ��������飬�������ÿһ�������
	int top = -1, j = 0, k = 0;			
	char ch;							//ch���ڴ��������Ԫ��
	root = NULL;							//��������ʼʱΪ��
	ch = str[j];
	if (ch == '\0') {					//������Ϊ�գ��˳�����
		return;
	}
	p = (BTNode*)malloc(sizeof(BTNode));//���Ƚ������׽���ʼ��Ϊ���������
	p->data = ch;
	p->lchild = p->rchild = NULL;		//�����Һ��Ӿ�Ϊ��
	while (ch != '\0') {				//����������
		switch (ch) {
		case '(': {						//�����Ŵ�����һ��Ԫ��Ϊ����㣬�������ڽ��������
			top++; k = 1; St[top] = p; break;//k=1��ʾ���ź����Ϊ���ӽ��
		}
		case ')': {						//�����Ŵ�����������Һ�����ϣ���Ҫ���ص���һ�����
			top--; break;
		}
		case ',': {						//���ű�ʾ��һ��Ԫ�ؿ���Ϊ�Һ��ӽ��
			k = 2; break;				
		}
		default: {						//��Ԫ�ز�Ϊ����ʱ
			if (root == NULL) {
				root = p;
			}
			else {						//b��Ϊ��ʱ
				p = (BTNode*)malloc(sizeof(BTNode));
				p->data = ch;
				p->lchild = p->rchild = NULL;
				switch (k) {			//���������ӽڵ���Һ��ӽ��
				case 1: {
					St[top]->lchild = p; break;//����
				}
				case 2: {
					St[top]->rchild = p; break;//�Һ���
				}
				}
			}
		}
		}
		j++;
		ch = str[j];//ch������һ��Ԫ��
	}
}

void DestroyNode(BTNode*& b) {//���ٶ�����
	if (b != NULL) {
		DestroyNode(b->lchild);
		DestroyNode(b->rchild);
		free(b);
	}
}

void PostNode(BTNode* root) {//�������������
	BTNode* p, * r;
	int flag;			//flag�����ж��Ƿ���Կ�ʼ����ջ�����,2
	stack<BTNode*> s;	//����ջ���ڴ�Ŷ��������
	p = root;
	do {
		while (p != NULL) {//�����ӽ�㿪ʼ��������㼰�������������ӽ���ջ
			s.push(p);
			p = p->lchild;//pָ�����ӽ��
		}
		r = NULL;
		flag = 2;		//������Ҷ�ӣ����Կ�ʼ����ջ��Ԫ��
		while (!s.empty() && flag==2) {//ջ��Ϊ����flag==2
			p = s.top();	//��ջ��Ԫ��ȡ����p
			if (p->rchild == r) {	//���Һ��ӽ��Ϊr�������ǰ���Ԫ��
				cout << p->data << " ";
				s.pop();	//��ջ��Ԫ��
				r = p;		//rָ��շ��ʹ��ý��
			}
			else {
				p = p->rchild;
				flag = 1;//��ʾ��ǰ���Ǵ���ջ�����
			}
		}
	} while (!s.empty());//ջ��ʱ�˳�ѭ��
	cout << endl;
}