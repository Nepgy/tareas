object huevoRepostero {
	method cuantasCalorias(){
		return 750
	}
	
	method tieneChocolateBlanco(){
		return true
	}
	
	method tieneChocolateAmargo(){
		return false
	}	
	method tieneChocolateLeche(){
		return false
	}
}

object huevoMixto {
	const caloriasChL = 400
	const caloriasChB = 500
		method calorias(){
		return caloriasChL + caloriasChB
	}
	method tieneChocolateBlanco(){
		return true
	}
	
	method tieneChocolateAmargo(){
		return false
	}
	method tieneChocolateLeche(){
		return true	
	}
}

object conejoChocolate {
	var peso = 10
	method cuantoPesa (x){
		peso = x
	}
	method cuantasCalorias(){
		return peso*10
	}	
	method tieneChocolateBlanco(){
		return false
	}
	method tieneChocolateAmargo(){
		return true
	}	
	method tieneChocolateLeche(){
		return false
	}
}

object huevitoEnBlister{
		var huevitos = 0

	method huevitos(x){
		huevitos = x
	}
	
	method cuantasCalorias(){
		return huevitos*100 + huevitos.div(5)*150 
	}
	
	method tieneChocolateBlanco(){
		return huevitos >= 5 
	}
	
	method tieneChocolateAmargo(){
		return false
	}
	method tieneChocolateLeche(){
		return false
	}	
}

object matrioshka {
	const base = 3000
	var huevoSorpresa = huevoMixto  
	var decoracion = flor
	
	method decoracion (deco){
		decoracion = deco
	}
	method caloriasHuevoSorpr (huevo){
		huevoSorpresa = huevo
	}
	method calorias(){
		return base + huevoSorpr.cuantasCalorias() + decoracion.cuantasCalorias()
	}
	
	method tieneChocolateBlanco(){
		return huevoSorpresa.tieneChocolateBlanco()
	}
	
	method tieneChocolateAmargo(){
		return true
	}
	method tieneChocolateLeche(){
		return false
	}	
}

object flor {
	var petalos = 10
			
	method cuantasCalorias(){
		return petalos * 100
	}
	method petalos(cantidad) {
		petalos = cantidad
	}	 
}

object arbol {
	method cuantasCalorias(){
		return 150
	}	 
}

object ana {
	var total = 0
	var huevos = [] 	

	method leGusta(huevos) {
		return not huevos.tieneChocolateAmargo() 
	}
	
	method comer(huevos){
		huevos.add(huevos)
		total += huevos.calorias()
	}
	
	method meHaceMal(huevos){
		return total > 5000 or self.comioChocolateBlanco() 
	}
 	
	method comioChocolateBlanco() {
		return huevos.any({huevo=>huevo.tieneChocolateBlanco()})
	}
}	


object jose {
	var ultimoHuevo
	
	
	}
	method meHaceMal(huevos){
		return ultimoHuevo.tieneChocolateAmargo() 
	}
	method comer(huevo){
		ultimoHuevo = huevo
	}
	method leGusta(huevos) { 
		return huevos.tieneChocolateBlanco() and huevos.calorias() < 400

}

object tito{
	
	method leGusta(huevos) {
		return true
	}
	
	method meHaceMal(huevos){
		return false
	}
	
	method comer(){}
}

object juego{
	
	var cazeria = []
		
	method agregar(huevos){
		cazeria.addAll(huevos)
	}	
	
	method cuantoFalta(){
		return cazeria.size()
	}
	
	method encontrarHuevos(nene,huevo){
		nene.comer(huevo)
		cazeria.remove(huevo)
	}
	
	method encontrarPrimerHuevo(chico){
		self.encontrarHuevos(chico, cazeria.first())
	}
	
	method HuevosRestantes(chico){
		cazeria.forEach({huevo => self.encontrarHuevos(chico,huevo)})
	}
}
