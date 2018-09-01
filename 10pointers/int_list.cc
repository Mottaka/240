#include "int_list.h"

namespace csce240 {

  IntList::IntList(const IntList& orig) {
    head_ = tail_ = nullptr; // set to nullptr in case orig is empty
  
    for (IntNode *curr = orig.head_;
         curr != nullptr;
         curr = curr->next_)
      PushBack(curr->elem_);
  }
  
  IntList::~IntList() {
    ClearList();
  }
  
  void IntList::PushFront(int elem) {
    if (head_ != nullptr) {
      head_->prev_ = new IntNode(elem, head_);
  
      head_ = head_->prev_;
    }
    else
      head_ = tail_ = new IntNode(elem);

    ++size_;
  }
  
  void IntList::PushBack(int elem) {
    if (tail_ != nullptr) {
      tail_->next_ = new IntNode(elem, nullptr, tail_);
  
      tail_ = tail_->next_;
    }
    else
      head_ = tail_ = new IntNode(elem);

    ++size_;
  }

  int IntList::PopFront() {
    assert(head_ != nullptr);

	int tmp = head_->elem_;

	if ( head_ != tail_ ) {
      head_ = head_->next_;

	  delete head_->prev_;

	  head_->prev_ = nullptr;
	}
	else {
      delete head_;

	  head_ = tail_ = nullptr;
	}

	--size_;

	return tmp;
  }

  int IntList::PopBack() {
    assert(tail_ != nullptr);

	int tmp = tail_->elem_;

	if ( head_ != tail_ ) {
      tail_= tail_->prev_;

	  delete tail_->next_;

	  tail_->next_ = nullptr;
	}
	else {
      delete tail_;

	  head_ = tail_ = nullptr;
	}

	--size_;

	return tmp;
  }
  
  IntList& IntList::operator=(const IntList& orig) {
    if (this == &orig) // do not copy list to itself
      return *this;
  
    ClearList();
    for (IntNode* curr = orig.head_;
         curr != nullptr;
         curr = curr->next_)
      PushBack(curr->elem_);
  
    return *this;
  }
  
  void IntList::ClearList() {
    if (head_ == nullptr)
      return;
  
    IntNode *prev(head_), *curr(head_->next_);
    while(curr != nullptr) {
      delete prev;
  
      prev = curr;
      curr = curr->next_;
    }
    delete prev;
  
    head_ = tail_ = nullptr;
    size_ = 0;
  }
  
  ostream& operator<<(ostream& ostr, const IntList& list) {
    IntNode *cur = list.head_;
  
    while (cur != nullptr) {
      ostr << cur->elem_;
  
      cur = cur->next_;

      if (cur != nullptr)
	    ostr << ", ";
    }
  
    return ostr;
  }

} // namespace csce240

