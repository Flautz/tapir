#include "simulate.hpp"

#include "TextSerializer.hpp"             // for TextSerializer
#include "UnderwaterNavModifModel.hpp"    // for UnderwaterNavModifModel
#include "UnderwaterNavModifOptions.hpp"  // for UnderwaterNavModifOptions
int main(int argc, const char* argv[]) {
    UnderwaterNavModifOptions options;
    return simulate<UnderwaterNavModifModel, TextSerializer>(argc, argv,
            &options);
}