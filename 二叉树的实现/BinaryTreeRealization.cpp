#include"BinaryTreeRealization.h"
int main() {
	BTNode* root;
	char str[MaxSize] = {};
	cout << "�������������" << endl;
	CreateChar(str);	//���ű�ʾ�����������
	CreateBTree(root, str);//������������ʽ�洢�ṹ�洢
	cout << "���������������" << endl;
	PreOrder(root);		//�������������
	cout << "���������������" << endl;
	InOrder(root);		//�������������
	cout << "���������������" << endl;
	PostOrder(root);		//�������������
	cout << "��α�����������" << endl;
	LevelOrder(root);		//��α���������
	DestroyBTree(root); //���ٶ�����
}