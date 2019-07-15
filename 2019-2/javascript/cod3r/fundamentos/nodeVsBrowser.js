let a = 3;

global.b = 123;

this.c = 456;
this.d = false;
this.e = 'teste';

console.log(a);
console.log(global.b);
console.log(this.c);
console.log(module.exports.c);
console.log(module.exports === this);

console.log(module.exports);

// criando uma variavel louca, sem var nem let!
// abc = 3; // não faça isso!!!
// console.log(global.abc); // 3
//
// module.exports = {e: 456, f: false, g: 'teste'}
