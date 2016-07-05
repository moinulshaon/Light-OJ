/*
	Author       :	Jan
	Problem Name :
	Algorithm    :
	Complexity   :
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	freopen("in.txt", "w", stdout);

	int cases = 5;
	printf("%d\n", cases);
	while( cases-- ) {
		puts("");

		int n = rand() % 100000 + 1, q;
		if( cases != 2) n = 100000;
		q = 50000;
		printf("%d %d\n", n, q);
		for( int i = 0; i < n; i++ ) {
			if( i ) putchar(' ');
			int x = rand() % 100001;

			if( cases == 4 ) x = rand() % 1001;
			if( cases == 5 ) x = rand() % 101;
			printf("%d", x);
		}
		puts("");
		while( q-- ) {
			int i;
			if( q % 20 == 0 ) {
				i = rand() % min(100, n) + 1;
			}
			i = rand() % n + 1;
			int j = rand() % n + 1;

			if( i > j ) swap(i, j);
			printf("%d %d\n", i, j);
		}
	}
	return 0;
}
