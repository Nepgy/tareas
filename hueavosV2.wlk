/** Los Huevos */
object huevoRepostero{
	method calorias (){
		return 750
	}
	}
object huevoMixto {
	method calorias (){
		return 900
	}
	}
object conejoDeChoco{
	var peso = 100
	method calorias (){
		return peso * 10 
	}
}

object huevitoEnBlister{
	var cantHuevos = 5
	method calorias (){
		return 100 * cantHuevos + (cantHuevos.div(5))*150
	}
}
object matrioshka{
	var huevoInterior = huevoMixto
	var decoracion = arbol
	method calorias (){
		return 3000 + huevoInterior.calorias() + decoracion.calorias()
	}
	}
object flor{
	var petalos = 5
	method calorias(){
		return petalos*100
	}
}
object arbol{
	method calorias (){
		return 150
	}
