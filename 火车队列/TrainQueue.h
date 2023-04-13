#pragma once
#include<iostream>
#include<queue>
using namespace std;

queue<int> GetTrain() {
	queue<int> line;//初始化队列保存火车车厢
	int n;
	cout << "请输入车厢总数：" << endl;
	cin >> n;
	int x;
	cout << "请输入车厢编号：" << endl;
	for (int i = 0; i < n; i++) {
		cin >> x;
		line.push(x);//将输入的车厢编号进队
	}
	return line;
}

void ReArrangement(queue<int> line) {
	queue<int> line1, line2, line3;//初始化三个缓冲队列
	int nowOut = 1;					//出轨车厢号第一个为1
	int length = line.size();		//length保存所有入轨车厢数
	cout << "出轨车厢为：" << endl;
	for (int i = 0; i < length; i++) {//对每一个入轨车厢进行判断
		int x = line.front();	//用x保存line队首值
		line.pop();				//队首出对
		if (x == nowOut) {		//若当前车厢值等于nowOut，将其直接出轨
			cout << x << " ";
			nowOut++;			//nowOut++
		}
		else {					//若当前车厢值不等于nowOut，将其添加到队列中
			if (line1.empty() || x > line1.back()) {//判断，当当前队列为空或当前车厢号大于第一个缓冲队列的队尾元素时，将其进队
				line1.push(x);
			}
			else if (line2.empty() || x > line2.back()) {//同理如上
				line2.push(x);
			}
			else if (line3.empty() || x > line3.back()) {
				line3.push(x);
			}
		}
	}
	while (nowOut<=length) {//当出轨完毕时结束循环
		int flag = 0;
		if (!line1.empty()) {//首先判断是否为空
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
		if (flag == 0) {//当会陷入死循环时，表示车厢编号排列无解，结束循环
			cout << "火车车厢不能顺序重新排列！" << endl;
			break;
		}
	}
}