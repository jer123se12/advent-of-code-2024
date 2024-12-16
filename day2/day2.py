total=0;
with open("input.txt", "r") as f:
	for line in f.readlines():
		ispass=True;
		stuffs=[int(x) for x in line.split(" ")]
		isacending=stuffs[0]<stuffs[1]
		for i in range(1,len(stuffs)):
			if (stuffs[i-1]<stuffs[i] != isacending):
				ispass=False
				break	
			if (abs(stuffs[i-1]-stuffs[i])<1 or abs(stuffs[i-1]-stuffs[i])<1):
				ispass=False
				break
		if (ispass):
			total+=1
print(total)
			
