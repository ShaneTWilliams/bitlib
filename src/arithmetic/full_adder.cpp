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

    this->a->pretty_name = this->full_name + "::A";
    this->b->pretty_name = this->full_name + "::B";
    this->sum->pretty_name = this->full_name + "::SUM";
    this->carry_in->pretty_name = this->full_name + "::CARRY_IN";
    this->carry_out->pretty_name = this->full_name + "::CARRY_OUT";
}
