#include <iostream>
#include <cstring>
using namespace std;
int gear[5][8], top[5];
bool visit[5];

void change(int gearNumber, int direction){ //12시 방향을 가리키는 index 바꿈
    if (direction > 0){
        top[gearNumber] = (top[gearNumber] + 8 - direction)%8;
    }else{
        top[gearNumber] = (top[gearNumber] - direction)%8;
    }
}

bool isDifferent(int front, int back){ // 마주보는 위치에서 극이 다르다면 true, 극이 같다면 false
    int frontIndex = (top[front]+2)%8;
    int backIndex = (top[back]+6)%8;
    if (gear[front][frontIndex] != gear[back][backIndex]) return true;
    return false;
}

void turn(int gearNumber, int direction){
    visit[gearNumber] = true;
    if (gearNumber == 1){
        if (!visit[gearNumber+1] && isDifferent(gearNumber,gearNumber+1)){
            turn(gearNumber+1,-direction);
        }
    }else if (gearNumber == 4){
        if (!visit[gearNumber-1] && isDifferent(gearNumber-1,gearNumber)){
            turn(gearNumber-1,-direction);
        }
    }else{ // 두 상황은 동시에 일어날 수 있음
        if (!visit[gearNumber-1] && isDifferent(gearNumber-1,gearNumber)){
            turn(gearNumber-1,-direction);
        }
        if (!visit[gearNumber+1] && isDifferent(gearNumber,gearNumber+1)){
            turn(gearNumber+1,-direction);
        }
    }
    change(gearNumber, direction);
    visit[gearNumber] = false;
}

int main(){
    for (int i=1;i<=4;i++){
        for (int j=0;j<8;j++){
            char c;
            cin>>c;
            gear[i][j] = c-'0';
        }
    }
    int count;
    cin>>count;
    while(count-->0){
        int gearNumber, direction;
        cin>>gearNumber>>direction;
        turn(gearNumber, direction);
    }

    int score = gear[1][top[1]]*1 + gear[2][top[2]]*2 + gear[3][top[3]]*4 + gear[4][top[4]]*8;
    cout<<score<<endl;
    return 0;
}
