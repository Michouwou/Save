x = float(input("Entrez une temperature en celsius : "))
y = x + 273.15
if y < 0:
    print("Si les lois de la thermodynamique sont correctes, cette température n'est pas possible")
else:
    print(str(x) + " degres celsius correspondent à " + str(y) + " degres kelvin")
