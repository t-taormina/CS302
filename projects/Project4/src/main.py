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
    # choice = int(input(
        # 'Edit Information\n==================\n' +
        # '1) Edit Title \n' +
        # '2) Edit Location \n' +
        # '3) Edit Date\nInput:'))
    # arg = input('Enter the new data:')
    # event.edit(choice, arg)
    # print(event)
    # print(repr(event))

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
    arg = input('Enter the new data:')
    event.edit(choice, arg)
    print(event)
    print(repr(event))

    return None


if __name__ == '__main__':
    main()
