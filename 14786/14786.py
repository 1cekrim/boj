from decimal import *

getcontext().prec = 200

pi = Decimal('3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196') 

def next_fact():
    def internal():
        a = 1
        b = 1
        while (True):
            yield a
            b += 1
            a *= b
    return internal()

def next_x(x):
    def internal():
        a = x
        while True:
            yield a
            a *= x
    return internal()

def next_sign():
    def internal():
        while True:
            yield 1
            yield -1
            yield -1
            yield 1
    return internal()

def sincos(x):
    x %= Decimal('2') * pi
    fact = next_fact()
    x = next_x(x)
    sign = next_sign()

    s = 0
    c = 1

    flagS = False
    flagC = False
    while not flagS or not flagC:
        ns = s + next(sign) * next(x) / next(fact)
        nc = c + next(sign) * next(x) / next(fact)

        if ns.compare(s) == Decimal('0'):
            flagS = True
        if nc.compare(c) == Decimal('0'):
            flagC = True
        s = ns
        c = nc

    return s, c


a, b, c = map(Decimal, input().split())

now = (c - b) / a
flagLeft = False
flagRight = False
while True:
    sin, _ = sincos(now)
    if a * now + b * sin - c < 0:
        flagLeft = True
        if flagRight:
            break
        now += 1
    else:
        flagRight = True
        if flagLeft:
            break
        now -= 1
pre = now + 100

while abs(now - pre) > 1e-15:
    sin, cos = sincos(now)
    next_val = now - (a * now + b * sin - c) / (a + b * cos)

    pre = now
    now = next_val

print('%.19f' % (now))