"""
Tyler Taormina
taormina@pdx.edu
"""
# cSpell:ignore Taormina

from events import Event, Vacation


def main():
    test_vacation_class()
    return None


def test_vacation_class():
    vacation = Vacation("20221225",
                        "Family Vacation",
                        "California",
                        "20221220")
    print(vacation)
    print(repr(vacation))
    # make edits
    choice = int(input(
        'Edit Information\n==================\n' +
        '1) Edit Title \n' +
        '2) Edit Location \n' +
        '3) Edit Date\n'
        '4) Edit End Date\nInput:'))
    date_format(choice)
    arg = input('Enter the new data:')
    vacation.edit(choice, arg)
    print(vacation)
    print(repr(vacation))
    return None


def test_event_class():
    event = Event("skiing", "mt. hood", "20221220")
    print(event)
    print(repr(event))
    # make edits
    choice = int(input(
            'Edit Information\n==================\n' +
            '1) Edit Title \n' +
            '2) Edit Location \n' +
            '3) Edit Date\nInput:'))
    date_format(choice)
    arg = input('Enter the new data:')
    event.edit(choice, arg)
    print(event)
    print(repr(event))
    return None


def date_format(arg: int):
    if (arg == 3 or arg == 4):
        print('Dates should be entered in format yyyymmdd.')


if __name__ == '__main__':
    main()
