const imprimirResultado = function(nota) {
    switch (Math.floor(nota)) {
        case 10:
        case 9:
            console.log('Quadro de honra');
            break;
        case 8: case 7:
            console.log('Aprovado');
            break;
        case 6: case 5: case 4:
            console.log('Substituição');
            break;
        case 3: case 2: case 1: case 0:
            console.log('Reprovado');
            break;
        default:
            console.log ('Nota Inválida');
            break;
    }
}
imprimirResultado(10);
imprimirResultado(8.9);
imprimirResultado(5);
imprimirResultado(1);
imprimirResultado(11);
imprimirResultado(-1);
