function getIntiroAleatorioEntre (min, max) {
  const valor = Math.random() * (max - min) + min
  return Math.floor(valor)
}

let opcao = 0
let i = 0

while (opcao !== -1) { // !== estritamente diferente.
  i++
  opcao = getIntiroAleatorioEntre(-1, 10)
  console.log(`Rodada: ${i}, opção escolhida foi ${opcao}.`)
}

console.log('Até a próxima!')
