function ehdez(){
var numero = prompt("Digite um número: ");

  if (numero < 10) {

    alert('O número é menor que 10');

  } else if(numero == 10) {

    alert('O número é 10');

  } else {

    alert('O número é maior que 10');
  }
};

function soma() {

  var n1str = prompt("Digite um numero");
  var n2str = prompt("Digite outro numero");
  var n1 = parseFloat(n1str, 10);
  var n2 = parseFloat(n2str, 10);
  total  = n1 + n1;
  alert(total);

};

function operando() {
  var n1str = prompt("Digite um numero");
  var n2str = prompt("Digite outro numero");
  var n1 = parseFloat(n1str, 10);
  var n2 = parseFloat(n2str, 10);
  var operador = prompt("Que tipo de opração você quer fazer?\n1 para Somar, 2 para Subtrair, 3 para Multiplicar ou 4 para Dividir")
  var operador = parseInt(operador, 10);
  switch (operador) {
    case 1:
        total = n1 + n2;
        alert(total);
      break;
    case 2:
        total = n1 - n2;
        alert(total);
      break;
      break;
    case 3:
        total = n1 * n2;
        alert(total);
      break;
      break;
    case 4:
        total = n1 / n2;
        alert(total);
      break;
    default:
        alert("Não deu!!!");
      break;
  }
};

function reptnome() {
  var nome = prompt("Escreva seu primeiro nome: ");
  var numero = prompt("Digite um número qualquer: ");
  var num = parseInt(numero, 10);
  var texto = "";
    for (var i = 0; i < num.length; i++) {
      alert(nome);
    }
};

function leitura() {
  var nome = prompt("Seu nome:");
  var endereco = prompt("Seu endereço:");
  var email = prompt("Seu E-mail:");
  alert("Seu nome é " + nome + " esse é o seu endereço " + endereco + " e o seu e-mail de contato é esse " + email);
}
