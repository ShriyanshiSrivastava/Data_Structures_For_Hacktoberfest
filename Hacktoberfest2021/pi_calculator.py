'''
This code calculates pi by choosing random point
Output is printed every 100 000 points
'''

from random import uniform

points_in = 0
points = 0

while True:
	point = [uniform(0.0, 1.0), uniform(0.0, 1.0)]
	if point[0]**2+point[1]**2 <= 1.0:
		points_in += 1
	points += 1
	if points%100000 == 0:
		print(f'[{points}]\t{points_in/points*4}{" "*10}', end='\r', flush=True)