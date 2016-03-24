/*************************************

FileName: Calculator.cpp
Authur: Neves     Date:2016.3.24
Discription: 
	The code is to scan a string and get the part of the string to a queue, and print the queue.
Fuction List: 
	1.queue<string> ToStringQueue(string input); To scan string.
	2.void print(queue<string> que); To print queue.

*************************************/ 

#include<iostream>
#include<string>
#include<queue>
using namespace std;


class Scan
{
	public:
		queue<string> ToStringQueue(string input);
		//Scan();
		//~Scan();
	//private:
};

class Print
{
	public:
		void print(queue<string> que);
		//Scan();
		//~Scan();
	//private:
}; 

/*************************************

Discription: To scan the string which is input. 
	And push every part of string into a queue.
Input: The string.
Output: <queue>.
return: The queue.

*************************************/
queue<string> Scan::ToStringQueue(string input)
{
	int lenth = 0;
	string part = "";
	queue<string>que;
	
	for (int i = 0; i < input.size(); i++)     						  //�ж�string input�����ÿһ���ַ��ǲ������֡�
	{
		if ((input[i] >= '0' && input[i] <= '9') || input[i] == '.')  //��������� 
		{
			lenth++;
			part += input[i];										  //�����ִ���part�У�һ����push��que�� 
			if (i == input.size() - 1) que.push(part);				  //���һλ�����ֵ����ҲӦ�ÿ��ǵ� 
		}
		else														  //����������� 
		{
			if (lenth == 0)											  //�������ַ�֮ǰ�������� 
			{
			    que.push(part = input[i]);
				part = "";
			}														  //lenth==0��˵��ǰ��û������ 
			else 													  //�������ַ�֮ǰ������ 
			{
				que.push(part);
				que.push(part = input[i]);
				lenth = 0;
				part = "";
			}														  //��lenth==0������£��������ŵ�ʱ�����¼��� 
		}
	}
	return que;
}

/*************************************

Discription: To print the queue from line to line.
Input: The queue.
Output: Every part of the queue.
return: None.

*************************************/
void Print::print(queue<string> que)
{
	for ( ; que.empty()==false; )		//��Ԫ��ȫ�������Ժ���� 
	{
		cout << que.front() << endl;	//print �����е� һ��Ԫ�� 
		que.pop();						//���������е�һ��Ԫ�� 
	}
}

int main()
{
	Scan scan;
	Print print;
	string input;
	queue<string>que;
	cin >> input;
	que = scan.ToStringQueue(input); 
	print.print(que);
	return 0;
} 










