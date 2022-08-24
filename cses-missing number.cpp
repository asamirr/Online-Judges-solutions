#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n, x;
	cin >> n;
	unordered_set<int> st;
	for(int i = 0; i < n; i++){
		cin >> x;
		st.insert(x);
	}
	for(int i = 0; i < n; i++){
		if(st.find(n - i) == st.end()){
			cout << n - i;
			break;
		}
	}
	return 0;
}
