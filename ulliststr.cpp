#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

////// WRITE YOUR CODE HERE ////TODOs///////////////////////////////////////
void ULListStr::push_back(const std::string& val)
{
    if(head_ == nullptr || tail_ == nullptr)  
    {
        head_ = new Item;
        tail_ = head_;
    }

    if (tail_->last >= ARRSIZE) // if fully occupied
    {
        Item* newTail = new Item;
        newTail->prev = tail_;
        tail_->next = newTail;
        tail_ = newTail;
    }

    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
}

void ULListStr::pop_back() 
{
    if (tail_ != nullptr) 
    {
        tail_->last--;
        size_--;

        if (tail_->first <= tail_->last) 
        {
            tail_->val[tail_->last] = "";
        }

        if (tail_->last == tail_->first) //then delete this tail
        {
            Item* newTail = tail_->prev;
            if (newTail != nullptr) 
            {
                newTail->next = nullptr;
                delete tail_;
                tail_ = newTail;
            }
            else 
            {
                delete tail_;
            }   
        }
    }
}

void ULListStr::push_front(const std::string& val) 
{
    if(head_ == nullptr || tail_ == nullptr)  
    {
        head_ = new Item;
        tail_ = head_;
    }

    head_->first--;
    
    if (head_->first < 0) // create new head
    {
        Item* newHead = new Item;
        newHead->next = head_;
        head_->prev = newHead;
        head_ = newHead;

        head_->last = ARRSIZE;
        head_->first = (ARRSIZE - 1);
    }

    head_->val[head_->first] = val;
    size_++;
}

void ULListStr::pop_front() 
{
    if(head_ != nullptr) 
    {
        head_->val[head_->first] = "";
        head_->first++;
        size_--;

        if (head_->first >= head_->last) //then delete this head
        {
            Item* newhead = head_->next;
            if (newhead != nullptr) 
            {
                newhead->prev = nullptr;
                delete head_;
                head_ = newhead;
            } 
            else 
            {
                delete head_;
            }
            
        }
    }
}

std::string const & ULListStr::back() const 
{
    if (tail_ != nullptr) 
    {
        size_t lastIndex = tail_->last - 1;
        if (lastIndex < 0) lastIndex = 0;

        return tail_->val[lastIndex];
    }

    return "";

}

std::string const & ULListStr::front() const 
{
    if (head_ != nullptr) 
    {
        return head_->val[head_->first];
    }

    return "";
}

std::string* ULListStr::getValAtLoc(size_t loc) const // the loc means overall location
{
    size_t index = loc;

    Item* pointerItem = head_;

    while (pointerItem != nullptr) 
    {
        size_t size = (pointerItem->last - pointerItem->first);

        if (index < size) 
        {
            return &pointerItem->val[pointerItem->first + index];
        }
        else 
        {
            index -= size;
            pointerItem = pointerItem->next;
        }
    }
    
    //otherwise
    return nullptr;
}

///////////////////////////////////////////////////////////////////////////

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
