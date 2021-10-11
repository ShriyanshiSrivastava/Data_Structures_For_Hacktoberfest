import random   

try:
	n=int(input("Enter the no. of digits required in pin in number "))
	pin = lambda: ''.join([str(random.randint(1,9)) for i in range(n)])
	print(pin())
	 
except ValueError:
	print("PLease enter a number only")

except:
	print('There has been some error')