#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum_queue1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long sum_queue2 = accumulate(queue2.begin(), queue2.end(), 0);      
    long long difference = abs(sum_queue1 - sum_queue2);
    
    int i = 0, j = 0;
    int temp = 0;
    
    if(sum_queue1 > sum_queue2){
        
        for( i = 0; i < queue1.size();){
            if ( temp == difference ) break;
            
            temp += 2 * queue1[i++];
            answer ++;
            
            if( temp < difference ) continue; // smaller than difference
            else if ( temp == difference) break; // answer
            else{  // larger than difference
                
                for(j ; j < queue2.size() + i;){
                    
                    if ( j < queue2.size() ) {
                        temp -= 2 * queue2[j++];
                        answer ++;
                    }
                    else{
                        temp -= 2 * queue1[ j++ - queue2.size() ];
                        answer ++;
                    }
                                        
    
                    if( temp == difference ) break;
                }
            }    
            
        }
        
        if( temp != difference)
            answer = -1;
    }
    
    else if ( sum_queue1 < sum_queue2){
        for( i = 0; i < queue2.size();){
            
            if ( temp == difference ) break; // answer
            
            temp += 2 * queue2[i++];
            answer ++;
            if( temp < difference ) continue; // smaller than difference
            
            else if ( temp == difference) break;
            else{  // larger than difference
                
                for(j ; j < queue1.size() + i;){
                    
                    if ( j < queue1.size() ) {
                        temp -= 2 * queue1[j++];
                        answer ++;
                    }
                    else{
                        temp -= 2 * queue2[ j++ - queue1.size() ];
                        answer ++;
                    }
                                        
    
                    if( temp == difference ) break;
                    
                }
            }    
            
        }
        if( temp != difference)
            answer = -1;
    }
    
    
    return answer;
}