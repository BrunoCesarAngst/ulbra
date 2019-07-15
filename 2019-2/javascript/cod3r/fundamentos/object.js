
// anotação dinâmica de objeto
const proj1 = {};
proj1.nome = 'Celular Ultra Mega';
proj1.preco = 4998.90;
proj1['Desconto produto'] = 0.4 //atributos com espaço é possível, mas, evitar!!

console.log(proj1);

// anotação literal de objeto
const proj2 = {
    nome: 'Camisa Polo',
    preco: 85.05,
    obj: {
        blabla: 1,
        obj: {
            blabla: 2
        }
    }
}

console.log(proj2);
