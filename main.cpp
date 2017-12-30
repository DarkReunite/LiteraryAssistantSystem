//
//  main.cpp
//  LiteraryAssistantSystem
//
//  Created by Dragon on 2017/12/28.
//  Copyright © 2017年 Dragon. All rights reserved.
//


#include <iostream>
using namespace std;
#define Max 100

int Next[100];
typedef char  SString[Max + 1];

void GetNext1(SString T, int next[])
{
    int j = 1;
    int k = 0;
    next[1] = 0;
    while (j < T[0] )
    {
        if (k == 0 || T[j] == T[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];
    }

}

int KMPIndex1(SString s, SString t ,int pos)
{
    int nextval[Max];
    int i = pos;
    int j = 1;
    
    GetNext1(t, nextval);
    while (i <= s[0] && j <= t[0])
    {
        if (j == 0 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
            j = nextval[j];
    }
    
    if (j >= t[0])   return (i - t[0]);
  
    else
        return (-1);
}

int length(SString str)
{
    int i=1;
    while (str[i]) i++;
    return(i-1);
}

//4.查找函数
void Search(char name[], SString keys)
{    //该函数是真个程序的重要部分，对于输入的每一个要查找的关键字，从小说文件中的逐行 读取字符串查找
    SString text;
    FILE *fp;
    int j = 0;  //列号
    int k = 0;  //用于格式的控制
    int i = 1;  //行号
    int num = 0;
    
    if (!(fp = fopen(name, "r"))) {
        printf("Open file error!\n");
        exit(0);
    }
    keys[0]=length(keys);
    cout<<&keys[1]<<"出现于:"<<endl;
    while (!feof(fp))
    {
        k = 0;
        fgets(&text[1], Max, fp);
        text[0]=length(text);
        j = KMPIndex1(text, keys, j+1);
        
        if(j!=-1)
        {
            
            cout<<"\t row = "<<i<<"\t col = "<<j;  //若匹配成功则打印行号和列号
            num++;
            k++;
        }
        while (j != -1)
        {
            //接着查找下一个匹配的单词
            j =KMPIndex1(text, keys, j+1);
            if (j != -1)
            {
                num++;
                cout<<","<<j;
            }
        }
        i++;        //行号加1
        if(k) cout<<endl;
    }//end while
    cout<<&keys[1]<<"总共出现"<<num<<"次\n"<<endl;
    
    
    
} //end find

int main()
{
    SString str[10];
    int n;
    char name[50];
    
    cout<<"请输入要读取的文件地址："<<endl;
    cin>>name;
    
    cout<<"你想查找多少个单词?(n<10)"<<endl;
    cin>>n;

    cout<<"请输入你要查找的单词："<<endl;
    for (int i = 0; i<n; i++)
        cin>>&str[i][1];
    
    
    for (int i = 0; i<n; i++)
        Search(name, str[i]);
    return 0;

}

