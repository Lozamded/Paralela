class Hormiga:
    cont = 0
    nombre = "hormiga"
    def __init__(self, pos_inicial, pos_actual):
      self.pos_inicial
      self.pos_actual



alambre = []
centro = float

largo = raw_input("ingrese largo del alambre: ")
n_hormigas = raw_input("ingrese la cantidad de hormigas: ")

while(int(n_hormigas) > int(largo)):
    print "largo = ",largo
    print "hormigas = ",n_hormigas
    n_hormigas = raw_input("el numero de hormigas no puede superar el largo del alambre.\n reingresar numero de hormigas: ")

centro = float(largo)/2
print "centro del alambre ", centro

for i in range(1,int(largo) + 1):
    alambre.append(int(i))

print "Largo del alambre", alambre

print"Hay en total", n_hormigas,"hormigas en un alambre de",largo,"centimetros. "


for i in range(1,int(n_hormigas)+1):
    print"poscion de la hormiga ",i, " : "
    posicion = raw_input()

    while int(posicion) > int(largo):
        posicion= raw_input("la ormiga esta afuera del alambre, reingresar posicion: ")

    while "hormiga" == str(alambre[int(posicion)-1]):
        posicion= raw_input("Ya hay una hormiga aqui, reingresar posicion: ")

    #hormiga = Hormiga(posicion,posicion)
    #alambre[int(posicion)-1] = hormiga

print alambre
