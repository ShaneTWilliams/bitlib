#include "bitlib/arithmetic/half_adder.hpp"

bl::HalfAdder::HalfAdder(std::string name)
    : Component(name),
      and_gate(AndGate<2>(name + "::AND")),
      xor_gate(XorGate<2>(name + "::XOR")),
      a_buf_gate(BufferGate(name + "::A_BUFFER")),
      b_buf_gate(BufferGate(name + "::B_BUFFER")) {
    bl::connect(this->a_buf_gate.output, this->and_gate.inputs[0]);
    bl::connect(this->b_buf_gate.output, this->and_gate.inputs[1]);
    bl::connect(this->a_buf_gate.output, this->xor_gate.inputs[0]);
    bl::connect(this->b_buf_gate.output, this->xor_gate.inputs[1]);

    this->a = a_buf_gate.input;
    this->b = b_buf_gate.input;
    this->sum = xor_gate.output;
    this->carry = and_gate.output;

    this->a->set_label(this->get_name() + "::A");
    this->b->set_label(this->get_name() + "::B");
    this->sum->set_label(this->get_name() + "::SUM");
    this->carry->set_label(this->get_name() + "::CARRY");
}
