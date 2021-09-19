
import sys

def __print(s):
	sys.stdout.write(s+"\n")

def __input():
	return sys.stdin.readline()

def __pow(v):
	return 10**v

if __name__ == '__main__':
	q = int(__input())
	for _t in range(q):
		arr = list(map(int, __input().split(" ")))
		x = arr[0] * __pow(arr[1])
		y = arr[2] * __pow(arr[3])
		if x > y:
			__print("X > Y")
		elif x < y:
			__print("X < Y")
		else:
			__print("X = Y")