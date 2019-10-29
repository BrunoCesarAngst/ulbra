const readline = require('readline')

const resp = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})
const resp1 = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

resp.question('numero? ', resposta1 => {
  console.log(`${resposta1}`)
  resp.close()
})

resp1.question('numero? ', resposta2 => {
  console.log(`${resposta2}`)
  resp.close()
})
