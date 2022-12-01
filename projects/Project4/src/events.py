"""
CS302 Project: Holiday Events
Author: Tyler Taormina
Date: 11.14.2022
Credits: NA

This file contains the hierarchy used in this project.
"""
# cSpell:ignore Taormina

from datetime import date
DEFAULT_DATE = "19910220"


class Event:
    """Base class for event hierarchy.
    """
    def __init__(self, title: str, location: str, date: str):
        """Initializes Event object."""
        self._title = title
        self._location = location
        self._date = date
        self.edit_date(date)

    def __str__(self):
        """Format _date and returns a formatted string for all data members."""
        converted_date_format = date(
                year=int(self._date[0:4]),
                month=int(self._date[4:6]),
                day=int(self._date[6:8]))
        return (f'Title: {self._title}\n' +
                f'Location: {self._location}\n' +
                f'Date: {converted_date_format}\n')

    def __repr__(self):
        """Returns string repr of Event object."""
        return (f"Event(title='{self._title}', " +
                f"location='{self._location}', " +
                f"date='{self._date}')")

    def edit(self, choice: int, arg: str):
        """Edit the
        """
        if (0 < choice < 4):
            # edit title: choice 1
            if (choice == 1):
                self.edit_title(arg)
            # edit location: choice 2
            if (choice == 2):
                self.edit_location(arg)
            # edit date: choice 3
            if (choice == 3):
                self.edit_date(arg)
            return 0
        else:
            return 1

    def edit_title(self, arg: str):
        """
        """
        self._title = arg

    def edit_location(self, arg: str):
        """
        """
        self._location = arg

    def edit_date(self, arg: str):
        """Determines if the argument passed is a valid
        date. If the date is valid, the data member is set.
        Otherwise, a default date is used to set data
        member. The default date is the day Python
        0.9.0 was released.
        """
        try:
            date(year=int(arg[0:4]),
                 month=int(arg[4:6]),
                 day=int(arg[6:8]))

            self._date = arg[0:8]
        except ValueError:
            print('Invalid date. Format: yyyymmdd\n' +
                  'Set date value to default: 1991-02-20 PLEASE CHANGE\n')
            self._date = DEFAULT_DATE

    def match(self, arg: str):
        if arg.lower() == self._title.lower():
            return True
        return False


class Vacation(Event):
    """Vacation class is publicly derived from the Event class.
    """
    def __init__(self, end_date: str, title: str, location: str, date: str):
        """Initializes Vacation object."""
        self._end_date = end_date
        self.edit_end_date(end_date)
        self._packing_list = []
        Event.__init__(self, title, location, date)

    def __str__(self):
        """Format _end_date and returns a formatted string for all data
        members in base and current class.
        """
        converted_date_format = date(
                year=int(self._end_date[0:4]),
                month=int(self._end_date[4:6]),
                day=int(self._end_date[6:8]))
        return (
                Event.__str__(self) +
                f'End Date: {converted_date_format}\n')

    def __repr__(self):
        """Formats the data members to mimic the function call made to
        construct the object.
        """
        return (
                f"Vacation(end_date='{self._end_date}', " +
                f"title='{self._title}', " +
                f"location='{self._location}', " +
                f"date='{self._date}')")

    def edit(self, choice: int, arg: str):
        """Edit the
        """
        if (0 < choice < 5):
            # call parent choice 1 - 3
            if 0 < choice < 4:
                Event.edit(self, choice, arg)
            # edit end date: choice 4
            if (choice == 4):
                self.edit_end_date(arg)
            return 0
        else:
            return 1

    def edit_end_date(self, arg: str):
        """Determines if the argument passed is a valid
        date. If the date is valid, the data member is set.
        Otherwise, a default date is used to set data
        member. The default date is the day Python
        0.9.0 was released.
        """
        try:
            date(year=int(arg[0:4]),
                 month=int(arg[4:6]),
                 day=int(arg[6:8]))

            self._end_date = arg[0:8]
        except ValueError:
            print('Invalid date. Format: yyyymmdd\n' +
                  'Set date value to default: 1991-02-20 PLEASE CHANGE\n')
            self._end_date = DEFAULT_DATE

    def match(self, arg: str):
        return super().match(arg)


class Meal(Event):
    """
    """
    def __init__(self, dress_code: str, start_time: str, title: str,
                 location: str, date: str):
        Event.__init__(self, title, location, date)
        self._dress_code = dress_code
        self._start_time = start_time

    def __str__(self):
        """Format _end_date and returns a formatted string for all data
        members in base and current class.
        """
        return (
                Event.__str__(self) +
                f'Dress Code: {self._dress_code}\n' +
                f'Start Time: {self.format_time()}\n')

    def __repr__(self):
        """Formats the data members to mimic the function call made to
        construct the object.
        """
        return (
                f"Meal(dress_code='{self._dress_code}', " +
                f"start_time='{self._start_time}', " +
                f"title='{self._title}', " +
                f"location='{self._location}', " +
                f"date='{self._date}')")

    def format_time(self):
        """
        """
        return (f'{self._start_time[0:2]}:' +
                f'{self._start_time[2:4]}' +
                f'{self._start_time[4:6]}')

    def edit(self, choice: int, arg: str):
        """Edit the
        """
        if (0 < choice < 6):
            # call parent choice 1 - 3
            if 0 < choice < 4:
                Event.edit(self, choice, arg)
            # edit end date: choice 4
            if (choice == 4):
                self.edit_dress_code(arg)
            if (choice == 5):
                self.edit_start_time(arg)
            return 0
        else:
            return 1

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

    def match(self, arg: str):
        return super().match(arg)


class Other(Event):
    """
    """
    def __init__(self, start_time: str, duration: str, title: str,
                 location: str, date: str):
        Event.__init__(self, title, location, date)
        self._duration = duration
        self._start_time = start_time

    def __str__(self):
        """Format _end_date and returns a formatted string for all data
        members in base and current class.
        """
        return (
                Event.__str__(self) +
                f'Start Time: {self.format_time()}\n' +
                f'Duration: {self._duration} hours\n')

    def __repr__(self):
        """Formats the data members to mimic the function call made to
        construct the object.
        """
        return (
                f"Meal(start_time='{self._start_time}', " +
                f"duration='{self._duration}', " +
                f"title='{self._title}', " +
                f"location='{self._location}', " +
                f"date='{self._date}')")

    def format_time(self):
        """
        """
        return (f'{self._start_time[0:2]}:' +
                f'{self._start_time[2:4]}' +
                f'{self._start_time[4:6]}')

    def edit(self, choice: int, arg: str):
        """Edit the
        """
        if (0 < choice < 6):
            # call parent choice 1 - 3
            if 0 < choice < 4:
                Event.edit(self, choice, arg)
            # edit end date: choice 4
            if (choice == 4):
                self.edit_duration(arg)
            if (choice == 5):
                self.edit_start_time(arg)
            return 0
        else:
            return 1

    def edit_start_time(self, arg: str):
        """
        """
        self._start_time = arg
        return None

    def edit_duration(self, arg: str):
        """
        """
        self._duration = arg
        return None

    def match(self, arg: str):
        return super().match(arg)
