import sys

def tell_factor_multiple(n, m):
    
    if m % n == 0:
        sys.stdout.write('factor\n')
    elif n % m == 0:
        sys.stdout.write('multiple\n')
    else:
        sys.stdout.write('neither\n')
    
    return 

b_iteration_trigger = True

while b_iteration_trigger:
    n, m = map(int, sys.stdin.readline().split())

    if n == 0 and m == 0:
        b_iteration_trigger = False
        continue
    else:
        tell_factor_multiple(n, m)
