//#include<iostream>
//#include<malloc.h>
//#define MaxSize 10
//using namespace std;
//
//typedef struct {
//	char data[MaxSize];
//	int length;
//}SqString;
//
//void InitString(SqString*& s) {
//	s = (SqString*)malloc(sizeof(SqString));
//	s->length = 0;
//}
//
//void CreateString(SqString*& s,int n) {
//	for (int i = 0; i < n; i++) {
//		cin >> s->data[i];
//		s->length++;
//	}
//}
//
//void DestroyString(SqString*& s) {
//	free(s);
//}
//
//int BF(SqString* s, SqString* t) {
//	int i = 0, j = 0;
//	while (i < s->length && j < t->length) {
//		if (s->data[i] == t->data[j]) {
//			i++;
//			j++;
//		}
//		else {
//			i = i - j + 1;
//			j = 0;
//		}
//	}
//	if (j >= t->length) {
//		return i - j;
//	}
//	else {
//		return -1;
//	}
//}
//
//void GetNext(SqString*& t, int next[]) {
//	int j, k;
//	j = 0; k = -1;
//	next[0] = -1;
//	while (j < t->length - 1) {
//		if (k == -1 || t->data[j] == t->data[k]) {
//			j++;
//			k++;
//			next[j] = k;
//		}
//		else k = next[k];
//	}
//}
//
//int KMPIndex(SqString* s, SqString* t) {
//	int next[MaxSize], i = 0, j = 0;
//	GetNext(t, next);
//	while (i < s->length && j < t->length) {
//		if (s->data[i] == t->data[j]) {
//			i++;
//			j++;
//		}
//		else {
//			j = next[j];
//		}
//	}
//	if (j >= t->length) return i - t->length;
//	else return -1;
//}
//
//
//void GetNextval(SqString* s, int nextval[]) {
//	int j = 0, k = -1;
//	nextval[0] = -1;
//	while (j < s->length) {
//		if (k == -1 || s->data[j] == s->data[k]) {
//			j++;
//			k++;
//			if (s->data[j] != s->data[k]) {
//				nextval[j] = k;
//			}
//			else nextval[j] = nextval[k];
//		}
//		else k = nextval[j];
//	}
//}
//
//int KMPIndexl(SqString* s, SqString* t) {
//	int nextval[MaxSize], i = 0, j = 0;
//	GetNextval(t, nextval);
//	while (i < s->length && j < t->length) {
//		if (j == -1 || s->data[i] == t->data[j]) {
//			j++;
//			i++;
//		}
//		else j = nextval[j];
//	}
//	if (j >= t->length) return i - t->length;
//	else return -1;
//}