#include<iostream>
using namespace std;
#include<string>
#define max(a,b)  ((a)-(b)>0?a:b)
int lcs(string a,string b,int al,int bl)
{

 
	if((al==0)||(bl==0))
		return 0;
	if(a[al]==b[bl])
		return lcs(a,b,al-1,bl-1)+1;  //假设Xn，Ym的公共子序列是Zk，这个是不需要证明，但是对于Zk-1是否是最优解这个要证明之，这样递推关系式才正确
	else
		return max(lcs(a,b,al-1,bl),lcs(a,b,al,bl-1));

}


int main(void)

{  
	string a="fwefe",b="hjk";
	 int result;
	 result=lcs(a,b,a.length()-1,b.length()-1);
	cout<<result<<endl;
   
return 0;
}
*/
#include <iostream>
#include<string>
using namespace std;
int arry[20][20];
string a="ABCBDAB";
	string b="BDCABA";
#define max(a,b)  ((a)-(b)>0?a:b)
int lcs(string a,string b)
{
  
  int x=static_cast <int>(a.length());
  int y=(int)b.length();
  for(int i=0;i<=x;i++)
	  arry[i][0]=0;
  for(int i=0;i<=y;i++)
	  arry[0][i]=0;
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++)
		{                                               //      A D S B
			if(a.operator[](i-1)==b.operator[](j-1))    //      0 0 0 0     
				arry[i][j]=arry[i-1][j-1]+1;            //  D 0 0 1 1 1
			else                                        //  A 0 1 1 1 1
			arry[i][j]=max(arry[i][j-1],arry[i-1][j]);  //  D 0 1 2 2 2
		}                                               //形成类似上面的结构，是得最小结构往上推的时候符合递推关系式，为了使单个字符能支持使用递推关系式，字符在二维数组中的位置应该从1开始，下标为0的最边上的两列应该是0

		return arry[x][y];
		
}
string change(string a)
{
	int b=(int)a.length()-1;
	int low=0;
	while(low<b)
	{
		int tmp;
		tmp=a.operator [](b);
		a.operator [](b)=a.operator [](low);
		a.operator [](low)=tmp;
		b--;
		low++;

	}
	return a;
}
void  lcsout(int x,int y,string out)
{
	
	while((x>0)&&(y>0))
	{
		if(a.operator [](x-1)==b.operator [](y-1))
		{
			out.push_back(a.operator [](x-1));
			x--;y--;

		}
		else if(arry[x-1][y]==arry[x][y-1])
		{
             lcsout(x-1,y,out);
			 lcsout(x,y-1,out);
			 return;
		}
		else if(arry[x-1][y]>arry[x][y-1])
			x--;
		else
			y--;
	}
	
     cout<<change(out)<<endl;
}
int main(void)
{

	int result;
       result=lcs(a,b);
	   cout<<result<<endl;;
	   int x=(int)a.length();int y=(int)b.length();
	   string out;
	  lcsout(x,y,out);
     
}
