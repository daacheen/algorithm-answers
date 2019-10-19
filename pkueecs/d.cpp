#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>

typedef long long LL;

using namespace std;

bool has4(int i) {
	while (i > 0) {
		if (i % 10 == 4) {
			return true;
		}
		i /= 10;
	}
	return false;
}

LL step(int i, int k, vector<LL>& dp) {
	if (i >= dp.size()) {
		return 0;
	}
	if (dp[i] != -1) {
		return dp[i];
	}

	LL ans = 0;
	for (int j = 1; j <= k; j++) {
		if (has4(j)) {
			continue;
		}
		ans += step(i + j, k, dp);
	}

	return dp[i] = ans;

}

int main() {
	int n, k;
	cin >> n >> k;

	while (n && k) {

		vector<LL> dp(n+1, -1);

		dp[n] = 1;
		dp[n-1] = 1;

		cout << step(0, k, dp) << endl;


		cin >> n >> k;
	}
}