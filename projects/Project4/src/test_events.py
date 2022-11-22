"""
Tyler Taormina
taormina@pdx.edu
Test suite for Program 4 CS302
"""
# cSpell:ignore Taormina

from events import Event


class TestEvent:
    def test_event_init(self):
        event = Event("lunch", "chick-fil-a", "20221114")
        assert event.title == "lunch"
        assert event.location == "chick-fil-a"
        assert event.date == "20221114"

    def test_event_str(self):
        event = Event("lunch", "chick-fil-a", "20221114")
        test_str = ("Title: lunch\n" +
                    "Location: chick-fil-a\n" +
                    "Date: 2022-11-14\n")
        assert event.__str__() == test_str

    def test_event_repr(self):
        event = Event("lunch", "chick-fil-a", "20221114")
        test_repr = ("Event(title=lunch, " +
                     "location=chick-fil-a, " +
                     "date=20221114)")
        assert event.__repr__() == test_repr
