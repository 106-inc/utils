#!/usr/bin/python3

class Angle:

    def __init__(self, deg=0, mins=0, secs=0):
        self.deg_ = deg
        self.min_ = mins
        self.sec_ = secs

    def __add__(self, other):
        sec_sum = self.sec_ + other.sec_
        min_sum = self.min_ + other.min_ + (sec_sum // 60)
        deg_sum = self.deg_ + other.deg_ + (min_sum // 60)

        return Angle(deg_sum, min_sum % 60, sec_sum % 60)

    def __str__(self):
        return f"{self.deg_}°{self.min_}'{self.sec_}''"


a = Angle(10, 34, 3)
print(a)