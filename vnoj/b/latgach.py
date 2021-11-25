
def fib(n):
	a = 0
	b = 1
	for i in range(n):
		c = a + b 
		a = b
		b = c
	return b

if __name__ == '__main__':
	t = int(input())
	for i in range(t):
		print(fib(int(input())))
