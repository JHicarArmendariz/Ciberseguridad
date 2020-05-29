# Guía de comandos útiles

## Herramientas forenses

- **exiftool:** Herramienta para obtener metadatos de cualquier archivo:
  - Uso básico: `exiftool <archivo>`
  - Mas usos: `man exiftool`
  - Link: <https://exiftool.org/>
- **xdd:** muestra en hexadecima el fichero de entrada o bien convierte a hexadecimal el binario que se le pasa.
  - Útil para comprobar cabeceras y pies de ficheros, que nos permitirá reconocer el tipo de fichero.
  - Cabeceras más comunes: (un listado más exhaustivo en: <https://en.wikipedia.org/wiki/List_of_file_signatures>)
    ![Cabeceras de archivos mas comunes](cabeceras_archivo.png)
  - Uso: `man xxd`
  - Hermanos: `uuencode`, `uudecode`
  - Usado junto con un tcpdump puede ser útil
- **scalpel** File Carving (recuperación de ficheros): <https://github.com/machn1k/Scalpel-2.0 >
  - Para recuperar ficheros: `scalpel -c scalpel.conf -o <dir_salida> <disp_a_recuperar>`
  - Uso: `man scalpel`
  - en `scalpel.conf` se configuran las reglas o patrones para identificar cabeceras y piés de ficheros
  - Podemos ir comentando/descomentado las líneas del fichero de configuración en función de lo que queramos recuperar.
- **Volcado de RAM**
  - **Volatility** Un framework forense escrito en Python, tanto para windows, linux, android u OsX
    -  <https://www.volatilityfoundation.org>
    -  <https://github.com/volatilityfoundation/volatility>
  - Siempre podremos hacer un volcado con dd: (controlar que el tamaño del fichero de salida no sea mayor que la RAM que tenemos)
    - `dd if=/dev/mem of=volcado.mem bs=1M`
    - `dd if=/proc/kcore of=volcado.mem`
- **Autopsy**: <http://sleuthkit.org/autopsy>
  - Plataforma digital forense con un montón de herramientas forenses digitales.
  - Una vez instalado, todas las herramientas están accesibles ejecutando `$PATH_INSTALACION/bin/autopsy`
- **Análisis de ejecutables**
  - `ldd programa`: Lista de librerías de las que depende un programa
  - `strace ./programa`: Muestra las llamadas al sistema y las señales que usa un programa durante su ejecución
  - `readelf -a ./programa`: Muestra información del contenido de un fichero en formato ELF

## Ciberdefensa

- Firewall
  - iptables <https://help.ubuntu.com/community/IptablesHowTo>; Iptables es un cortafuegos de Linux utilizado por muchas personas en todo el mundo. Se basa principalmente en el filtrado de paquetes.
  - firewalld <https://firewalld.org/>
- IDS
  - snort <https://www.snort.org/>
  - Si queremos instalar más librerías es mejor hacer una instalación manual. (para usar reglas más sofisticadas)

  ```console
  sudo apt-get install snort
  sudo snort -c /etc/snort/snort.conf -l /var/log/snort/ -A full
  ```

  donde:

  - `-c` se refiere al archivo de configuración
  - `-l` se refiere al lugar donde se encuentra el fichero de registro (log)
  - `-A` se refiere al tipo de alerta a ser registrada en log. En este caso, utilizando "full" se registra toda la información sobre los paquetes.

  - <http://manual-snort-org.s3-website-us-east-1.amazonaws.com/>

## Ataques

Previo a cualquier ataque, hay que descubrir vulnerabilidades, para ello, entre otras muchas cosas, podemos usar:

- nmap: para escanear una red, ver puertos abiertos, SO de los equipos conectados a la red (con la opción `-O`, obtenemos el sistema operativo)
- wireshark: Sniffer para ver el tráfico de red.

- Metasploit: Es un framework de pentesting, normalmente viene instalado y configurado en Kali linux