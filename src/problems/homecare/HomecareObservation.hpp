/** @file HomecareObservation.hpp
 *
 * Defines the HomecareObservation class, which represents an observation in the Homecare POMDP.
 */
#ifndef HOMECARE_OBSERVATION_HPP_
#define HOMECARE_OBSERVATION_HPP_

#include <cstddef>                      // for size_t

#include <ostream>                      // for ostream
#include <vector>                       // for vector

#include "problems/shared/GridPosition.hpp"
#include "solver/abstract-problem/DiscretizedPoint.hpp"
#include "solver/abstract-problem/Observation.hpp"

#include "global.hpp"                     // for RandomGenerator

namespace homecare {
class HomecareModel;

class HomecareObservation : public solver::Point {
    friend class HomecareTextSerializer;
  public:
    HomecareObservation(GridPosition robotPos, GridPosition targetPos,
        int targetRegion, bool call);

    virtual ~HomecareObservation() = default;
    _NO_COPY_OR_MOVE(HomecareObservation);

    std::unique_ptr<solver::Observation> copy() const override;
    double distanceTo(solver::Observation const &otherObs) const override;
    bool equals(solver::Observation const &otherObs) const override;
    std::size_t hash() const override;
    void print(std::ostream &os) const override;

    /** Returns the position the robot has observed itself in. */
    GridPosition getRobotPos() const;
    /** Returns position of opponent if within 1 cell from robot, 
     *   otherwise returns (-1, -1) 
     */
    GridPosition getTargetPos() const;
    int getTargetRegion() const;
    bool getCall() const;

  private:
    GridPosition robotPos_;
    GridPosition targetPos_;
    int targetRegion_;
    bool call_;
};
} /* namespace homecare */
#endif /* HOMECARE_OBSERVATION_HPP_ */