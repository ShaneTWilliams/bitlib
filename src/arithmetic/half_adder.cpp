#include "bitlib/arithmetic/half_adder.hpp"

bl::HalfAdder::HalfAdder(std::string name)
    : Component(name),
      and_gate(AndGate<2>("::AND")),
      xor_gate(XorGate<2>("::XOR")),
      a_buf_gate(BufferGate("::A_BUF")),
      b_buf_gate(BufferGate("::B_BUF")) {
    bl::connect(this->a_buf_gate.output, this->and_gate.inputs[0]);
    bl::connect(this->b_buf_gate.output, this->and_gate.inputs[1]);
    bl::connect(this->a_buf_gate.output, this->xor_gate.inputs[0]);
    bl::connect(this->b_buf_gate.output, this->xor_gate.inputs[1]);

    this->a = a_buf_gate.input;
    this->b = b_buf_gate.input;
    this->sum = xor_gate.output;
    this->carry = and_gate.output;

    this->a->pretty_name = this->full_name + "::A";
    this->b->pretty_name = this->full_name + "::B";
    this->sum->pretty_name = this->full_name + "::SUM";
    this->carry->pretty_name = this->full_name + "::CARRY";
}
