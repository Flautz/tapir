#ifndef SOLVER_BELIEFTREE_HPP_
#define SOLVER_BELIEFTREE_HPP_

#include <memory>                       // for unique_ptr
#include <vector>                       // for vector

#include "geometry/Action.hpp"
#include "geometry/Observation.hpp"

#include "global.hpp"

namespace solver {
class ActionMapping;
class BeliefNode;

class BeliefTree {
  public:
    friend class Solver;
    friend class TextSerializer;

    /* Constructs an empty belief tree. */
    BeliefTree();

    // Default destructor; copying and moving disallowed!
    ~BeliefTree();
    _NO_COPY_OR_MOVE(BeliefTree);

    /** Returns the number of belief nodes. */
    long getNumberOfNodes() const;

    /** Resets the tree and sets it root to be the given new node. */
    BeliefNode *setRoot(std::unique_ptr<BeliefNode> root);

    /** Returns the root node. */
    BeliefNode *getRoot() const;

    /**
     * Adds a child belief node to the given belief node; this node will be
     * added to the flattened node list if and only if it is actually new.
     */
    BeliefNode *createOrGetChild(BeliefNode *node, Action const &action,
            Observation const &obs);

    /** Retrieves the node with the given ID. */
    BeliefNode *getNode(long id);

    /** Sets the child with the given ID. */
    void setNode(long id, BeliefNode *node);

private:
    std::unique_ptr<BeliefNode> root_;
    std::vector<BeliefNode *> allNodes_;
};
} /* namespace solver */

#endif /* SOLVER_BELIEFTREE_HPP_ */
