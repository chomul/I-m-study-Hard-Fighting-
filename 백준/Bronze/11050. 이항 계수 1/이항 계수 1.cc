#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<cmath>
#include<string>
using namespace std;

int main() {
	int n, r;
	cin >> n >> r;
	int a = 1, b = 1, c = 1, d;
	for (int i = 1; i <= n; i++) {
		a *= i;
	}
	for (int i = 1; i <= r ; i++) {
		b *= i;
	}
	for (int i = 1; i <= n-r; i++) {
		c *= i;
	}
	d = a / (b * c);
	cout << d;

}