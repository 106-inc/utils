#!/usr/bin/python3

import math

class Angle:

    def __init__(self, degs=0, mins=0, secs=0):
        sec_sum = secs
        min_sum = mins + sec_sum // 60
        deg_sum = degs + min_sum // 60

        self.sec_ = sec_sum % 60
        self.min_ = min_sum % 60
        self.deg_ = deg_sum

    def __iadd__(self, other):
        sec_sum = self.sec_ + other.sec_
        min_sum = self.min_ + other.min_ + (sec_sum // 60)
        deg_sum = self.deg_ + other.deg_ + (min_sum // 60)

        self.sec_ = sec_sum % 60
        self.min_ = min_sum % 60
        self.deg_ = deg_sum

        return self

    def __add__(self, other):
        temp = self
        temp += other

        return temp

    def __isub__(self, other):
        self += -other

        return self

    def __sub__(self, other):
        temp = self
        temp -= other

        return self

    def __neg__(self):
        self.deg_ = -self.deg_
        self.min_ = -self.min_
        self.sec_ = -self.sec

        return self

    def __str__(self):
        return f"{self.deg_}°{self.min_}'{self.sec_}''"

    def __float__(self):
        return self.degrees()

    def degrees(self):
        return self.deg_ + self.min_ / 60 + self.sec_ / 3600

    def radians(self):
        return self.degrees() / 180 * math.pi


a = Angle(30)
b = a + a

print('a = ', a)
print(b.degrees())
print(b.radians())
