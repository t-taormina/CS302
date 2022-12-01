"""
Tyler Taormina
taormina@pdx.edu
"""
# cSpell:ignore Taormina
# cSpell:ignore RBnode

from events import Event, Vacation, Meal, Other
from red_black import RBnode
from aLL import Node, LinkedList, Table
TABLE_SIZE = 3
VACATION = 0
MEAL = 1
OTHER = 2


def main():
    """
    test_meal_class()
    test_other_class()
    test_vacation_class()
    test_RBnode_class()
    test_node_class()
    """
    test_linked_list_class()
    return None


def test_linked_list_class():
    v1 = Vacation("20221225",
                  "day trip",
                  "oregon",
                  "20221220")

    v2 = Vacation("20221225",
                  "Family Vacation",
                  "California",
                  "20221220")

    v3 = Vacation("20221225",
                  "holiday",
                  "new york",
                  "20221220")

    v4 = Vacation("20221225",
                  "beaches",
                  "costa mesa",
                  "20221220")

    values = [v1, v2, v3, v4]
    """
    list = LinkedList(values)
    list.insert(v1)
    list.insert(v2)
    list.display()
    """
    table = Table(TABLE_SIZE)
    table.insert(values, 0)
    table.display_all()


def test_node_class():
    meal = Meal("Casual",
                "0500PM",
                "Work Dinner",
                "Applebees",
                "20221224")
    vacation = Vacation("20221225",
                        "Family Vacation",
                        "California",
                        "20221220")
    meal_node = Node(meal)
    vacation_node = Node(vacation)
    print(meal_node)
    print(vacation_node)
    return None


def test_RBnode_class():
    """
    """
    meal = Meal("Casual",
                "0500PM",
                "Work Dinner",
                "Applebees",
                "20221224")
    vacation = Vacation("20221225",
                        "Family Vacation",
                        "California",
                        "20221220")
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


def get_duration():
    user_input: str = input('Enter duration in format: hh\n' +
                            'For example: 01 for one hour\n->')
    return user_input


def get_date():
    user_input: str = input('Dates should be entered in format: yyyymmdd\n')
    return user_input


def menu_core():
    """
    """
    return ('Edit Information\n==================\n' +
            '1) Edit Title \n' +
            '2) Edit Location \n' +
            '3) Edit Date\n')


def meal_menu():
    """
    """
    return '4) Edit Dress Code\n5) Edit Start Time\n->'


def vacation_menu():
    """
    """
    return '4) Edit End Date\n->'


def other_menu():
    """
    """
    return '4) Edit Duration\n5) Edit Start Time\n->'


def collect_vacation_argument(choice: int):
    """
    """
    if choice == 3 or choice == 4:
        arg = get_date()
    else:
        arg = input('Enter the new data:\n->')
    return arg


def collect_meal_argument(choice: int):
    """
    """
    if choice == 3:
        arg = get_date()
    elif choice == 5:
        arg = get_time()
    else:
        arg = input('Enter the new data:\n->')
    return arg


def collect_other_argument(choice: int):
    """
    """
    if choice == 3:
        arg = get_date()
    elif choice == 4:
        arg = get_duration()
    elif choice == 5:
        arg = get_time()
    else:
        arg = input('Enter the new data:\n->')
    return arg


def edit_meal_menu():
    """
    """
    choice = int(input(menu_core() + meal_menu()))
    arg = collect_meal_argument(choice)
    return choice, arg


def edit_vacation_menu():
    """
    """
    choice = int(input(menu_core() + vacation_menu()))
    arg = collect_vacation_argument(choice)
    return choice, arg


def edit_other_menu():
    """
    """
    choice = int(input(menu_core() + other_menu()))
    arg = collect_other_argument(choice)
    return choice, arg


def test_meal_class():
    """
    """
    meal = Meal("Casual",
                "0500PM",
                "Work Dinner",
                "Applebees",
                "20221224")
    print(meal)
    print(repr(meal))
    choice, arg = edit_meal_menu()
    meal.edit(choice, arg)
    print(meal)
    print(repr(meal))


def test_other_class():
    """
    """
    other = Other("0500PM",
                  "2",
                  "Work Dinner",
                  "Applebees",
                  "20221224")
    print(other)
    print(repr(other))
    choice, arg = edit_other_menu()
    other.edit(choice, arg)
    print(other)
    print(repr(other))


def test_vacation_class():
    """
    """
    vacation = Vacation("20221225",
                        "Family Vacation",
                        "California",
                        "20221220")
    print(vacation)
    print(repr(vacation))
    # make edits
    choice, arg = edit_vacation_menu()
    vacation.edit(choice, arg)
    print(vacation)
    print(repr(vacation))

    # Copy works for objects
    copy_vacation = vacation
    print('\n' + copy_vacation.__str__())
    return None


def test_event_class():
    """
    """
    event = Event("skiing", "mt. hood", "20221220")
    print(event)
    print(repr(event))
    # make edits
    return None


if __name__ == '__main__':
    main()
