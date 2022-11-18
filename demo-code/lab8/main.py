# Tyler Taormina Lab 8


import os 

class Person:
    def __init__(self):
        self._name = None

    def read(self):
        temp = input('Please enter your name: ')
        self.name = temp

    def equals(self, person):
        if self._name.upper() == person._name.upper():
            return True
        return False




class Demo1: 
    def __init__(self, name, age): 
        self.name = name 
        self.age = age 

    def read(self):
        self.name = input('Please enter your name: ')
        done = Falue
        while not done:
            temp_num = input('Please enter your age: ')
            try: 
                self.age = int(temp_num)
                done = True
            except ValueError:
                print('Your age needs to be a number that is greater than 0!')
        return None

    def display(self):
        print(f'Name: {self.name}, Age: {self.age}')

    def display_odd(self, num):
        for i in range(num):
            if i % 2 == 0 and i >= num - 2:
                    print(i, end = '\n')
            elif i % 2 == 0:
                print(i, end = ', ')
        print()
        return None
    
def main(): 
    tyler = Person();
    tyler.read();
    taury = Person();
    taury.read();
    if tyler.equals(taury):
        print('The names are equal!')

    #object = Demo1('Tyler', 28)         #create an object of class demo1
    #object.read()
    #object.display_odd(10)
    #object.display()

if __name__ == '__main__':
    main()
