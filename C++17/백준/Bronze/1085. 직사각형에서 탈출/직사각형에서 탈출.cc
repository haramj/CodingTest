#include <cstdio>

int main() {
#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif // _WIN32
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	
	int min = x;
	if (y < min) min = y;
	if (w - x < min) min = w - x;
	if (h - y < min) min = h - y;

	printf("%d\n", min);
	return 0;
}