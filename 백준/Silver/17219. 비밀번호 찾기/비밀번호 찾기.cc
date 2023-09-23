#include <iostream>
#include <array>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <map>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
    string id, pw;
    map <string, string> account;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> id >> pw;
        account[id] = pw;
    }
    for(int i=0; i<m; i++) {
        cin >> id;
        cout << account[id] << '\n';
    }
	return 0;
}


