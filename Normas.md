# Normas
## Informacion de incio
xdpyinfo|grep "depth of root window"

tigervncserver -kill :1

tigervncserver :1 -geometry 1440x768 -depth 24 -rfbport 5901 -dpi 96 -localhost -Securitytypes None

xdpyinfo|grep "depth of root window"


Para pasar los nuevos cambios al codespace
git fetch
git status
git pull

Para modificar algo
git add (nombre del archivo modificado)
git commit -m “V2.0 “tu nombre” “tu archivo”

para cuando no puedas hacer push o commit 
git merge

## Normas para el desarrollo

Todos los objetos tendran una funcion actualizar que recibirá la posición del jugador y dt. 
De este modo, se llamará del siguiente modo [NombreDelObjeto].actualizar(posicion, dt);