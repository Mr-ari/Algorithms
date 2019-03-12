#include <bits/stdc++.h>
using namespace std;

void subsequences(char in[],char out[],int i,int j){

    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return ;
    }

    out[j] = in[i];
    //including the i th character
    subsequences(in,out,i+1,j+1);
    //excluding the i th charecter
    out[j] = '\0';
    subsequences(in,out,i+1,j); 
}

void subsequences_bitmasking(char in[],int n){

    for(int i = 0;i< 1<<n;i++){
        int j=0;
        for(int no=i;no>0;no=no>>1,j++){
            if(no&1){
                cout<<in[j];
            }
        }
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{
    int n=3;
    char in[1000] = "abc";
    char out[1000];
    //subsequences(in,out,0,0);
    subsequences_bitmasking(in,n);
    return 0;
}
