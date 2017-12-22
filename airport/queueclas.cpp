#include "Queueclas.h"
　
　
void Queueclas::push(Request req)
{
 landing.push_back(req);
}
void Queueclas::
void Queueclas::pop()
{
 landing.pop_back();
}
bool Queueclas::isempty()
{
 if (landing.empty())
 {
  cout << "queue is empty";
 }
}
Queueclas::Queueclas()
{
}
　
Queueclas::~Queueclas()
{
}
