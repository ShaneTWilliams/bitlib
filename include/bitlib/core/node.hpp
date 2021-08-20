#pragma once

#include <deque>
#include <vector>

#include "bitlib/core/bitlib.hpp"
#include "bitlib/core/component.hpp"
#include "bitlib/core/primitive.hpp"

namespace bl {

class InputNode;
class OutputNode;

void connect(InputNode* input_node, OutputNode* output_node);
void disconnect(InputNode* input_node, OutputNode* output_node);
bool is_connected(InputNode* input_node, OutputNode* output_node);
void connect(OutputNode* output_node, InputNode* input_node);
void disconnect(OutputNode* output_node, InputNode* input_node);
bool is_connected(OutputNode* output_node, InputNode* input_node);

class Node : public Component {
 public:
    Node(Direction direction, State start_state, UpdateCallback update_callback,
         std::string name);

    State get_state(void);

    const Direction direction;
    const UpdateCallback update_state;
    bool log_state_changes = false;

 protected:
    State state;
};

class OutputNode : public Node {
 public:
    OutputNode(bl::State start_state, UpdateCallback update_callback,
                           std::string name);

    static OutputNode* create_new(bl::State start_state, UpdateCallback update_callback,
                                  std::string name);

    void connect(InputNode* node);
    void disconnect(InputNode* node);
    bool is_connected(InputNode* node);

    void set_state(State state, bool push_to_queue = true);

    std::vector<InputNode*> connections;

 private:
    OutputNode(bl::State start_state, Primitive* parent, std::string name);
};

class InputNode : public Node {
 public:
    InputNode(bl::State start_state, UpdateCallback update_callback,
                         std::string name);

    static InputNode* create_new(bl::State start_state, UpdateCallback update_callback,
                                 std::string name);

    void connect(OutputNode* node);
    void disconnect(OutputNode* node);
    bool is_connected(OutputNode* node);

    void set_state(State state);

    bool is_floating = true;

 private:
    InputNode(bl::State start_state, Primitive* parent, std::string name);
};

OutputNode* create_output_node(bl::State start_state, Primitive* parent, std::string name);

extern std::deque<InputNode> input_netlist;
extern std::deque<OutputNode> output_netlist;

}  // namespace bl
