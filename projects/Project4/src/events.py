"""
CS302 Project: Holiday Events
Author: Tyler Taormina
Date: 11.14.2022
Credits: NA

This file contains the hierarchy used in this project.
"""
# cSpell:ignore Taormina

from datetime import date


class Event:
    """Base class for event hierarchy."""
    def __init__(self, title: str, location: str, date: date):
        """Initializes Event object."""
        self._title = title
        self._location = location
        self._date = date

    def __str__(self):
        """Format _date and returns a formatted string for all data members."""
        return (f'Title: {self._title}\n' +
                f'Location: {self._location}\n' +
                f'Date: {self._date}\n')

    def __repr__(self):
        """Returns string repr of Event object."""
        return (f"Event(title='{self._title}', " +
                f"location='{self._location}', " +
                f"date='{self._date}')")

    def __lt__(self, other):
        """
        """
        if self._title.lower() < other._title.lower():
            return True
        else:
            return False

    def __ge__(self, other):
        """Compares two Event objects titles. Alphabetically determined."""
        if self._title.lower() >= other._title.lower():
            return True
        else:
            return False

    def edit_title(self, arg: str):
        """Changes data member _title to argument passed in parameter."""
        self._title = arg
        return None

    def edit_location(self, arg: str):
        """Changes data member _location to argument passed in parameter."""
        self._location = arg
        return None

    def edit_date(self, arg: date):
        """Changes data member _date to argument passed in parameter."""
        self._date = date
        return None

    def match(self, arg: str):
        """Determines if an object has a _title matching the argument passed.
        """
        if arg.lower() == self._title.lower():
            return True
        return False

    def match_node(self, other):
        """
        """
        if other._title.lower() == self._title.lower():
            return True
        return False


class Home(Event):
    """Home class is publicly derived from the Event class.
    """
    def __init__(self, start_time: str, guests, title: str, date: date):
        """Initializes Vacation object."""
        Event.__init__(self, title, "Home", date)
        self._start_time = start_time
        self._guest_list = guests

    def __str__(self):
        """Format _end_date and returns a formatted string for all data
        members in base and current class.
        """
        return (
                Event.__str__(self) +
                f'Start Time: {self.format_time()}\n' +
                'Guest List: ' +
                ', '.join([str(item) for item in self._guest_list]) +
                '\n')

    def __repr__(self):
        """Formats the data members to mimic the function call made to
        construct the object.
        """
        return (
                f"Home(start_time='{self._start_time}', " +
                f"title='{self._title}', " +
                f"location='{self._location}', " +
                f"date='{self._date}')")

    def __lt__(self, other):
        """
        """
        return super().__lt__(other)

    def __ge__(self, other):
        """
        """
        return super().__ge__(other)

    def edit_start_time(self, arg: str):
        """
        """
        self._start_time = arg
        return None

    def edit_title(self, arg: str):
        """
        """
        return super().edit_title(arg)

    def edit_location(self, arg: str):
        """
        """
        return super().edit_location(arg)

    def edit_date(self, arg: date):
        """
        """
        return super().edit_date(arg)

    def add_guest(self, guest: str):
        """
        """
        self._guest_list.append(guest)
        return None

    def match(self, arg: str):
        """
        """
        return super().match(arg)

    def match_node(self, other):
        """
        """
        return super().match_node(other)

    def format_time(self):
        """
        """
        return (f'{self._start_time[0:2]}:' +
                f'{self._start_time[2:4]}' +
                f'{self._start_time[4:6]}')


class Away(Event):
    """
    """
    def __init__(self, dress_code: str, start_time: str, title: str,
                 location: str, date: date):
        Event.__init__(self, title, location, date)
        self._dress_code = dress_code
        self._start_time = start_time

    def __str__(self):
        """Format _end_date and returns a formatted string for all data
        members in base and current class.
        """
        return (
                Event.__str__(self) +
                f'Start Time: {self.format_time()}\n' +
                f'Dress Code: {self._dress_code}\n')

    def __repr__(self):
        """Formats the data members to mimic the function call made to
        construct the object.
        """
        return (
                f"Away(dress_code='{self._dress_code}', " +
                f"start_time='{self._start_time}', " +
                f"title='{self._title}', " +
                f"location='{self._location}', " +
                f"date='{self._date}')")

    def __lt__(self, other):
        """
        """
        return super().__lt__(other)

    def __ge__(self, other):
        """
        """
        return super().__ge__(other)

    def edit_start_time(self, arg: str):
        """
        """
        self._start_time = arg
        return None

    def edit_dress_code(self, arg: str):
        """
        """
        self._dress_code = arg
        return None

    def edit_title(self, arg: str):
        """
        """
        return super().edit_title(arg)

    def edit_location(self, arg: str):
        """
        """
        return super().edit_location(arg)

    def edit_date(self, arg: date):
        """
        """
        return super().edit_date(arg)

    def match(self, arg: str):
        """
        """
        return super().match(arg)

    def match_node(self, other):
        """
        """
        return super().match_node(other)

    def format_time(self):
        """
        """
        return (f'{self._start_time[0:2]}:' +
                f'{self._start_time[2:4]}' +
                f'{self._start_time[4:6]}')


class Vacation(Event):
    """
    """
    def __init__(self, end_date: date, packing_list, title: str,
                 location: str, date: date):
        Event.__init__(self, title, location, date)
        self._end_date = end_date
        self._packing_list = packing_list

    def __str__(self):
        """Format _end_date and returns a formatted string for all data
        members in base and current class.
        """
        return (
                Event.__str__(self) +
                f'End date: {self._end_date}\n' +
                'Packing List: ' +
                ', '.join([str(item) for item in self._packing_list]) +
                '\n')

    def __repr__(self):
        """Formats the data members to mimic the function call made to
        construct the object.
        """
        return (
                f"Vacation(end_date='{self._end_date}', " +
                f"title='{self._title}', " +
                f"location='{self._location}', " +
                f"date='{self._date}')")

    def __lt__(self, other):
        """
        """
        return super().__lt__(other)

    def __ge__(self, other):
        """
        """
        return super().__ge__(other)

    def edit_end_date(self, arg: date):
        """
        """
        self._end_date = arg
        return None

    def edit_title(self, arg: str):
        """
        """
        return super().edit_title(arg)

    def edit_location(self, arg: str):
        """
        """
        return super().edit_location(arg)

    def edit_date(self, arg: date):
        """
        """
        return super().edit_date(arg)

    def add_item(self, item: str):
        """
        """
        self._packing_list.append(item)
        return None

    def match(self, arg: str):
        """
        """
        return super().match(arg)

    def match_node(self, other):
        """
        """
        return super().match_node(other)
