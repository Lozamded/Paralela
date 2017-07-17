def file_len(fname):
    with open(fname) as f:
        for i, l in enumerate(f):
            pass
    return i + 1

texto = "grafo_ejemplo.txt"
archivo = open(texto, "r")
num_lineas = file_len(texto)

i = int(0)
cant_triangulos = int(0);

print "Lista de adyasencia: "
recorrido = ["0","0","0","0"]

lookup = int(0)

comparador = int(0)
num = 0
num2 = 0

revisado = [];

for num,linea in enumerate(archivo,1):
    print "linea ",num," ", linea
    numero = linea.split(" ")
    print "numero ",numero
    numero[0] = int(numero[0])
    numero[1] = int(numero[1])
    if not int(numero[0]) in revisado:
        recorrido[0]=int(numero[0])
        lookup = int(numero[1])
        recorrido[1]=lookup
        print "primera vuelta, buscar el ",lookup
        archivo.seek(0)
        for num2,linea2 in enumerate(archivo,1):
            print "primera sublinea ",num2,", ", linea2
            numero2 = linea2.split(" ")
            print "comparar ", numero2[0]," con ",lookup
            if(lookup == int(numero2[0])):
                print "encontrado, estoy en el nodo"
                print "comparar ", numero2[1]," con ",recorrido[0]," deben ser distintos"
                if(int(numero2[1]) != int(recorrido[0])):
                    print "es distinto, sirve"
                    recorrido[2] = int(numero2[1])
                    lookup = recorrido[2]
                    print "segunda vuelta, buscar el ",lookup
                    archivo.seek(0)
                    for num3,linea3 in enumerate(archivo,1):
                        print"segunda sublinea ", num3, ", ", linea3
                        numero3 = linea3.split(" ")
                        if(lookup == int(numero3[0])):
                            print "encontrado, estoy en el nodo"
                            if(int(numero3[1]) == int(recorrido[0])):
                                print "eureka es un triangulo"
                                cant_triangulos += 1
                                recorrido[3] = int(numero3[1])
                                print "recorrido: ",recorrido

                                revisado.append(recorrido[0])
                                revisado.append(recorrido[1])
                                revisado.append(recorrido[2])
                                revisado.append(recorrido[3])
                                recorrido[0] = 0;
                                recorrido[1] = 0;
                                recorrido[2] = 0;
                                recorrido[3] = 0;

        if num < num_lineas :
            archivo.seek(0)
    #print "linea ",num," ", linea
    #print "numero  ", numero
    print "revisados ",revisado











archivo.seek(0)
print"cantidad de triangulos ", cant_triangulos
