function calcular(oper) {
   var valor1 = document.calculando.valor1.value;
   var valor2 = document.calculando.valor2.value;

   if (oper == "somar") {
      var res = parseInt(valor1) + parseInt(valor2);
   } else {
      if (oper == "subtrair") {
         var res = valor1-valor2;
      } else {
         if (oper == "multiplicar") {
            var res = valor1*valor2;
         } else {
            var res = valor1/valor2;
         }
      }
   }

   document.calculando.res.value = res;
}
