function ktri() {
  var quantk = parseFloat(document.energisando.quantk.value);
  var custok = parseFloat(document.energisando.custok.value);

  if (quantk <= 100){
      resultado = quantk * custok;
    } else if (quantk > 100 || quantk <= 200){
      resultado = (quantk * custok) * 1.25;
    }else{
      resultado = (quantk * custok) * 1.5;
    }
  document.energisando.res.value = resultado;
}
