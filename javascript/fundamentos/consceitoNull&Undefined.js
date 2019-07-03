const a = {name: 'Teste'}; // a recebe o endereço do objeto

console.log(a);

const b = a; // b recebe o mesmo endereço que a recebeu, ou seja, do objeto

console.log(b);

b.nome = 'Opa';

console.log(a); // tanto alterando em a ou b, estarei fazendo alteração no mesmo endereço, pois, os dois apontam para o mesmo local, isso é atribuição por referencia

let c = 3; // 3 é um tipo primitivo defenido para c, por tanto um valor

let d = c; // d está recebendo o valor de c
d++;

console.log(c); // 3
console.log(d); // 4

let valor; // sem valor, não inicializada
console.log(valor); // undefined
// console.log(valor2); // ReferenceError: valor2 is not defined, o valor nem foi declarado

valor = null; // não recebe (ausência de) valor nem endereço de memória
console.log(valor);

// console.log(valor.toString()); //TypeError: Cannot read property 'toString' of null

const produto = {};
console.log(produto.preco); // undefined
// console.log(produto.preco.a); // TypeError: Cannot read property 'a' of undefined

console.log(produto);

produto.preco = 3.50;
console.log(produto);

produto.preco = undefined; // evite atribuir undefined
console.log(!!produto.preco);
// delete produto.preco
console.log(produto);

produto.preco = null; // sem preço
console.log(produto);


