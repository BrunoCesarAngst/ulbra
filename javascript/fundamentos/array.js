const valores = [7.7, 8.9, 6.3, 9.2];
console.log(valores[0], valores[3]); // 7.7 9.2
console.log(valores[4]); // undefined

valores[4] = 10; 
console.log(valores); // [ 7.7, 8.9, 6.3, 9.2, 10 ]
valores[7] = 13;
console.log(valores); //[ 7.7, 8.9, 6.3, 9.2, 10, <2 empty items>, 13 ]

console.log(valores.length); // 8 "elementos"

valores.push({id: 3}, false, null, 'teste');
console.log(valores); //[ 7.7, 8.9, 6.3, 9.2, 10, <2 empty items>, 13, { id: 3 }, false, null, 'teste' ]

console.log(valores.pop()); // retira e mostra o último valor do array "teste"
delete valores[0]; // deleta o elemento do índice 0
console.log(valores); //[ <1 empty item>, 8.9, 6.3, 9.2, 10, <2 empty items>, 13, { id: 3 }, false, null ]

console.log(typeof valores); // object
