
archivo = open("grafo_ejemplo.txt", "r")
#contenido = archivo.read()
i = int(0)

print "Lista de adyasencia: "

for linea in archivo.readlines():
    i+=1
    print "linea ",i ," ",  linea

archivo.seek(0)

print "fin ejecucion"
