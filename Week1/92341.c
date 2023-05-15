#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using namespace std;

int str_to_time(string in, string out) {
    int hour = stoi(out.substr(0,2)) - stoi(in.substr(0,2));
    int min = stoi(out.substr(3,2)) - stoi(in.substr(3,2));
    
    int time = hour * 60 +min;
    return time;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<string,string> map_record;
    unordered_map<string, int> result;
    
    for(int i = 0; i< records.size(); i++) {
        stringstream ss(records[i]);
        string temp;
        vector<string> info; // information of record [0] = time, record[1] = number, record[2] = type
        
        while (ss >> temp) info.push_back(temp);
        if(info[2] == "IN") map_record.insert({info[1], info[0]});
        else{
            string in_time = map_record[info[1]]; // in time
            map_record.erase(info[1]); // delete inform
            
            int time = abs(str_to_time(in_time, info[0]));
            result.insert({info[1], time});
        }
    }
    
     for(auto it : map_record) {
        if(!map_record[it.first].empty())
            result.insert( {it.first, abs(str_to_time(it.second, "23:59")) } );
    }
    
    for(auto it : result) {
        int price = 0;
        if(it.second <= fees[0]) price = fees[1];
        else {
            price = fees[1] + ceil((double)(it.second - fees[0]) / fees[2]) * fees[3];
        }
        answer.push_back(price);
        
    }
    
    
    return answer;
}