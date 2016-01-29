#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d[8],l,i,n=0,t,p;
	scanf("%d %d",&a,&b);
	c=a+b;
	l=c;
	if(l<0) l=-l;
	for(i=0;l!=0;i++)
	{
		d[i]=l%10;
		n+=1;
		l/=10;	
	}
	for(i=0;i<n/2;i++)
	{
		t=d[i];
		d[i]=d[n-1-i];
		d[n-1-i]=t;
	}
	p=n%3;
	if(c<0) printf("-");
	for(i=0;i<n;i++)
	{
		printf("%d",d[i]);
		if((i+1-p)%3==0&&i!=n-1) printf(",");
	}
	return 0;	
} 
