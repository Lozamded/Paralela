

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
    pocision = raw_input()

    while int(pocision) > int(largo):
        pocision= raw_input("la ormiga esta afuera del alambre, reingresar pocision: ")

    while "hormiga" == str(alambre[int(pocision)-1]):
        pocision= raw_input("Ya hay una hormiga aqui, reingresar pocision: ")

    alambre[int(pocision)-1] = "hormiga"

print alambre
