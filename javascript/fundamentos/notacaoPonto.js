console.log(Math.ceil(6.1));

const obj1 = {};
obj1.nome = 'bola';
obj1['nome2'] = 'bola2';
console.log(obj1.nome, obj1.nome2);

function Obj(nome) {
    this.nome = nome;
    this.exec = function() {
        console.log('exec...')
    }
}
const obj2 = new Obj('cadeira');
const obj3 = new Obj('mesa');
console.log(Obj.nome);
console.log(obj2.nome);
console.log(obj3.nome);
obj3.exec();
