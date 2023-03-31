#include"SqString.h"
int main() {
	SqString* s,*s1,*str;
	int n;
	cout << "第一个串:" << endl;
	cin >> n;
	CreateString(s, n);
	cout << "第二个串:" << endl;
	cin >> n;
	CreateString(s1, n);
	DispString(s);
	cout <<"第一个串的长度：" << s->length << endl;
	InsertString(s, s1, str, 9);
	cout << "插入后串为：" << endl;
	DispString(str);
	DeleteString(s, str, 2, 5);
	cout << "删除后串为：" << endl;
	DispString(str);
	SwitchString(s, s1, str, 2, 5);
	cout << "替换后字符串为：" << endl;
	DispString(str);
	GetString(s, str, 2, 10);
	cout << "提取后字符串为：" << endl;
	DispString(str);
	ConnectString(s, s1, str);
	cout << "连接后字符串为：" << endl;
	DispString(str);
	DestroyString(s);
	DestroyString(s1);
	DestroyString(str);
	return 0;
}