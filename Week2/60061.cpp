#include <iostream>
#include <string>
#include <vector>

using namespace std;


int** ary;

bool is_Add_Possible(vector<int> frame){
    
    switch( frame[2] ){
        
        case 0:
            // ->o. or ^o
            if( frame[1] == 0) return true;
            if ( ary[ frame[1] ][ frame[0] ] % 4 > 0 ) return true;
            else
                return false;
            break;
        case 1:
            // ->o. or ^o
            if ( ary[ frame[1] ][ frame[0] ] % 4 > 0 ) return true;
            else
                // ->^o or ->o->
                if ( (ary[ frame[1] ][ frame[0] + 1 ] % 4 == 1) ||  ary[ frame[1] ][ frame[0] + 1 ] / 4 % 2 == 1) return true;
                else
                    return false;
            break;
    }
    
}
void add_Frame( vector<int> frame ){
    
    switch( frame[2] ){
        
        case 0:
            ary[ frame[1] ][ frame[0] ] += 4;
            ary[ frame[1] + 1][ frame[0] ] += 1;
            break;
        case 1:
            // ->o. or ^o
                               
            ary[ frame[1] ][ frame[0] ] += 8;
            ary[ frame[1] ][ frame[0] + 1 ] += 2;
            break;
    }
    
}
bool is_Del_Possible(vector<int> frame, int n){
    
    switch( frame[2] ){
        
        case 0:
            // ->o. or ^o
            
            if ( ary[ frame[1] + 1 ][ frame[0] ] - 1  > 0 ){
                bool possible = false;
                int temp_x = frame[0];
                while( temp_x < n + 1) {
                    if( ary[ frame[1] + 1 ][ temp_x ] % 4 % 2 == 1 ) {
                        possible = true;
                        break;
                    }
                    else
                        temp_x ++;
                }
                
                temp_x = frame[0];
                while( temp_x > -1) {
                    if( ary[ frame[1] + 1 ][ temp_x ] % 4 % 2 == 1 ) {
                        possible = true;
                        break;
                    }
                    else
                        temp_x --;
                }
                if( possible ) return true;
                return false;
            }
            else
                return true;
            break;
        case 1:
            // 왼쪽과 아래에서 들어오는게 없고, 위로 올라가는게 있으면 false
            if ( ary[ frame[1] ][ frame[0] ] / 4 % 2 == 1 ){
                if ( ( ary[ frame[1] ][ frame[0] ] % 4 == 0 ) ) return false;
                else{
                    int temp_x = frame[0];
                    while( temp_x > -1) {
                        if( ary[ frame[1] + 1 ][ temp_x ] % 4 % 2 == 1 ) {
                            return true;
                            break;
                        }
                        else
                            temp_x --;
                    }
                    
                    if (temp_x == -1) return false;
                }
            } 
            else{
                int temp_x = frame[1] + 1;
                while( temp_x < n + 1 ){
                    // 아래에서 올라오는거 없음
                    if( ary[ temp_x ][ frame[0] ] % 4 % 2 != 1 ) {
                        // 더 갈 수 없음
                        if ( ary[ temp_x ][ frame[0] ] / 4 < 2 ){         
                            // 위로 가는거 있음
                            if( (ary[ temp_x ][ frame[0] ] / 4 % 2 == 1 ) ) return false;
                        }
                        temp_x++;
                        continue;
                    }
                    else break;
                }
                // Ary 초과.
                if ( temp_x == n + 1) return false;
            }
            return true;
            break;
    }
}
void del_Frame( vector<int> frame){
    
    switch( frame[2] ){
        
        case 0:
            ary[ frame[1] ][ frame[0] ] -= 4;
            ary[ frame[1] + 1][ frame[0] ] -= 1;
            break;
        case 1:
            // ->o. or ^o
                               
            ary[ frame[1] ][ frame[0] ] -= 8;
            ary[ frame[1] ][ frame[0] + 1 ] -= 2;
            break;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    
    vector<vector<int>> answer;
    
    // make n * n array
    ary = (int**)malloc(sizeof(int*) * (n + 1) ) ;
    for(int i = 0; i < n + 1 ; i++){
        ary[i] = (int*)malloc(sizeof(int) * ( n + 1 ) );
        for(int j = 0; j < n + 1; j++ ) ary[i][j] = 0;
    }
    
    for(int i = 0; i < build_frame.size(); i++){
        switch( build_frame[i][3] ) {
            case 0:
                if( is_Del_Possible(build_frame[i] , n) ) del_Frame( build_frame[i] );
                
                cout << endl;
                break;
            case 1:
                if( is_Add_Possible(build_frame[i]) ) add_Frame( build_frame[i] );
                break;    
        }
    }
    
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < n + 1; j++ ){
            if( ary[j][i] / 4 % 2 == 1 ){
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                temp.push_back(0);
                answer.push_back( temp );
            }
            if( ary[j][i] / 4 / 2 == 1 ){
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                temp.push_back(1);
                answer.push_back( temp );
            }
        }
    }
    
    return answer;
}