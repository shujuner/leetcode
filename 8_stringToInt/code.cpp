class Solution {
public:
    int myAtoi(string str) {
        int sign=1,i=0,result=0;
        while(str[i]==' ')
        {
            i++;
            continue;
        }
        int count=0;
        while(str[i]=='-'||str[i]=='+')
        {
            sign=1-2*(str[i]=='-'?1:0);
            i++;
            ++count;
        }
        if(count>=2)
            return 0;
        for(i;i<str.size()&&str[i]>='0'&&str[i]<='9';i++)
        {
            if(result>INT_MAX/10||(result==INT_MAX/10&&str[i]-'0'>7))
            {
                if(sign==1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            result=(str[i]-'0')+result*10;
        }
        return sign*result;
    }
};