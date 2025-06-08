#include "taskMngrBaseObject.hpp"

void taskMngrBaseObject::MarkNew()
{
    state = EntityState::New;
}

void taskMngrBaseObject::MarkModified()
{
    state = EntityState::Modified;
}

void taskMngrBaseObject::MarkDeleted()
{
    state = EntityState::Deleted;
}

void taskMngrBaseObject::MarkUnchanged()
{
    state = EntityState::Unchanged;
}

EntityState taskMngrBaseObject::getState()
{
    return state;
}
