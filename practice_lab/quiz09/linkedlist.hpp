#pragma once

// Node data structure
// struct = class with public members

// DON'T CHANGE

class Node
{
public:
  Node( const char *newData );
  ~Node();
  
  const char *data;     // data associated with node
  Node *succ;   // pointer to successor node

  // member functions
  void set(const char *data);
  const char* get() const;
  Node *next();
};


// SList data structure
class SList
{
public:
  // public interface

  // constructor: no nodes
  SList();

  // destructor
  ~SList();

  // free all nodes and empty list
  void free();

  // add node containing data at front
  void add_head( const char *data );

  // check list to see if data already exists.
  // If not, then add it at the front.
  // returns 1 if a node was added, 0 if 
  // data already existed in the list
  int add_unique( const char *data );

  // returns pointer to head node
  Node *get_head();

  // removes head node
  void remove_head();

  // return number of nodes
  int size();

  // Search list for a node with contents equal to data.
  // If found, return a pointer to it.
  // Otherwise, return NULL.
  Node *find( const char *data );

private:
  // private data
  Node *head; // pointer to head node
  int n;      // number of nodes
};
