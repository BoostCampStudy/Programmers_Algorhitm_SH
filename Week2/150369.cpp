#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    int deliver_n = n - 1, pickup_n = n -1;
    long long answer = 0;
    
    
    // Start Position
    while( ((deliveries[ deliver_n ] == 0) || ( pickups[ pickup_n ] == 0 )) && ( deliver_n != -1 && pickup_n != -1 ) ) {
        if( deliver_n != -1 && !deliveries[ deliver_n ] ) deliver_n--;
        if( pickup_n != -1 && !pickups[ pickup_n ] ) pickup_n--;
        
    }
    
    int deliver_complete = 0, pickup_complete = 0;
    // Search
    
    while( !( deliver_n == -1 && pickup_n == -1) ){
        
        int delivering = 0;
        int pickuping = 0;
        if(deliver_n == -1) deliver_complete = 1;
        if(pickup_n == -1) pickup_complete = 1;
        
        if( deliver_complete )
            answer += (pickup_n + 1) * 2;
        else if( pickup_complete )
            answer += (deliver_n + 1) * 2;
        else      
            deliver_n > pickup_n ? answer += (deliver_n + 1) * 2 : answer += (pickup_n + 1) * 2;
        
        
        
        
        while( !(deliver_n == -1) ){
            
            delivering += deliveries[deliver_n];
            if(delivering < cap) deliver_n--;
            else{
                if(delivering == cap){
                    
                    deliver_n--;
                    while(1){
                        if( deliver_n == -1 ) break;
                        if( deliveries[deliver_n] > 0) break;
                        deliver_n--;
                    }
                    break;
                }
                else{
                    deliveries[deliver_n] = delivering - cap;
                    break;
                }
            }
        }
        while( !(pickup_n == -1) ) {
            
            pickuping += pickups[pickup_n];
            
            if( pickuping < cap ) pickup_n--;
            else{
                if(pickuping == cap){
                    pickup_n--;
                    while(1){
                        if( pickup_n == -1 ) break;
                        if( pickups[pickup_n] > 0) break;
                        pickup_n--;
                    }
                    break;
                }
                else{
                    pickups[pickup_n] = pickuping - cap;
                    break;
                }
            }
        }
        
        
    }
    
    return answer;
}
