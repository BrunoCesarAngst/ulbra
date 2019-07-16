function soma () {
  let soma = 0
  for (i in arguments) {
    soma += arguments[i]
  }
  return soma
}
console.log(soma()) // 0
console.log(soma(1)) // 1
console.log(soma(2, 4)) // 6
console.log(soma(2, 4, 2.1, 3.5, ' teste')) // 11.6 teste
console.log(soma(' a', ' b', ' c')) // 0 a b c, pois, o 0 esta atribuido a variável soma.