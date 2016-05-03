#ifndef AGENTSET_H
#define AGENTSET_H

template<class T>
class AgentSet : public Agent, public std::vector<T>
{
public:
    AgentSet(int n, Economy &root) : Agent(root), std::vector<T>(n, T(root)) {};
    AgentSet(const std::vector<typename T::Config> &configs, Economy &root);
    void step();
};

template<class T>
AgentSet<T>::AgentSet(const std::vector<typename T::Config> &configs, Economy &r) : Agent(r) {
    std::vector<T>::reserve(configs.size());
    T dummy(r);
    for(const typename T::Config conf : configs) {
        std::vector<T>::push_back(dummy);
        std::vector<T>::back().conf = conf;
    }
}

template<class T>
void AgentSet<T>::step() {
    for(T &member : *this) {
        member.step();
    }
}

#endif // AGENTSET_H
