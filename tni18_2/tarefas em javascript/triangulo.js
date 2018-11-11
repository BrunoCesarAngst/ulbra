function ktri() {
  var ab = parseFloat(document.triangulando.ab.value);
  var ac = parseFloat(document.triangulando.ac.value);
  var bc = parseFloat(document.triangulando.bc.value);

  if (ab < ac + bc && ac < bc + ab && bc < ab + ac){
    if (ab == ac && ac == bc){
      resultado = 'Triângulo Equilátero';
    } else if (ab == ac || ac == bc || bc == ab){
      resultado = 'Triângulo Isósceles';
    }else{
      resultado = 'Triângulo Escaleno';
    }
  } else {
    resultado = 'Algum valor inválido!!!'
  }
  document.triangulando.res.value = resultado;
}
