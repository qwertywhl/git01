#pragma once
#include<iostream>
#include<malloc.h>
#define MaxSize 100
using namespace std;

typedef struct {
	char data[MaxSize];
	int length;
}SqString;

void CreateString(SqString*& s, int n) {//���������ڴ�����ʱ�򽫴�����
	s = (SqString*)malloc(sizeof(SqString));
	s->length = 0;
	char e;
	for (int i = 0; i < n; i++) {//��ǰ�����˴��ĳ���
		cin >> e;
		s->data[i] = e;
		s->length++;
	}
}

void DestroyString(SqString*& s) {//���ٴ�
	free(s);
}

void DispString(SqString* s) {//�����
	for (int i = 0; i < s->length; i++) {
		cout << s->data[i];
	}
	cout << endl;
}

void InsertString(SqString* s, SqString* s1, SqString*& str,int n) {//���봮����s1���뵽s�ĵ�n��λ�ã������浽str��
	str = (SqString*)malloc(sizeof(SqString));
	str->length = 0;
	int i;
	for (i = 0; i < n-1; i++) {//�Ƚ�s��ǰn-1���ŵ�str��
		str->data[i] = s->data[i];
		str->length++;
	}
	for (int j = 0; j < s1->length; j++) {//��s1�ŵ�str��
		str->data[i] = s1->data[j];
		str->length++;
		i++;
	}
	for (int k = n-1; k < s->length; k++) {//��s��ʣ��ķŵ�str��
		str->data[i] = s->data[k];
		i++;
		str->length++;
	}
}

void DeleteString(SqString* s, SqString*& str, int m,int n) {//ɾ��s�дӵ�m��λ�ÿ�ʼ��n���ַ�ɾ�������浽str��
	str = (SqString*)malloc(sizeof(SqString));
	str->length = 0;
	int i;
	for (i = 0; i < m - 1; i++) {
		str->data[i] = s->data[i];
		str->length++;
	}
	for (int j = m + n - 1; j < s->length; j++) {//����n���ַ�
		str->data[i] = s->data[j];
		i++;
		str->length++;
	}
}

void SwitchString(SqString* s, SqString* s1, SqString*& str, int m, int n) {
	str = (SqString*)malloc(sizeof(SqString));//��s�дӵ�m���ַ���ʼ��n���ַ��滻Ϊs1��������str��
	str->length = 0;
	int i;
	for (i = 0; i < m - 1; i++) {
		str->data[i] = s->data[i];
		str->length++;
	}
	for (int j = 0; j < s1->length; j++) {
		str->data[i] = s1->data[j];
		i++;
		str->length++;
	}
	for (int k = m + n - 1; k < s->length; k++) {
		str->data[i] = s->data[k];
		str->length++;
		i++;
	}
}

void GetString(SqString* s, SqString*& str, int m, int n) {
	str = (SqString*)malloc(sizeof(SqString));//��ȡs�дӵ�m���ַ���ʼ��n���ַ����浽str��
	str->length = 0;
	int i,j=0;
	for (i = m - 1; i <= n; i++) {
		str->data[j] = s->data[i];
		str->length++;
		j++;
	}
}

void ConnectString(SqString* s, SqString* s1, SqString*& str) {
	str = (SqString*)malloc(sizeof(SqString));
	str->length = 0;
	int i;
	for (i = 0; i < s->length; i++) {
		str->data[i] = s->data[i];
		str->length++;
	}
	for (int j = 0; j < s1->length; j++) {
		str->data[i] = s1->data[j];
		i++;
		str->length++;
	}
}