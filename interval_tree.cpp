#include <interval_tree.h>
#include <cmath>

using namespace std;


Itree::Itree(int num_elem)
{ if(num_elem>0)
   num_elements_ = num_elem;
  else
   num_elements_ = 10;
}

template<class IntrvlIter>
void Itree::Build(const IntrvlIter start, const IntrvlIter end)
{ 
  //Check if num_elements and start-end matches.  
  if(distance(start, end) != num_elements_)
    num_elements_ = distance(start, end);
  
  // Push all the intervals and BuildItree for root node.
  for(IntrvlIter i = start; i != end; ++i)
    pending_intrvls_.push_back(*i);
  data_.push_back(node(0,-1));
  BuildItree(0, pending_intrvls_);
 
  // Now do for all nodes.
  /*int current;
  while(!build_q_.empty())
  { current = build_q_.front();
    build_q_.pop();
    BuildItree(current, pending_intrvls_);
  }*/
  return;
}

// A function to swap out a middle element of data, with last element.
// Please ensure that del_node's parents child link to del_node is
// already severed.
int Itree::SwapOutNode(int del_node, int keep_node)
{ 
  // Check del_node's parents.
  if(data_[del_node].parent != -1)
  { if(data_[data_[del_node].parent].right == del_node)
      data_[data_[del_node].parent].right = -1;
    else if (data_[data_[del_node].parent].left == del_node)
      data_[data_[del_node].parent].right = -1;
    else
      return -3; // Orphaned del_node or wrong parent pointer.
  }
  
  // Check keep_node's parents and update them.
  if(data_[keep_node].parent != -1)
  { if(data_[data_[keep_node].parent].right == keep_node)
      data_[data_[keep_node].parent].right = del_node;
    else if (data_[data_[keep_node].parent].left == keep_node)
      data_[data_[keep_node].parent].right = del_node;
    else 
      return -2; // Orphaned keep_node or wrong parent pointer.
  }
  return 0;
}

int Itree::Median(std::vector<intrvl> intrvls)
{ int total_points = intrvls.size()*2;
  std::vector<int> all_points;
  for(std::vector<intrvl>::iterator i = intrvls.begin(); i != intrvls.end(); ++i)
  {  all_points.push_back(i->a);
     all_points.push_back(i->b);
  }
  std::sort(all_points.begin(), all_points.end());
  return (all_points[round(total_points/2)]);
}


void Itree::BuildItree(int curr_node, std::vector<intrvl> intrvls)
{   
  data_[curr_node].index = curr_node;
  data_[curr_node].median = Median(intrvls);
  data_[curr_node].counter = 0;
  data_[curr_node].subtree_size = 0;

  std::vector<intrvl> lintrvls;
  std::vector<intrvl> rintrvls;

  // Parse thru the intervals, and either push them to current nodes interval list
  // or add them to a list of intervals to be passed to right and left children.
  for(std::vector<intrvl>::iterator i = intrvls.begin(); i!= intrvls.end(); ++i)
  { if(i->a > data_[curr_node].median)
      rintrvls.push_back(*i);
    else if(i->b < data_[curr_node].median)
      lintrvls.push_back(*i);
    else
    { data_[curr_node].ldata.insert(*i);
      data_[curr_node].rdata.insert(i->b);
      ++data_[curr_node].subtree_size;
    }
  }
  
  // Now initialize right and left child nodes and pass the data to them, 
  // if they exist.
  if(lintrvls.size()!=0)
  { int lchild = data_.size();
    data_.push_back(node(lchild, curr_node));
    data_[curr_node].left = lchild;
    BuildItree(data_[curr_node].left, lintrvls);
    //build_q_.push_back(lchild);
  }
  else
  { data_[curr_node].left = -1; 
  }
  if(rintrvls.size()!=0)
  { int rchild = data_.size();
    data_.push_back(node(rchild, curr_node));
    data_[curr_node].right = rchild;
    BuildItree(data_[curr_node].right, rintrvls);
    //build_q_.push_back(rchild);
  }
  else
  { data_[curr_node].right = -1; 
  }
  
  return;
}


int Itree::CountQuery(int number, int curr_node=0)
{ int count=0;
  
  if(number < data_[curr_node].median) 
  { 
    std::set<intrvl>::iterator i = data_[curr_node].ldata.upper_bound( intrvl(number,0, 0));
    count += distance(data_[curr_node].ldata.begin(),i); 
    if(data_[curr_node].left != -1)
      count += CountQuery(number, data_[curr_node].left);
  }
   else if(number > data_[curr_node].median) 
   { std::set<int>::iterator i  = lower_bound(data_[curr_node].rdata.begin(), data_[curr_node].rdata.end(), number);
     count += distance(i,data_[curr_node].rdata.end()); 
     if(data_[curr_node].right != -1)
       count += CountQuery(number, data_[curr_node].right);
   } 
  else if(number == data_[curr_node].median)
    return data_[curr_node].ldata.size();

  return count;
}

// Skeleton Code
int Itree::Balance(int root_node)
{ std::vector<intrvl> intrvls;
  std::queue<int> nodes_q, del_q;
  int curr_node;
  int last_node = data_.size()-1;

  if(data_[root_node].left != -1)
    nodes_q.push(data_[root_node].left);
  if(data_[root_node].right != -1)
    nodes_q.push(data_[root_node].right);

  while(!nodes_q.empty())
  { curr_node = nodes_q.front();
    nodes_q.pop();
    intrvls.insert(intrvls.end(), data_[curr_node].ldata.begin(), data_[curr_node].ldata.end()); 
    //intrvl.insert(data_[curr_node].ldata.begin(), data_[curr_node].ldata.end(), std::back_inserter(intrvl) ); 
    if(data_[curr_node].left!=-1)
    { nodes_q.push(data_[curr_node].left);
      //del_q.push_back(data_[curr_node].left);
    }
    if(data_[curr_node].right!=-1)
    { nodes_q.push(data_[curr_node].right);
      //del_q.push_back(data_[curr_node].right);
    }
    if(SwapOutNode(curr_node, last_node)<0)
      return -1;
    if(last_node !=0) --last_node;
  }
  data_.erase(data_.begin()+last_node, data_.end());
  
  BuildItree(root_node, intrvls); 
  return 0;
}


int Itree::Insert(int node, intrvl interval)
{ 
  // Balance the tree if needed.
  if(data_[node].counter >= data_[node].subtree_size)
  { if(Balance(node)<0)
      return -1;
  }

  if(interval.a > data_[node].median)
    Insert(data_[node].right, interval);

  else if(interval.b < data_[node].median)
    Insert(data_[node].left, interval);

  else 
  { // delete_all_sub_nodes;
    data_[node].ldata.insert(interval);
    data_[node].rdata.insert(interval.b);
    ++data_[node].subtree_size;
    ++num_elements_;
  }

  ++data_[node].counter;
  return 0;
}

int Itree::Delete(int node, intrvl interval)
{ int num_del = 0, num_del2 = 0;
  if(interval.a > data_[node].median)
    Delete(data_[node].right, interval);
  else if(interval.b < data_[node].median)
    Delete(data_[node].left, interval);
  else
  { num_del = data_[node].ldata.erase(interval);
    num_del2 = data_[node].rdata.erase(interval.b);
    if(num_del !=1 || num_del2 !=1 )
      return -1;
  --data_[node].subtree_size;
  --num_elements_;  
  }

  ++data_[node].counter;

  return 0;
}

template void Itree::Build(std::vector<intrvl>::iterator, std::vector<intrvl>::iterator);

