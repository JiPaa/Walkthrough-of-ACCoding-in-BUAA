#include<cstdio>
#include<cstring>
#define maxn 15
int a[maxn][maxn];
int n;
//hint:���ζ�ά����ʱ�����һά�ĳ��ȱ����У���ע��[][]��**��c/c++���б�������
int det(int a[][maxn], int x) {
	if (x == 1) return a[0][0];
	int b[maxn][maxn];
	int ret = 0;
	int cur = 1;
	//չ������
	for (int k = 0; k < x; ++k) {
		for (int i = 1; i < x; ++i) {
			int sit = 0;
			for (int j = 0; j < x; ++j) {
				if (j == k)continue;
				b[i - 1][sit++] = a[i][j];
			}
		}
		ret += cur * a[0][k] * det(b, x - 1);
		cur *= -1;
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("%d\n", det(a, n));
}