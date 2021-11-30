#define max(a, b) ((a > b) ? a: b)

typedef unsigned int boolean;
typedef struct set SET;

// Operações básicas
SET* set_criar(void);
void set_apagar(SET** set);
boolean set_inserir(SET *set, int elemento);
boolean set_remover(SET* set, int elemento);
void set_imprimir(SET* conjunto);

// Operações específicas
boolean set_pertence(SET* set, int elemento);
SET* set_uniao(SET* A, SET* B);
SET* set_inter(SET* A, SET* B);
