// Template Header
#include <bits/stdc++.h>
using namespace std;


int N;

int count_distinct(const vector<string>& ids){

	map<string,int> Hash; 
	
// Submitted Area
    for (const auto&id : ids) Hash[id]++;
    return Hash.size();
// Template Fooster

}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> N;
	vector<string> ids(N);
	
	for (int i = 0; i < N; i++) cin >> ids[i];
		
	cout << count_distinct(ids);

	return 0;
}

