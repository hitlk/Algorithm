#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define maxn 100024

struct KMP{
    int next[maxn];
    /*
    next[j] represent the longest prefix-suffix of string
    which length was k, namely p[0...j-1]. Because it means length,
    just jump next[j] when t[i] not equal p[j].
    */
    void getnext(char *str){
        int len = strlen(str);
        int i, j;
        for(i=2,j=next[1]=0; i<=len; i++){
            while(j && str[j]!=str[i-1])
                j = next[j];
            if(str[j] == str[i-1])
                j++;
            next[i] = j;
        }
    }
    void find(char *t, char *p){
        getnext(p);
        int i, j;
        for(i=0,j=0; i<strlen(t); i++){
            while(j && t[i]!=p[j])
                j = next[j];
            if(t[i] == p[j])
                j++;
        }
        printf("%s%s\n",t,p+j);
    }
    /*
    next[j] represent the end index of longest prefix-suffix,
    namely p[0...j]. Because it means index, jump next[j]
    when t[i] not equal p[j+1].
    */
    void get_next(char *str){
        int len = strlen(str);
        int i, j;
        for(i=1; j=next[0]=-1; i<len; i++){
            while(j>=0 && str[j+1]!=str[i])
                j = next[j];
            if(str[j+1] == str[i])
                j++;
            next[i] = j;
        }
    }
    void solve(char *t, char *p){
        int i, j;
        for(i=0,j=-1; i<strlen(t); i++){
            while(j>=0 && p[j+1]!=t[i])
                j = next[j];
            if(p[j+1] == t[i])
                j++;
        }
    }
};
char str[maxn], p[maxn];
KMP kmp;

int main(){
    while(scanf("%s",str) != EOF){
        strcpy(p,str);
        reverse(p,p+strlen(p));
        kmp.find(str,p);
    }
    return 0;
}
