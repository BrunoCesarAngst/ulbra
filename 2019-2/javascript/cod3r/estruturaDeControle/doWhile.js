function getInteiroAleatorioEntre (min, max) {
  const valor = Math.random() * (min, max) + min
  return Math.floor(valor)
}
let opcao = -1
let i = 0

do {
  i++
  opcao = getInteiroAleatorioEntre(-1, 10)
  console.log(`Rodada: ${i}, opção escolhida foi ${opcao}.`)
} while (opcao !== -1)
console.log('Até a próxima!')
