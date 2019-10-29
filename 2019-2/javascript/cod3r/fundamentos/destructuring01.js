// novo recurso do ES2015

const pessoa = {
    nome: 'Ana',
    idade: 5,
    endereco: {
        logradouro: 'Rua 123',
        numero: 1000
    }
}

const {nome, idade} = pessoa;
console.log(nome, idade);

const {nome: n, idade: i} = pessoa;
console.log(n, i);

const {sobrenome, bonita = true} = pessoa;
console.log(sobrenome, bonita); // undefined true

const {endereco: {logradouro, numero, cep}} = pessoa;
console.log(logradouro, numero, cep); // Rua 123 1000 undefined

//const {conta: {ag, num}} = pessoa;
//console.log(ag, numero); // TypeError: Cannot destructure property `ag` of 'undefined' or 'null'. 
