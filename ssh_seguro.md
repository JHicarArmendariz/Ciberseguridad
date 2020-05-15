# Securizar openssh

## Básico

Instalar ssh: `sudo apt-get install openssh-server` (o el manejador de paquetes de la distribución que sea).

Tendremos que hacer algunos cambios en el archivo `/etc/ssh/sshd_config` para aumentar la seguridad de SSH -es conveniente hacer backup del fichero.)

Como casi cualquier otro paquete de software, SSH está controlado por una serie de directivas en su archivo de configuración. La instalación predeterminada del servidor OpenSSH es razonablemente segura. Sin embargo, es posible que desees realizar algunos cambios para reforzar su seguridad en mayor medida.

- **PermitRootLogin**: Indica si se le permite hacer ssh al usuario _root_, **no** evitará que cualquiera intente iniciar sesión en tu servidor a través de SSH como root. Si un atacante logra atacar tu servidor SSH y acceder con permisos de root, tendrá control completo sobre tu máquina, y por eso conviene cambiar la directiva anterior.
- **AllowUsers**: Cuando la directiva AllowUsers está activa, solo los usuarios especificados en la misma pueden acceder al sistema a través de SSH. Esto añade una capa adicional de protección.
  - Para añadir múltiples usuarios a la directiva AllowUsers, simplemente agrégalos uno por uno, sin comas, ni punto y coma. Una directiva AllowUsers que permite que la cuenta de usuario mooc y la cuenta de usuario kaliuser inicien sesión se vería así:

    ```text
    AllowUsers mooc kaliuser
    ```

- **Port**: De forma predeterminada, SSH se ejecuta sobre el puerto 22 de TCP/IP, lo que significa que cualquier malware automático podría atacar al sistema por este puerto. Cambiar la directiva Port a algo diferente hará que SSH se ejecute en un puerto diferente, bloqueando algunos posibles intentos de ataque. Para configurar SSH para que se ejecute en el puerto 4321, asegúrate de que la directiva Port tenga este aspecto: `Port 4321`

Una vez que hayas terminado de modificar las directivas en `/etc/ssh/sshd_config`, guárdalo y reinicia el demonio SSH.
