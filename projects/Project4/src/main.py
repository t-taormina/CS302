"""
Tyler Taormina
taormina@pdx.edu
"""
# cSpell:ignore Taormina
# cSpell:ignore RBnode

from events import Event, Home, Away, Vacation, date
from red_black import RBnode, RBtree
from aLL import Table
# Type Indicators.
TABLE_SIZE = 3
HOME = 0
AWAY = 1
VACATION = 2
NIL = Event("Null", "Null", date(2022, 1, 1))


def main():
    """
    test_meal_class()
    test_other_class()
    test_vacation_class()
    test_RBnode_class()
    test_node_class()
    test_table_class()
    """
    test_RBtree_class()
    return None


def test_RBtree_class():
    tree = RBtree()
    homes = build_home_list()
    away_list = build_away_list()
    vacations = build_vacation_list()
    for home in homes:
        tree.insert(home, "Review place holder.")
    for away in away_list:
        tree.insert(away, "Review place holder.")
    for vac in vacations:
        tree.insert(vac, "Review place holder.")
    # tree.display()
    print(tree)
    return None


def test_table_class():
    home_values = build_home_list()
    away_values = build_away_list()
    vacation_values = build_vacation_list()
    """
    list = LinkedList(other_values)
    list.display()
    list.remove_specific("SoCCEr")
    list.display()
    """
    table = Table(TABLE_SIZE)
    table.insert_multiple(home_values, HOME)
    table.insert_multiple(away_values, AWAY)
    table.insert_multiple(vacation_values, VACATION)
    # table.display_specific_event("ski trip")
    # table.display_all()
    table.display_next()
    table.display_next_specific(AWAY)
    # table.remove_event("bbq")
    # table.display_category(HOME)
    # print(table)


def build_home_list():
    guests = ["Tony", "Alex", "Zach", "Will", "KJ", "Mom", "Frank"]
    h1 = Home("1200PM",
              guests,
              "Family Dinner",
              date(2022, 12, 23))
    guests = ["Layna", "Ry", "Grandpa", "Grandma", "Aaron", "Mom", "Frank"]
    h2 = Home("0500PM",
              guests,
              "BBQ",
              date(2022, 1, 1))
    guests = ["Taury", "Monique"]
    h3 = Home("0800AM",
              guests,
              "Breakfast",
              date(2022, 12, 26))
    return [h1, h2, h3]


def build_away_list():
    a1 = Away("Casual",
              "1200PM",
              "Work Dinner",
              "Din Thai Fung",
              date(2022, 12, 20))
    a2 = Away("Formal",
              "0500PM",
              "Ball",
              "Convention Center",
              date(2022, 12, 22))
    a3 = Away("Semi-Formal",
              "0700PM",
              "Cocktails",
              "Kells",
              date(2022, 12, 14))
    a4 = Away("Casual",
              "0300PM",
              "Family BBQ",
              "Moms",
              date(2022, 12, 24))
    return [a1, a2, a3, a4]


def build_vacation_list():
    items = ["toiletries", "socks", "pants", "hat", "shoes",
             "slippers", "laptop", "books"]
    v1 = Vacation(date(2023, 1, 5),
                  items,
                  "Family Vacation",
                  "California",
                  date(2022, 12, 23))
    v2 = Vacation(date(2022, 12, 20),
                  items,
                  "Ski Trip",
                  "Mt. Hood",
                  date(2022, 12, 16))
    return [v1, v2]


if __name__ == '__main__':
    main()
