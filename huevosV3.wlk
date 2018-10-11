object huevoRepostero {
	method calorias(){
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
	method cuantopesa (x){
		peso = x
	}
	method calorias(){
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

object huevitoenBlister{
		var huevitos = 0

	method huevitos(x){
		huevitos = x
	}
	
	method calorias(){
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
	var huevoSorpr = huevoMixto  
	var decoracion = flor
	
	method decoracion (deco){
		decoracion = deco
	}
	method caloriasHuevoSorpr (huevo){
		huevoSorpr = huevo
	}
	method calorias(){
		return base + huevoSorpr.calorias() + decoracion.calorias()
	}
	
	method tieneChocolateBlanco(){
		return huevoSorpr.tieneChocolateBlanco()
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
			
	method calorias(){
		return petalos * 100
	}
	method petalos(cantidad) {
		petalos = cantidad
	}	 
}

object arbol {
	method calorias(){
		return 150
	}	 
}

object ana {
	var total = 0
	var huevineos = [] 	

	method leGusta(huevos) {
		return not huevos.tieneChocolateAmargo() 
	}
	
	method comer(huevos){
		huevineos.add(huevos)
		total += huevos.calorias()
	}
	
	method meEnferma(huevos){
		return total > 5000 or self.comioChocolateBlanco() 
	}
 	
	method comioChocolateBlanco() {
		return huevineos.any({huevo=>huevo.tieneChocolateBlanco()})
	}
}	


object jose {
	var ultimoHuevo
	
	method leGusta(huevos) { 
		return huevos.tieneChocolateBlanco() and huevos.calorias() < 400
	}
	method meEnferma(huevos){
		return ultimoHuevo.tieneChocolateAmargo() 
	}
	method comer(huevo){
		ultimoHuevo = huevo
	}
	

}

object tito{
	
	method leGusta(huevos) {
		return true
	}
	
	method meEnferma(huevos){
		return false
	}
	
	method comer(){}
}

object juego{
	
	var cazaditos = []
		
	method agregar(huevos){
		cazaditos.addAll(huevos)
	}	
	
	method cuantoFalta(){
		return cazaditos.size()
	}
	
	method encontrarHuevos(nene,huevo){
		nene.comer(huevo)
		cazaditos.remove(huevo)
	}
	
	method encontrarPrimerHuevo(chico){
		self.encontrarHuevos(chico, cazaditos.first())
	}
	
	method HuevosRestantes(chico){
		cazaditos.forEach({huevo => self.encontrarHuevos(chico,huevo)})
	}
}
