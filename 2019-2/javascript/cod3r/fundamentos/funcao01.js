// função sem retorno
function imprimirSoma(a, b){
    console.log(a + b);
}

imprimirSoma(2, 3); // 5
imprimirSoma(2); // NaN, e pode ser tratado
imprimirSoma(); // NaN
imprimirSoma(2, 10, 4, 5, 6); // pega os dois parametros e ignora o resto sem reclamar!!!!

// função com retorno
function soma(a, b = 1){
    return a + b;
}

console.log(soma(2, 3)); // a função soma não tem o console.log, por tanto, estamos chamando a função dentro desse console.log.
console.log(soma(2)); // 3, pois b esta setado com valor 1

