# Informática forense

- [Informática forense](#inform%c3%a1tica-forense)
  - [Algunas definiciones](#algunas-definiciones)
  - [Evidencias digitales](#evidencias-digitales)
  - [Principales conceptos](#principales-conceptos)
  - [Recuperación de los datos](#recuperaci%c3%b3n-de-los-datos)
  - [Metadata](#metadata)
  - [Herramienta Exiftool](#herramienta-exiftool)
  - [Extensiones de fichero](#extensiones-de-fichero)
  - [Data carving](#data-carving)
  - [Análisis RAM](#an%c3%a1lisis-ram)
  - [Material adicional: Técnicas de análisis forense en imágenes digitales](#material-adicional-t%c3%a9cnicas-de-an%c3%a1lisis-forense-en-im%c3%a1genes-digitales)
  - [El informe técnico forense](#el-informe-t%c3%a9cnico-forense)
  - [RESUMEN DEL INFORME](#resumen-del-informe)
  - [HISTORIAL Y OBJETIVOS](#historial-y-objetivos)
  - [EVIDENCIA ANALIZADA](#evidencia-analizada)
  - [HALLAZGOS Y DETALLES DE APOYO](#hallazgos-y-detalles-de-apoyo)
  - [INVESTIGAR PISTAS](#investigar-pistas)
  - [CONCLUSIONES](#conclusiones)
  - [¿Cómo recogemos datos?](#%c2%bfc%c3%b3mo-recogemos-datos)
  - [Procedimientos en un proceso legal](#procedimientos-en-un-proceso-legal)
    - [Recolección](#recolecci%c3%b3n)
    - [Preservación](#preservaci%c3%b3n)
    - [Análisis](#an%c3%a1lisis)
    - [Presentación](#presentaci%c3%b3n)

## Algunas definiciones

- **Cadena de custodia:** Proceso de documentación de la evidencia digital. Busca qué ha pasado con la evidencia.
    - lo que encontré
    - cómo lo encontré
    - qué hice con ella
- **Datos volátiles:** Información que se puede perder cuando se apague el dispositivo (en cuando se apague el ordenador, la información se pierde)
    - procesos
    - usuarios logueados
    - conexiones de red
- **Datos no volátiles:** Información almacenada de forma permanente
- **Borrado seguro:** Proceso para eliminar información de dispositivos de almacenamiento de forma que no se pueda recuperar
    - Esto se tiene que hacer en los dispositivos sobre los que se van a hacer copias de la evidencia con el fin de que la prueba no pierda validez.
- **CERT (_Computer Emergency Response Team_):** Grupo de reacción para incidentes informáticos

## Evidencias digitales

Las evidencias digitales son información de valor probatorio. El análisis forense digital a veces se confunde con la recuperación de datos, pero hay algunas diferencias. También las situaciones en las que se pueden aplicar estas técnicas son cuestiones a considerar.

¿Qué son las pruebas digitales? La evidencia digital es cualquuer información de valor probatorio que se almacena o transmite en forma digital (datos en binario a bajo nivel). Los dispositivos digitales registran evidencias de todo lo que haces.

Muchas veces, el análisis forense digital se confunde con la recuperación de datos, pero debemos distinguir ambos términos.

**Informática forense**:

- Se centra en recuperar evidencias que el usuario ha ocultado, eliminado o simplemente dejado atrás mientras realizaba sus actividades.
- Las pruebas pueden ser inculpatorias o exculpatorias.

**Recuperación de datos**:

- Está enfocada en recuperar información que se liberó por error o se perdió durante la sobrecarga de energía.
- Por lo general, sabes lo que estás buscando porque, de lo contrario, este proceso puede ser realmente costoso tanto en tiempo como en recursos y podría llevar a un callejón sin salida.

Ahora dos definiciones principales. _Investigación forense_ se refiere a la aplicación de la ciencia para resolver un problema legal. Y _Informática forense_ corresponde a _"la aplicación de la informática y los procedimientos de investigación para un propósito legal que implica el análisis de las evidencias digitales, la cadena de custodia, la validación con matemáticas, el uso de herramientas validadas, la repetibilidad y la presentación de informes y la posible presentación por parte de los expertos"_, tal como definió Zatyko en 2007.

En cuanto a su aplicabilidad. La informática forense se puede aplicar en:

- Investigaciones penales. Por ejemplo: pornografía infantil, robo de identidad y homicidios.
- Pero también se puede aplicar en litigios civiles, e inteligencia.

Un principio importante es el **Principio de intercambio de Locard** que dice que cuando las personas entran o salen de la escena del crimen dejarán o se llevarán algo, por ejemplo, ADN, huellas dactilares, cabello o fibras. Esto también es cierto para las evidencias digitales, como pueden ser archivos de registro y artefactos del sistema.

Se deben considerar algunos consejos finales.

- La ciencia forense es nueva y algunos procedimientos aún están en desarrollo, por lo que el analista forense necesita estar actualizado.
- Como analista forense:
  -  Necesitamos ser objetivos, neutrales y seguir las evidencias donde sea que conduzcan.
  - Como experto, debemos estar cualificados para emitir una opinión y debemos ser un comunicador efectivo.

## Principales conceptos

Conceptos como las cabeceras o los pies de archivos son esenciales en informática forense. Entre todos los conceptos, el grabado de datos conocido como _data carving_, es uno de los más relevantes, así como su relación con los discos duros magnéticos y los discos de estado sólido.

- **Bits y bytes** En el nivel más bajo del ordenador, la información se almacena en bits y bytes. Un bit almacena un valor de 0 o 1. 1 byte es un grupo de 8 bits.
- **Encabezado y pie de fichero** Describen el tipo de fichero. A menudo se denominan firma del archivo. Estos corresponden a los primeros y últimos bytes del fichero respectivamente, los primeros bytes se refieren al encabezado y los últimos al pie del fichero.

## Recuperación de los datos

Es el proceso de extraer una colección de datos de un conjunto de datos más grande. Las técnicas de recuperación de datos se utilizan con frecuencia durante una investigación digital cuando se analiza el espacio del sistema de archivos no asignado para extraer ficheros.

Garfinkel y Metz propusieron una taxonomía para la recuperación de ficheros.

- **Encabezado y pie de fichero:** es un método para buscar fichero a
ir de datos y procesar utilizando encabezados y un pie de fichero
istintos tipos de fichero.
- **Encabezado y tamaño máximo del archivo:** es un método para buscar ficheros a partir de datos sin procesar utilizando distintos encabezados y tamaño máximo del tipo de archivo.
- **Encabezado y tamaño embebido del fichero:** es un método para buscar
ficheros a partir de datos sin procesar utilizando encabezados distintos y la longitud del fichero que está incrustada en el propio fichero.

Otros métodos utilizados son los siguientes:

- Propiedades estadísticas de la entrada (por ejemplo, entropía, que es la aletoriedad de la entrada)
- Semántica de los datos, que se basa en el análisis lingüístico contenido del archivo (por ejemplo, si algunas frases en español se identifican en un documento HTML escrito en inglés, el analizador semántico podría concluir que las frase en español son parte de un fichero asignado previamente)
- Información de la estructura del sistema de ficheros (su uso requiere conocimientos de Sistemas Operativos a bajo nivel).

Existen más métodos, aunque hemos mencionado los más relevantes.

Un punto interesante es identificar si las técnicas recuperación de datos son igualmente efectivas en un disco magnético, llamado HDD, que en un disco de estado sólido, llamado SSD.

La efectividad se basa el funcionamiento de discos HDD y SSD:

- En el caso de usar SSD, las posiciones en la memoria no se pueden  sobrescribir si no se han eliminado previamente. Primero se borran los datos que fueron marcados para su liberación y posteriormente se escriben las zonas de memoria que hayan sido previamente borradas. Para el borrado de los datos se utiliza el comando TRIM.
- Por el contrario, HDD aplica una técnica muy diferente para escribir
o acceder a los datos. Cuando se accede a los datos hay que volver las partes mecánicas del disco, lo que consume tiempo. Con respecto a la eliminación de los archivos, cuando se elimina algo, en lugar de borrarlo de forma permanente, los datos unicamente son desvinculados.

El concepto de **TRIM** es esencial para la recuperación de datos porque cuando se aplica, los datos ya no se pueden recuperar. Esto sólo aplica a los discos SSD.

## Metadata

Los metadatos son datos que describen otros datos.

Los metadatos son muy importantes en informática forense:

- Pueden corroborar información sobre los propios documentos.
- Pueden revelar información sobre alguien que intenta eliminar u ocultar información.
- Se puede usar para correlar automáticamente documentos de diferentes fuentes.

Ejemplos de metadatos son: nombres de archivo, extensiones de archivo, tamaño del archivo, función resumen del archivo y así sucesivamente.

## Herramienta Exiftool

**Exiftool** es una herramienta de código abierto para Windows y Linux. Permite ver, escribir y editar información de metadatos en una amplia variedad de archivos. Esta herramienta se puede descargar desde [aquí](http://www.sno.phy.queensu.ca/~phil/exiftool/)

La forma más general de ejecutar exiftool es:

1. Descomprimir el archivo
2. Compilar el archivo usando el makefile. O simplemente acceder a exiftool.exe en Windows
3. Ejecutar: exiftool nombre_archivo

## Extensiones de fichero

¿Podemos confiar en las extensiones de los archivos? Si tienes un archivo y cambias su extensión, no afecta a su contenido ... existen herramientas que pueden ayudar a identificar este hecho. El punto clave está en estudiar las cabeceras y los pies de los archivos ... ¡no confíes en la extensión!

Las extensiones de archivo, se componen de tres letras, ubicadas al final del nombre del archivo, y se corresponden con el tipo de archivo.

Ahora, debemos responder a la siguiente pregunta: ¿podemos confiar en las extensiones del archivo? Para responder a esta pregunta, imagine que tiene dos archivos. Un archivo imagen, por ejemplo un archivo jpg y la copia de este archivo.

Vamos a cambiar la extensión de la copia de la imagen como un archivo de texto: de jpg a txt.

Si leemos el contenido en binario de ambos archivos, tenemos el siguiente resultado. Podemos ver como los primeros bytes son idénticos, es decir, los encabezados de ambos ficheros son iguales.

Lo mismo sucede con el pie del fichero.Ambos pies del fichero son idénticos.

Entonces, la respuesta a la pregunta es que, desde un punto de vista forense, las extensiones de archivo no son confiables. Entonces, como no son útiles, deberíamos
confiar únicamente en el encabezado y el pie de fichero.

Por esta razón, los encabezados y pies del fichero a menudo se denominan firmas del archivo.

Una utilidad para ver en hexadecimal el fichero es con `xdd <fichero>`

## Data carving

Los archivos borrados pueden recuperarse usando técnicas de data carving. La  herramienta _scalpel_ nos puede ayudar en este tema. Considerando un dispositivo USB, si eliminas archivos y utilizas esta herramienta, los archivos eliminados pueden ser recuperados.

scalpel es una herramienta de código abierto para MAC y Linux que permite recuperar archivos borrados. Se puede descargar desde: https://github.com/machn1k/Scalpel-2.0

La forma más general de ejecutar scalpel es:

1. Descomprimir el archivo
2. Compilar el archivo usando el makefile
3. Ejecutar: `scalpel –c scalpel.conf –o output locationFileDeleted`

También lo podemos instalar en ubuntu con la paquetería: `sudo apt install scalpel`

> Nota: scalpel.conf está en este mismo repositorio el el directorio `files`

Veremos cómo se pueden recuperar los archivos:

Imagine el siguiente escenario: tenemos una memoria USB con cuatro ficheros JPG.

1. Comenzamos eliminando los ficheros uno y cuatro.
2. Luego ejecutamos Scalpel sobre el dispositivo USB
3. Especificamos el archivo de configuración y también la carpeta de salida.

Una vez terminado, podemos identificar que ambos archivos son recuperados. Si se abre la carpeta de salida, podemos identificar los ficheros recuperados: uno y dos.

¿Cuál es la magia bajo este proceso? Podemos ver como Scalpel usa un conjunto de reglas.

En términos generales, los encabezados y pies de fichero son los componentes principales de estas reglas.

En nuestro ejemplo particular, estos bytes corresponden con el encabezado y pie de un fichero jpg.

Ahora, estudie en detalle el archivo de configuración y luego comience a jugar con Scalpel.

## Análisis RAM

La búsqueda e impresión de cadenas embebidas en binarios se puede realizar mediante un análisis del volcado de memoria (dump). Para ello... 

Primero necesitas hacer un volcado de memoria RAM de tu sistema, para eso, es necesario ser superusuario.

```console
memdump > /tmp/memoria
```

Luego se pueden usar técnicas de recuperación de datos o el comando **strings**.

A continuación se enumeran enlaces útiles con herramientas e instrucciones:

- https://www.hackingarticles.in/4-ways-capture-memory-for-analysis-memory-forensics/

- http://www.computerpi.com/mac-ram-acquisition/

Si encuentras dificultades con la adquisición de la RAM, puedes jugar con este fichero de imagen (está en el directorio `files`).

De hecho, este es un volcado de un disquete que se utilizará en el caso práctico.

**strings** es un comando que devuelve cadenas de caracteres imprimibles que encuentra en los archivos. Por ejemplo, se puede usar para extraer texto de archivos binarios. Esta herramienta ya está instalada en un sistema operativo como Linux y Mac. La forma más general de ejecutar strings es:

```console
strings nombre_archivo
```

## Material adicional: Técnicas de análisis forense en imágenes digitales

(https://www.welivesecurity.com/la-es/2016/12/09/analisis-forense-imagenes-digitales/)

Un aspecto importante del análisis forense es la identificación de las fuentes que generan las imágenes, pues éstas son utilizadas en multitud de servicios online (por ejemplo, las redes sociales) y pueden proporcionar información relevante para relacionar un individuo con un dispositivo, lugar o evento.

Esto es útil desde el momento en que cada vez hay medios mas sofisticados para manipular las imágenes.

Se pueden usar diferentes técnicas:

- **Metadatos:** De aquí se saca informacion básica, y hay que tener en cuenta que esta información puede haber sido alterada, con lo que se debe de complementar con otras técnicas.
- **Análisis por matriz de cuantización o cuantificacion:** Se necesita de una referencia con la que comparar.
- **Análisis de ruido de foto respuesta no uniforme (PRNU):** El ruido de la foto es una característica de cada sensor de cámara digital. Necesita contar con imágenes planas hechas con el dispositivo para generar un patrón PRNU con el que se comparará la imagen a analizar mediante un proceso de correlación. Cuanto mas cercano a 1 es el coeficiente de correlación mayor es la probabilidad de que la imagen haya sido tomada con el dispositivo analizado.

## El informe técnico forense

Debe contener (al menos), las siguientes secciones:

## RESUMEN DEL INFORME

Escribe uno o dos párrafos que resuman tu informe. Debe contener una breve declaración del caso investigado, información de antecedentes y los principales hallazgos y conclusiones. Sé conciso, ve al grano y no incluyas demasiados detalles técnicos. La extensión debe ser entre 200 y 500 palabras, dependiendo de la complejidad del caso, los hallazgos y las conclusiones.

## HISTORIAL Y OBJETIVOS

Esta sección contiene toda la información relevante, incluida una descripción de por qué un examen forense de este ordenador/dispositivo/datos/ etcétera, era necesario y qué hipótesis inicial (si hay alguna) se consideró. Después de proporcionar los antecedentes, describe todas las tareas realizadas en la investigación.

## EVIDENCIA ANALIZADA

Presenta en esta sección todas las evidencias recopiladas y analizadas durante la investigación. En la mayoría de los casos, se recomienda utilizar una tabla para proporcionar esta información, mostrando las cuestiones principales de cada evidencia y las relaciones entre ellas. Incluye aquí sólo un resumen de las evidencias recopiladas y analizadas, y remite al lector al Anexo para obtener la lista completa y detalles adicionales.

## HALLAZGOS Y DETALLES DE APOYO

Esta sección describe los principales hallazgos de la investigación, incluidas todas las conclusiones y opiniones del analista forense. Organizar los hallazgos es un componente clave, por lo tanto, trata de describirlos en orden decreciente de importancia o relevancia para el caso. Cada hallazgo relevante debe incorporar un análisis en profundidad de cómo se llega a la conclusión expuesta, incluyendo todos los medios técnicos utilizados durante el análisis.

## INVESTIGAR PISTAS

En muchos casos, es posible que necesites poner fin a tu investigación sin haber completado todas las tareas o sin haber analizado todas las pruebas reunidas durante la investigación. Esto debe documentarse en esta sección, proporcionando una breve descripción de cada elemento o grupo de elementos para, sin embargo, poder continuar con la investigación.

## CONCLUSIONES

Finaliza tu informe resumiendo los principales hallazgos técnicos de la investigación. Además de presentar datos técnicos, indica también aquí cualquier opinión de expertos en la materia que desees proporcionar.

## ¿Cómo recogemos datos?

Seguir siempre estas reglas:

1. No cambiar el estado del dispositivo (no apagarlo o encenderlo), si lo pagamos perdemos lo que hay en RAM y si lo encendemos podemos desencadenar la posible ejecución de comandos maliciosos que borren evidencias
2. Recopilar evidencias de mayor a menor volatilidad
3. No confiar en la información proporcionada por los programas del sistema, se recomienda recopilar la información desde un medio protegido (p.ej, un LiveCD o similar)
4. No ejecutar aplicaciones que modifiquen la fecha y hora de acceso al los archivos del sistema
5. Si no estás seguro de lo que haces, ¡¡No lo hagas!!

## Procedimientos en un proceso legal

4 pasos: Recoleccion - Preservación - Análisis - Presentación

### Recolección

1. Metodología de primer respondiente: El interviniente tiene que decidir lo que hacer dependiendo del contexto (apagar/no apagar)
2. Identificar la infraestructura técnica involucrada: sacar imágenes, logs, etc.
3. Identificación y documentación de los aspectos físicos de la escena (vigilancia, cámaras)
4. Toma de datos volátiles: Lo primer se hace un dump de la memoria y luego ya se pasan scripts que sea
5. Toma de datos no volátiles: Generación de _original peritable_ (clon bit a bit)
6. Embalaje evidencia recolectada
7. Establecer cadena de custodia

La idea es que en el sitio se generen, al menos dos copias, una par

### Preservación

1. Transporte de la evidencia al laboratorio
2. Generar original peritable para el Análisis
3. Almacenar la evidencia bajo esquemas seguros y auditables
4. Mantener la cadena de custodia
5. Establecer periodos de verificación de la evidencia
6. Documentar los cambios

### Análisis

1. Establecer ventanas de tiempo del incidente y del sistema
2. Definir el diccionario de datos
3. Indexar la información recolectada
4. Reconstrucción y determinación del incidente
5. Recuperar información eliminada
6. Determinar, documentar y extraer la evidencia recolectada bajo los mismos procedimientos que determina la evidencia digital

### Presentación

1. Dos informes (Técnio y Jurídico)
2. Coordinar el proceso de presentación de la evidencia
3. Testificar sobre el resultado de la investigación
