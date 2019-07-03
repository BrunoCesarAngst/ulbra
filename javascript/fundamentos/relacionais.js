console.log('01)', '1' == 1);
console.log('02)', '1' === 1); // estritamente igual, tipo e valor
console.log('03)', '3' != 3);
console.log('04)', '3' !== 3); // estritamente diferente

console.log('----------------------');
console.log('05)', 3 < 2);
console.log('06)', 3 > 2);
console.log('06)', 3 <= 2);
console.log('08)', 3 >= 2);

console.log('----------------------');
const d1 = new Date(0);
const d2 = new Date(0);
console.log('09)', d1 === d2); // endereço de memória são diferente
console.log('10)', d1 == d2); // endereço de memória são diferente
console.log('11)', d1.getTime() == d2.getTime()); // getTime() é number em mílisegundos ...
console.log('12)', d1.getTime() === d2.getTime()); // ... de um determinado tempo 

console.log('----------------------');
console.log('13)', undefined == null);
console.log('13)', undefined === null);
