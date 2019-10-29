const notas = [6.7, 7.4, 9.8, 8.1, 7.7]
for (let i in notas) {
  console.log(parseInt(i) + parseInt(1), notas[i])
}

const pessoa = {
  nome: 'Bruno',
  sobrenome: 'Angst',
  idade: 36,
  peso: 87
}
for (let atributo in pessoa) {
  console.log(`${atributo} = ${pessoa[atributo]}`)
}
