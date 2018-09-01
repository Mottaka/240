#ifndef _240_LECT_10POINTERS_INTLIST_H_
#define _240_LECT_10POINTERS_INTLIST_H_

#include <cassert>
#include <iostream>
using std::ostream;


namespace csce240 {

  struct IntNode {
    IntNode(int elem,
            IntNode* next=nullptr, IntNode* prev=nullptr) :
            elem_(elem), next_(next), prev_(prev) {};
  
    int elem_;
    IntNode *next_, *prev_;
  };
  
  class IntList {
   public:
    IntList() : head_(nullptr), tail_(nullptr), size_(0) {};
    IntList(int elem) : head_(new IntNode(elem)),
                        tail_(head_), size_(1) {};
    IntList(const IntList& original);
    ~IntList();
  
    inline int front() const { return head_->elem_; };
    inline int back() const { return tail_->elem_; };
  
    void PushFront(int elem);
    void PushBack(int elem);

	int PopFront();
	int PopBack();
  
    inline int size() const { return size_; }
  
    IntList& operator=(const IntList& original);
  
    friend ostream& operator<<(ostream& ostr, const IntList& list);
  
   private:
    void ClearList();
  
    IntNode *head_, *tail_;
    int size_;
  };
}
#endif
