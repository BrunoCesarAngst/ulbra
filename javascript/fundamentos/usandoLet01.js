/* let ou */ var numero = 1;
{
    let numero = 2;
    console.log('dentro =', numero); // dentro = 2, os dois valores co-existem pois estão em escopos diferentes
}
console.log('fora =', numero); // fora = 1
