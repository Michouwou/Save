from upemtk import *
from random import randint
from time import sleep
from math import *
from copy import *

class turtle:

    nb_turtles = 0;
    collide = False

    # Les deux méthodes qui suivent sont des méthodes de classes,
    # elles permettent un comportement particulier et sont utilisées ici pour
    # compter le nombre de tortues instancier dans le programme utilisateur

    @classmethod
    def increase_turtle_number(self):
        self.nb_turtles += 1
        
    @classmethod
    def get_nb_turtles(self):
        return (self.nb_turtles)

    @classmethod
    def decrease_turtle_number(self):
        self.nb_turtles -= 1

    # La méthode suivante est statique, elle ne dépend pas de l'instance mais de la
    # classe, elle ne recoit donc pas d'argument implicite

    @staticmethod
    def generate_randTag():
        tmp = "__" # On commence le tag par '__' ça évite que l'utilisateur trouve le moyen d'utiliser le même
        for i in range(1, 15):
            tmp += chr(randint(97, 122)) # On ajoute une lettre minuscule aléatoire
        return (tmp)
    
    def __init__(self, pos_x = 0, pos_y = 0, teta = 0, color = "black", shape = 'TRIANGLE', tag = ""):
        self.pos_x = pos_x # Position en x
        self.pos_y = pos_y # Position en y
        self.teta = 0 # Angle de la tortue
        self.pen = False # Si la tortue dessine (True) ou pas (False)
        self.color = color # Couleur du dessin
        self.sublist_tags = [] # Les tags des tortues enfants
        self.sublist = [] # Les tortues enfants
        self.speed = 1
        # Si aucun tag n'a été donné on en génère un automatiquement
        if (tag == ""):
            self.tag = self.generate_randTag()
        # Sinon on donne le tag demandé
        else:
            self.tag = tag
        self.shape = shape # Forme de la tortue
        self.pshape = self.def_shape(shape) # Points qui compose la forme
        if (teta != 0):
            self.rotate(teta) # Si l'angle de depart n'est pas nul on fait directement tourner la tortue
        self.draw() # On dessine la tortue
        self.increase_turtle_number()

    def def_shape(self, shape):
        # Le premier point de chaque forme devra être le point dans la direction duquel la
        # tortue avance
        if (shape == 'TRIANGLE'):
            return [[0, -10], [6, 6], [-6, 6]] # Le point du haut, puis le point de droite puis celui de gauche
    
    def draw(self):
        point(self.pos_x, self.pos_y, epaisseur = 2, tag = "turtle") # Centre de la tortue (ce qui trace aussi la ligne
        if (self.pen): # Si le crayon est baissé, on dessine
            point(self.pos_x, self.pos_y, tag = "trace", couleur = self.color)
        i = 0
        tmp = len(self.pshape)
        while i < tmp - 1: # Tant qu'on est pas au bout des points de la forme de la tortue on relie deux points adjacents
            ligne(self.pos_x + self.pshape[i][0], self.pos_y + self.pshape[i][1], self.pos_x + self.pshape[i + 1][0], self.pos_y + self.pshape[i + 1][1], tag=self.tag)
            i += 1
        ligne(self.pos_x + self.pshape[tmp - 1][0], self.pos_y + self.pshape[tmp - 1][1], self.pos_x + self.pshape[0][0], self.pos_y + self.pshape[0][1], tag = self.tag)

    def rotate(self, teta = pi/2): # Par défaut la tortue fait un quart de tour sur la gauche
        tmp = len(self.pshape)
        self.teta += teta
        i = 0
        while i < tmp:
            sec_tmp1 = self.pshape[i][0]
            sec_tmp2 = self.pshape[i][1]
            # Formule correcte mais à revoir pour compréhension (chopée sur Wikipédia)
            self.pshape[i][0] = sec_tmp1 * cos(teta) + sec_tmp2 * sin(teta)
            self.pshape[i][1] = -sec_tmp1 * sin(teta) + sec_tmp2 * cos(teta)
            i += 1
        self.refresh()

    def refresh(self): # Fonction qui redessine la tortue, à appeler après chaque modif
        efface(self.tag)
        self.draw()
        mise_a_jour()

    def forward(self, nb): # Fonction pour faire avancer la tortue de nb pixels
        self.pos_x += nb * -sin(self.teta)
        self.pos_y -= nb * cos(self.teta)
        self.refresh()

    def trace(self, color = "black", value = True): # Pour faire ou non dessiner la tortue, ou pour changer la couleur du trait
        self.pen = value
        self.color = color

    def check_collision(self, w_width, w_height): # Return True si la tortue est contre un mur, False sinon
        if (turtle.collide == True):
            return (False)
        x = self.pos_x
        y = self.pos_y
        for e in self.pshape:
            if (floor(x + e[0]) == 0 or floor(x + e[0]) == w_width or floor(y + e[1]) == 0 or floor(y + e[1]) == w_height):
                return (True)
        return (False)

    def divide(self): # Divise la tortue en deux, symétriquement par rapport à la direction de la tortue pour le moment
        new = deepcopy(self) # Copie profonde pour pas avoir deux fois le même objet
        self.increase_turtle_number() # On augmente le nombre de tortues
        self.sublist.append(new) # On met la nouvelle tortue dans la liste des tortues enfants
        new.tag = self.generate_randTag() # On génère un tag aléatoire
        self.sublist_tags.append(new.tag) # On garde le tag en mémoire
        new.rotate(-pi/2) # On fait partir les deux tortues dans des sens opposés
        self.rotate()
        return(new) # On renvoie l'objet créé
        

cree_fenetre(400, 400)
t = turtle(pos_x = 200, pos_y = 200, tag = "turtle", teta = pi/8)
attente_clic()
t.trace()
print(t.get_nb_turtles())
for i in range(1, 100):
    t.forward(1)
    sleep(0.01)
t.rotate()
t.trace("blue")
for i in range(1, 100):
    t.forward(1)
    sleep(0.01)
t.rotate(0.5)
t.trace(value = False)
t2 = t.divide()
print(t.get_nb_turtles())
print(t.sublist_tags)
for i in range(1, 100):
    t.forward(1)
    t2.forward(1)
    sleep(0.01)
j = 1
while (t.check_collision(400, 400) == False):
    t.forward(1)
    t.rotate(pi/500)
    j += 1
    if (t.get_nb_turtles() < 10 and j % 10 == 0 and j < 200):
        t.divide()
        print(t.sublist_tags)
    if (j % 30 == 0 and t.get_nb_turtles() > 1):
        efface(t.sublist_tags[0])
        t.sublist_tags.pop(0)
        t.sublist.pop(0)
        t.decrease_turtle_number() # Ca en fait ce sera une fonction pour effacer les tortues dans les enfants
        # Mais je cherche encore un moyen ergo de le faire et simple
    sleep(0.01)
attente_clic()
ferme_fenetre()
