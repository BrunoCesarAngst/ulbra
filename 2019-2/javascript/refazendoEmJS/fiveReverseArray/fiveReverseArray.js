var numero = [' 1', ' 2', ' 3', ' 4', ' 5'];
console.log('\narray =', numero + '\n');

numero.reverse(); // método reverse
console.log('com método reverse =', numero + '\n');

var numero = [' 1', ' 2', ' 3', ' 4', ' 5'];
var reversedNum = [];
for(let i = numero.length - 1; i >= 0; i--) {
  reversedNum.push(numero[i]);
}
console.log('com for loop =', reversedNum + '\n');

var numero = [' 1', ' 2', ' 3', ' 4', ' 5'];
var reversedNum = [];
numero.map((val) => {
  reversedNum.unshift(val);
})
console.log('com map e unshift =', reversedNum + '\n');

var numero = [' 1', ' 2', ' 3', ' 4', ' 5'];
var reversedNum = numero.slice().reverse();
console.log('com slice e reverse =', reversedNum + '\n');

var numero = [' 1', ' 2', ' 3', ' 4', ' 5'];
var reversedNum = [...numero].reverse();
console.log('com spread e reverse =', reversedNum + '\n');

var numero = [' 1', ' 2', ' 3', ' 4', ' 5'];
let reversedArray = [];
var newArray = numero.reduce((reversedArray, value) => {
  return [value, ...reversedArray];
}, reversedArray);
console.log('com reduce =', newArray + '\n');
