function area (largura, comprimento) {
  const area = largura * comprimento
  if (area > 20) {
    console.log(`Valor acima do permitido: ${area} m2.`)
  } else {
    return area
  }
}
console.log(area(2, 2))
console.log(area(2))
console.log(area())
console.log(area(4, 4, 6, 7, 10))
console.log(area(2, 15))