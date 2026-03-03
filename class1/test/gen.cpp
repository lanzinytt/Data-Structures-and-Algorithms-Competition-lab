#include <bits/stdc++.h>
using namespace std;

int main() {

	mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
	int T = uniform_int_distribution<int>(1, 10)(rng);

	for (int t = 0; t < T; ++t) {
		int N = uniform_int_distribution<int>(1, 10000)(rng);
		cout << N << '\n';
		for (int i = 0; i < N; ++i) {
			int D = uniform_int_distribution<int>(1, 10000)(rng);
			int C = uniform_int_distribution<int>(1, 10000)(rng);
			cout<<D<<' '<<C<<endl;
		}
	}
	cout<<0<<endl;
	return 0;
}

