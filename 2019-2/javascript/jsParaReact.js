
const saudacao = 'Olá';
const sujeito = 'Mundo';

console.log(`${saudacao} ${sujeito}!`);
console.log(saudacao + ' ' + sujeito + '!');

// function caixa({ className, ...props }) {
//   return <div className={ `box ${className}` } {...props} />
// }

const a = 'hello'
const b = 42
const c = { d: [ true, false ] }
console.log({a, b, c})
console.log({a:a, b:b, c:c})

// function Contador({ iniciaContador, passo }) {
//   const [contador, definirContador] = useContador({ iniciaContador, passo })
//   return <button onClick={definirContador}>{contador}</button>
// }

const sejaCinco = () => 5
const adicioneCinco = a => a + 5
const divida = (a, b) => a / b

function sejaCinco1() {
  return 5
}
function adicioneCinco1(a) {
  return a + 5
}
function divida1(a, b) {
  return a / b
}
console.log(sejaCinco() + ', ' + sejaCinco1())
console.log(adicioneCinco(5) + ', ' + adicioneCinco1(6))
console.log(divida(4, 2) + ', ' + divida(6, 2))

// function ListaDeUrsosDePeluica({ursosDePelucia}) {
//   return (
//     <ul>
//       {ursosDePelucia.map(ursoDePelucia => (
//         <li key={ursoDePelucia.id}>
//           <span>{ursoDePelucia.nome}</span>
//         </li>
//       ))}
//     </ul>
//   )
// }
