from random import *

list=[]

for i in range(150):
	list.append(randint(250,500))
shuffle(list)

print(list)