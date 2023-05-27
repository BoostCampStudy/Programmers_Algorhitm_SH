#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct pos{
    int x;
    int y;
    int distance;
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

//한 층의 visit
bool visit[5][5] = {false, };

bool search(vector<string> map, int x, int y){
    queue<pos> Queue;
    
    Queue.push({x, y, 0});
    visit[x][y] = true;
    
    while( !Queue.empty() ){
        int px = Queue.front().x;
        int py = Queue.front().y;
        int pd = Queue.front().distance;
        Queue.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = px + dx[i];
            int ny = py + dy[i];
            int nd = pd + 1;
            
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if(visit[nx][ny] || map[nx][ny] == 'X') continue;
            
            if(map[nx][ny] == 'P'){
                if( nd <= 2 ) {
                    return false;
                }
            }
            else{
                if( nd > 2 ) continue;
                Queue.push({nx, ny, nd});
                visit[nx][ny] = true;
            }
        }   
    }
    return true;
    
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i < 5; i++){
        
        for(int j = 0; j < 5; j++) for(int k = 0; k < 5; k++) visit[j][k] = false;
        
        
        bool flag = true;
        
        
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                if( places[i][j][k] == 'P' ){
                    flag = search(places[i], j, k);
                    if(flag == false) break;
                }
            }
            if(flag == false) break;
        }
        if(flag == false) answer.push_back(0);
        else answer.push_back(1);
        
    }
    
    return answer;
}