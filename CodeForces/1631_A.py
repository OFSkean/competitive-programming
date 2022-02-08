import sys

n = sys.stdin.readline()
for i in range(int(n)):
	l = int(sys.stdin.readline())
	a = [int(x) for x in sys.stdin.readline().split()]
	b = [int(x) for x in sys.stdin.readline().split()]
	
	for j in range(l):
		if (a[j] > b[j]):
			a[j], b[j] = b[j], a[j]
			
	print(max(a) * max(b))
