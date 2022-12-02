"""
def test_node_class():
    meal_node = Node(meal)
    vacation_node = Node(vacation)
    print(meal_node)
    print(vacation_node)
    return None


def test_RBnode_class():
    """
    """
    meal_node = RBnode(meal)
    vacation_node = RBnode(vacation)
    print(meal_node)
    print(vacation_node)
    return None


def get_time():
    """
    """
    user_input: str = input('Enter time in format: hhmmAM / hhmmPM\n' +
                            'For example: 0430PM\n->')
    return user_input


def get_date():
    print('No leading zeroes necessary!')
    year = int(input('Enter the year:'))
    month = int(input('Enter the month:'))
    day = int(input('Enter the day:'))
    return date(year, month, day)


def test_meal_class():
    """
    """
    print(meal)
    print(repr(meal))
    choice, arg = edit_meal_menu()
    meal.edit(choice, arg)
    print(meal)
    print(repr(meal))


def test_other_class():
    """
    """
    print(other)
    print(repr(other))
    choice, arg = edit_other_menu()
    other.edit(choice, arg)
    print(other)
    print(repr(other))


def test_vacation_class():
    """
    """
    print(vacation)
    print(repr(vacation))
    # make edits
    choice, arg = edit_vacation_menu()
    vacation.edit(choice, arg)
    print(vacation)
    print(repr(vacation))
    return None


def test_event_class():
    """
    """
    print(event)
    print(repr(event))
    return None
"""
