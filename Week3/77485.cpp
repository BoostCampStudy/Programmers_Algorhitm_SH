#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> table(rows, vector<int>(columns));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns ; j++){
            table[i][j] = columns * i + j;
        }
    }
    
    for (auto query : queries) {
        int minimum = 2147483647;
        // 덮어쓰기.
        vector<vector<int>> temp = table;
        
        // 위
        for (int i = query[1]; i < query[3]; i++) {
            table[ query[0] - 1 ][i] = temp[ query[0] - 1][ i - 1 ];
            minimum = min( minimum, table[ query[0] - 1 ][i] );
        }   
        // 오
        for (int i = query[0] ; i < query[2] ; i++) {
            table[ i ][query[3] - 1] = temp[ i - 1 ][query[3] - 1];
            minimum = min(table[ i ][ query[3] - 1 ], minimum);
        }      
        // 아
        for (int i = query[3] - 1; i > query[1] - 1; i--) {
            table[ query[2] - 1 ][ i - 1 ] = temp[ query[2] - 1 ][ i ];
            minimum = min(table[ query[2] - 1 ][i - 1], minimum);
        }
        // 왼쪽의 ㅣ 부분
        for ( int i = query[2] - 1; i > query[0] - 1; i--) {
            table[ i - 1 ][ query[1] - 1 ] = temp[ i ][ query[1] - 1];
            minimum = min( table[ i - 1 ][ query[1] - 1], minimum);
        }
        answer.push_back( minimum + 1 );
    }

    
    return answer;
}