
def calc(a, n):
	sl = 0 
	sm = 0
	res = -20000000007
	cr = 0
	for i in a: 
		sm += i 
	for j in reversed(range(n)):
		i = n - j - 1
		if (i == n - 1):
			return res
		sl += a[i]
		sm -= a[i]
		cr = sl / (i+1) + sm / (n-i-1)
		if (cr <= res):
			return res
		res = cr


if __name__ == '__main__':
	t = int(input())
	for i in range(t):
		n = int(input())
		inp = input().split(" ")
		a = [int(x) for x in inp]
		a.sort()
		print(calc(a, n))