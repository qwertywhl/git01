#pragma once
#include<iostream>
#include<queue>
using namespace std;

queue<int> GetTrain() {
	queue<int> line;//��ʼ�����б���𳵳���
	int n;
	cout << "�����복��������" << endl;
	cin >> n;
	int x;
	cout << "�����복���ţ�" << endl;
	for (int i = 0; i < n; i++) {
		cin >> x;
		line.push(x);//������ĳ����Ž���
	}
	return line;
}

void ReArrangement(queue<int> line) {
	queue<int> line1, line2, line3;//��ʼ�������������
	int nowOut = 1;					//���쳵��ŵ�һ��Ϊ1
	int length = line.size();		//length����������쳵����
	cout << "���쳵��Ϊ��" << endl;
	for (int i = 0; i < length; i++) {//��ÿһ����쳵������ж�
		int x = line.front();	//��x����line����ֵ
		line.pop();				//���׳���
		if (x == nowOut) {		//����ǰ����ֵ����nowOut������ֱ�ӳ���
			cout << x << " ";
			nowOut++;			//nowOut++
		}
		else {					//����ǰ����ֵ������nowOut��������ӵ�������
			if (line1.empty() || x > line1.back()) {//�жϣ�����ǰ����Ϊ�ջ�ǰ����Ŵ��ڵ�һ��������еĶ�βԪ��ʱ���������
				line1.push(x);
			}
			else if (line2.empty() || x > line2.back()) {//ͬ������
				line2.push(x);
			}
			else if (line3.empty() || x > line3.back()) {
				line3.push(x);
			}
		}
	}
	while (nowOut<=length) {//���������ʱ����ѭ��
		int flag = 0;
		if (!line1.empty()) {//�����ж��Ƿ�Ϊ��
			if (line1.front() == nowOut) {
				cout << line1.front() << " ";
				line1.pop();
				nowOut++;
				flag++;
			}
		}
		if (!line2.empty()) {
			if (line2.front() == nowOut) {
				cout << line2.front() << " ";
				line2.pop();
				nowOut++;
				flag++;
			}
		}
		if (!line3.empty()) {
			if (line3.front() == nowOut) {
				cout << line3.front() << " ";
				line3.pop();
				nowOut++;
				flag++;
			}
		}
		if (flag == 0) {//����������ѭ��ʱ����ʾ�����������޽⣬����ѭ��
			cout << "�𳵳��᲻��˳���������У�" << endl;
			break;
		}
	}
}