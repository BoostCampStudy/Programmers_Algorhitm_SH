#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    while( n != 0 ){
        int remain = n % 3;
        n = n / 3;
        switch(remain){
            case 0 :
                answer.insert(0, "4");
                n = n - 1;
                break;
            case 1:
                answer.insert(0, "1");
                break;
            case 2:
                answer.insert(0, "2");
                break;
        }
    }
    return answer;
}