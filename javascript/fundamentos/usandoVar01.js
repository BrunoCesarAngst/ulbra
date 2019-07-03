{
    {
        {
            {
                var sera = 'será???'; // var global, que é visível em todo código
                console.log(sera);
            }
        }
    }
}
console.log(sera);
// valor atribuída com var é visível até fora de escopo que não seja uma função.

function teste(){
    var local = 123; // var dentro de função, só é visível dentro da função geratriz
    console.log(local);
}
teste();
console.log(local);
