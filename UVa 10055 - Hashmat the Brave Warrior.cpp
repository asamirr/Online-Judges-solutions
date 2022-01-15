#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x, y;
    while(scanf("%lld %lld", &x , &y) != EOF){
        if(y > x)
            cout << y - x << endl;
        else cout << x - y << endl;
    }
    return 0;
}