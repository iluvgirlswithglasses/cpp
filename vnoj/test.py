import random

if __name__ == '__main__':
	n = int(input());
	q = int(input());
	inf = int(input());
	#
	f = open('test.inp', 'w');
	f.write('{} {}\n'.format(n, q));
	#
	for i in range(n):
		f.write('{} '.format(random.randint(1, inf)));
	f.write('\n');
	# 
	for i in range(q):
		f.write('FIND {}\n'.format(i+1));
