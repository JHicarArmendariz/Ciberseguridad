# Anexos

## Informática Forense

### Algunas definiciones

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

### Procedimientos

4 pasos: Recoleccion - Preservación - Análisis - Presentación

#### Recolección

1. Metodología de primer respondiente: El interviniente tiene que decidir lo que hacer dependiendo del contexto (apagar/no apagar)
2. Identificar la infraestructura técnica involucrada: sacar imágenes, logs, etc.
3. Identificación y documentación de los aspectos físicos de la escena (vigilancia, cámaras)
4. Toma de datos volátiles: Lo primer se hace un dump de la memoria y luego ya se pasan scripts que sea
5. Toma de datos no volátiles: Generación de _original peritable_ (clon bit a bit)
6. Embalaje evidencia recolectada
7. Establecer cadena de custodia

La idea es que en el sitio se generen, al menos dos copias, una par

#### Preservación

1. Transporte de la evidencia al laboratorio
2. Generar original peritable para el Análisis
3. Almacenar la evidencia bajo esquemas seguros y auditables
4. Mantener la cadena de custodia
5. Establecer periodos de verificación de la evidencia
6. Documentar los cambios

#### Análisis

1. Establecer ventanas de tiempo del incidente y del sistema
2. Definir el diccionario de datos
3. Indexar la información recolectada
4. Reconstrucción y determinación del incidente
5. Recuperar información eliminada
6. Determinar, documentar y extraer la evidencia recolectada bajo los mismos procedimientos que determina la evidencia digital

#### Presentación

1. Dos informes (Técnio y Jurídico)
2. Coordinar el proceso de presentación de la evidencia
3. Testificar sobre el resultado de la investigación
