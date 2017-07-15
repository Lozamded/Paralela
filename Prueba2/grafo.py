
archivo = open("grafo_ejemplo.txt", "r")
#contenido = archivo.read()
i = int(0)

print "Lista de adyasencia: "
recorrido = []


for linea in archivo.readlines():
    numero = linea.split(" ")
    for n in numero:
        recorrido.append(n)
    print numero



print "fin ejecucion"

print recorrido

archivo.seek(0)
