# TC1030_Proyecto_A01709229
Este proyecto es un juego de batallas de naves. Esta pensado para que sean 4 naves de diferentes colores que entren en batalla. Este juego se compone de 4 clases principales además de ciertas herencias que están hechas para simplificar el código y el proceso del proyecto.

# Funcionalidad
En este proyecto los jugadores tomaran turnos para realizar ataques. El jugador podrá escoger a que otro jugador quiere atacar. La nave es nuestro objeto principal esta tiene un escudo, total de vida y un piloto. Si la nave tiene escudo entonces cuando entre daño solo la vida de la nave se vera atacada. Si la nave no tiene escudo, entonces además de verse afectada la vida de la nave también el piloto recibe daño. Cuando la nave o el piloto mueran el jugador será eliminado. Los jugadores pueden escoger entre que armas utilizar, y además cada jugador tiene la opción de usar un botiquín cada 6 rondas para la vida del piloto. Los jugadores deberán usar el botiquin y el arma de manera estratégica para ganar. Finalmente, tendremos un instructivo en nuestro main para que las persona sepan como usar el juego, y al finalizar cada turno se imprime el status de cada nave.

Habían opciones de como se podían adquirir los botiquines, una era tener un currency dentro del juego, pero para mas simplicidad al usar cada botiquin tendrás una repercusión, entonces se tendrán que usar de manera estratégica.

# Notas UML
Para el uml use getters para poder accesar a la información privada de ciertos atributos en las clases. Hice esto para que se claro como una clase podía accesar a la información de la otra aunque mucha gente dice que no es necesario agregar getters y setters en los diagramas. DE igual manera, la forma en que implemente los getters y setters fue usando la información obtenida en clase de 'TC1033' ya que he visto que hay múltiples formas de implementarlo. Ya intente accesar la información de esta manera y todo salió a la perfección.
