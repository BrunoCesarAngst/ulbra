// função em JS é First-Class Object (Citizens)
// Higher-order function

// função de forma literal
function func1 () { }

// Armazenar em uma variavel.
const func2 = function () { } // uma função anonima atribuida a uma constante.
func2() // envocando a função

// Armazenar uma função dentro de uma Array.
const array = [function (a, b) { return a + b }, func1, func2]
console.log(array[0](3, 2)) // 5

// Armazenar funções em atributos de objetos.
const obj = {}
obj.falar = function () { return 'Olá' }
console.log(obj.falar()) // Olá
console.log(obj) // { falar: [Function] }

// Passando uma função como parametro de outra função.
function run (func) {
  func()
}
run(function () { console.log('run é executar') }) // run é executar

// Uma função pode retornar/conter outra função.
function soma (a, b) {
  return function (c) {
    console.log(`Os parametros da função soma (${a}, ${b}) mais o retorno de um parametro ${c} =`, a + b + c)
  }
}
soma(7, 5)(3) // a função soma com seus parametros é também um retorno de parametro.
// outra forma ...
const dezMais = soma(5, 5)
dezMais(8)
