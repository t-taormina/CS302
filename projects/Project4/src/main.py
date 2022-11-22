"""
Tyler Taormina
taormina@pdx.edu
"""
# cSpell:ignore Taormina

from events import Event


def main():
    test_classes()
    return None


def test_classes():
    event = Event("skiing", "mt. hood", "20221220")
    print(event)
    print(repr(event))
    # make edits
    choice = int(input(
            'Edit Information\n==================\n' +
            '1) Edit Title \n' +
            '2) Edit Location \n' +
            '3) Edit Date\nInput:'))
    event.edit(choice)
    print(event)
    print(repr(event))

    return None


if __name__ == '__main__':
    main()
