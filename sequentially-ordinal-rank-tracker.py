# Sequentially Ordinal Rank Tracker
from sortedcontainers import SortedList

class SORTracker:
    def __init__(self):
        self.l = SortedList()
        self.i = 0

    def add(self, name: str, score: int) -> None:
        self.l.add((-score, name))

    def get(self) -> str:
        ret = self.l[self.i][1]
        self.i += 1
        return ret
