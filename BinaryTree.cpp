#include"BinaryTree.h"
int main() {
	char str[MaxSize] = "";
	cout << "�����������ű�ʾ����ʾ�Ķ�������" << endl;
	CreateChar(str);	//���������
	BTNode* b;
	CreateNode(b, str); //�����ű�ʾ����ʾ�Ķ���������ʽ�ṹ�洢
	cout << "�������������Ϊ��" << endl;
	PostNode(b);		//�������������
	DestroyNode(b);		//���ٶ�����
}