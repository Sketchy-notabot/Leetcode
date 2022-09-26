class Solution {
public:
    int parent[26];
    int find(int k){
        if(parent[k]!=k)
            parent[k]=find(parent[k]);
        return parent[k];
    }
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;i++)
            parent[i]=i;
        for(string equation: equations){
            if(equation[1]=='='){
                int p1 = find(equation[0]-'a');
                int p2 = find(equation[3]-'a');
                parent[p1]=parent[p2];
            }
        }
        for(string equation: equations)
            if(equation[1]=='!')
                if(find(equation[0]-'a')==find(equation[3]-'a'))
                    return false;
        return true;        
    }
};
