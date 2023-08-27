#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll mod(ll A, ll B, ll C) 
{
	if (B==1) return A%C;
	else {
	    // Go recursion
		ll half = mod(A, (int)(B/2), C);
		ll tmp = (half*half) % C;

		if (B%2 == 0) 
			return tmp;
		else 
			return (tmp * (A%C)) % C;
	}
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;
	int answer = mod(A, B, C);
	cout << answer;
}
