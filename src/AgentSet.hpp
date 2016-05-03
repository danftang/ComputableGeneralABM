#ifndef AGENTSET_H
#define AGENTSET_H

template<class T>
class AgentSet : public Agent, public std::vector<T>
{
public:
    AgentSet(int n, Economy &root) : Agent(root), std::vector<T>(n, T(root)) {};
    void step();
};

template<class T>
void AgentSet<T>::step() {
    for(T &member : *this) {
        member.step();
    }
}

#endif // AGENTSET_H
