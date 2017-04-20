#ifndef _MERGESORT_HH
#define _MERGESORT_HH

#include "Lista_hh"

//Nie byłem w stanie poradzić sobie ze zrozumieniem kodu kolegi i posortowaniem go.

using namespace std;

class Merge_sort
{
private:
  Lista lista;
  int start;
  int middle;
  int end;
public:
  void merge(int lista, int start, int middle, int end);
  void sort(int lista, int start, int end);
}
  
  void Merge_sort::merge(int lista, int start, int middle, int end);
{
  
};

void Merge_sort::sort(int lista, int start, int end):
{
  int s;

  if(start != end)
    {
      s = (start + end)/2;
      sort(tab, start, s);
      sort(tab, s+1, end);
      merge(tab, start, s, end);
    }
};

#endif
