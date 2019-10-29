// v e v -> v em 'e' a verdade prevalece quando todos são verdadeiros
// v e f -> f
// f e ? -> f
//
// v ou ? -> v
// f ou v -> v em 'ou' a verdade prevalece quando existe uma verdade
// f ou f -> f
//
// v xor v -> f
// v xor f -> v 
// f xor v -> v em 'xor' a verdade só existe quando existe verdade e falso
// f xor f -> f
//
// !v -> f
// !f -> v

function compras(trabalho1, trabalho2) {
    const comprarSorvete = trabalho1 || trabalho2;
    const comprarTv50 = trabalho1 && trabalho2;
    //const comprarTv32 = !!(trabalho1 ^ trabalho2); // bitwise xor
    const comprarTv32 = trabalho1 != trabalho2; // avaliar a diferença é como um xor
    const manterSaudavel = !comprarSorvete; // operador unário

    return {comprarSorvete, comprarTv50, comprarTv32, manterSaudavel};
}

console.log(compras(true, true));
console.log(compras(true, false));
console.log(compras(false, true));
console.log(compras(false, false));
