"""
CS302 Project: Holiday Events
Author: Tyler Taormina
Date: 11.14.2022
Credits: NA

This file contains the client code for program 4/5.
"""
# cSpell:ignore Taormina
import random
from events import Event, Home, Away, Vacation, date
from red_black import RBtree
from aLL import Table

# Type Indicators.
HOME = 0
AWAY = 1
VACATION = 2
TYPE_INDICATORS = [HOME, AWAY, VACATION]
TABLE_SIZE = 3
NIL = Event("Null", "Null", date(2022, 1, 1))
ENTER = 'PRESS ENTER TO CONTINUE:'
CENTER = 80
MAIN_MENU_SIZE = 10


class Client:
    """Initializes table, empty tree, and a filled test tree"""
    def __init__(self):
        self._table = Table(TABLE_SIZE)
        self._tree = RBtree()
        self._test_tree = RBtree()
        self.build()

    def run(self):
        """Client driver"""
        self.welcome()
        self.intro()
        flag = True
        while flag:
            self.menu()
            option = self.get_menu_choice(MAIN_MENU_SIZE+1)
            flag = self.process_menu_choice(option)
        return

    def build(self):
        """Fills test tree and tables."""
        self.build_home_list()
        self.build_away_list()
        self.build_vacation_list()
        return None

    def build_home_list(self):
        """Fills test tree and table with Home Events."""
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
        home_values = [h1, h2, h3]
        reviews = self.build_reviews(home_values)
        self._table.insert_multiple(home_values, HOME)
        self._test_tree.insert_multiple(home_values, reviews)
        return None

    def build_reviews(self, values):
        """Builds a list of reviews for testing."""
        testing = ["It was fun.", "It was amazing.", "I'd never do it again",
                   "Plan a little differently next year", "YESSSSS",
                   "Invite Mom to this.", "Call Frank about this one.",
                   "Lets find a better venue", "Hopefully I am not sick"]
        reviews = []
        for i in range(len(values)):
            num = random.randint(0, len(testing)-1)
            reviews.append(testing[num])
        return reviews

    def build_away_list(self):
        """Fills test tree and table with Away Events."""
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
        away_values = [a1, a2, a3, a4]
        reviews = self.build_reviews(away_values)
        self._table.insert_multiple(away_values, AWAY)
        self._test_tree.insert_multiple(away_values, reviews)
        return

    def build_vacation_list(self):
        """Fills test tree and table with Vacation Events."""
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
        vacation_values = [v1, v2]
        reviews = self.build_reviews(vacation_values)
        self._table.insert_multiple(vacation_values, VACATION)
        self._test_tree.insert_multiple(vacation_values, reviews)
        return

    def welcome(self):
        """Welcome message"""
        s = 'Program 4/5 by Tyler Taormina'
        print('\n' * 4)
        s = s.center(CENTER)
        print(s)
        print('\n' * 4)
        input(ENTER)
        return

    def intro(self):
        """Brief introductory information."""
        s = """
        Please read program specifications found in README.md\n
        For testing purposes I have prebuilt the table data
        structure. Feel free to add to it. I will refer to the
        table as calendar and I will refer to the tree as
        completed list. As events are attended, they will be moved
        from the calendar to the list(from table -> tree). A review
        will need to inserted during this process. Happy Holidays!\n
        """
        s = s.center(CENTER)
        print(s)

    def menu(self):
        """Displays main menu."""
        title = "MENU"
        menu = """
        ================================================
        1)   View all Events in the Calendar.
        2)   View the next Event in the Calendar.
        3)   View all Events of a specific category in the Calendar.
        4)   Add an Event to the Calendar.
        5)   Attend an Event and leave a review.
        6)   Cancel an event.
        7)   View attended events.
        8)   Find Event.
        9)   Print Tree with Red/Black and Level Indicators for Verification
        10)  Exit
        """
        title = title.center(CENTER - 20)
        menu = menu.center(CENTER)
        print(title)
        print(menu)

    def get_menu_choice(self, size):
        """Returns integer selection within bounds set by size argument."""
        flag = True
        option = 0
        while flag:
            option = input('->')
            try:
                if 0 < int(option) < size:
                    flag = False
                else:
                    print('The menu choice you have selected is out of bounds')
            except ValueError:
                print('Enter a number')
        return int(option)

    def process_menu_choice(self, num):
        """Calls corresponding functions to menu choice from user."""
        flag = True
        match num:
            case 1:  # display all
                print('\n')
                self._table.display_all()
                input(ENTER)
                print('\n\n')

            case 2:  # display next
                print('\n')
                self._table.display_next()
                input(ENTER)
                print('\n\n')

            case 3:  # displays only events the chosen category
                print('\n')
                category = self.get_category()  # line: 229
                self._table.display_category(category-1)
                input(ENTER)
                print('\n\n')

            case 4:
                print('\n')
                s = 'What kind of event is this?'
                self.center_print(s)
                category = self.get_category()
                self._table.insert(self.make_event(category),
                                   TYPE_INDICATORS[category-1])
                print('\n\n')

            case 5:
                print('\n')
                s = 'Enter the title or name of the event you are attending'
                self.center_print(s)
                arg = input('->')
                data = self._table.retrieve_event(arg)
                if data:
                    s = 'Retrieving...'
                    self.center_print(s)
                    self._table.remove_event(arg)
                    s = 'Enter a review or notes on the event if you like: '
                    self.center_print(s)
                    review = input('->')
                    self._tree.insert(data, review)
                    print('\n\n')
                else:
                    s = 'Event not found!'
                    self.center_print(s)
                    print('\n\n')

            case 6:
                print('\n')
                s = """
                Enter the title or name of the event you would
                like to cancel:
                """
                self.center_print(s)
                arg = input('->')
                data = self._table.retrieve_event(arg)
                if data:
                    self._table.remove_event(arg)
                    self.center_print('Removing...')
                    print('\n\n')
                else:
                    self.center_print('Event not found')
                    print('\n\n')

            case 7:
                print('\n')
                self._tree.display()
                print('\n\n')
            case 8:
                print('\n')
                s = """
                Enter the title or name of the event you would
                like to find:
                """
                self.center_print(s)
                arg = input('->')
                data = self._table.retrieve_event(arg)
                if data:
                    self.center_print('Found in your calendar!')
                    print(data)
                    print('\n\n')
                else:
                    data = self._tree.retrieve(arg)
                    if data:
                        self.center_print('Found in the attended events list!')
                        print(data)
                        print('\n\n')
                    else:
                        self.center_print('Event not found.')
                        print('\n\n')
            case 9:
                print('\n\n')
                print(self._tree)
                print('\n\n')

            case 10:
                print('\n\n')
                s = "Exiting..."
                print(s.center(CENTER))
                flag = False
        return flag

    def get_category(self):
        """Determines category from user input."""
        menu = """
        1)  Home Event/s.
        2)  Away Event/s.
        3)  Vacation Event/s.
        """
        menu = menu.center(CENTER)
        print(menu)
        return self.get_menu_choice(TABLE_SIZE+1)

    def make_event(self, category):
        """Build event based on category argument."""
        data = None
        match category:
            case 1:
                data = self.build_home()
            case 2:
                data = self.build_away()
            case 3:
                data = self.build_vacation()
        return data

    def build_home(self):
        """Build Home Event."""
        time = self.get_time()
        s = 'Please enter a guest'
        self.center_print(s)
        guests = self.build_list()
        s = 'Enter the name of the Event'
        self.center_print(s)
        name = input('->')
        date = self.get_date()
        return Home(time, guests, name, date)

    def build_away(self):
        """Build Away Event."""
        s = 'Enter the dress code for the Event'
        self.center_print(s)
        dc = input('->')
        time = self.get_time()
        s = 'Enter the name of the Event'
        self.center_print(s)
        name = input('->')
        s = 'Enter the location of the Event'
        self.center_print(s)
        location = input('->')
        date = self.get_date()
        return Away(dc, time, name, location, date)

    def build_vacation(self):
        """Build Vacation Event."""
        s = 'Please enter the starting date'
        self.center_print(s)
        start_date = self.get_date()
        s = 'Please enter the ending date'
        self.center_print(s)
        end_date = self.get_date()
        s = 'Please enter an item you need to pack...'
        self.center_print(s)
        pack = self.build_list()
        s = 'Enter the location of the Vacation'
        self.center_print(s)
        loc = input('->')
        s = 'Enter the name of the Vacation'
        self.center_print(s)
        name = input('->')
        return Vacation(end_date, pack, name, loc, start_date)

    def get_time(self):
        """Return string representing time."""
        self.center_print('Enter time in format: hhmmAM / hhmmPM\n' +
                          'For example: 0430PM')
        user_input: str = input('->')
        return user_input

    def build_list(self):
        """Returns a list filled with user input."""
        list = []
        flag = True
        while flag:
            person = input('->')
            list.append(person)
            ans = input('Add another (y/n): ')
            if ans.lower() == 'n':
                flag = False
            else:
                self.center_print("Enter another: ")
        return list

    def get_date(self):
        """Returns date object."""
        self.center_print('Enter the year')
        y = input('->')
        self.center_print('Enter the month with no leading zeroes')
        m = input('->')
        self.center_print('Enter the day with no leading zeroes')
        d = input('->')
        try:
            data = date(int(y), int(m), int(d))
            return data
        except ValueError:
            print('Invalid date')
            return self.get_date()

    def center_print(self, arg):
        """Prints centered."""
        arg = arg.center(CENTER)
        print(arg)
        return
