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


typedef struct {
    char data[Max];
    unsigned int length;
} SqString;

//next函数
void GetNext(SqString t,int next[])
{
    int j = 0;
    int k = -1;
    next[0] = -1;
    while (j < t.length )
    {
        if (k == -1 || t.data[j] == t.data[k])
        {
            j++;
            k++;
            next[j] = k;
            
        }
        else
            k = next[k];
    }
    
    for (int i = 0; i<t.length; i++) {
        cout<<next[i]<<" " ;
    }
    
}

//
////next函数 j从1开始
//void GEtNext1(SqString t, int next[])
//{
//    int j = 1;
//    int k = 0;
//    next[0] = 0;
//    while (j < t.length -1)
//    {
//        if (k == 0 || t.data[j] == t.data[k]) {
//            j++,k++;
//            next[j] = k;
//        }
//        else
//            k = next[k];
//    }
//
//    for (int i = 1; i<t.length; i++) {
//        cout<<next[i]<<" ";
//    }
//
//}

int KMPIndex1(SqString s, SqString t)
{
    int nextval[Max];
    int i = 0;
    int j = 0;
    
    GetNext(t, nextval);
    while (i<s.length && j<t.length)
    {
        if (j == -1 || s.data[i] == t.data[j])
        {
            i++;
            j++;
        }
        else
            j = nextval[j];
    }
    
    if (j>=t.length) {
        return (i - t.length);
        
    }
    else
        return (-1);
}



int main()
{
    
    SqString str;
    FILE *fp;
    
    char name[50];
    cout<<"请输入要读取的文件地址："<<endl;
    cin>>name;
    
    if (!fopen(name, "r")) {
        cout<<"文件打开错误！"<<endl;
    }
    
    //    str.length = (int)strlen(str.data);
    //
    //    cout<<str.length<<endl;
    //    GetNext(str, Next);
    //
    
    
    
    
    
    
}

