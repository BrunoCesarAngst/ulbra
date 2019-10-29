const readline = require('readline')

const leituraEmLinha = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

leituraEmLinha.question('Escolha, papel, pedra ou tesoura? ', resposta => {

  const opcoes = {
    pedra: 1,
    papel: 2,
    tesoura: 3
  }

  const respostaDoUsuario = opcoes[resposta]
  const respostaDoComputador = Math.round(Math.random() * 2) + 1

  if (respostaDoUsuario === 1 && respostaDoComputador === 3) {
    console.log('Você ganhou!');
  } else if (respostaDoUsuario === 1 && respostaDoComputador === 2) {
    console.log('Você perdeu!');
  } else if (respostaDoUsuario === 1 && respostaDoComputador === 1) {
    console.log('Empatou!');
  }


  if (respostaDoUsuario === 2 && respostaDoComputador === 1) {
    console.log('Você ganhou!');
  } else if (respostaDoUsuario === 2 && respostaDoComputador === 3) {
    console.log('Você perdeu!');
  } else if (respostaDoUsuario === 2 && respostaDoComputador === 2) {
    console.log('Empatou!');
  }

  if (respostaDoUsuario === 3 && respostaDoComputador === 2) {
    console.log('Você ganhou!');
  } else if (respostaDoUsuario === 3 && respostaDoComputador === 1) {
    console.log('Você perdeu!');
  } else if (respostaDoUsuario === 3 && respostaDoComputador === 3) {
    console.log('Empatou!');
  }

  leituraEmLinha.close()
})
