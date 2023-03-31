#pragma once
#include<iostream>
#include<malloc.h>
#define MaxSize 100
using namespace std;

typedef struct {
	char data[MaxSize];
	int length;
}SqString;

void CreateString(SqString*& s, int n) {//创建串，在创建的时候将串输入
	s = (SqString*)malloc(sizeof(SqString));
	s->length = 0;
	char e;
	for (int i = 0; i < n; i++) {//提前输入了串的长度
		cin >> e;
		s->data[i] = e;
		s->length++;
	}
}

void DestroyString(SqString*& s) {//销毁串
	free(s);
}

void DispString(SqString* s) {//输出串
	for (int i = 0; i < s->length; i++) {
		cout << s->data[i];
	}
	cout << endl;
}

void InsertString(SqString* s, SqString* s1, SqString*& str,int n) {//插入串，将s1插入到s的第n个位置，并保存到str中
	str = (SqString*)malloc(sizeof(SqString));
	str->length = 0;
	int i;
	for (i = 0; i < n-1; i++) {//先将s中前n-1个放到str中
		str->data[i] = s->data[i];
		str->length++;
	}
	for (int j = 0; j < s1->length; j++) {//将s1放到str中
		str->data[i] = s1->data[j];
		str->length++;
		i++;
	}
	for (int k = n-1; k < s->length; k++) {//将s中剩余的放到str中
		str->data[i] = s->data[k];
		i++;
		str->length++;
	}
}

void DeleteString(SqString* s, SqString*& str, int m,int n) {//删除s中从第m个位置开始的n个字符删除并保存到str中
	str = (SqString*)malloc(sizeof(SqString));
	str->length = 0;
	int i;
	for (i = 0; i < m - 1; i++) {
		str->data[i] = s->data[i];
		str->length++;
	}
	for (int j = m + n - 1; j < s->length; j++) {//跳过n个字符
		str->data[i] = s->data[j];
		i++;
		str->length++;
	}
}

void SwitchString(SqString* s, SqString* s1, SqString*& str, int m, int n) {
	str = (SqString*)malloc(sizeof(SqString));//将s中从第m个字符开始的n个字符替换为s1并保存在str中
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
	str = (SqString*)malloc(sizeof(SqString));//提取s中从第m个字符开始的n个字符保存到str中
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