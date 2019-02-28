# ENIGMA

Se trata de un programa en C que codifica y decodifica un mensaje dado por el usuario, que puede estar cifrado en varios sistemas, de manera que el usuario le diga al programa qué sistema está utilizando.

## Integrantes del equipo

Jaime Bustillo Ergui, @jbustilloe.

Nicolás García Romero, @nicogarrom.

Jesús Marcos Torero, @jesusmarcostorero.

## Objetivos del trabajo

Saber manipular cadenas de caracteres variables, utilizar ficheros y automatizar el proceso de codificación y decodificación.
  
  El funcionamiento del código Enigma se basa en el funcionamiento de la propia máquina Enigma, que usaba un mecanismo electromecánico de discos que cambiaban continuamente de posición y que hacían que las transformaciones de un caracter a otro variasen. Por ejemplo, si tú escribías “abc abc”, ninguna de las dos letras iguales se transformaba en la misma letra, porque al escribir un caracter, la configuración del codificador cambiaba.
	Ya que el codificador y decodificador van cambiando continuamente, tiene que establecerse de antemano una configuración inicial en las posiciones de los discos, que podía tener hasta 5. El funcionamiento era el siguiente: al pulsar una tecla, el primer disco giraba una posición; y una vez pulsadas 26 teclas, el disco daba una vuelta completa y volvía a su posición original, pero entonces hacía que se moviese el disco siguiente en una posición. Esto se traduce en que la máquina puede alternarse en 26^3=17576 alfabetos distintos.
	Nuestro objetivo es simplificarlo, recreando todo este proceso en forma de código, y que siga manteniendo su función, tanto la de codificar como decodificar.
