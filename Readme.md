# 🧱 Vector Dinâmico em C

> Implementação genérica de vetor dinâmico (similar ao `std::vector` do C++) feita em C puro — com arquitetura limpa, encapsulamento real e suporte a qualquer tipo de dado.

---

## 📌 Sobre o Projeto

Este projeto implementa uma estrutura de dados **vetor dinâmico** em C puro, reproduzindo o comportamento do `std::vector` do C++ sem depender de C++ nem de bibliotecas externas.

O foco está em boas práticas de engenharia de software aplicadas a C:

- **Encapsulamento** via ponteiros opacos (pseudo-POO)
- **Crescimento automático exponencial** para amortizar realocações
- **Genericidade** com `void *` — funciona com `int`, `double`, `struct`, qualquer tipo
- **Gerenciamento correto de memória** — sem vazamentos, com `free` explícito
- **Separação clara** entre interface pública (`vector.h`) e implementação (`vector.c`)

---

## 🚀 Como Compilar e Executar

### Pré-requisitos

- GCC ou Clang instalado
- GNU Make

### Passos
```bash
# Clone o repositório
git clone https://github.com/seu-usuario/seu-repositorio.git
cd seu-repositorio

# Compile
make

# Execute os testes
./vector_test
```

---

## 🗂️ Estrutura do Projeto
.
├── vector.h        # Interface pública — tipos e assinaturas das funções
├── vector.c        # Implementação interna
├── vector_test.c   # Programa de teste e uso de exemplo
└── Makefile        # Regras de compilação

---

## 🔧 Interface Pública

A API segue um estilo orientado a objetos em C, onde o vetor é sempre manipulado por ponteiro:
```c
// Criação e destruição
Vector *vector_create(size_t element_size);
void    vector_destroy(Vector *v);

// Acesso e modificação
void   vector_push_back(Vector *v, const void *element);
void  *vector_get(const Vector *v, size_t index);
void   vector_set(Vector *v, size_t index, const void *element);
void   vector_pop_back(Vector *v);

// Informações
size_t vector_size(const Vector *v);
size_t vector_capacity(const Vector *v);
int    vector_is_empty(const Vector *v);
```

### Exemplo de uso com `int`
```c
Vector *v = vector_create(sizeof(int));

for (int i = 0; i < 10; i++) {
    vector_push_back(v, &i);
}

int *val = (int *) vector_get(v, 4);
printf("Elemento no índice 4: %d\n", *val); // 4

vector_destroy(v);
```

### Exemplo de uso com `struct`
```c
typedef struct {
    char name[64];
    int  age;
} Person;

Vector *people = vector_create(sizeof(Person));

Person p = { "Alice", 30 };
vector_push_back(people, &p);

Person *retrieved = (Person *) vector_get(people, 0);
printf("%s tem %d anos\n", retrieved->name, retrieved->age);

vector_destroy(people);
```

---

## ⚙️ Estratégia de Crescimento

Quando a capacidade atual é atingida, o vetor dobra de tamanho:
capacidade inicial → 4
push além do limite → realoca para 8 → 16 → 32 → ...

Isso garante complexidade **amortizada O(1)** para `push_back`, evitando realocações frequentes.

| Operação         | Complexidade |
|------------------|-------------|
| `push_back`      | O(1) amortizado |
| `get` / `set`    | O(1)        |
| `pop_back`       | O(1)        |
| `vector_size`    | O(1)        |

---

## 🧠 Decisões de Design

### Por que `void *`?
Permite genericidade sem templates (inexistentes em C). O custo é que o tipo é responsabilidade do chamador — não há verificação em tempo de compilação.

### Por que ponteiro opaco?
O tipo `Vector` é declarado no `.h` mas definido apenas no `.c`. Isso esconde os detalhes de implementação e impede acesso direto aos campos internos, simulando encapsulamento.

### Por que crescimento exponencial e não linear?
Crescimento linear (ex: `+10` por vez) causaria O(n²) realocações no total. Dobrar a capacidade garante O(n) realocações no total — muito mais eficiente.

---

## 📈 Próximos Passos

- [ ] `vector_insert(v, index, element)` — inserção em posição arbitrária
- [ ] `vector_remove(v, index)` — remoção por índice
- [ ] `vector_shrink_to_fit(v)` — liberar memória não utilizada
- [ ] `vector_foreach(v, callback)` — iteração com função de callback
- [ ] `vector_sort(v, comparator)` — ordenação com `qsort` interno
- [ ] Testes com Valgrind para verificação de memória
- [ ] Documentação com Doxygen

---

## 🧪 Verificação de Memória

Recomenda-se rodar com Valgrind para garantir ausência de vazamentos:
```bash
valgrind --leak-check=full ./vector_test
```

---

## 📄 Licença

Este projeto está sob a licença MIT. Consulte o arquivo `LICENSE` para mais informações.
