#include <iostream>
#include <cmath>

using namespace std;

int N;

int main()
{
	cin >> N;

	int cnt = 0;

	while (1) {
		cnt++;
		if ((cnt * cnt) == N) {
			cout << 1;
			return 0;
		}
		else if ((cnt * cnt) > N) {
			break;
		}
	}

	cnt = 0;

	while (1) {
		cnt++;
		int x =  N - (cnt * cnt);
		if (x < 0) {
			break;
		}
		double dist = sqrt(x);
		if (dist - int(dist) == 0) {
			cout << 2;
			return 0;
		}
	}

	cnt = 0;

	while (1) {
		cnt++;
		
		if ((cnt * cnt) > N) {
			break;
		}

		for (int i = cnt;; i++) {
			int x = N - ((cnt * cnt)+(i * i));
			if (x < 0) {
				break;
			}
			double dist = sqrt(x);
			if (dist - int(dist) == 0) {
				cout << 3;
				return 0;
			}
		}
	}

	cnt = 0;

	while (1) {
		cnt++;

		if ((cnt * cnt) > N) {
			break;
		}

		for (int i = cnt;; i++) {
			if (((cnt * cnt)+(i * i)) > N) {
				break;
			}

			for (int j = i;; j++) {
				int x = N - ((cnt * cnt) + (i * i) + (j * j));
				if (x < 0) {
					break;
				}
				double dist = sqrt(x);
				if (dist - int(dist) == 0) {
					cout << 4;
					return 0;
				}
			}
		}
	}

	cout << " 틀림 ";

	return 0;
}
