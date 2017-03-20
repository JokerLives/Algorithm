#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

void LCM(long long N,unsigned long a[],unsigned long& cnt) {
	int i = 2;
	while (N!=1) {
		int M = floor(sqrt(N) + 0.5);
		for (;i<=M;i++) {
			int ok = 0;
			while (N%i == 0&&N!=0) {
				ok = 1;
				N = N / i;
				a[cnt] *= i;
			}
			if(ok)cnt++;
		}
		a[cnt++] = N;
		N = 1;
	}
}

int main() {
	int t = 1;
	unsigned long a[40],cnt;
	long long N,sum;
	cin >> N;
	while (N != 0) {
		if(N==2147483647)cout << "case " << t << ":" << "2147483648" << endl;
		else {
			for (int i = 0;i < 40;i++) {
				a[i] = 1;
			}
			cnt = 0;
			LCM(N, a, cnt);
			if (cnt == 0) {
				sum = N + 1;cout << "case " << t << ":" << sum << endl;
			}
			else {
				sum = 0;
				for (int i = cnt - 2;i >= 0;i--) {
					sum += a[i];
				}
				cout << "case " << t << ":" << sum << endl;
			}
		}
		cin >> N;
		t++;
	}
}
