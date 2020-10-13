from turtle import Screen, Turtle, Vec2D

screen = Screen()
screen.bgcolor('#527CE0')

#input points to draw the curve
print('Enter Start Point :')
x,y = map(int, input().split())
p0 = Vec2D(x,y)

print('Enter Control Point :')
x,y = map(int, input().split())
p1 = Vec2D(x,y)

print('Enter End Point :')
x,y = map(int, input().split())
p2 = Vec2D(x,y)

#lambda function to draw the bezier curve based on the paramter 't': 
#B(t) = (1 - t^2)P0 + 2(1-t)t P1 + t^2 P2 ; 0 <= t <= 1
bezier = lambda t: p1 + (1 - t)**2 * (p0 - p1) + t**2 * (p2 - p1)

turtle = Turtle()print('Enter End Point :')
x,y = map(int, input().split())
p2 = Vec2D(x,y)

#lambda function to draw the bezier curve based on the paramter 't': 
#B(t) = (1 - t^2)P0 + 2(1-t)t P1 + t^2 P2 ; 0 <= t <= 1
bezier = lambda t: p1 + (1 - t)**2 * (p0 - p1) + t**2 * (p2 - p1)

turtle = Turtle()print('Enter End Point :')
x,y = map(int, input().split())
p2 = Vec2D(x,y)

#lambda function to draw the bezier curve based on the paramter 't': 
#B(t) = (1 - t^2)P0 + 2(1-t)t P1 + t^2 P2 ; 0 <= t <= 1
bezier = lambda t: p1 + (1 - t)**2 * (p0 - p1) + t**2 * (p2 - p1)

turtle = Turtle()
turtle.penup()

for position in [p2, p1, p0]:
    turtle.goto(position)
    turtle.dot()
    x = ""
    if(position == p0):
    	x = 'Start Point'
    elif(position == p1):
    	x = 'Control Point'
    else :
    	x = 'End Point'
    point  = ('(' + str(position[0]) + ',' + str(position[1]) + ')')
    turtle.write(x + point)

turtle.pendown()

#drawing the curve based on Bezier function
t = 0
while t <= 1:
    position = bezier(t)

    turtle.setheading(turtle.towards(position))
    turtle.goto(position)

    t += 0.1

screen.exitonclick()
