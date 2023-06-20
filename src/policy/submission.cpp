#include <cstdlib>
#include <climits>
#include "../state/state.hpp"
#include "./submission.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Alphabeta::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  auto actions = state->legal_actions;
    return actions[alphabeta(state, depth, INT_MIN, INT_MAX).idx];
    //return actions[0];
}
Node Alphabeta::alphabeta(State* state, int depth, int alpha, int beta){
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
            Node n = alphabeta(ns, depth-1, alpha, beta);
            if(n.value>value){
                value = n.value;
                idx = i;
            }
            alpha = std::max(alpha, value);
            if(alpha >= beta) break;
        }
        return Node(value, idx);
    }
    else{
        int value = INT_MAX;
        int idx = 0;
        for(int i=0; i<actions.size(); i++){
            State* ns = state->next_state(actions[i]);
            Node n = alphabeta(ns, depth-1, alpha, beta);
            if(n.value<value){
                value = n.value;
                idx = i;
            }
            beta = std::min(beta, value);
            if(beta<=alpha) break;
        }
        return Node(value, idx);
    }
}