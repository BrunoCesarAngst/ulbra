const escola ='Cod3r'

console.log(escola.charAt(4)) //r
console.log(escola.charAt(5)) // não retorna erro!
console.log(escola.charCodeAt(3)) // retorna o código html do caracter
console.log(escola.indexOf('3')) //retorna o índice de determinado caracter

console.log(escola.substring(1)) // retorna string a partir do índice
console.log(escola.substring(0, 3)) // retorna string a partir do índice até outro índice exclusivo

console.log('Escola '.concat(escola).concat('!')) // função concatenar
console.log('Escola ' + escola + '!') // outra forma de concatenar

console.log(escola.replace(3, 'e')) // função de substituir
console.log(escola.replace(/\d/, 'e')) // função de substituir com regex

console.log('Ana,Maria,Pedro'.split(',')) // função que retorna uma array
console.log('Ana,Maria,Pedro'.split(/,/)) // função que retorna uma array com regex
