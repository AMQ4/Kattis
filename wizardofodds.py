import math
n, k = map(int, input().split())

# as mentioned, we can think in a question as a function f: Z+ -> {true, false}
#
# so, the function f(n) is true iff log(n) <= k.
#
print("Your wish is granted!" if math.log2(n) <= k else "You will become a flying monkey!")
