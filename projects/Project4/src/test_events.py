"""
Tyler Taormina
taormina@pdx.edu
Test suite for Program 4 CS302
"""
# cSpell:ignore Taormina

from events import Event, Vacation, DEFAULT_DATE


class TestEvent:
    def test_event_init(self):
        event = Event("lunch", "timberline", "20221114")
        assert event._title == "lunch"
        assert event._location == "timberline"
        assert event._date == "20221114"

    def test_event_str(self):
        event = Event("lunch", "timberline", "20221114")
        test_str = ("Title: lunch\n" +
                    "Location: timberline\n" +
                    "Date: 2022-11-14\n")
        assert event.__str__() == test_str

    def test_event_repr(self):
        event = Event("lunch", "timberline", "20221114")
        test_repr = ("Event(title='lunch', " +
                     "location='timberline', " +
                     "date='20221114')")
        assert event.__repr__() == test_repr

    def test_event__edit(self):
        event = Event("lunch", "timberline", "20221114")
        event.edit(1, "cubs game")
        event.edit(2, "chicago")
        event.edit(3, "20220517")
        assert event._title == "cubs game"
        assert event._location == "chicago"
        assert event._date == "20220517"

    def test_event_invalid_edit(self):
        event = Event("lunch", "timberline", "20221114")
        event.edit(1, "")
        event.edit(2, "")
        event.edit(3, "")
        assert event._title == ""
        assert event._location == ""
        assert event._date == DEFAULT_DATE


class TestVacation:
    def test_vacation_init(self):
        vacation = Vacation("20221225",
                            "Family Vacation",
                            "California",
                            "20221220")
        assert vacation._title == "Family Vacation"
        assert vacation._location == "California"
        assert vacation._date == "20221220"
        assert vacation._end_date == "20221225"

    def test_vacation_str(self):
        vacation = Vacation("20221225",
                            "Family Vacation",
                            "California",
                            "20221220")
        test_str = ("Title: Family Vacation\n" +
                    "Location: California\n" +
                    "Date: 2022-12-20\n" +
                    "End Date: 2022-12-25\n")
        assert vacation.__str__() == test_str

    def test_vacation_repr(self):
        vacation = Vacation("20221225",
                            "Family Vacation",
                            "California",
                            "20221220")
        test_repr = ("Vacation(end_date='20221225', " +
                     "title='Family Vacation', " +
                     "location='California', " +
                     "date='20221220')")
        assert vacation.__repr__() == test_repr

    def test_vacation_valid_edit(self):
        vacation = Vacation("20221225",
                            "Family Vacation",
                            "California",
                            "20221220")
        vacation.edit(1, "cubs game")
        vacation.edit(2, "chicago")
        vacation.edit(3, "20220517")
        vacation.edit(4, "20220530")
        assert vacation._title == "cubs game"
        assert vacation._location == "chicago"
        assert vacation._date == "20220517"
        assert vacation._end_date == "20220530"

    def test_vacation_invalid_edit(self):
        vacation = Vacation("20221225",
                            "Family Vacation",
                            "California",
                            "20221220")
        vacation.edit(1, "Family trip")
        vacation.edit(2, "New York")
        vacation.edit(3, "123412341234")
        vacation.edit(4, "000000000000000000000000000")
        assert vacation._title == "Family trip"
        assert vacation._location == "New York"
        assert vacation._date == DEFAULT_DATE
        assert vacation._end_date == DEFAULT_DATE
