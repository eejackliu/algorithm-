#include<iostream>
using namespace std;
#define MASK 0x7fffffff
int max (int x, int y)
{
int sx,sy,s,is_x;
sx=x>>31;
sy=y>>31;
s=((y&MASK)-(x&MASK))>>31;

is_x=((!(sx^sy))&s)||((sx^sy)&sy);//此处应为逻辑或，sx或者sy为负数时最高位为1，右移的时候左边补的是1，最后的符号位sy会是-1. 当两书符号相异时，is_x的值与((sx^sy)&sy)相同，为了兼顾符号相同的情况应用逻辑或，
                                  //因为前面含有按位与，结果有可能为-1.
return is_x*x+(!is_x)*y;          //若is_x需要1时就
} 
//真值表  sx    sy       s        is_x
//        1      0       *         1       
//        0      1       *          0
//                               当符号相异的时候就不能用sx和sy来决定is_x且当符号相异的时候又不能影响is_x的值，故用!(sx^sy)来当判断的条件之一
//                               只有将两个数相减得到的数的最高位来做大小的标记不用考虑其他情况
//        0      0               x>y最高位为0，则用y-x最高位才能为1，或者用x-y再将结果取饭，这势必将增加操作步骤
//                               
//         1     1               同上 
//                                
//                        
  int main(void)
  {
	  cout<<max(-2,-6)<<endl;

  }




