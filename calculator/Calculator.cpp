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

queue<string> Scan::ToStringQueue(string input)
{
	int lenth=0;
	string part="";
	queue<string>que;
	
	for(int i=0;i<input.size();i++)
	{
		if((input[i]>='0'&&input[i]<='9')||input[i]=='.')
		{
			lenth++;
			part+=input[i];//�����ִ���part�У�һ����push��que�� 
			if(i==input.size()-1) que.push(part);//���һλ�����ֵ����ҲӦ�ÿ��ǵ� 
		}
		else
		{
			if(lenth==0)
			{
			    que.push(part=input[i]);
				part="";
			}	//lenth==0��˵��ǰ��û������ 
			else 
			{
				que.push(part);
				que.push(part=input[i]);
				lenth=0;
				part="";
			}//��lenth==0������£��������ŵ�ʱ�����¼��� 
		}
	}
	return que;
}

void Print::print(queue<string> que)
{
	for (; que.empty()==false; )		//��Ԫ��ȫ�������Ժ���� 
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
	cin>>input;
	que=scan.ToStringQueue(input); 
	print.print(que);
	return 0;
} 










