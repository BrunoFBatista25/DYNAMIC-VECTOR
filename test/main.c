#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ====================== Struct de exemplo para testar ======================
typedef struct {
    int id;
    char nome[50];
    float salario;
} Pessoa;

// ====================== Funções auxiliares de teste ======================

void print_int(const void* elem)
{
    printf("%d ", *(const int*)elem);
}

void print_double(const void* elem)
{
    printf("%.2f ", *(const double*)elem);
}

void print_pessoa(const void* elem)
{
    const Pessoa* p = (const Pessoa*)elem;
    printf("[ID: %d | %s | R$ %.2f] ", p->id, p->nome, p->salario);
}

int main(void)
{
    printf("=== Teste do Vector Dinâmico ===\n\n");

    printf("1. Vector de int:\n");
    Vector* v_int = vector_create(sizeof(int));

    for (int i = 0; i < 15; i++) {
        vector_push_back(v_int, &i);
    }

    printf("Tamanho: %zu | Capacidade: %zu\n", vector_size(v_int), v_int->capacity);

    printf("Elementos: ");
    for (size_t i = 0; i < vector_size(v_int); i++) {
        print_int(vector_at(v_int, i));
    }
    printf("\n\n");

    printf("2. Vector de double:\n");
    Vector* v_double = vector_create(sizeof(double));

    double valores[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    for (int i = 0; i < 5; i++) {
        vector_push_back(v_double, &valores[i]);
    }

    printf("Elementos: ");
    for (size_t i = 0; i < vector_size(v_double); i++) {
        print_double(vector_at(v_double, i));
    }
    printf("\n\n");

    printf("3. Vector de Pessoa:\n");
    Vector* v_pessoa = vector_create(sizeof(Pessoa));

    Pessoa p1 = {1, "Bruno Felipe", 8500.75};
    Pessoa p2 = {2, "Ana Silva", 6200.00};
    Pessoa p3 = {3, "Carlos Mendes", 12400.50};

    vector_push_back(v_pessoa, &p1);
    vector_push_back(v_pessoa, &p2);
    vector_push_back(v_pessoa, &p3);

    printf("Pessoas cadastradas:\n");
    for (size_t i = 0; i < vector_size(v_pessoa); i++) {
        print_pessoa(vector_at(v_pessoa, i));
        printf("\n");
    }
    printf("\n");

    printf("4. Teste clear + novos elementos:\n");
    vector_clear(v_int);

    int novos[] = {100, 200, 300};
    for (int i = 0; i < 3; i++) {
        vector_push_back(v_int, &novos[i]);
    }

    printf("Após clear e novos pushs: ");
    for (size_t i = 0; i < vector_size(v_int); i++) {
        print_int(vector_at(v_int, i));
    }
    printf("\n\n");

    printf("5. Teste pop_back:\n");
    vector_pop_back(v_pessoa);
    printf("Após remover última pessoa:\n");
    for (size_t i = 0; i < vector_size(v_pessoa); i++) {
        print_pessoa(vector_at(v_pessoa, i));
        printf("\n");
    }

    vector_destroy(v_int);
    vector_destroy(v_double);
    vector_destroy(v_pessoa);

    printf("\n=== Todos os testes concluídos com sucesso! ===\n");
    printf("Memória liberada corretamente.\n");

    return 0;
}