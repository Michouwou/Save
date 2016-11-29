entite = ""
while (entite != "chat") and (entite != "chien") and (entite != "hamster") and (entite != "sequoia"):
    entite = input("Veuillez choisir une entite vivante parmi : chat, chien, hamster et sequoia :\n")

age = 0
while (age < 1):
    age = int(input("Veuillez entrer l'age a convertir : "))

if (entite == "chat"):
    print("Votre chat a " + str(5*age+14) + " ans, en age humain")
elif (entite == "chien"):
    print("Votre chien a " + str(6.5*age+12) + " ans, en age humain")
elif (entite == "hamster"):
    print("Votre hamster a " + str(15*age+40) + " ans, en age humain")
else:
    print("Votre sequoia a " + str(0.04*age) + " ans, en age humain")
