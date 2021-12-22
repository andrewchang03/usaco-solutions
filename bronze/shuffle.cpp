#include <iostream>
#include <fstream>
const int MAX_N = 100;
using namespace std;

int A[MAX_N+1];
int order[MAX_N+1];
int original_order[MAX_N+1];

int main(void)
{
  ifstream fin ("shuffle.in");
  ofstream fout ("shuffle.out");

  int N;

  fin >> N;
  for (int i=1; i<=N; i++)
    fin >> A[i];
  for (int i=1; i<=N; i++)
    fin >> order[i];

  for (int iter=0; iter<3; iter++) {
    for (int i=1; i<=N; i++) original_order[i] = order[A[i]];
    for (int i=1; i<=N; i++) order[i] = original_order[i];
  }

  for (int i=1; i<=N; i++)
    fout << order[i] << "\n";
  return 0;
}
