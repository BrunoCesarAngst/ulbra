var numero = 1;
{
    var numero = 2;
    console.log('dentro =', numero); // dentro = 2, bloco simples não é considerado escopo relevante!
}
console.log('fora =', numero); // fora = 2
