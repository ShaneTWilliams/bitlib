#include "bitlib/latches/sr.hpp"

bl::SrLatch::SrLatch(std::string name)
    : Component(name), s_nor(NorGate<2>(name + "::S_NOR")), r_nor(NorGate<2>(name + "::R_NOR")) {
    bl::connect(this->s_nor.output, this->r_nor.inputs[0]);
    bl::connect(this->r_nor.output, this->s_nor.inputs[0]);

    this->s = s_nor.inputs[1];
    this->r = r_nor.inputs[1];
    this->q = r_nor.output;
    this->qn = s_nor.output;

    this->s->set_label(this->get_name() + "::S");
    this->r->set_label(this->get_name() + "::R");
    this->q->set_label(this->get_name() + "::Q");
    this->qn->set_label(this->get_name() + "::QN");
}
