nb = int(input("Entrez un nombre : "))
if (nb % 2 == 0):
    print(nb, " est divisible par deux")
elif (nb % 3 == 0):
    print(nb, " est divisible par trois")
elif (nb % 2 == 0) and (nb % 3 == 0):
    print(nb, " est divisible par deux et trois")
