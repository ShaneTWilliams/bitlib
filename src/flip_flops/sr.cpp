#include "bitlib/flip_flops/sr.hpp"

bl::SrFlipFlop::SrFlipFlop(std::string name)
    : Component(name),
      sr_latch(SrLatch(name + "::SR_LATCH")),
      s_and(AndGate<2>(name + "::S_AND")),
      r_and(AndGate<2>(name + "::R_AND")),
      en_buf(BufferGate(name + "::EN_BUF")) {
    bl::connect(this->s_and.output, this->sr_latch.s);
    bl::connect(this->r_and.output, this->sr_latch.r);

    bl::connect(this->en_buf.output, this->s_and.inputs[0]);
    bl::connect(this->en_buf.output, this->r_and.inputs[0]);

    this->s = s_and.inputs[1];
    this->r = r_and.inputs[1];
    this->q = sr_latch.q;
    this->qn = sr_latch.qn;
    this->en = en_buf.input;

    this->s->set_label(this->get_name() + "::S");
    this->r->set_label(this->get_name() + "::R");
    this->q->set_label(this->get_name() + "::Q");
    this->qn->set_label(this->get_name() + "::QN");
    this->en->set_label(this->get_name() + "::EN");
}
