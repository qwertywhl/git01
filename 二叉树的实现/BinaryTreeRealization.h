#pragma once
#include<iostream>
#include<stack>
#include<queue>
#define MaxSize 20
using namespace std;

typedef struct Node {
	char data;
	struct Node* lchild;//���ӽ��
	struct Node* rchild;//�Һ��ӽ��
}BTNode;

void InitNode(BTNode*& b) {//��ʼ�������
	b = (BTNode*)malloc(sizeof(BTNode));
	b->lchild = b->rchild = NULL;
}

void DestroyBTree(BTNode*& b) {//���ٶ�����
	if (b != NULL) {
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}

void CreateChar(char* str) {//�����������뷨��ʾ�Ķ�����
	char ch;
	int i = 0;
	while (cin >> ch) {
		*(str + i) = ch;
		i++;
	}
}

void CreateBTree(BTNode*& b,char *str) {//��������������ʽ�ṹ�洢��
	BTNode* st[MaxSize],*p;				//���������飬���ڴ洢ÿһ�������
	int j = 0, k = 0, top = -1;	//k=1��ʾ�����p��Ϊջ���������ӣ�k=2�����p��Ϊջ�������Һ���
	char ch;
	ch = str[j];
	b = NULL;
	if (ch == '\0') return;				//������Ϊ�գ��˳�����
	p = (BTNode*)malloc(sizeof(BTNode));
	p->lchild = p->rchild = NULL;
	p->data = ch;
	while (ch != '\0') {				
		switch (ch) {
		case '(': {						//�����ű�ʾ��һ���ڵ�Ϊ���ӽ��
			top++; k = 1; 
			st[top] = p; break;//�����p��ջ
		}
		case ')': {			//�����ű�ʾ��ǰ�������
			top--; break;	//�����p��ջ
		}
		case ',': {			//���ű�ʾ��һ�����Ϊ�Һ���
			k = 2; break;
		}
		default: {
			p = (BTNode*)malloc(sizeof(BTNode));
			p->lchild = p->rchild = NULL;
			p->data = ch;
			if (b == NULL) {//bΪ��ʱ����ʾ��ʱpΪ���ڵ�
				b = p;
			}
			else{
				switch (k) {//�������Һ�������ڵ���������
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

void PreOrder(BTNode*& b) {//����������������ǵݹ飩����㣬��������������
	stack<BTNode*> st;		//�ṹ��ָ������ջ
	BTNode* p;
	if (b == NULL) { cout << "������Ϊ��!" << endl; return; }//��������Ϊ�գ��˳�����
	else {
		st.push(b);			//��������ջ
		while (!st.empty()) {
			p = st.top();
			st.pop();
			cout << p->data << " ";//��������
			if (p->rchild != NULL) {//���������Ƚ�ջ�Ա�������Ҳ����Һ��ӽ��
				st.push(p->rchild);
			}
			if (p->lchild != NULL) {//��������ջ
				st.push(p->lchild);
			}
		}
		cout << endl;
	}
}

void PreOrder2(BTNode*& b) {//��������ǵݹ��㷨2
	BTNode* p;			
	stack<BTNode*> st;	//ջ��ű������Ľ��
	p = b;
	while (!st.empty() || p != NULL) {	
		while (p != NULL) {		//���ʽ��p���ƶ���������
			cout << p->data << " ";//�����ǰ���ʽ��
			st.push(p);			//���������ӽ�ջ
			p = p->lchild;
		}
		if (!st.empty()) {	//��ջ���գ��ƶ����Һ���
			p = st.top();
			st.pop();
			p = p->rchild;
		}
	}
	cout << endl;
}

void InOrder(BTNode*& b) {//����������������ǵݹ飩������������㣬������
	BTNode* p;
	stack<BTNode*> st;		//ջ������
	p = b;
	while (!st.empty() || p != NULL) {
		while (p != NULL) {	//���ʽ��p�����������½�㲢��ջ
			st.push(p);
			p = p->lchild;	//�ƶ�������
		}
		if (!st.empty()) {	
			p = st.top();
			st.pop();
			cout << p->data << " ";//��ջ�����
			p = p->rchild;		//ת����������
		}
	}
	cout << endl;
}

void PostOrder(BTNode*& b) {//����������������ǵݹ飩���������������������
	BTNode* p, * r;
	stack<BTNode*> st;
	bool flag;		//��־λ������Ƿ���Կ�ʼ����ջ�����
	p = b;
	do {
		while (p != NULL) {
			st.push(p);		//��p����������������ջ
			p = p->lchild;
		}
		r = NULL;			//rָ��շ��ʵĽ�㣬��ʼʱΪ��
		flag = true;		//flag��ʾ���ڴ���ջ�����
		while (!st.empty() && flag) {
			p = st.top();
			if (p->rchild == r) {	//����ǰ�ڵ�������Ϊ�ոշ��ʹ��Ľ�㣬��ʾ���е��������������
				cout << p->data << " ";
				st.pop();			//��ջ
				r = p;
			}
			else {
				p = p->rchild;		//�����ǣ���������������
				flag = false;
			}
		}
	} while (!st.empty());	//ջ�ս���
	cout << endl;
}

void LevelOrder(BTNode*& b) {//��α���������
	BTNode* p;
	queue<BTNode*> qu;		//����
	qu.push(b);
	while (!qu.empty()) {
		p = qu.front();		//ȡ����Ԫ��
		qu.pop();
		cout << p->data << " ";
		if (p->lchild != NULL) qu.push(p->lchild);//���ӽ���
		if (p->rchild != NULL) qu.push(p->rchild);//�Һ��ӽ���
	}
}

BTNode* CreateBT1(char* pre, char* in, int n) {//�������к��������й��������
	BTNode* b;
	char* p;
	int k;
	if (n <= 0) return NULL;
	b = (BTNode*)malloc(sizeof(BTNode));//�����������ڵ�b
	b->data = *pre;						
	for (p = in; p > in + n; p++) {//�������������ҵ������λ��
		if (*p == *pre) break;
	}
	k = p - in;								//ȷ������������������е�λ��
	b->lchild = CreateBT1(pre + 1, in, k);//�ݹ鹹��������
	b->rchild = CreateBT1(pre + k + 1, p + 1, n - k - 1);//�ݹ鹹��������
	return b;
}

BTNode* CreateBT2(char* post, char* in, int n) {//�������к��������й��������
	BTNode* b;
	char r, * p;
	int k;
	if (n <= 0) return NULL;
	r = *(post + n - 1);
	b = (BTNode*)malloc(sizeof(BTNode));//�����������ڵ�b
	b->data = r;
	for (p = in; p < in + n; p++) {
		if (*p == r) break;
	}
	k = p - in;							//ȷ������������������е�λ��
	b->lchild = CreateBT2(post, in, k);//�ݹ鹹��������
	b->rchild = CreateBT2(post + k, p + 1, n - k - 1);//�ݹ鹹��������
}