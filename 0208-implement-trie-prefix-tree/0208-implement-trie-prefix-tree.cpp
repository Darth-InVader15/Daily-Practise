class Node{
    public:
    Node* links[26];
    bool flag= false;

    bool contains(char ch)
    {
        return links[ch-'a'] != NULL ;
    }
    void put(char ch, Node* node)
    {
        links[ch-'a'] = node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag = 1;
    }
    bool isEnd()
    {
        return flag;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(auto x:word)
        {
            if(!temp->contains(x))
            {
                temp->put(x,new Node());
            }
            temp = temp->get(x);
        }
        temp->setEnd();
    }
    
    bool search(string word) {
        Node* temp = root;
        for(auto x:word)
        {
            if(!temp->contains(x))   return false;
            temp = temp->get(x);
        }
        return temp->isEnd();
    }
    
    bool startsWith(string word) {
        Node* temp= root;
        for(auto x:word)
        {
            if(!temp->contains(x))   return 0;
            temp = temp->get(x);
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */