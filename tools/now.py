from datetime import datetime

if __name__ == '__main__':
	now = datetime.now();
	n = now.strftime("%Hh-%Mm-%Ss");
	print(n);
