#include<map>  
#include<string>  
#include<iostream>  
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	map<string, int, greater<string> > name_score_map;
	name_score_map["LiMin"] = 90;
	name_score_map["ZiLinMi"] = 79;
	name_score_map["BoB"] = 92;
	//mapתvector
	vector<pair<string, int>>v(name_score_map.begin(), name_score_map.end());
	sort(v.begin(), v.end(), [](pair<string, int>a, pair<string, int>b) {
		return a.first.size() < b.first.size(); });
	for (auto c : v) {
		cout << c.first << " " << c.second << endl;
	}
	return 0;
}