
import sys, re

try:
    b = sys.stdin.read()
    assert re.fullmatch(r'\s*[1-9]\d*\s+[1-9]\d*\s+[1-9]\d*\s*', b)
    b = b.split()
    assert len(b) == 3
    n = int(b[0])
    m = int(b[1])
    o = int(b[2])
    assert 3 <= n <= 10**9
    assert n % 2 == 0
    assert n == m + 0
    assert isprime(m)
    assert isprime()
