"""
Tyler Taormina
taormina@pdx.edu
"""
# cSpell:ignore Taormina

from events import Event, Vacation, Meal, Other


def main():
    test_meal_class()
    test_other_class()
    test_vacation_class()
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
