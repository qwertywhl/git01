#include"SqString.h"
int main() {
	SqString* s,*s1,*str;
	int n;
	cout << "��һ����:" << endl;
	cin >> n;
	CreateString(s, n);
	cout << "�ڶ�����:" << endl;
	cin >> n;
	CreateString(s1, n);
	DispString(s);
	cout <<"��һ�����ĳ��ȣ�" << s->length << endl;
	InsertString(s, s1, str, 9);
	cout << "�����Ϊ��" << endl;
	DispString(str);
	DeleteString(s, str, 2, 5);
	cout << "ɾ����Ϊ��" << endl;
	DispString(str);
	SwitchString(s, s1, str, 2, 5);
	cout << "�滻���ַ���Ϊ��" << endl;
	DispString(str);
	GetString(s, str, 2, 10);
	cout << "��ȡ���ַ���Ϊ��" << endl;
	DispString(str);
	ConnectString(s, s1, str);
	cout << "���Ӻ��ַ���Ϊ��" << endl;
	DispString(str);
	DestroyString(s);
	DestroyString(s1);
	DestroyString(str);
	return 0;
}