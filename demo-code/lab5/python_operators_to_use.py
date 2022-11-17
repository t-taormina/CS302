#Operator overloading in Python

class Point:
    #note: don't need to overload =, ==, != 
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    # +
    def __add__(self, second):
        temp = Point(self.x + second.x, self.y + second.y)
        return temp

    # +=
    def __iadd__(self, other):
        self.x += other.x
        self.y += other.y
        return self

        
    # <<
    def __str__(self):
        return (f'x: {self.x}, y: {self.y}')

    # * 
    def __mul__(self, second):
        temp = Point(self.x * second.x, self.y * second.y)
        return temp

    # *=
    def __imul__(self, other):
        self.x *= other.x
        self.y *= other.y
        return self


class Shape:
    #don't need: =, ==, !=
    def __init__(self, x, y, color="no color"):
        self.center = Point(x,y) 
        self.color = color

    #only s + p, returns shape
    def __add__(self, second):
        temp = Shape(0, 0, self.color)
        temp.center = self.center + second
        return temp

    #shape += point, remains shape
    def __iadd__(self, other):
        self.center += other
        return self
        
    # <<
    def __str__(self):
        return f'{self.center}, color: {self.color}'
        

class Circle(Shape):
    def __init__(self, x=0, y=0, r=0, color="no color"):
        super().__init__(x,y, color)
        self.r = r
        
    # <<
    def __str__(self):
        return super().__str__() + ', ' + (f'r: {self.r}')

    # *
    def __mul__(self, second):
        pass

    # *=
    def __imul__(self, other):
        pass

    # + 
    def __add__(self, other):
        super().__add__()
        temp = self
        return temp


def test_circle():
    circle1 = Circle(1,1,2,"blue")
    circle2 = Circle(1,1,2,"red")
    c = circle1 + circle2
    print("test circle + circle:")
    print("circle1", circle1, "; circle2:", circle2)
    print("result is", c)
    print(type(c))


def test_point():
    #Test output point
    p = Point(1,2)
    print("testing print point:")
    print(p)
    print()

    #Test point + point
    print("testing point + point:")
    p2 = Point(3,4)
    print("p: " + str(p) + "; p2: " + str(p2))
    p3 = p + p2
    print("result is", p3)
    print()

    #Test point += point
    print("testing point += point")
    print("p3: " + str(p3) + "; p2: " + str(p2))
    p3 += p2
    print("result is", p3)
    print()

    #Test point * point
    print("testing point * point")
    print("p3: " + str(p3) + "; p2: " + str(p2))
    p4 = p3 * p2
    print("result is", p4)
    print()

    #Test point *= point
    print("testing point *= point")
    print("p3: " + str(p3) + "; p2: " + str(p2))
    p3 *= p2
    print("result is", p3)
    print()

def test_shape():
    #Test output shape 
    s = Shape(1,2,"blue")
    print("testing print shape:")
    print("result is", s)
    print()

    #Test shape + point
    print("testing shape + point:")
    p = Point(1,4)
    print("s: " + str(s) + "; p3: " + str(p))
    s2 = s + p
    print("result is", s2)
    print()

    #Test shape += point
    print("testing shape += point:")
    p2 = Point(3,2)
    print("s2: " + str(s2) + "; p2: " + str(p2))
    s2 += p2
    print("result is", s2)
    print()

print("What class would you like to test?")
choice = int(input("1: Point, 2: Shape, 3: Circle "))
if choice == 1:
    test_point()
elif choice == 2:
    test_shape()
else:
    test_circle()
