#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) {
        return node;
    }
    UndirectedGraphNode * result;
    unordered_map<int, UndirectedGraphNode*> uin;
    vector<UndirectedGraphNode *> graphnode_v;
    queue<UndirectedGraphNode *> graphnode_q;
    int tmplabel = node->label;
    UndirectedGraphNode * tmpnode;
    UndirectedGraphNode * tmpnewnode;
    tmpnewnode = new UndirectedGraphNode(tmplabel);
    uin[tmplabel] = tmpnewnode;
    graphnode_v.push_back(node);
    graphnode_q.push(node);
    result = tmpnewnode;
    while (!graphnode_q.empty()) {
        tmpnode = graphnode_q.front();
        graphnode_q.pop();
        for( auto tmpnb : tmpnode->neighbors ) {
            tmplabel = tmpnb->label;
            if (!uin[tmplabel]) {
                tmpnewnode = new UndirectedGraphNode(tmplabel);
                uin[tmplabel] = tmpnewnode;
                graphnode_v.push_back(tmpnb);
                graphnode_q.push(tmpnb);
            }
        }
    }
    for( auto tmpvnode : graphnode_v ) {
        tmpnode = uin[tmpvnode->label];
        for( auto tmpnb : tmpvnode->neighbors ) {
            tmpnode->neighbors.push_back(uin[tmpnb->label]);
        }
    }
    return result;
}

int main() {
    UndirectedGraphNode a(0);
    UndirectedGraphNode b(1);
    UndirectedGraphNode c(2);
    a.neighbors.push_back(&b);
    a.neighbors.push_back(&c);
    b.neighbors.push_back(&c);
    c.neighbors.push_back(&c);
    unordered_map<int, UndirectedGraphNode*> uin;

    UndirectedGraphNode * tmp = cloneGraph(&a);
    cout<<tmp->neighbors[0]->neighbors[0]->neighbors[0]->label<<endl;

    return 0;
}
