#include<stdio.h>
#include<memory.h>
#include<string.h>
#include <iostream>


typedef struct
{
    int digits[1000];
    int len;  //长度
    int pos;  //小数点位置
}bigfloat;
//打印一个bigfloat
void print_bigfloat(bigfloat big)
{
    int i=0;
    int j=0;
    while(big.digits[big.len-1-i]==0&&big.len-big.pos>i)
        i++;
    while(big.digits[j]==0&&j<big.pos)
        j++;
    for(;i<big.len-j;i++)
    {
        if(big.pos==big.len-i) putchar('.');
        printf("%d",big.digits[big.len-1-i]);
    }
}
//b*c
bigfloat b_c( bigfloat b, bigfloat c )
{
    int i,j;
    bigfloat res;
    memset(res.digits,0,sizeof(res.digits));  //置0
    res.pos=b.pos+c.pos;         //处理小数点位
    res.len=b.len+c.len;         //处理长度
    //计算一次
    for(i=0;i<b.len;i++)
        for(j=0;j<c.len;j++)
            res.digits[i+j]+=b.digits[i]*c.digits[j];
    //处理进位
    for (i=0;i<res.len;i++)
        if (res.digits[i]>9)
        {
            res.digits[i+1]+=res.digits[i]/10;
            res.digits[i]%=10;
            while (res.digits[res.len]) res.len++;
        }
    return res;
}
//求大数s的n次幂
bigfloat bigpow(bigfloat s, int n )
{
    bigfloat res;
    if(n==1) return s;
    if(n==2) return b_c(s,s);
//    return b_c(s,bigpow(s,n-1));
    while (n > 2) {
        if (n % 2 == 1)
            return b_c(s, bigpow(s, n-1));
        else {
            res = bigpow(s, n/2);
            return b_c(res, res);
        }
    }
}
//输入一个浮点型大数
bigfloat get_one(char str[10])
{
    int len_str;
    int len=0;
    int i;
    bigfloat one;
    memset(one.digits,0,sizeof(one.digits));  //置0
    one.len=0;
    one.pos=0;
    len_str=strlen(str);
    for(i=0;i<len_str;i++)
    {
        if(str[len_str-1-i]=='.') one.pos=i;
        else
        {
            one.digits[len]=str[len_str-1-i]-'0';
            len++;
        }
    }
    one.len=len;
    return one;
}
int main()
{
    bigfloat s;
    char str[10];
    int n;
    while(scanf("%s %d",str,&n)!=EOF)
    {
        s=get_one(str);
        print_bigfloat(bigpow(s,n));
    }
    return 0;
}

//int pow(int s, int n) {
//    if (n == 1)
//        return s;
//    if (n == 2)
//        return s*s;
//    while (n > 2) {
//        if (n % 2 == 1) {
//            return s * pow(s, n-1);
//        }
//        else {
//            int r = pow(s, n/2);
//            return r * r;
//        }
//    }
//}
//
//int main () {
//    int a;
//    int n;
//    std::cin >> a >> n;
//    std::cout << pow(a, n);
//}
