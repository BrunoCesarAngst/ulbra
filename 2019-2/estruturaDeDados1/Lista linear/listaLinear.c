#define MAX 100
struct lista
{
  int FL;
  int dados[MAX]

};

// aqui o struct lista passa a se chamar só Lista.
typedef struct lista Lista;

Lista* Cria_lista(void){
  Lista* pt = (Lista*)malloc(size(Lista));
  if(pt != NULL){
    pt -> FL = 0;
  return pt;
  }
}

Lista* Libera_lista(Lista* Ptl)

