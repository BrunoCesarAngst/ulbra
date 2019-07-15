const funcs = [];
for (let i = 0; i < 10; i++) { // let tem escopo de função, criando uma "memória" (!conceito clojer!)!!!
    funcs.push(function(){
        console.log(i);
    })
}
funcs[2](); // 2
funcs[8](); // 8
