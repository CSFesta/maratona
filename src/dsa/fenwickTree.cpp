#include "../template.h"

struct FenwickTree {
    std::vector<int64_t> bit;
    int64_t n;

    FenwickTree(int64_t size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int64_t index, int64_t delta) {
        for (; index <= n; index += index & -index)
            bit[index] += delta;
    }

    int64_t query(int64_t index) {
        int64_t sum = 0;
        for (; index > 0; index -= index & -index)
            sum += bit[index];
        return sum;
    }

    int64_t range_query(int64_t left, int64_t right) {
        return query(right) - query(left - 1);
    }
};

/*
Inicializacao: FenwickTree fw(n);
adicionar/atualizar valor: fw.update(index, val), 
    -> index = vai somar ate o index q passado. 
    -> val = valor que sera acrescentado a mais
valor total de uma posicao: fw.query(index), ele precisa somar log(n) valores anteriores
valor total de um uma posicao ate outra: fw.range_query(index_inicial, index_final)
*/

