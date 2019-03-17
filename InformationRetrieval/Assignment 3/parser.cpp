#include <bits/stdc++.h>
using namespace std;

const int USERS = 1000;
const int ITEMS = 1700;
int matrix[USERS + 1][ITEMS + 1];
int maxuid = -1, maxmid = -1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int uid, mid, rating, ts;
	while (cin >> uid) {
		cin >> mid >> rating >> ts;
		matrix[uid][mid] = rating;
		maxuid = max(maxuid, uid);
		maxmid = max(maxmid, mid);
	}
	cout << maxuid << ' ' << maxmid << '\n';
	for (int i = 1; i <= maxuid; i++) {
		for (int j = 1; j <= maxmid; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

