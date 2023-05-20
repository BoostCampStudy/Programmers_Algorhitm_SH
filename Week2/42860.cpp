#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int next;
    int temp = len - 1 ;
    for(int i = 0; i < len; i++){
        answer += min(name[i] - 'A', 91 - name[i]);
        next = i + 1;
        while(next < len && name[next] == 'A') next ++;
        
        temp = min(temp, i + (len - next) + min(i, len - next) );
        
    }
                    
    answer += temp;
    return answer;
}