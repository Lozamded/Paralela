#Funcion que retorna numero de Lineas
def file_len(fname):
    with open(fname) as f:
        for i, l in enumerate(f):
            pass
    return i + 1

#tiempo
import time
start_time = time.time()

#Abrir el archivo
texto = "zebra.txt"
archivo = open(texto, "r")
num_lineas = file_len(texto)

print "para el dataset: ",texto
print "numero de lineas", num_lineas

num_nodos = long(1)

#Obtengo el primer el numero del primer nodo
linea =archivo.readline()
nodo = linea.split(" ")
numero0 = long(nodo[0])
#print "numero0: ",numero0

#Busco el mayor de los nodos para saber el total de nodos.
for linea in archivo.readlines():
    nodo = linea.split(" ")
    numero1 = long(nodo[0])
    #print "numero1: ",numero1
    #print "numero0: ", numero0, " < ","numero1: ", numero1
    if(numero0 < numero1):
        #print "si "
        #num_nodos +=1
        numero0 = numero1
        #print "suma 1"
        #print "numero0: ",numero0

archivo.seek(0)

#print"revisar segunda columna "

#Verficiar si no hay un nodo mayor en la segunda columna
for linea in archivo.readlines():
    nodo = linea.split(" ")
    numero1 = long(nodo[1])
    #print "numero1: ",numero1
    #print "numero0: ", numero0, " < ","numero1: ", numero1
    if(numero0 < numero1):
        #print "si "
        numero0 = numero1
        #print "suma 1"
        #print "numero0: ",numero0

#Muestro el numero total de nodos
num_nodos += numero0
#print "numero de nodos ",num_nodos

#Creacion de la matriz de adyasencia
matriz = [0] * num_nodos
for i in range(num_nodos):
    matriz[i] = [0] * num_nodos

archivo.seek(0)

#LLeno la matriz de adyasencia con las colisiones
for num,linea in enumerate(archivo,0):
    #print "linea ",num," ", linea
    nodo = linea.split(" ")
    matriz[long(nodo[0])][long(nodo[1])] = 1
    matriz[long(nodo[1])][long(nodo[0])] = 1
    #print "matriz[",int(nodo[0])-1,"][",int(nodo[1])-1,"] = 1"

#Si es necesario imprimir la matriz de adyacencia
#print "matriz "
#for i in matriz:
#    print i

# Funcion para calcular los triangulos de un grafo
# Se ingresa un una matriz de adyacencia de un grafo g y un booleano para el caso que sea dirigido o no
def countTriangle(mat, isDirected):
	nodes = num_nodos #Numero de nodos
	count_Triangle = 0 #Inicializo conteo
	# Considera todas las posibles tripletas en un grafo
	for i in range(nodes):
		for j in range(nodes):
			for k in range(nodes):
				# Verifica si la tripleta satisface la condicion
				if( i!=j and i !=k and j !=k and
						mat[i][j] and mat[j][k] and mat[k][i]):
					count_Triangle += 1
                        #print "matriz[",i,"][",j,"]: ",mat[i][j]
                        #print "matriz[",j,"][",k,"]: ",mat[i][k]
                        #print "matriz[",k,"][",i,"]: ",mat[i][j]
                        #print "sumo ",count_Triangle
	# Para grafos dirigidos dividir por 3 para grafos no dirigidos, dividir por 6
	return count_Triangle/3 if isDirected else count_Triangle/6

num_triangulos = countTriangle(matriz,False)
print "numero de nodos ",num_nodos
print "El numero de triangulos del grafo: ", num_triangulos
print("Tiempo de ejecion: %s [segundos] " % (time.time() - start_time))
