#include <bits/stdc++.h>

using namespace std;

int a, b, mx;

int solve(int n){
    
    if(n == 1)
        return 1;
        
    if(n % 2 == 0){
    	
	return 1 + solve(n / 2);
    }
    //Checking if it's odd using a bitwise operator because I'm such a good boy!
    else if(n & 1){
    	
        return 1 + solve((3 * n) + 1);
    }
}

int main(){

    while (cin >> a >> b){
        int maxCycle = 0;
        if(a < b){
        	for(int i = a; i <= b; i++){
            	mx = solve(i);
            	maxCycle = max(mx, maxCycle);
        	}
        }
        else{
        	for(int i = b; i <= a; i++){
            	mx = solve(i);
            	maxCycle = max(mx, maxCycle);
        	}
        }
        printf("%d %d %d\n", a, b, maxCycle);
    }
    return 0;
}