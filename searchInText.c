#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LINE 256
#define WORD 30

int get_line(char s []);

int getword(char w []);

int substring(char * str1,char * str2);

int similar(char * s, char * t, int n);

void print_lines (char * str);

void print_similar_words(char * str);

int main()
{
    char searchString[WORD], aOrb;
    getword(searchString);
    scanf(" %c\n",&aOrb);
    if(aOrb=='a')
    {
        print_lines(searchString);
    }
    else if(aOrb=='b')
    {
       print_similar_words(searchString); 
    }
    return 0;
}

int get_line(char s[])
{
    int i=0;
    char ch = '\0';
    int ret;
    ret = scanf("%c", &ch);
    while((i<LINE)){
        if (ch == '\n' || ret == EOF)
        {
            *(s+i) = '\0';
            break;
        }
        *(s+i)= ch;
        i++;
        ret = scanf("%c", &ch);
    }
    return i;
}

int getword(char w[])
{
    int i=0;
    char ch = '\0';
    int ret;
    ret = scanf("%c", &ch);
    while(i<WORD){
        if ((ch == '\n') || (ch == '\t') || (ch == ' ') || ret == EOF)
        {
            *(w+i) = '\0';
            break;
        }
        *(w+i)= ch;
        i++;
        ret = scanf("%c", &ch);
    }
    return i;
}

int substring(char * str1,char * str2)
{
    int str1Len=strlen(str1), str2Len=strlen(str2);
    int count;
    for(int k1=0; k1<=(str1Len-str2Len); k1++)
    {
        count = 0;
        for(int k2=0; k2<str2Len;k2++)
        {
            if(*(str1+k1+k2)==*(str2+k2))
            {
                count++;
            }
        }
        if(count>=str2Len)
        {
            return 1;
        }

    }
    return 0;
}

int similar(char * s, char * t, int n)
{

    int strSLen=strlen(s), strTLen=strlen(t);
    int j = 0;
    
    if(strSLen-strTLen != n)
    {
        return 0;
    }
 
    for (int i = 0; i < strSLen && j < strTLen; ++i)
    {
        if (*(s + i) == *(t + j))
            j++;
    }

    return (strTLen == j);

}

void print_lines (char * str)
{
    char theLine[LINE]= {0};
    int sum=get_line(theLine);
    while (sum!=0)
    {
        if(substring(theLine,str)==1)
        {
            printf("%s\n",theLine);
        }
        sum=get_line(theLine);
    }
}

void print_similar_words(char * str)
{
    char theWord[WORD]= {0};
    int sum=getword(theWord);
    while (sum!=0)
    {
        if(similar(theWord,str,1)==1 || similar(theWord,str,0)==1)
        {
            printf("%s\n",theWord);
        }
        sum=getword(theWord);
    }
}
