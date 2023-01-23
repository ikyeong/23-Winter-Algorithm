#include <iostream>
#include <algorithm>
using namespace std;
//최소 모음 1개(a e i o u), 자음 2개 존재
int L, C, countVowel;
char alphabet[16];

bool isVowel(char ch){
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        return true;
    }
    return false;
}

void DFS(int x, int pos, string ans){
    if (x == L){
        if (countVowel > 0 && L-countVowel > 1) cout<<ans<<endl;
    }
    else{
        for (int i=pos;i<=C;i++){
            if (isVowel(alphabet[i])) countVowel ++;
            DFS(x+1, i+1, ans+alphabet[i]);
            if (isVowel(alphabet[i])) countVowel--;
        }
    }
}

int main(){
    cin>>L>>C;
    for (int i=1;i<=C;i++) cin>>alphabet[i];

    sort(alphabet+1, alphabet+C+1);
    //sort(alphabet, alphabet+C) 에서 수정

    DFS(0,1,"");

    return 0;
}
