x = int(input("Premier nombre : "))
y = int(input("Second nombre  : "))

if (x % 2 == 0) and (x > 0):
    print(x, "est pair et positif.")
    if y % 2 == 0:
        print(y, "est pair.")
    else:
        print(x, "est pair et positif, et", y, "est impair.")

if y < x:
    print(y, "est plus petit que", x)

elif x == y:
    print(x, "est égal à", y)

else:
    print(y, "est plus grand que", x)
