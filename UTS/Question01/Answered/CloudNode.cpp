#include "CloudNode.hpp"
#include "Formatter.hpp"

CloudNode::CloudNode(std::string name, int limit) : server_name(name), used_gb(0), limit_gb(limit) {
    Formatter::printCtor(this->server_name);
}

CloudNode::CloudNode(const CloudNode& other) : server_name(other.server_name + "_backup"), used_gb(0), limit_gb(other.limit_gb) {
    Formatter::printCCtor(this->server_name);
}

CloudNode& CloudNode::operator=(const CloudNode& other) {
    if (this != &other) {
        this->used_gb = other.used_gb + 2;
        if (this->used_gb > this->limit_gb) {
            this->used_gb = this->limit_gb;
        }
        Formatter::printAssign(this->server_name);
    }
    return *this;
}

CloudNode::~CloudNode() {
    Formatter::printDtor(this->server_name);
}

CloudNode CloudNode::operator+(int n) const {
    CloudNode res(*this);
    res.limit_gb += n;
    return res;
}

CloudNode CloudNode::operator-(int n) const {
    CloudNode res(*this);
    res.used_gb = this->used_gb - n;
    if (res.used_gb < 0) {
        res.used_gb = 0;
    }
    return res;
}

void systemWipe(CloudNode &node) {
    node.used_gb = 0;
    node.limit_gb = 0;
}
