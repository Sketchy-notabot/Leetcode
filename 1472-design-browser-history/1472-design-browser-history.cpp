class BrowserHistory {
public:
    vector<string> urls;
    int curr, end;
    BrowserHistory(string homepage) {
        curr = 0;
        end = 0;
        urls.push_back(homepage);
    }
    
    void visit(string url) {
        if(curr==end){
            curr++;
            end++;
            if(end==urls.size())
                urls.push_back(url);
            else
                urls[curr] = url;
        }
        else{
            curr++;
            urls[curr]=url;
            end = curr;
        }
    }
    
    string back(int steps) {
        if(steps>curr){
            curr=0;
            return urls[0];
        }
        curr-=steps;
        return urls[curr];
    }
    
    string forward(int steps) {
        if(curr+steps>=end){
            curr=end;
            return urls[curr];
        }
        curr+=steps;
        return urls[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */