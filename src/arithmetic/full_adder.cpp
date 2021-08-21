#include "bitlib/arithmetic/full_adder.hpp"

bl::FullAdder::FullAdder(std::string name)
    : Component(name),
      half_adder_1(HalfAdder(name + "::HALF_ADDER_1")),
      half_adder_2(HalfAdder(name + "::HALF_ADDER_2")),
      or_gate(OrGate<2>(name + "::OR_GATE")) {
    bl::connect(this->half_adder_1.sum, this->half_adder_2.b);
    bl::connect(this->half_adder_1.carry, this->or_gate.inputs[0]);
    bl::connect(this->half_adder_2.carry, this->or_gate.inputs[1]);

    this->a = half_adder_1.a;
    this->b = half_adder_1.b;
    this->sum = half_adder_2.sum;
    this->carry_in = half_adder_2.a;
    this->carry_out = or_gate.output;

    this->a->set_label(this->get_name() + "::A");
    this->b->set_label(this->get_name() + "::B");
    this->sum->set_label(this->get_name() + "::SUM");
    this->carry_in->set_label(this->get_name() + "::CARRY_IN");
    this->carry_out->set_label(this->get_name() + "::CARRY_OUT");
}
