for (let i = 0; i < 10; i++) {
    console.log(i);
}
console.log('i =', i); // ReferenceError: i is not defined, i recebeu a variável let que, só esta visível dentro for.
