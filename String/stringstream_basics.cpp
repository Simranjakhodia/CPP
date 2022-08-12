int countWords(string str) {
    stringstream ss(str);
    string word;
    int count = 0;
    while(ss >> word)
        count++;
        
    return count;
}

void printFrequency(string str) {
    map<string, int> m;
    stringstream ss(str);
    string word;
    
    while(ss >> word)
        m[word]++;
        
        
    for(auto i = m.begin(); i != m.end(); m++)
        cout << i.first << " " << i.second;
}

void findWords(string str, int k) {
    stringstream ss;
    string word;
    
    int count = 0;
    while(ss >> word) {
        if(word.size() > k) {
            cout << word << " ";
            count++;
        }
    }
    cout << endl << count << " words have length greater than " << k << endl;
}


