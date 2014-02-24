#include "disjoint_set.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std; 

Universe::Universe(long int elements)
{ elts_ = new Elt[elements];
  num_elements_ = elements;
  for(long int i=0; i<num_elements_;i++)
  { elts_[i].parent = i;
    elts_[i].rank = 0;
    elts_[i].size = 1;
 }
}

Universe::~Universe()
{ delete [] elts_;
  return ;
}

//Union two of sets such that the one of bigger rank will contain the smaller one.
//In case they are of equal rank then increment rank by one of the randomly chosen parent.
void Universe::UnionSet(long int x, long int y)
{ if(elts_[x].parent == elts_[y].parent)
  return; 

  if(elts_[x].rank < elts_[y].rank)
  { elts_[x].parent = y;
    elts_[y].size = elts_[x].size + elts_[y].size; 
  }
  //else if(elts_[x].rank > elts_[y].rank)
  else
  {  elts_[y].parent = x;
     elts_[x].size = elts_[y].size + elts_[x].size; 
     if(elts_[x].rank == elts_[y].rank) elts_[x].rank++;
  }
  /*else 
  { elts_[y].parent = x;
    elts_[x].rank++;
    elts_[x].size = elts_[x].size + elts_[y].size; 
   }*/
}

//Find till the parent and itself is the same.
long int Universe::FindSet(long int x)
{ if(elts_[x].parent != x)
    { elts_[x].parent = FindSet(elts_[x].parent);
      //x.parent = temp.parent;
    }
  return(elts_[x].parent);
}

//Print the graph into a dot file for visualizing using GraphViz.
long int Universe::PrintGraph(char* filename)
{  ofstream outdata;
   outdata.open(filename); 
   if( !outdata ) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

   outdata << "digraph Disjoint_graph {" << endl;
   for(long int i=0;i<num_elements_;i++)
   outdata << i <<" -> " << FindSet(i) << endl; 
   //elts_[i].parent << endl;
   outdata << "}" << endl;
   outdata.close();
   return 1;
}
