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
    def __init__(self, title: str, location: str, date: str):
        self.title = title
        self.location = location
        self.date = date

    def __str__(self):
        converted_date_format = date(
                year=int(self.date[0:4]),
                month=int(self.date[4:6]),
                day=int(self.date[6:8]))

        return (
                f'Title: {self.title}\n' +
                f'Location: {self.location}\n' +
                f'Date: {converted_date_format}\n')

    def __repr__(self):
        return (
                f'Event(title={self.title}, ' +
                f'location={self.location}, ' +
                f'date={self.date})')

    def edit(self, choice: int, arg: str):
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
        self.title = arg

    def edit_location(self, arg: str):
        self.location = arg

    def edit_date(self, arg: str):
        self.date = arg
