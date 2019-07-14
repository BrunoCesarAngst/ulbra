var idade = 68
if (idade < 16) {
    console.log(`Com menos de ${idade} você não pode votar!`);
} else if (idade < 18 || idade > 65) {
        console.log(`Com ${idade} anos, você não é obrigado a votar!`)
} else {
    console.log(`Com menos de ${idade} você é obrigado a votar!`);
}
