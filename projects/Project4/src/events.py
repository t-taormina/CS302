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
    """Base class for event hierarchy.
    """
    def __init__(self, title: str, location: str, date: str):
        """Initializes Event object."""
        self._title = title
        self._location = location
        self._date = date

    def __str__(self):
        """Format _date and returns a formatted string for all data members."""
        converted_date_format = date(
                year=int(self._date[0:4]),
                month=int(self._date[4:6]),
                day=int(self._date[6:8]))

        return (
                f'Title: {self._title}\n' +
                f'Location: {self._location}\n' +
                f'Date: {converted_date_format}\n')

    def __repr__(self):
        """Returns string repr of Event object."""
        return (
                f"Event(title='{self._title}', " +
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
        self._title = arg

    def edit_location(self, arg: str):
        self._location = arg

    def edit_date(self, arg: str):
        self._date = arg