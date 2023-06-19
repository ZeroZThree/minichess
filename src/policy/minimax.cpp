#include <cstdlib>
#include <climits>
#include "../state/state.hpp"
#include "./minimax.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Minimax::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  auto actions = state->legal_actions;
    //return actions[minimax(state, depth).idx];
    return actions[0];
}
Node Minimax::minimax(State* state, int depth){
    if(!state->legal_actions.size()){
        state->get_legal_actions();
    }
    auto actions = state->legal_actions;
    if(depth==0 || !actions.size()){
        return Node(state->evaluate(), -1);
    }
    else if(state->player==0){
        int value = INT_MIN;
        int idx = 0;
        for(int i=0; i<actions.size(); i++){
            State* ns = state->next_state(actions[i]);
            Node n = minimax(ns, depth-1);
            if(n.value>value){
                value = n.value;
                idx = i;
            }
        }
        return Node(value, idx);
    }
    else{
        int value = INT_MAX;
        int idx = 0;
        for(int i=0; i<actions.size(); i++){
            State* ns = state->next_state(actions[i]);
            Node n = minimax(ns, depth-1);
            if(n.value<value){
                value = n.value;
                idx = i;
            }
        }
        return Node(value, idx);
    }
}