# -*- coding: utf-8 -*-
"""Untitled0.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1dtG_3YL-n4M-WRhPzp4GTRn3-Iq8GoYs

### 1. Өгөгдсөн хүснэгтээс нийт ялгаатай утгатай элемэнтүүдийн тоог ол.
"""

input = ["a",3,"hehe","hehe"]
result = set()
for x in input:
  result.add(x)
print(result)

"""### 2. Өгөгдсөн өгүүлбэрийн үг бүр нь хэдэн удаа давтагдсанг ол."""

input = "never gonna let you down never gonna give you up"
words = input.split()
result = {}
for x in words:
  result[x]=result.get(x,0)+1
for key,value in result.items():
  print(key," : ",value)

"""### 3. Өгөгдсөн хүснэгтээс 'xyz' тэмдэгт мөрийг агуулсан тэмдэгт мөрүүдийг хэвлэ."""

test = ["xyz", "x a z"]
for x in test:
    if "xyz" in x:
        print(x)

"""### 4. Өгөгдсөн хүснэгтээс 'xyz' тэмдэгт мөрөөр эхэлсэн эсвэл төгссөн тэмдэгт мөрүүдийг хэвлэ."""

test = ["xyz", "x a z"]
for x in test:
    if x.startswith("xyz") or x.endswith("xyz"):
        print(x)

"""### 5. Хамгийн эхний анхны 50 тоог олох функц бич."""

def printprime(until):
    primes = [1]
    number = 2
    while len(primes) < until:
        isPrime = True
        for x in range(2, number):
            if number % x == 0:
                isPrime = False
        if isPrime:
            primes.append(number)
        number += 1
    for x in primes:
        print(x)


printprime(50)