#include<iostream>
using namespace std;
 
bool charcompare(char *a,char*b)
{
	char *aa=a;char*bb=b;
	int al=(int)strlen(a);
	int bl=(int)strlen(b);
	if (al<bl)
		return false;
	for (int i=0;i<al-bl;i++)
	{
		while(*a==*b)
		{
			a++;b++;
			if(*b=='\0')
				return true;

		}
		b=bb;
	}
	return false;

}
  int main(void)
  {
	  char*a="ababcabcacbab";
	  char*b="abca";
	  cout<<charcompare(a,b)<<endl;
	 
       
  }

