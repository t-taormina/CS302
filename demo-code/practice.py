import numpy as np

def main():
    #say_hello()
    #say_goodbye()
    check_out(1)
    return None

def say_hello():
    print('hello')
    return None

def say_goodbye():
    print('goodbye')
    return None

def check_out(num):
    if num >= 10:
        print('this is greater than 10')
    else:
        print('this is less than 10')
    return None

if __name__ == '__main__':
    main()