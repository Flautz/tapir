Toolkit for approximating and Adapting POMDP solutions In Realtime (TAPIR)
==========================================================================

TAPIR is a C++ implementation of the Adaptive Belief Tree (ABT) algorithm [1].
ABT is an online POMDP solver capable of adapting to modifications to the POMDP
model without the need to reconstruct the policy from scratch.

[1] H. Kurniawati and V. Yadav. An Online POMDP Solver for Uncertainty Planning
in Dynamic Environment. Proc. Int. Symp. on Robotics Research. 2013.
http://robotics.itee.uq.edu.au/~hannakur/dokuwiki/papers/isrr13_abt.pdf

For bug reports and suggestions, please email rdl.algorithm@itee.uq.edu.au

For information on updates, please visit http://robotics.itee.uq.edu.au/~tapir


System Requirements
-------------------

Operating systems:
- Linux
- Windows (untested)

Building and running the C++ source code requires:
- [GNU C++ compiler](https://gcc.gnu.org) (>= 4.8) or equivalent
- [libspatialindex](http://libspatialindex.github.io) (>= 1.7.0)
	Debian/Ubuntu package name: "libspatialindex-dev"
- [Eigen 3](http://eigen.tuxfamily.org) (>= 3.2.0)
	Debian/Ubuntu package name: "libeigen3-dev"


Quick Start (Command-line Interface)
------------------------------------

For a command-line interface, at the top level directory of TAPIR
(where this README file is located), run:

    make all

or, for faster compilation via multi-threading,

    make all -jN

where N is the number of threads you want to use - 8 is a good choice on many
CPUs.

This will create the executables for a command-line interface for each of
the example problems - these are created in /bin/basic/[problem-name],
and also in /src/problems/[problem-name] for convenience.

After compiling, you can try the following commands to try solving the example
problem Tag:

    cd bin/basic/tag
    ./solve
    ./simulate

For a more detailed description of the Tag POMDP, see
http://www.cs.cmu.edu/~ggordon/jpineau-ggordon-thrun.ijcai03.pdf

The command "solve" uses use the parameters set in a problem-specific
configuration file, which for Tag is, by default, [here](cfg/tag/default.cfg).
The purpose of "solve" is to output a policy, which by default will be
written to the file "pol.pol" in the current working directory.

The command "simulate" uses the same default configuration file, but its
function is to run online simulations to evaluate the performance of
the TAPIR solver. It starts by loading an initial policy from the policy
file (default "pol.pol", as output by "solve"), and runs a step-by step
simulation of the POMDP. The online solver is run on every step so that
the policy can be dynamically generated on every step.

To change the configuration settings, edit the default configuration
files, or copy them and make your own version, e.g.

    cd cfg/tag
    cp default.cfg my_tag_settings.cfg

Now you can edit my_tag_settings.cfg to change the settings. To use
with a different configuration file, use the command-line argument
--cfg, e.g.

    cd bin/basic/tag
    ./solve --cfg my_tag_settings.cfg

Note that "solve" is still searching for configuration settings in
the folder "cfg/tag" - you can change this by using the argument
--base-path <path>.

Some of the core settings can also be set via command-line arguments;
for details run

    solve --help

or

    simulate --help

to see the command-line options for either executable.

Quick Start (ROS and V-REP Interface)
-------------------------------------

TAPIR provides interface with ROS and V-REP, and has been tested with:
...

If you have ROS and V-REP installed in your system, TAPIR can interface with
them. Please compile with:
...


To try solving an example problem with ROS and V-REP interface, run:
...


Implementing a new POMDP model
------------------------------

To create a new POMDP model and use it with the the command-line interface,

1. Read and follow the guidelines in [the detailed overview](docs/Overview.md).
2. Create a new subdirectory for your POMDP in
[the problems folder](src/problems).
3. Implement all the required classes, as per [the overview](docs/Overview.md)
4. Add a new Makefile to your problem directory - just copy
[the Tag Makefile](src/problems/tag/Makefile) and change MODULE_NAME to match
your new problem.
5. Add your problem to the CHILD_FOLDERS variable in the
[problems Makefile](src/problems/Makefile)
6. Create a new subdirectory in [the config folder](cfg) for your problem, and
add any required configuration files there.
7. Compile your code via "make [problem-name]", or simply by running "make" from
your new subfolder of src/problems, e.g.
    cd src/problems/tag
    make

Package Structure
-----------------

Here's a quick overview of the contents of this package, by directory structure:
- README.md - this README!
- [Makefile](Makefile) - used to change most of the core settings used
in building the code.
- [.make](.make) - contains template Makefile code which is included by
the Makefiles in many of the subdirectories. This is the core of the build
system, which is described in the [Build System README](.make/README.md).
- [cfg](cfg) - contains problem-specific configuration settings for each of the
example problems.
- [docs](docs) - contains [the detailed overview](docs/Overview.md), as well as
Doxygen settings in order to generate [HTML documentation](html/index.html).
- [html](html) - the output folder for HTML documentation
- [src](src) - the source folder
    - [solver](src/solver) - the core ABT solver source code
    - [options](src/options) - contains code for parsing configuration options.
    Most of the work is done by two libraries included in the code:
        - [TCLAP](src/options/tclap) - see http://tclap.sourceforge.net/ for
        more details.
        - [inih](src/options/inih) - see https://code.google.com/p/inih/ for
        more details.
    - [problems](src/problems) - contains the code for all of the example
    problems.
        - [shared](src/problems/shared) - contains shared code used by many
        problems
        - [RockSample](src/problems/rocksample) - contains code for the
        RockSample POMDP.
        - [Tag](src/problems/tag) - contains code for the Tag POMDP.

Acknowledgements
----------------

The development of this package is partially funded by
the BEE Division Grant 2013.


Release Notes
-------------
