#include <chrono>
#include <iostream>
#include <thread>

#include "bitlib/core/executor.hpp"
#include "bitlib/core/node.hpp"
#include "bitlib/flip_flops/sr.hpp"
#include "bitlib/gates/and.hpp"
#include "bitlib/gates/not.hpp"
#include "bitlib/memory/register.hpp"
#include "bitlib/sources/single_source.hpp"
#include "bitlib/util/logging.hpp"

int main(void) {
    bl::log::log_level = bl::log::Level::DEBUG;

    bl::Register<8> reg1("REGONE");
    bl::Register<8> reg2("REGTWO");

    bl::SingleSource a = bl::SingleSource("a");
    bl::SingleSource b = bl::SingleSource("b");
    bl::SingleSource c = bl::SingleSource("c");

    bl::connect(reg1.bits[0].input, a.output);
    bl::connect(reg1.bits[1].input, b.output);
    bl::connect(reg1.bits[6].input, c.output);

    for (int i = 0; i < 8; i++) {
        bl::connect(reg1.bits[i].output, reg2.bits[i].input);
    }

    reg1.bits[0].input->log_state_changes = true;
    reg2.bits[0].input->log_state_changes = true;
    reg1.bits[6].input->log_state_changes = true;
    reg2.bits[6].input->log_state_changes = true;

    bl::executor_inst.run();

    bl::log::info << std::hex << reg1.data;
    bl::log::info << std::hex << reg2.data;
    a.set_output(bl::State::HIGH);
    c.set_output(bl::State::HIGH);
    std::cin.get();

    bl::log::info << std::dec << reg1.data;
    bl::log::info << std::hex << reg2.data;
    a.set_output(bl::State::LOW);
    c.set_output(bl::State::LOW);
    std::cin.get();

    bl::log::info << std::hex << reg1.data;
    bl::log::info << std::hex << reg2.data;
    bl::executor_inst.kill();
}
