/*************************************************

Copyright:lengzijian

Author:lengzijian

Date:2012-09-20 

Description:扩展python的二进制操作

**************************************************/




#include <stdio.h>
#include <string.h>

/*************************************************
Function:       btod
Description:    二进制char转换成十进制
Calls:         
Input:          char *bstr 输入二进制字符串
Output:         对应二进制字符串的整形
Return:         Output
Others:     
*************************************************/


int btod(char *bstr)
{
    int d = 0;
    unsigned int len = strlen(bstr);
    
    if(len > 10)
        return -1;
        
    len--;
    
    int i = 0;
    for(i = 0; i <= len; i++)
    {
        int tmp = bstr[i] - '0';
        if(tmp > 1)
            return -1;
        d += tmp * ( 1 << (len - i));
    }
    
    return d;
}


/*************************************************
Function:       dtob
Description:    十进制转化成二进制
Calls:         
Input:          int d       :输入的十进制
                int count   :字符串位数，如果为6位，那么count=64
                char *bstr  :用于返回二进制字符串
Output:         bstr:二进制字符串，返回二进制字符串中1的个数。
Return:         二进制字符串中1的个数
Others:     
*************************************************/
int dtob(int d, int count, char *bstr)
{
    if(d < 0)
        return -1;
        
    int mod = 0;
    char tmpstr[64];
    bzero(tmpstr, sizeof(tmpstr));
    bzero(bstr, strlen(bstr));
    
    int i = 0;
    int one_num = 0;
    while( (count-i) != 0)
    {
        if(d > 0)
        {
            mod = d % 2;
            d /=2;
            tmpstr[i] = mod + '0';
            if(mod == 1)
                one_num ++;
        }
        else
        {
            tmpstr[i] = '0';
        }
        i++;
    }
    unsigned int len = strlen(tmpstr);
    for(i = 0; i < len; i++)
    {
        bstr[i] = tmpstr[len - i -1];
    }
    
    return one_num;
}

