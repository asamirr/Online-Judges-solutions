#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	string s;
	cin >> s;
	int currentCnt = 1, cnt = INT_MIN;
	for(int i = 0; i < s.size() - 1; i++){
	    if(s[i] == s[i+1]) currentCnt++;
	    else {
	        cnt = max(cnt, currentCnt);
	        currentCnt = 1;
	    }
	}
	cout <<  max(cnt, currentCnt);
	return 0;
}
