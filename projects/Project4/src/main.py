"""
Tyler Taormina
taormina@pdx.edu
"""
# cSpell:ignore Taormina
# cSpell:ignore RBnode

from events import Event, Home, Away, Vacation, date
from red_black import RBnode
from aLL import Table
TABLE_SIZE = 3
HOME = 0
AWAY = 1
VACATION = 2


def main():
    """
    test_meal_class()
    test_other_class()
    test_vacation_class()
    test_RBnode_class()
    test_node_class()
    """
    test_table_class()
    return None


def test_table_class():
    home_values = build_home_list()
    # away_values = build_away_list()
    # vacation_values = build_vacation_list()
    """
    list = LinkedList(other_values)
    list.display()
    list.remove_specific("SoCCEr")
    list.display()
    """
    table = Table(TABLE_SIZE)
    table.insert(home_values, HOME)
    # table.insert(meal_values, MEAL)
    # table.insert(other_values, OTHER)
    # table.display_specific_event("socCer")
    # table.display_category(HOME)
    print(table)
    # table.remove_event("day TRIP")
    # table.display_category(VACATION)


def build_home_list():
    guests = ["Tony", "Alex", "Zach", "Will", "KJ", "Mom", "Frank"]
    h1 = Home("1200PM",
              guests,
              "Family Dinner",
              date(2022, 12, 23))
    h2 = Home("0500PM",
              guests,
              "BBQ",
              date(2022, 1, 1))
    h3 = Home("0800AM",
              guests,
              "Breakfast",
              date(2022, 12, 26))
    return [h1, h2, h3]


if __name__ == '__main__':
    main()
