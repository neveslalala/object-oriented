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
			part+=input[i];//把数字存在part中，一次性push到que中 
			if(i==input.size()-1) que.push(part);//最后一位是数字的情况也应该考虑到 
		}
		else
		{
			if(lenth==0)
			{
			    que.push(part=input[i]);
				part="";
			}	//lenth==0，说明前面没有数字 
			else 
			{
				que.push(part);
				que.push(part=input[i]);
				lenth=0;
				part="";
			}//在lenth==0的情况下，遇到符号的时候重新计数 
		}
	}
	return que;
}

void Print::print(queue<string> que)
{
	for (; que.empty()==false; )		//当元素全部弹出以后结束 
	{
		cout << que.front() << endl;	//print 队列中第 一个元素 
		que.pop();						//弹出队列中第一个元素 
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










