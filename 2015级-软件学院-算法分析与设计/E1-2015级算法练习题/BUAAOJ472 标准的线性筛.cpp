#include<cstdio>
#include<cstring>
#define maxn 25000010
//100w�������У�ż������ȫ�������ǣ������2�Ļ���ֱ�����yes
//���Ǻ�a[i]��ʾ����2*i+1�����Ƿ�������
/*
1��������������ֱ�Ӹ�ֵfalse
3�ǣ���ô9��15��һ������ 1 4 7 10�ȶ����Ա�ȥ���ˣ���ֱ�Ӽ�k�����false����

*/

bool isPrime[maxn];
//bool skip[maxn];
int countPrime[maxn];
inline void initial() {
	memset(isPrime, 1, sizeof(isPrime));
	for (int i = 1; i < maxn; ++i) {
		if (isPrime[i]) {
			int k = (i << 1) + 1;
			for (int j = i + k; j < maxn; j += k) {
				isPrime[j] = false;
			}
		}
	}

	countPrime[1] = 2;
	for (int i = 2; i < maxn; ++i)countPrime[i] = countPrime[i - 1] + isPrime[i];
	//4��3����������һ��������ֱ��������n/2-1����
}

int main() {
	
	int n;
	initial();
	while (scanf("%d", &n) != EOF) {
		if (n == 1)printf("0\n");
		else if (n == 2)printf("1\n");
		else printf("%d\n", countPrime[(n - 1) >> 1]);
			
	}

}