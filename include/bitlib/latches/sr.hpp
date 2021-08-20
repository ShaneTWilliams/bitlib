#pragma once

#include "bitlib/core/component.hpp"
#include "bitlib/gates/nor.hpp"

namespace bl {

class SrLatch : public Component {
 public:
    SrLatch(std::string name);

    InputNode* s;
    InputNode* r;
    OutputNode* q;
    OutputNode* qn;

 private:
    NorGate<2> s_nor;
    NorGate<2> r_nor;
};

}  // namespace bl
