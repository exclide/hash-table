#ifndef HASH_TABLE_PERF_TEST_H
#define HASH_TABLE_PERF_TEST_H

#include <benchmark/benchmark.h>
#include "hash_table_chain.h"
#include "hash_table_open.h"
#include <unordered_map>
#include <random>

std::random_device rd;
std::default_random_engine generator(rd());
std::uniform_int_distribution<int> distribution(0,INT_MAX);
const int SIZE = 67004173;

static void BM_UnorderedMap(benchmark::State& state) {
    std::unordered_map<int, int> mp;
    mp.reserve(SIZE);

    for (auto _ : state) {
        mp.insert({distribution(generator), 1});
    }
}

static void BM_OpenHash(benchmark::State& state) {
    hash_table_open<int, int> mp(SIZE);

    for (auto _ : state) {
        mp.insert(distribution(generator), 1);
    }
}

static void BM_ChainHash(benchmark::State& state) {
    hash_table_chain<int, int> mp(SIZE);

    for (auto _ : state) {
        mp.insert(distribution(generator), 1);
    }
}


BENCHMARK(BM_UnorderedMap)->Iterations(SIZE/2);
BENCHMARK(BM_OpenHash)->Iterations(SIZE/2);
BENCHMARK(BM_ChainHash)->Iterations(SIZE/2);

#endif //HASH_TABLE_PERF_TEST_H
