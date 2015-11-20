#include <iostream>
using namespace std;
int  a[ ][3]={{1,0,7},{ 3,2,1},{0,1,5}};
int t[3][3];
int con;
int main(void)
{
     for (int i=0;i<3;i++)
     {
		 for (int j=0;j<3;j++)
		 {
			 
			  for (int k=0;k<3;k++)
			 {
				 if((a[i][k])&&(a[k][j]))                // 1 0 7   在进行乘加运算之前先对参加乘法的
				 { t[i][j]=t[i][j]+a[i][k]*a[k][j];      // 3 2 1   单元是否为0进行预判，能够减少运算次数
				 con++;                                  // 0 1 5   对于没有乘加指令的运算或许有用，但是对于有乘加指令的处理器，判断的开销反而会抵消减少运算带来的好处
				 }
			 }
			 
		 }
     }









	for (int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			cout<<t[i][j]<<" ";
		cout<<endl;
	}
	cout<<con<<endl;
return 0;
}
