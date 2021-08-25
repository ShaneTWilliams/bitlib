#include "bitlib/flip_flops/d.hpp"

bl::DFlipFlop::DFlipFlop(std::string name)
    : Component(name),
      sr_flip_flop(SrFlipFlop(name + "::SR_FF")),
      d_buf(BufferGate(name + "::D_BUF")),
      d_not(NotGate(name + "::D_NOT")) {
    bl::connect(this->d_buf.output, this->sr_flip_flop.r);
    bl::connect(this->d_buf.output, this->d_not.input);
    bl::connect(this->d_not.output, this->sr_flip_flop.s);

    this->d = d_buf.input;
    this->clk = sr_flip_flop.clk;
    this->q = sr_flip_flop.q;
    this->qn = sr_flip_flop.qn;

    this->d->set_label(this->get_name() + "::D");
    this->clk->set_label(this->get_name() + "::CLK");
    this->q->set_label(this->get_name() + "::Q");
    this->qn->set_label(this->get_name() + "::QN");
}
