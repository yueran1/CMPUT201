#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "linkedlist.hpp"

Node::Node( const char *newData )
{
  data = strdup( newData );
  succ = NULL;
}

Node::~Node()
{
  delete data;
  // Don't delete next - we might
  // only be deleting one node out of the
  // linked list.
  // SList is responsible for deleting
  // other nodes.
}

// set node data
void Node::set(const char *x)
{
  // Save a copy of string x
  delete data;
  data = strdup( x );
}

// return node data
const char * Node::get() const
{
  return data;
}

// return pointer to next node
Node *Node::next()
{
  return succ;
}


// constructor: initialize list, no nodes
SList::SList()
{
  head = 0;
  n = 0;
}

// destructor: free all nodes
SList::~SList()
{
  free();
}

// frees all node memory and empties list
void SList::free()
{
  while (head) {
    remove_head();
  }
}

// return number of nodes
int SList::size()
{
  return n;
}

// add node containing data at front
void SList::add_head( const char *data )
{
  Node *q = new Node( data );   // new node
  q->succ = head;       // old head is q successor
  head = q;             // new node is head
  n++;                  // one more node
}

int SList::add_unique( const char *data )
{
  Node *q = find( data );
  if( q == NULL ) {
    // No node with this data exists yet.
    // Add it.
    add_head( data );
    return 1;
  }
  return 0;
}

// returns pointer to head node
Node *SList::get_head()
{
  return head;
}

// removes head node
void SList::remove_head()
{
  if (!head) {          // no node?
    printf("can't remove head from empty list!\n");
    exit(1);            // stop program
  }
  n--;                  // one less node
  Node *q = head->succ; // save pointer to successor
  delete head;          // free head node
  head = q;             // head successor now head
}

Node *SList::find( const char *data )
{
  Node *p = head;
  // Loop through each node in the list
  while( p != NULL ) {
    // If p contains the data we're looking for,
    // return a pointer to it
    if( strcmp( data, p->data ) == 0 ) {
      return p;
    }
    p = p->succ;
  }
  // Didn't find the data we were looking for,
  // return NULL.
  return NULL;
}
