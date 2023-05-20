#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    //동일횟수 => Set
    unordered_map<string, set<string>> report_cnt;
	//id index
    unordered_map<string, int> id;
    for (int i = 0 ; i < id_list.size() ; i++) {
        id[ id_list[i] ] = i;
    }
    
    for (int i = 0 ; i < report.size() ; i++) {
		string user, report_str;

		stringstream ss;
        ss.str( report[i] );
		ss >> user >> report_str;
		report_cnt[ report_str ].insert( user );
	}
    
    
    for (auto a : report_cnt) {
		if ( a.second.size() >= k) {
			for (auto b : a.second){
                answer[ id [ b ] ]++;
            }
		}
	}

    return answer;
}