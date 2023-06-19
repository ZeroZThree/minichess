#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
struct Node{
  int value;
  int idx;
  Node(int value, int idx):value(value), idx(idx){}
};
class Minimax{
  public:
    Node node;
    static Move get_move(State *state, int depth);
    static Node minimax(State* state, int depth);
};