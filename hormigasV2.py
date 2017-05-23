class Hormiga:
    tag = 0
    nombre = "hormiga"
    def __init__():
      self.pos_inicial
      self.pos_actual
      self.orientacion



alambre = []
centro = float
centro2 = float

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

    hormiga = Hormiga
    hormiga.pos_inicial = posicion
    hormiga.pos_actual = posicion
    hormiga.nombre = hormiga.nombre + " " + str(i)
    texto = "hormiga"
    alambre[int(posicion)-1] = texto +str(i) #hormiga
    print "poicision inicial de la ",hormiga.nombre ," ", hormiga.pos_inicial

print alambre

if int(n_hormigas) > 1:
    if (float(largo) % 2 == 0):
        centro2 = float(centro)+1
        print "largo par", int(centro), " y ", int(centro2), "centros"

        i = int(0)
        while alambre[i] != ("hormiga"+str(i+1)):
            i = i+1
            if(i >= int(largo)-1):
                break
        print "chao while"
        print "en la posicion ", i+1, "del alambre hay una ",alambre[i]


        # print "casillas hacia la derecha"
        # for i in range(int(centro),int(largo)):
        #     print "casilla",alambre[i]
        #
        # print "casillas hacia la izquierda"
        # for i in reversed(range(0,int(centro))):
        #     print "casilla",alambre[i]

    else:
        centro = float(centro) +0.5
        print "largo inpar ", int(centro), "centro"
else:
    print "solo hay una hormiga"
