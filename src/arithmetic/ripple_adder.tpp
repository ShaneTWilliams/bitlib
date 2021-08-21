
template <uint8_t NUM_BITS>
bl::RippleAdder<NUM_BITS>::RippleAdder(std::string name)
    : Component(name) {

    this->adders.reserve(NUM_BITS);
    for (uint8_t i = 0; i < NUM_BITS; i++) {
        this->adders.emplace_back(name + "::ADDER_" + std::to_string(i));
        this->input_a_bits.push_back(this->adders[i].a);
        this->input_b_bits.push_back(this->adders[i].b);
        this->sum_bits.push_back(this->adders[i].sum);
    }
    this->carry_in = this->adders[0].carry_in;
    this->carry_out = this->adders[NUM_BITS-1].carry_out;

    for (uint8_t i = 0; i < NUM_BITS - 1; i++) {
        bl::connect(this->adders[i].carry_out, this->adders[i+1].carry_in);
    }

    this->carry_in->set_label(this->get_name() + "::CARRY_IN");
    this->carry_out->set_label(this->get_name() + "::CARRY_OUT");
}
