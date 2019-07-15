const funcs = [];
for (var i = 0; i < 10; i++) { // var não tem escopo de função, var é global!!!
    funcs.push(function(){
        console.log(i);
    })
}
funcs[2](); // 10
funcs[8](); // 10
