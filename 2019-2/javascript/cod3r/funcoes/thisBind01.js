const pessoa = {
    saudacao: 'Bom Dia',
    falar() {
        console.log(this.saudacao)
    }
}
pessoa.falar()

const falar = pessoa.falar
falar() //conflitos entre paradigas: funcional e OO *falar() está dentro do escopo do objeto pessoa

const falarDentroDePessoa = pessoa.falar.bind(pessoa)
falarDentroDePessoa() //O objeto this da função liga (e tem o mesmo corpo que a função original) ao objeto especificado