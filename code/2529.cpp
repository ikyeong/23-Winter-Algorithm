#include <iostream>
using namespace std;
int N;
char seq[10];

/*
최솟값 구하기
input이 >:
(연속된 >개수 + now)에서부터 now까지 ans에 더하기
input이 <:
시작 or 마지막 index가 포함: 연속된<개수 만큼 now부터 추가하기
else:(연속된 <개수-1)만큼 now부터 추가하기
*/

string getMin(){
    int now = 0, count = 0, index = 1;
    char prev = ' ';
    string ans = "";

    if (seq[index] == '<'){
        ans += to_string(now++);
        index++;
    }

    for (;index<=N;index++){
        if (seq[index] == '>'){
            count++;
        }else{ // value가 '<'
            if (prev == '>'){
                for (int i=count;i>=0;i--){
                    ans += to_string(now+i);
                }
                now += count+1;
                count = 0;
            }else{
                ans += to_string(now++);

            }

        }
        prev = seq[index];
    } 

    if (prev == '>'){
        for (int i=count;i>=0;i--){
            ans += to_string(now+i);
        }
    }else{
        ans += to_string(now++);
    }

    return ans;
}

string getMax(){
    int now = 9, count = 0, index = 1;
    char prev = ' ';
    string ans = "";

    if (seq[index] == '>'){
        ans += to_string(now--);
        prev = seq[index];
        index++;
    }

    for (;index<=N;index++){
        if (seq[index] == '<'){
            count++;
        }else{ // value가 '>'
            if (prev == '<'){
                for (int i=count;i>=0;i--){
                    ans += to_string(now-i);
                }
                now -= count+1;
                count = 0;
            }else{
                ans += to_string(now--);

            }

        }
        prev = seq[index];
    } 

    if (prev == '<'){
        for (int i=count;i>=0;i--){
            ans += to_string(now-i);
        }
    }else{
        ans += to_string(now--);
    }

    return ans;
}

int main(){
    cin>>N;
    for (int i=1;i<=N;i++){
        cin>>seq[i];
    }
    cout<<getMax()<<endl;
    cout<<getMin()<<endl;

    return 0;
}
