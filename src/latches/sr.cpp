#include "bitlib/latches/sr.hpp"

bl::SrLatch::SrLatch(std::string name)
    : Component(name), s_nor(NorGate<2>(name + "::S_NOR")), r_nor(NorGate<2>(name + "::R_NOR")) {
    bl::connect(this->s_nor.output, this->r_nor.inputs[0]);
    bl::connect(this->r_nor.output, this->s_nor.inputs[0]);

    this->s = s_nor.inputs[1];
    this->r = r_nor.inputs[1];
    this->q = r_nor.output;
    this->qn = s_nor.output;

    this->s->pretty_name = this->full_name + "::S";
    this->r->pretty_name = this->full_name + "::R";
    this->q->pretty_name = this->full_name + "::Q";
    this->qn->pretty_name = this->full_name + "::QN";
}
