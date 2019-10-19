#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	int n;
	cin >> n;

	char buffer[10];
	while (n) {
		string s = "1";

		for (int i = 2; i <= n; i++) {
			string s1 = std::to_string(i);
			if (s1 > s) {
				s = s1;
			}
		}

		cout << s << endl;
		cin >> n;
	}
}