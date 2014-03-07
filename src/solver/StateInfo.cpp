#include "StateInfo.hpp"

#include <algorithm>                    // for find
#include <memory>                       // for unique_ptr
#include <set>                          // for set
#include <utility>                      // for move
#include <vector>                       // for vector, vector<>::iterator

#include "ChangeFlags.hpp"              // for ChangeFlags, ChangeFlags::UNCHANGED
#include "geometry/State.hpp"                    // for State

namespace solver {
class BeliefNode;
class HistoryEntry;

StateInfo::StateInfo(std::unique_ptr<State> state) :
    state_(std::move(state)),
    id_(-1),
    usedInHistoryEntries_(),
    changeFlags_(ChangeFlags::UNCHANGED) {
}

// Constructor for serialization.
StateInfo::StateInfo() :
    StateInfo(nullptr) {
}

StateInfo::StateInfo(State const &state) :
        StateInfo(state.copy()) {
}

// Do nothing!
StateInfo::~StateInfo() {
}

long StateInfo::getId() const {
    return id_;
}

void StateInfo::setId(long id) {
    id_ = id;
}

State const *StateInfo::getState() const {
    return state_.get();
}

void StateInfo::addHistoryEntry(HistoryEntry *entry) {
    usedInHistoryEntries_.insert(entry);
}

void StateInfo::removeHistoryEntry(HistoryEntry *entry) {
    usedInHistoryEntries_.erase(entry);
}

void StateInfo::resetChangeFlags() {
    changeFlags_ = ChangeFlags::UNCHANGED;
}

void StateInfo::setChangeFlags(ChangeFlags flags) {
    changeFlags_ |= flags;
}

} /* namespace solver */
