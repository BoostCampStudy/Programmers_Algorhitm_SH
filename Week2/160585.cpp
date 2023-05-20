#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool Check_Posible(char Key, vector<string> board){
    
    //row
    for(int i = 0; i < 3; i++){
        if( (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] == Key) ){
            return true;
        }
    }
    //column
    for(int i = 0; i < 3; i++){
        if( (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[2][i] == Key) ){

            return true;
        }
    }
    
    //Diagonals
    if( (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[2][2] == Key) ) return true;    
    if( (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[2][0] == Key)) return true;
    
    return false;
}

int cnt_Posible(char Key, vector<string> board){
    int cnt = 0;
    //row
    for(int i = 0; i < 3; i++){
        if( (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] == Key) ){
            cnt++;
        }
    }
    //column
    for(int i = 0; i < 3; i++){
        if( (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[2][i] == Key) ){

            cnt++;
        }
    }
    
    //Diagonals
    if( (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[2][2] == Key) ) cnt++;   
    if( (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[2][0] == Key)) cnt++;
    
    return cnt;
}

int solution(vector<string> board) {
    int answer = -1;
    int cnt_X = 0, cnt_O = 0;
    for( auto line : board ){
        cnt_X += count(line.begin(), line.end(), 'X');
        cnt_O += count(line.begin(), line.end(), 'O');
    }
    
    // Count 로 나누기
    if ( cnt_X > cnt_O || abs( cnt_O - cnt_X ) > 1) answer = 0;
    else if( (Check_Posible('O', board)  &&  cnt_X != cnt_O - 1) || (Check_Posible('X', board)) && cnt_X != cnt_O ){
        answer = 0;
    }
    else
        answer = 1;
        
    return answer;
}