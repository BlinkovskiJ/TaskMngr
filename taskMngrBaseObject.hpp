#pragma once

public enum class EntityState {
	Unchanged,
	New,
	Modified,
	Deleted
};

ref class taskMngrBaseObject abstract
{
protected:
	EntityState state = EntityState::Unchanged;

public:
	void MarkNew();
	void MarkModified();
	void MarkDeleted();
	void MarkUnchanged();

	EntityState getState();
};

