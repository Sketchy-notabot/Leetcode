class CombinationIterator {
public:
    string curr, characters;
    int hasNextBool;
    CombinationIterator(string characters, int combinationLength) {
        curr = characters.substr(0, combinationLength);
        this->characters = characters;
        hasNextBool = 0;
    }
    
    string next() {
        string ret = curr;
        if(ret==characters.substr(characters.length()-curr.length())){
            hasNextBool++;
            return ret;
        }
        int i = curr.length()-1;
        while(i>=0){
            if(curr[i]!=characters[characters.length()-curr.length()+i]){
                int j=0;
                while(characters[j]!=curr[i]) j++;
                while(i<curr.length())
                    curr[i++]=characters[++j];
                break;
            }
            i--;
        }
        return ret;
    }
    
    bool hasNext() {
        if(hasNextBool)
            return false;
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */