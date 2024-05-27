TallerEstructura
-----------------INTEGRANTES------------------
Nombre: Ignacio Andres Rodriguez Bruna 
Rut: 20.543.006-7
Correo: ignacio.rodriguez02@alumnos.ucn.cl
Nombre: Claudio Gabriel Palta Contreras
Rut: 20.788.795-1
Correo: claudio.palta@alumnos.ucn.cl

-----------------LINEAS DE COMPILACIÓN Y EJECUCIÓN------------------------ 
Linea para compilar: 
g++ -o InterfazPrincipal InterfazPrincipal.cpp HashMap.cpp NodoProducto.cpp Producto.cpp Cliente.cpp ColaClientes.cpp

Linea para Ejecutar: 
./InterfazPrincipal

----MAIN----
1) se cargan los datos del archivo txt, para luego desplegar el menu de opciones del usuario.(por pruebas realizada se leen corectamente ).

2) dependiendo de la opcion que escoga el usuario se ejecutara el metodo correspondiente a la opcion seleccionada

3) Si selecciona entregar numero, se le pediran por pantalla los datos del cliente y el tipo de cliente que es, luego se creara un nuevo objeto de cliente y a este se le asignara un numero de atencion y se enviara a una cola de clientes(que esta dividida en sus diferentes tipos).

4) si selecciona llamarCliente, primero se verifica que hayan clientes en la cola, luego se apunta al nodo siguiente de clientes, luego si el cliente esta siendo atendido se le pregunta por la id del producto que desea comprar. Si se encuentra el producto se le pregunta al cliente si desea realizar la compra, si dice que si se compra en cambio si dice que no no se realiza la compra, y en el caso que no se encuentre el producto deseado se indica que el producto no se encontro.(se genera un problema pero al comienzo no se encuentran productos), priemro se debera crear algun producto y luego se debera atender a personas en lista para que el producto si sea reconocible en el caso de que se entregue la id correcta.

5) si selecciona gestionarBodega, se ingresa al metodo que contiene un submenu que contiene distintas opciones para gestionar la bodega, si selecciona  agregar producto a la bodega, se le piden todos los datos del producto y se agrega a la bodega. Si selecciona generar boletas de venta no hace nada. Y por ultimo si selecciona volver al menu principal lo devuelve.

Por ultimo se crea un metodo para cargar productos al hasmap y otro metodo para guardarDatos en el Hashmap