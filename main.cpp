#include <benchmark/benchmark.h>
#include <vector>
using namespace std;
struct BigTestStruct
{

  int iValue = 1;
  float fValue;
  long lValue;
  double dValue;
  char cNameArr[10];
  int iValArr[100];
};

int iterMax = 10000;
int iterMin = 10;

void FillVectorPush(vector<BigTestStruct>& testVector, int iter)
{
  for (int i = 0; i < iter; i++)
  {
    BigTestStruct bt;
    testVector.push_back(bt);
  }
}

void FillVectorEmplace(vector<BigTestStruct>& testVector, int iter)
{
  for (int i = 0; i < iter; i++)
  {
    BigTestStruct bt;
    testVector.emplace_back(bt);
  }
}

vector<BigTestStruct> testVector1;
vector<BigTestStruct> testVector2;


static void BM_VectorPushBack10000Iter(benchmark::State& state) {

for (auto _ : state)
{
  FillVectorPush(testVector1, iterMax);
}
}

static void BM_VectorEmplace10000Iter(benchmark::State& state) {

for (auto _ : state)
{
  FillVectorEmplace(testVector2, iterMax);
}
}

static void BM_VectorPushBack10Iter(benchmark::State& state) {

for (auto _ : state)
{
  FillVectorPush(testVector1, iterMin);
}
}

static void BM_VectorEmplace10Iter(benchmark::State& state) {

for (auto _ : state)
{
  FillVectorEmplace(testVector2, iterMin);
}
}

// Register the function as a benchmark
//BENCHMARK(BM_VectorPushBack);
//BENCHMARK(BM_VectorEmplace);

// Define another benchmark

BENCHMARK(BM_VectorPushBack10000Iter)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_VectorEmplace10000Iter)->Unit(benchmark::kMillisecond);
BENCHMARK(BM_VectorPushBack10Iter);
BENCHMARK(BM_VectorEmplace10Iter);
BENCHMARK_MAIN();  

