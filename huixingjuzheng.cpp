#include<iostream>
using namespace std;

#define min(a,b)  ((a)-(b)>0?b:a)
int main(void)

{  int n=4;
    int k,d,left,p;
	
	for(int i=1;i<=n;i++)
	{	for(int j=1;j<=n;j++)
		{
			k=min(min(j,(n-j+1)),min(i,(n-i+1)));//j为5时边界就变成0了，所以要加1
            d=i-k+j-k;
            left=n*n-(n-2*(k-1))*(n-2*(k-1))+1;//i，j从1开始算，k变了，则要减1
            if(i<=j)
				p=left+d;
			else
				p=left+4*(n-2*(k-1)-1)-d;   //i，j从1开始算，k变了，则要减1
			cout<<"  "<<p;
          
		} 
	cout<<endl;
	}
return 0;
}
*/
#include<iostream>
using namespace std;

#define min(a,b)  ((a)-(b)>0?b:a)
int main(void)

{  int n=5;
    int k,d,left,p;
	
	for(int i=0;i<n;i++)
	{	for(int j=0;j<n;j++)
		{
			k=min(min(j,(n-j-1)),min(i,(n-i-1)));//每一圈以左上角的元素的k值为参考，则每一圈离正方形的边界是一样远的，故要用边长减位置或者边长本身来求得距离边界的长度
            d=i-k+j-k;
            left=n*n-(n-2*k)*(n-2*k);//i，j从0开始算求得每一圈左上角的值，在这加个1就使所有数都加1

            if(i<=j)
				p=left+d; //右上，右边数字
			else
				p=left+4*((n-2*k)-1)-d;   //每一环总共有多少数
			cout<<"  "<<p;
          
		} 
	cout<<endl;
	}
return 0;
}
