#include <iostream>
using namespace std;
int M;
int set;

void add(){
    int n;
    cin>>n;
    set = set | (1<<n);
}

void remove(){
    int n;
    cin>>n;
    set = set & (~(1<<n));
}

void check(){
    int n;
    cin>>n;
    int ans = (set>>n) & 1;
    cout<<ans<<"\n"; //endl에서 시간초과로 수정
}

void toggle(){
    int n;
    cin>>n;
    set = set ^ (1<<n);
}

void all(){
    set = ~(set & 0);
}

void empty(){
    set = set & 0;
}

int main(){
    //시간초과 오류로 추가
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>M;

    for (int i=0;i<M;i++){
        string command;
        cin>>command;
        if (command == "add") add();
        else if (command == "remove") remove();
        else if (command == "check") check();
        else if (command == "toggle") toggle();
        else if (command == "all") all();
        else if (command == "empty") empty();
    }
    
    return 0;
}
