function rand(/*isso é um destructuring -->*/{min = 0, max = 1000}) {
    const valor = Math.random() * (max - min) + min;
    return Math.floor(valor);
}
console.log(rand(/*isso é um objeto -->*/{max: 50, min: 40})); // isso é mesmo que ...
const obj = {max: 50, min: 40};
console.log(rand(obj));

console.log(rand({min: 955}));

console.log(rand({}));
