/*
 *题号：
 *时间：
 *解题思想：
 *
 */
//include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
#define maxn 8000000
char s[maxn];
char tree[maxn];

void set(int i) {
    if(tree[2*i] == 0)
    {
        set(2*i);
    }
    
    if(tree[2*i+1] == 0)
    {
        set(2*i+1);
    }
    
    if(tree[2*i] == 'B' && tree[2*i + 1] == 'B') tree[i] = 'B';
    else if(tree[2*i] == 'I' && tree[2*i + 1] == 'I') tree[i] = 'I';
    else if(tree[2*i] == 'B' && tree[2*i + 1] == 'I') tree[i] = 'F';
    else if(tree[2*i] == 'I' && tree[2*i + 1] == 'B') tree[i] = 'F';
    else if(tree[2*i] == 'F' || tree[2*i + 1] == 'F') tree[i] = 'F';
}

void print(int i) {
    if(tree[2*i] == 0 && tree[2*i+1] == 0) {
        printf("%c", tree[i]);
    }
    
    else {
        print(2*i);
        print((2*i+1));
        printf("%c", tree[i]);
    }
}

int main() {
    scanf("%d",&n);
    scanf("%s",s+1);
    int len = strlen(s+1);
    memset(tree, 0 , sizeof(tree));
    
    for(int i = 1;i <= len;i++) {
        if(s[i] == '0') tree[len + i - 1] = 'B';
        if(s[i] == '1') tree[len + i - 1] = 'I';
    }
    //set(1);
    
    for(int i = len - 1;i >= 1;i--)
    {
        if(tree[2*i] == 'B' && tree[2*i + 1] == 'B') tree[i] = 'B';
        else if(tree[2*i] == 'I' && tree[2*i + 1] == 'I') tree[i] = 'I';
        else if(tree[2*i] == 'B' && tree[2*i + 1] == 'I') tree[i] = 'F';
        else if(tree[2*i] == 'I' && tree[2*i + 1] == 'B') tree[i] = 'F';
        else if(tree[2*i] == 'F' || tree[2*i + 1] == 'F') tree[i] = 'F';
    }
    //能用循环就别用递归
    //递归容易
    
    print(1);
    putchar('\n');
    
    return 0;
}