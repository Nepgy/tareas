object roberto {
var peso
var transporte = camion

method peso(){
return peso + transporte.peso()
}

method transporte(vehiculo){
transporte = vehiculo
}
method tieneCredito(){
return false
}
}

object chuck{
var peso = 900

method peso(){
return peso
}

method tieneCredito(){
return true
}
}

object neo{
method peso(){
return 0 
}
}

object puenteBrooklyn { 
method dejarPasar(mensajero){
return mensajero.peso() < 1000
}
}

object matrix{
method dejarPasar(mensajero){
return mensajero.tieneCredito()
}
}

object camion{
var acoplados 
method peso(){
return acoplados * 500
}
method acoplados(cantAcoplados){
acoplados = cantAcoplados
}
}

object bici{
method peso(){
return 0
}
}

object paquete{
var pago 
var destino
method pagar(){
return pago = true
}
method estaPago(){
return pago
}
method destino(lugar){
return destino = lugar
}
method puedeSerEntregadoPor(mensajero){
return destino.dejarPasar(mensajero) and self.estaPago()
}
