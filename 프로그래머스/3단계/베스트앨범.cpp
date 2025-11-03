#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct playIndex{
    int index;
    int plays;
}; 

bool cmp(pair<string, int> & a, pair<string, int> & b){
    return a.second > b.second;
}

bool cmp2(playIndex &a, playIndex & b){
    if(a.plays == b.plays){
        return a.index < b.index;
    }
    return a.plays > b.plays;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    
    vector<int> answer;
    unordered_map<string, vector<playIndex>> um;
    
    for(int i = 0 ; i < genres.size(); i++){
        um[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string, int>> unique_genres;
    
    
    for (auto & p : um){
        int sum = 0;
        
        sort(um[p.first].begin(), um[p.first].end(), cmp2);
        for(int j = 0 ; j < um[p.first].size(); j++){
            sum += um[p.first][j].plays;
        }
        unique_genres.push_back({p.first, sum});
    }
    
    sort(unique_genres.begin(), unique_genres.end(), cmp);
    
    for(int i =0 ; i < unique_genres.size(); i++){
        if(um[unique_genres[i].first].size() < 2){
            answer.push_back(um[unique_genres[i].first][0].index);
        }
        else{
            answer.push_back(um[unique_genres[i].first][0].index);
            answer.push_back(um[unique_genres[i].first][1].index);     
        }
    }
    
    return answer;
}