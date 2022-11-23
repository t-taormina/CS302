"""
Tyler Taormina
taormina@pdx.edu
Test suite for Program 4 CS302
"""
# cSpell:ignore Taormina

from events import Event, Vacation


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

    def test_event_edit(self):
        event = Event("lunch", "timberline", "20221114")
        event.edit(1, "cubs game")
        event.edit(2, "chicago")
        event.edit(3, "20220517")
        assert event._title == "cubs game"
        assert event._location == "chicago"
        assert event._date == "20220517"

    def test_event_edit_empty_inserts(self):
        event = Event("lunch", "timberline", "20221114")
        event.edit(1, "")
        event.edit(2, "")
        event.edit(3, "")
        assert event._title == ""
        assert event._location == ""
        assert event._date == ""


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


"""
    def test_vacation_edit(self):
        vacation = Vacation("20221225",
                            "Family Vacation",
                            "California",
                            "20221220")
        vacation.edit(1, "cubs game")
        vacation.edit(2, "chicago")
        vacation.edit(3, "20220517")
        assert vacation._title == "cubs game"
        assert vacation._location == "chicago"
        assert vacation._date == "20220517"

    def test_vacation_edit_empty_inserts(self):
        vacation = Vacation("20221225",
                            "Family Vacation",
                            "California",
                            "20221220")
        vacation.edit(1, "")
        vacation.edit(2, "")
        vacation.edit(3, "")
        assert vacation._title == ""
        assert vacation._location == ""
        assert vacation._date == ""
"""
